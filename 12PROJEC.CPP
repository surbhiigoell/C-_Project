//-----------------------------------------------------------------------
//			HEADER FILES USED IN THE PROJECT
//-----------------------------------------------------------------------
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <iomanip.h>
#include <dos.h>
#include <ctype.h>
//-----------------------------------------------------------------------
//				CLASS CUSTOMER
//-----------------------------------------------------------------------
class customer
{
	char name[20];
	int age;
	char gender[10];
	long double aadhar_num;
	char con_num[20];
	char email_id[40];
	char address[40];
	char profession[10];
	char father_name[20];
	int num_of_members;
	char destination[10];
	int dd, dm, dy;
	int ad, am, ay;
	char hotel[10];
	char transport[10];
	int transport_price;
	int hotel_price;
	long net_amount;
	char passport_num[20];
	char visa_num[20];

public:
	customer();
	int getnum_of_members()
	{
		return num_of_members;
	}
	void setmem(int n)
	{
		num_of_members = n;
	}
	char *getname()
	{
		return name;
	}
	int get_hotel_price()
	{
		return hotel_price;
	}
	int get_transport_price()
	{
		return transport_price;
	}
	long get_net_amount()
	{
		return net_amount;
	}
	void set_net_amount(long n)
	{
		net_amount = n;
	}
	void Destination();
	void Transport();
	void Dates();
	void Hotel();
	void getdata();
	void showdata();
	void show();
};
//-----------------------------------------------------------------------
//	 	       	   DEFAULT CONSTRUCTOR
//-----------------------------------------------------------------------
customer::customer()
{
	strcpy(name, NULL);
	age = 0;
	strcpy(gender, "male");
	aadhar_num = 0;
	strcpy(con_num, NULL);
	strcpy(email_id, NULL);
	strcpy(address, NULL);
	strcpy(profession, NULL);
	strcpy(father_name, NULL);
	num_of_members = 1;
	strcpy(destination, NULL);
	dd = 1, dm = 1, dy = 2020;
	ad = 7, am = 1, ay = 2020;
	strcpy(hotel, NULL);
	strcpy(transport, NULL);
	transport_price = 0;
	hotel_price = 0;
}
//-----------------------------------------------------------------------
//		              	VALID NAME
//-----------------------------------------------------------------------
int validname(char s[])
{
	int flag = 1;
	if (strlen(s) < 2)
	{
		flag = 0;
	}
	else
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (!isalpha(s[i]) && s[i] != '.' && s[i] != ' ')
				flag = 0;
		}
	}
	return flag;
}
//-----------------------------------------------------------------------
//				VALID MOBILE
//-----------------------------------------------------------------------
int validmobile(char s[])
{
	int flag = 1;
	if (strlen(s) != 10)
	{
		flag = 0;
	}
	else
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (!isdigit(s[i]))
			{
				flag = 0;
			}
		}
	}
	return flag;
}
//-----------------------------------------------------------------------
//				VALID MAIL
//-----------------------------------------------------------------------
int validmail(char s[])
{
	int flag = 1;
	if (strlen(s) < 10)
	{
		flag = 0;
	}
	else
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (!isalnum(s[i]) && s[i] != '@' && s[i] != '.' && s[i] != '_')
			{
				flag = 0;
			}
		}
	}
	return flag;
}
//-----------------------------------------------------------------------
//			FUNCTION TO GET DESTINATION
//-----------------------------------------------------------------------
void customer::Destination()
{
	clrscr();
	int ch, choice;
aj:
	cout << "\n\t\t-----------------------------------------\n";
	cout << "\n\t\t\t   DESTINATION";
	cout << "\n\t\t-----------------------------------------\n";
	cout << "\n\n\t\t1.international\t2.domestic\n";
	cout << "\n\t\tenter your choice : ";
	cin >> ch;
	cout << "\n\t\t-----------------------------------------";
	switch (ch)
	{
	case 1:
		for (int i = 0; i < num_of_members; i++)
		{
			cout << "\n\t\tenter passport number of travellor number " << i + 1 << ": ";
			gets(passport_num);
			cout << "\n\t\tenter visa number of travellor number " << i + 1 << ": ";
			gets(visa_num);
		}
	ai1:
		cout << "\n\n\t\t1.Dubai\t2.USA\t3.Maldives\n";
		cout << "\n\t\t-----------------------------------------\n";
		cout << "\n\t\tenter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			strcpy(destination, "Dubai");
			break;
		case 2:
			strcpy(destination, "USA");
			break;
		case 3:
			strcpy(destination, "Maldives");
			break;
		default:
			"\n\n\t\twrong choice \n";
			goto ai1;
		}
		break;
	case 2:
	ai2:
		cout << "\n\n\t\t1.Goa\t2.Shimla\t3.Mumbai\t4.Chennai\n";
		cout << "\n\t\t-----------------------------------------";
		cout << "\n\t\tenter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			strcpy(destination, "Goa");
			break;
		case 2:
			strcpy(destination, "Shimla");
			break;
		case 3:
			strcpy(destination, "Mumbai");
			break;
		case 4:
			strcpy(destination, "Chennai");
			break;
		default:
			"\n\n\t\twrong choice \n";
			goto ai2;
		}
		break;
	default:
		cout << "\n\n\t\tinvalid choice\n";
		goto aj;
	}
}
//-----------------------------------------------------------------------
//		        FUNCTION TO CHOOSE A HOTEL
//-----------------------------------------------------------------------
void customer::Hotel()
{
	clrscr();
	int ch, choice;
ah:
	cout << "\n\t\t-----------------------------------------";
	cout << "\n\t\t\t        HOTEL";
	cout << "\n\t\t-----------------------------------------";
	cout << "\n\n\t\t1.5 star\t2.4 star\t3.3 star";
	cout << "\n\t\tenter your preference in hotel : ";
	cin >> ch;
	cout << "\n\t\t(charges are given for one night)\n";
	switch (ch)
	{
	case 1:
	ag1:
		cout << "\n\t\t-------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(15) << "hotel" << setw(10) << "rate\n";
		cout << "\n\t\t------------------------------------------";
		cout << "\n\t\t" << setw(2) << "1" << setw(15) << "ITC Maurya" << setw(10) << "7000";
		cout << "\n\t\t" << setw(2) << "2" << setw(15) << "Viceroy" << setw(10) << "7300";
		cout << "\n\t\t" << setw(2) << "3" << setw(15) << "Taj" << setw(10) << "7500";
		cout << "\n\n\t\tenter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			strcpy(hotel, "ITC Maurya");
			hotel_price = 7000;
			break;
		case 2:
			strcpy(hotel, "Viceroy");
			hotel_price = 7300;
			break;
		case 3:
			strcpy(hotel, "Taj");
			hotel_price = 7500;
			break;
		default:
			cout << "wrong choice\n";
			goto ag1;
		}
		break;
	case 2:
	ag2:
		cout << "\n\t\t-----------------------------------------\n";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(15) << "hotel" << setw(10) << "rate\n";
		cout << "\n\t\t---------------------------------------\n";
		cout << "\n\t\t" << setw(2) << "1" << setw(15) << "Country inn" << setw(10) << "5000\n";
		cout << "\n\t\t" << setw(2) << "2" << setw(15) << "Radission" << setw(10) << "5200\n";
		cout << "\n\t\t" << setw(2) << "3" << setw(15) << "City" << setw(10) << "5500\n";
		cout << "\n\n\t\tenter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			strcpy(hotel, "Country inn");
			hotel_price = 5000;
			break;
		case 2:
			strcpy(hotel, "Radission");
			hotel_price = 5200;
			break;
		case 3:
			strcpy(hotel, "City");
			hotel_price = 5500;
			break;
		default:
			cout << "wrong choice\n";
			goto ag2;
		}
		break;
	case 3:
	ag3:
		cout << "\n\t\t----------------------------------------\n";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(15) << "hotel" << setw(10) << "rate\n";
		cout << "\n\t\t---------------------------------------\n";
		cout << "\n\t\t" << setw(2) << "1" << setw(15) << "Sentinal" << setw(10) << "3000\n";
		cout << "\n\t\t" << setw(2) << "2" << setw(15) << "Green leaf" << setw(10) << "3300\n";
		cout << "\n\t\t" << setw(2) << "3" << setw(15) << "Lemon tree" << setw(10) << "3500\n";
		cout << "\n\n\t\tenter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			strcpy(hotel, "Sentinal");
			hotel_price = 3000;
			break;
		case 2:
			strcpy(hotel, "Green leaf");
			hotel_price = 3300;
			break;
		case 3:
			strcpy(hotel, "Lemon tree");
			hotel_price = 3500;
			break;
		default:
			cout << "wrong choice\n";
			goto ag3;
		}
		break;
	default:
		cout << "\n\n\t\tinvalid choice\n";
		goto ah;
	}
}
//-----------------------------------------------------------------------
//		           FUNCTION TO GET DATES
//-----------------------------------------------------------------------
void customer::Dates()
{
	clrscr();
	textbackground(BLUE);
	cout << "\n\t\t-----------------------------------------";
	cout << "\n\t\t\t   DATES OF TRAVEL";
	cout << "\n\t\t-----------------------------------------\n";
k1:
	cout << "\n\t\tenter date of departure";
	cout << "\n\t\tenter day : ";
	cin >> dd;
	if (dd > 31)
	{
		cout << "\n\t\twrong date ";
		goto k1;
	}
k2:
	cout << "\n\t\tenter month : ";
	cin >> dm;
	if (dm > 12)
	{
		cout << "\n\t\twrong month ";
		goto k2;
	}
k3:
	cout << "\n\t\tenter year : ";
	cin >> dy;
	if (dy < 2020)
	{
		cout << "\n\t\twrong year ";
		goto k3;
	}
	cout << "\n\t\tenter date of arrival";
k4:
	cout << "\n\t\tenter day : ";
	cin >> ad;
	if (ad > 31)
	{
		cout << "\n\t\twrong date ";
		goto k4;
	}
k5:
	cout << "\n\t\tenter month : ";
	cin >> am;
	if (am > 12)
	{
		cout << "\n\t\twrong month ";
		goto k5;
	}
k6:
	cout << "\n\t\tenter year : ";
	cin >> ay;
	if (ay < 2020)
	{
		cout << "\n\t\twrong year ";
		goto k1;
	}
}
//-----------------------------------------------------------------------
//		  FUNCTION TO CALCULATE PRICE ACCORDING TO
//			  MODE OF TRANSPORTATION
//-----------------------------------------------------------------------
void customer::Transport()
{
	clrscr();
	int ch;
	cout << "\n\t\t-----------------------------------------";
	cout << "\n\t\t\t  MODE OF TRANSPORT";
	cout << "\n\t\t-----------------------------------------";
	cout << "\n\n\t\tyour destination is " << destination << endl;
	if (!strcmpi(destination, "goa"))
	{
	al1:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------\n";
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "flight" << setw(10) << "6000" << endl;
		cout << "\n\t\t" << setw(2) << "2" << setw(20) << "train" << setw(10) << "3000" << endl;
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "flight");
			transport_price = 6000;
			break;
		case 2:
			strcpy(transport, "train");
			transport_price = 3000;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al1;
		}
	}
	else if (!strcmpi(destination, "shimla"))
	{
	al2:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------" << endl;
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "bus" << setw(10) << "2000";
		cout << "\n\t\t" << setw(2) << "2" << setw(20) << "train" << setw(10) << "1500";
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "bus");
			transport_price = 2000;
			break;
		case 2:
			strcpy(transport, "train");
			transport_price = 1500;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al2;
		}
	}
	else if (!strcmpi(destination, "mumbai"))
	{
	al3:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------" << endl;
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "flight" << setw(10) << "6500";
		cout << "\n\t\t" << setw(2) << "2" << setw(20) << "train" << setw(10) << "3500";
		cout << "\n\t\t" << setw(2) << "3" << setw(20) << "bus" << setw(10) << "4000";
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "flight");
			transport_price = 6500;
			break;
		case 2:
			strcpy(transport, "train");
			transport_price = 3500;
			break;
		case 3:
			strcpy(transport, "bus");
			transport_price = 4000;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al3;
		}
	}
	else if (!strcmpi(destination, "dubai"))
	{
	al4:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------" << endl;
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "flight" << setw(10) << "10000";
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "flight");
			transport_price = 10000;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al4;
		}
	}
	else if (!strcmpi(destination, "usa"))
	{
	al5:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------" << endl;
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "flight" << setw(10) << "17000";
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "flight");
			transport_price = 17000;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al5;
		}
	}
	else if (!strcmpi(destination, "maldives"))
	{
	al6:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------" << endl;
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "flight" << setw(10) << "8000";
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "flight");
			transport_price = 8000;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al6;
		}
	}
	else if (!strcmpi(destination, "chennai"))
	{
	al7:
		cout << "\n\t\tmode of transportation avaliable are ";
		cout << "\n\t\t-----------------------------------------------";
		cout << "\n\t\t" << setw(2) << "s.no." << setw(20) << "mode of transportation" << setw(10) << "rate";
		cout << "\n\t\t-----------------------------------------------" << endl;
		cout << "\n\t\t" << setw(2) << "1" << setw(20) << "flight" << setw(10) << "7000";
		cout << "\n\t\t" << setw(2) << "2" << setw(20) << "train" << setw(10) << "3800";
		cout << "\n\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			strcpy(transport, "flight");
			transport_price = 7000;
			break;
		case 2:
			strcpy(transport, "train");
			transport_price = 3800;
			break;
		default:
			cout << "\nwrong choice\n";
			goto al7;
		}
	}
	else
	{
		cout << "\nwrong choice\n";
	}
}
//-----------------------------------------------------------------------
//		  	FUNCTION TO INPUT DETAILS
//-----------------------------------------------------------------------
void customer::getdata()
{
	int ch;
	int num;
	do
	{
		cout << "\n\t\tenter your name : ";
		gets(name);
		num = validname(name);
		if (num == 0)
		{
			cout << "\n\t\tinvalid name.Please re-enter\n";
		}
	} while (num == 0);
	cout << "\n\t\tenter your age : ";
	cin >> age;
ak:
	cout << "\n\t\t1.female\t2.male\n";
	cout << "\n\t\tenter your gender : ";
	cin >> ch;
	switch (ch)
	{
	case 1:
		strcpy(gender, "female");
		break;
	case 2:
		strcpy(gender, "male");
		break;
	default:
		cout << "\n\t\t\twrong choice\n";
		goto ak;
	}
	do
	{
		cout << "\n\t\tenter contact number : ";
		gets(con_num);
		num = validmobile(con_num);
		if (num == 0)
		{
			cout << "\n\n\t\tinvalid mobile number.Please re-enter\n";
		}
	} while (num == 0);
	do
	{
		cout << "\n\t\tenter email id : ";
		gets(email_id);
		num = validmail(email_id);
		if (num == 0)
		{
			cout << "\n\n\t\tinvalid email id.Please re-enter\n";
		}
	} while (num == 0);
	cout << "\n\t\taadhar number : ";
	cin >> aadhar_num;
	textbackground(BLUE);
	cout << "\n\t\tenter your address : ";
	gets(address);
	cout << "\n\t\tenter your profession : ";
	gets(profession);
	cout << "\n\t\tenter father's name : ";
	gets(father_name);
	Destination();
	Hotel();
	Dates();
	Transport();
}
//-----------------------------------------------------------------------
//			FUNCTION TO DISPLAY DETAILS
//-----------------------------------------------------------------------
void customer::showdata()
{
	clrscr();
	cout << "\n\t\tDetails of " << name << " are :";
	cout << "\n\t------------------------------------------\n";
	cout << "\n\t\tnumber of members travelling : " << num_of_members;
	cout << "\n\t\tdestination of travel : " << destination;
	cout << "\n\t\tdate of departure : " << dd << "-" << dm << "-" << dy;
	cout << "\n\t\tdate of arrival : " << ad << "-" << am << "-" << ay;
	cout << "\n\t\thotel of stay : " << hotel;
	cout << "\n\t\tmode of transportation : " << transport << "\n";
	for (int i = 0; i < num_of_members; i++)
	{
		textbackground(BLUE);
		cout << "\n\t\tname of " << i + 1 << " member travelling : " << name;
		cout << "\n\t\tage of " << i + 1 << " member travelling : " << age;
		cout << "\n\t\tgender of " << i + 1 << " member travelling : " << gender;
		cout << "\n\t\taadhar number of " << i + 1 << " member travelling : " << aadhar_num;
		cout << "\n\t\tcontact number of " << i + 1 << " member travelling : " << con_num;
		cout << "\n\t\temail id of " << i + 1 << " member travelling : " << email_id;
		cout << "\n\t\taddress of " << i + 1 << " member travelling : " << address;
		cout << "\n\t\tprofession of " << i + 1 << " member travelling : " << profession;
		cout << "\n\t\tfather's name of " << i + 1 << " member travelling : " << father_name;
	}
}
//-----------------------------------------------------------------------
//			FUNCTION TO CREATE TABULAR FORM OF DATA
//				FOR FUNCTION DATABASE()
//-----------------------------------------------------------------------
void customer::show()
{
	cout << "\n\t" << setw(10) << name;
	cout << setw(15) << destination;
	cout << setw(17) << transport;
	cout << setw(2) << dd << "-" << dm << "-" << dy;
	cout << "  " << ad << "-" << am << "-" << ay;
}
//-----------------------------------------------------------------------
//                    FUNCTION TO ADD A NEW ACCOUNT
//-----------------------------------------------------------------------
void add()
{
	clrscr();
	int n;
	char ch;
	ofstream f;
	f.open("account.dat", ios::binary | ios::app);
	customer c[10];
	cout << "\n\t\tenter number of members traveling : ";
	cin >> n;
	cout << "\n\t------------------------------------------------------";
	for (int i = 0; i < n; i++)
	{
		cout << "\n\t\tenter details of " << i + 1 << " travellor \n";
		c[i].setmem(n);
		c[i].getdata();
		f.write((char *)&c[i], sizeof(c[i]));
		textbackground(BLUE);
		cout << "\n\t\t-------------------------------------------------";
	}
	f.close();
}
//-----------------------------------------------------------------------
//			FUNCTION TO READ THE BINARY FILE
//-----------------------------------------------------------------------
void search()
{
	customer c;
	char name[20];
	cout << "\n\t\tenter name to be search : ";
	gets(name);
	clrscr();
	ifstream f;
	f.open("account.dat", ios::binary);
	while (f.read((char *)&c, sizeof(c)))
	{
		if (!strcmpi(name, c.getname()))
			c.showdata();
		textbackground(BLUE);
	}
	f.close();
}
//-----------------------------------------------------------------------
//		       FUNCTION TO MODIFY DATA
//-----------------------------------------------------------------------
void update()
{
	fstream f;
	customer c;
	f.open("account.dat", ios::in | ios::out | ios::binary);
	char name[20], ch;
	int found = 0;
	cout << "\n\n\t\tenter your name : ";
	gets(name);
	clrscr();
	while (f.read((char *)&c, sizeof(c)))
	{
		if (!strcmpi(name, c.getname()))
		{
			found = 1;
			c.showdata();
			cout << "\n\t\tare you sure you want to update(y/n)?";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				clrscr();
				c.getdata();
				f.seekp(f.tellg() - sizeof(c));
				f.write((char *)&c, sizeof(c));
				cout << "\n\t\tupdate succesfull\n";
			}
		}
		else
		{
			cout << "\n\t\trecord not updated\n";
		}
	}
	f.close();
	if (found == 0)
	{
		cout << "\n\t\tname " << name << " does not exist";
	}
}
//-----------------------------------------------------------------------
//			FUNCTION TO REMOVE DATA
//-----------------------------------------------------------------------
void remove()
{
	fstream f1, f2;
	customer c;
	char ch, name[20];
	int found = 0;
	f1.open("account.dat", ios::binary | ios::in);
	f2.open("temp.dat", ios::binary | ios::out);
	cout << "\n\t\tenter name : ";
	gets(name);
	clrscr();
	while (f1.read((char *)&c, sizeof(c)))
	{
		if (!strcmpi(name, c.getname()))
		{
			found = 1;
			c.showdata();
			textbackground(BLUE);
			cout << "\n\t------------------------------------------";
			cout << "\n\t\tare you sure to delete(y/n)? ";
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				cout << "\n\t\tdelete succesfull\n";
			}
			else
			{
				f2.write((char *)&c, sizeof(c));
				cout << "\n\t\trecord not deleted\n";
			}
		}
		else
		{
			f2.write((char *)&c, sizeof(c));
		}
	}
	f1.close();
	f2.close();
	remove("account.dat");
	rename("temp.dat", "account.dat");
	if (found == 0)
	{
		cout << "\n\t\tname " << name << " does not exist";
	}
}
//-----------------------------------------------------------------------
//			FUNCTION TO DISPLAY DATABASE
//-----------------------------------------------------------------------
void database()
{
	clrscr();
	fstream f;
	customer c;
	f.open("account.dat", ios::binary | ios::in);
	cout << "\n\t\t    **********************************\n";
	cout << "\n\t\t\t        DATABASE";
	cout << "\n\t\t    **********************************\n";
	cout << "\n\t----------------------------------------------------------------\n";
	cout.setf(ios::left);
	cout << "\n\t" << setw(10) << "NAME" << setw(15) << "destination" << setw(17) << "m.o.transport" << setw(12) << "d.o.dept." << setw(10) << "d.o.arr.";
	cout << "\n\t----------------------------------------------------------------\n";
	while (f.read((char *)&c, sizeof(c)))
	{
		c.show();
	}
	f.close();
	cout << "\n\t----------------------------------------------------------------\n";
}
//-----------------------------------------------------------------------
//			FUNCTION TO CALCULATE ADMIN BILL
//-----------------------------------------------------------------------
void adminmenu();
void a_bill()
{
	char name[20];
	cout << "\n\n\t\tenter customer name : ";
	gets(name);
	clrscr();
	customer c;
	long t_transport_exp, transport_tax;
	long t_hotel_exp, hotel_tax;
	long t_service_exp, service_tax;
	long hotel_commission, transport_commission, profit;
	fstream f;
	f.open("account.dat", ios::in | ios::out | ios::binary);
	{
		while (f.read((char *)&c, sizeof(c)))
		{
			if (!strcmpi(name, c.getname()))
			{
				int n = c.getnum_of_members();
				cout << "\n\t\tnumber of members travelling : " << n;
				t_transport_exp = 2 * (n * (c.get_transport_price()));
				cout << "\n\t\ttotal transport expenditure is : " << t_transport_exp;
				transport_tax = (18 * t_transport_exp) / 100;
				cout << "\n\t\ttransport tax is : " << transport_tax;
				cout << "\n\t\t-----------------------------------------\n";
				if (n % 2 == 0)
				{
					t_hotel_exp = (n * (c.get_hotel_price())) / 2;
				}
				else
				{
					t_hotel_exp = ((n + 1) * (c.get_hotel_price())) / 2;
				}
				cout << "\n\t\ttotal hotel expenditure is : " << t_hotel_exp;
				hotel_tax = (28 * t_hotel_exp) / 100;
				cout << "\n\t\thotel tax is : " << hotel_tax;
				cout << "\n\t\t-----------------------------------------\n";
				long net = t_transport_exp + transport_tax + t_hotel_exp + hotel_tax;
				t_service_exp = ((10 * net) / 100) + ((18 * net) / 100);
				textbackground(BLUE);
				cout << "\n\t\ttotal service charges : " << t_service_exp;
				net += t_service_exp;
				c.set_net_amount(net);
				cout << "\n\t\ttotal expenditure by customer is : " << c.get_net_amount();
				cout << "\n\t\t-----------------------------------------\n";
				hotel_commission = (8 * t_hotel_exp) / 100;
				transport_commission = (9 * t_transport_exp) / 100;
				cout << "\n\t\tcommission on hotel booking : " << hotel_commission;
				cout << "\n\t\tcommission on transport booking : " << transport_commission;
				cout << "\n\t\tservice charges : " << t_service_exp;
				profit = hotel_commission + transport_commission + t_service_exp;
				cout << "\n\t\ttotal profit : " << profit;
				cout << "\n\t\t-----------------------------------------";
			}
		}
	}
}
//-----------------------------------------------------------------------
//                      FUNCTION TO CALCULATE CUSTOMER BILL
//-----------------------------------------------------------------------
void customermenu();
void c_bill()
{
	char name[20];
	cout << "\n\t\tenter your name : ";
	gets(name);
	clrscr();
	customer c;
	long t_transport_exp, transport_tax;
	long t_hotel_exp, hotel_tax;
	long t_service_exp, service_tax;
	fstream f;
	f.open("account.dat", ios::in | ios::out | ios::binary);
	{
		while (f.read((char *)&c, sizeof(c)))
		{
			if (!strcmpi(name, c.getname()))
			{
				int n = c.getnum_of_members();
				cout << "\n\t\tnumber of members travelling : " << n;
				t_transport_exp = 2 * (n * (c.get_transport_price()));
				cout << "\n\t\ttotal transport expenditure is : " << t_transport_exp;
				transport_tax = (18 * t_transport_exp) / 100;
				cout << "\n\t\ttransport tax is : " << transport_tax;
				cout << "\n\t\t-----------------------------------------\n";
				if (n % 2 == 0)
				{
					t_hotel_exp = (n * (c.get_hotel_price())) / 2;
				}
				else
				{
					t_hotel_exp = ((n + 1) * (c.get_hotel_price())) / 2;
				}
				cout << "\n\t\ttotal hotel expenditure is : " << t_hotel_exp;
				hotel_tax = (28 * t_hotel_exp) / 100;
				cout << "\n\t\thotel tax is : " << hotel_tax;
				cout << "\n\t\t-----------------------------------------\n";
				long net = t_transport_exp + transport_tax + t_hotel_exp + hotel_tax;
				t_service_exp = (10 * net / 100) + (18 * net / 100);
				textbackground(BLUE);
				cout << "\n\t\ttotal service charges : " << t_service_exp;
				net += t_service_exp;
				c.set_net_amount(net);
				cout << "\n\t\ttotal expenditure is : " << c.get_net_amount();
				cout << "\n\t\t-----------------------------------------";
			}
		}
	}
}
//-----------------------------------------------------------------------
//		   FUNCTION TO ENTER CHOICE FOR ADMIN
//-----------------------------------------------------------------------
void adminmenu()
{
	int ch;
xx:
	do
	{
		clrscr();
		cout << "\n\t\tTRAVEL ADDICT TOURS AND TRAVELS";
		cout << "\n\n\t\t\t  admin menu";
		cout << "\n\t\t\t***************";
		cout << "\n\t\t\t***************";
		cout << "\n\t\t1.add details";
		cout << "\n\t\t2.search details";
		cout << "\n\t\t3.bill and profit";
		cout << "\n\t\t4.modify details";
		cout << "\n\t\t5.cancel trip";
		cout << "\n\t\t6.database";
		cout << "\n\t\t7.exit";
		cout << "\n\t-----------------------------------------\n";
		cout << "\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			add();
			break;
		case 2:
			search();
			break;
		case 3:
			a_bill();
			break;
		case 4:
			update();
			break;
		case 5:
			remove();
			break;
		case 6:
			database();
			break;
		case 7:
			exit(0);
		default:
			cout << "\n\t\twrong choice\n";
			goto xx;
		}
		getch();
	} while (ch != 7);
}

//-----------------------------------------------------------------------
//                FUNCTION TO ENTER CHOICE FOR CUSTOMER
//-----------------------------------------------------------------------
void about_us();
void customermenu()
{
z3:
	int ch;
	do
	{
		clrscr();
		cout << "\n\t\tTRAVEL ADDICT TOURS AND TRAVELS";
		cout << "\n\n\t\t\t  coustomer menu";
		cout << "\n\t\t\t******************";
		cout << "\n\t\t\t******************";
		cout << "\n\t\t1.add details";
		cout << "\n\t\t2.search details";
		cout << "\n\t\t3.payments and bill";
		cout << "\n\t\t4.modify details";
		cout << "\n\t\t5.cancel trip";
		cout << "\n\t\t6.about us";
		cout << "\n\t\t7.exit";
		cout << "\n\t-----------------------------------------\n";
		cout << "\n\t\tenter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			add();
			break;
		case 2:
			search();
			break;
		case 3:
			c_bill();
			break;
		case 4:
			update();
			break;
		case 5:
			remove();
			break;
		case 6:
			about_us();
			break;
		case 7:
			exit(0);
		default:
			cout << "\n\t\twrong choice\n";
			goto z3;
		}
		getch();
	} while (ch != 7);
}
//-----------------------------------------------------------------------
//			     FUNCTION ABOUT US
//-----------------------------------------------------------------------
void about_us()
{
	clrscr();
	char ch;
	cout << "\n\t-------------------------------------------------";
	cout << "\n\t-------------------------------------------------";
	cout << "\n\t      TRAVEL ADDICT TOURS AND TRAVELS\n";
	cout << "\n\t-------------------------------------------------";
	cout << "\n\t-------------------------------------------------";
	cout << "\n\twelcome fellow customer to the world of travelling.We";
	cout << "\n\thave sworn an oath to make your trails happy and";
	cout << "\n\tconvenient.We listen to your travelling problems and";
	cout << "\n\tsolve them as our own.Travel Addict is one the asia's";
	cout << "\n\tlargest tour and travels agency offering jobs to";
	cout << "\n\tabout 50,000 people accross the globe.It offers many";
	cout << "\n\ttours in India and the world.It's approach is widespread";
	cout << "\n\taccross the globe from USA to Japan.It has been serving";
	cout << "\n\tglobal citizens from 1998 and promises to do so in";
	cout << "\n\tupcoming years.Travel Addict was found by Sir Thomas";
	cout << "\n\tLuther on 10th August 1998 in London,England and since";
	cout << "\n\tthen the agency is achieving new hights.We thank you";
	cout << "\n\tfor choosing us as your travel patner.Welcome to the";
	cout << "\n\tTravel Addict family.";
	cout << "\n\t-------------------------------------------------";
	cout << "\n\t do you want to continue(y/n)? : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		customermenu(); //back to menu
	}
	else
	{
		exit(0);
	}
}
//-----------------------------------------------------------------------
//		FUNCTION TO OPEN PROJECT IN ADMINISTRATION MODE
//		     		OR CUSTOMER MODE
//-----------------------------------------------------------------------
void password();
void mainmenu()
{
z4:
	int ch;
	do
	{
		clrscr();
		cout << "\n\t\tTRAVEL ADDICT TOURS AND TRAVELS";
		cout << "\n\t\t\tmain menu";
		cout << "\n\t\t\t**************";
		cout << "\n\t\t\t****(made by : surbhi goel)****";
		cout << "\n\t\t\t**************";
		cout << "\n\t\t1. ADMIN";
		cout << "\n\t\t2.CUSTOMER";
		cout << "\n\t\t3.EXIT";
		cout << "\n\t------------------------------------------------";
		cout << "\n\t\tenter choice[1-3] : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			password(); //password required only to log into adminmenu and not customer menu
			adminmenu();
			break;
		case 2:
			customermenu();
			break;
		case 3:
			cout << "\n\t\tthank you for choosing us\n\texit";
			delay(500);
			exit(0);
		default:
			cout << "\n\tinvalid choice ";
			goto z4;
		}
		getch();
	} while (ch != 3);
}
//-------------------------------------------------------------------------
//			FUNCTION TO ACCEPT PASSWORD
//-------------------------------------------------------------------------
void password()
{
	char pw[50];
xy:
	cout << "\n\t\t\tENTER PASSWORD: ";
	for (int i = 0; i < 10; i++)
	{
	password:
		pw[i] = getch();
		if (i == 0 && pw[i] == 13) //enter key's ASCII value is 13
		{
			goto password;
		}
		else
		{
			if (pw[i] == 13)
				break;
			else if (pw[i] == '\b')
			{
				i--;
				cout << "\b \b"; //backSPACE
				goto password;
			}
		}
		cout << "*";
	} //end of for loop
	pw[i] = '\0';
	if (strcmp("travel", pw) == 0) //condition to check password
	{
		cout << "\n\n\t\tCORRECT PASSOWRD";
		cout << "\n\t\tlogin succesfull...";
		cout << "\n\n\n\t\tplease wait while loading the project";
		for (int k = 0; k < 6; k++)
		{
			delay(500);
			cout << ".";
		}
		clrscr();
		cout << "***************************************************";
		cout << "*****************************";
		cout << "\n";
		cout << "\n\t\t     welcome to travel addict computers\n";
		cout << "***************************************************";
		cout << "*****************************";
		cout << "\n\t\tloading the project\n";
		cout << "\t20%..\n";
		delay(500);
		cout << "\t40%..\n";
		delay(500);
		cout << "\t60%..\n";
		delay(500);
		cout << "\t80%..\n";
		delay(500);
		cout << "\t100% completed...\n";
		delay(500);
		adminmenu();
	}
	else
	{
		cout << "\n\t\t\tWRONG PASSWORD! ACCESS DENIED!!!";
		goto xy;
	}
}
//-----------------------------------------------------------------------
//				MAIN FUNCTION
//-----------------------------------------------------------------------
void main()
{
	clrscr();
	textcolor(WHITE);	  //to put text colour
	textbackground(BLUE); //to impart background colour
	mainmenu();			  //function call
	getch();
}