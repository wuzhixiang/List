#include "all.h"
#include <iostream>
#include <string>
using namespace std;

static bool comp( int& i1, int& i2 )
{
	return i1<i2;
}

class Stu
{
public:
	Stu( int i=0,string n="" )
	{
		id=i;
		name=n; 
	}
	~Stu() {}
	int id;
	string name;
	static bool comp( Stu& s1,Stu& s2 )
	{
		return s1.id<s2.id; 
	}
};

ostream &operator<<( ostream &output, const Stu& my )
{
	output<<"ID:"<<my.id<<"     "<<"Name:"<<my.name<<endl;
	return output;
}

void main()
{
	List<Stu> cose092;
	cose092.insertAtBack(Stu(201, "wang"));
	cose092.insertAtFront(Stu(203, "hang"));
	cose092[6]=Stu(202, "zhang");
	cose092.insertAt(Stu(404, "li"), 1);
	cose092.output();
	cout<<endl;

	List<Stu> cose094;
	cose094.insertAtFront(Stu(401,"fang"));
	cose094[cose094.getsize()]=Stu(403,"liu");
	cose094.insertAtFront(Stu(402,"wu"));
	cose094.output();
	cout<<endl;

	List<Stu> cose09(cose092);
	cose09.appendAt( cose094,1 );
	cose09.output();
	cout<<endl;

	cose09.sort( Stu::comp );
	cose09.output();
	cout<<endl;

	cose09.listRotate();
	cose09.swap(2, 4);
	cose09.output();
	cout<<endl;

	cose09.removeFrom( 3 );
	cose09.removeFromFront();
	cose09.output();
	cout<<endl;

	cose09=cose094;
	cose09.output();
	cout<<endl;

	int x=3;
	List<int> int1;
	int1.insertAtFront( ++x );
	int1.insertAt( --x, 0 );
	Listiter<int>* port=int1.listGetIterator();
	port->listIndex( &int1, 0 );
	cout<<(*static_cast<int*>( port->ptr->pdata ));
	cout<<endl;

	List<int> int2,int3;
	int2=int1;
	int3=int1;
	int2.insertAtFront( ++x );
	int3.insertAtBack( --x );
	int1.appendAtBack( int2 );
	int1.appendAtFront( int3 );
	int1.output();
	cout<<endl;

	int1.sort( comp );
	int1.output();
	cout<<endl;
}
