
#include <iostream>
#include <conio.h>

using namespace std;

class giatUi { 
	private: 
		float kg; 
		float price; 
		float congThem ; 
	public: 
		giatUi() {
			kg = price = congThem = 0;
		}
		~giatUi() {
			kg = price = congThem = 0;
		}
			
		void nhap() {
			cout << "hay nhap so kg can giat: "<< endl;
			cin >> kg;
			cout << "gia cua 1 kg la: "<< endl;
			cin >> price ;
			cout << "chi phi cong them moi kg la: "<< endl;
			cin >> congThem;	
		}
		float tinhTien() {
			float tien;
				tien = kg * price;
			if(kg!= 0)	{
				tien = kg * price + congThem;
			}
			if(kg > 10) return(tien * 0.95);
			else  return tien ;
		}
		
		float getkg() {
			return kg;
		}
};

class thueXe {
	private: 
		float hours; 
		float price; 
	public:
		thueXe() {
			hours = price = 0;
		}
		~thueXe() {
			hours = price = 0;
		}
		
		void nhap() {
			cout << "nhap so gio ban muon thue xe :"<< endl;
			cin >> hours;
			cout << "gia thue xe moi gio: "<< endl;
			cin >> price;
		}
		
		float tinhTien() {
			float tien;
			
				tien = hours * price;
				if(hours >= 10) return ( tien*0.9);
				else return tien ;
		}
		
		float gethours() {
			return hours;
		}
};

class dichVu {
	private:
    	giatUi giatUi_;
    	thueXe thueXe_;
	public:
    	dichVu():giatUi_(),thueXe_(){}
   		~dichVu() {}
   		
    	void nhap() {
        	char s1,s2;
        	puts("ban co giat khong (y/n)??");
        	do{
            	s1=getch();
        	}while(s1!='y'&& s1!='Y'&& s1!='n'&& s1!='N');
        
        	if(s1=='Y'||s1=='y') giatUi_.giatUi::nhap();
        	else giatUi_ =giatUi();
        
        	puts("ban co thue xe khong (y/n)??");
        	do{
            	s2=getch();
        	}while(s2!='y'&& s2!='Y'&& s2!='n'&& s2!='N');
        
        	if(s2=='Y'||s2=='y') thueXe_.thueXe::nhap();
        	else thueXe_ = thueXe();
   	 		}
   	 	
    	float tinhTien() {
        	return (giatUi_.giatUi::tinhTien() + thueXe_.thueXe::tinhTien() );
    	}
    	
    	void nhaplai() {
    		char nl;
        	puts("ban co muon nhap lai thong tin khong (y/n)??");
        	do{
            	nl=getch();
        	}while(nl!='y'&& nl!='Y'&& nl!='n'&& nl!='N');
        	if(nl=='Y'||nl=='y')
			{
				giatUi_.giatUi::nhap();
				thueXe_.thueXe::nhap();
			 }        	
        	
		}
    	 
    	
    	void in() {
        	if(giatUi_.giatUi::getkg()>=10)
	            cout<<"chi phi giat ui la:\t"<<giatUi_.giatUi::tinhTien()<<"\tduoc giam gia 5%"<<endl;
	        else
            	cout<<"chi phi giat ui la:\t"<<giatUi_.giatUi::tinhTien()<<endl;
        	if(thueXe_.thueXe::gethours()>7)
            	cout<<"chi phi thue xe la:\t"<<thueXe_.thueXe::tinhTien()<<"\tduoc giam gia 10%"<<endl;
        	else
            	cout<<"chi phi thue xe la:\t"<<thueXe_.thueXe::tinhTien()<<endl;
            
        	cout<<"tong chi phi la:\t"<<dichVu::tinhTien()<<endl;
    }

};



class khachHang {
	private:
		char codekh[10], namekh[20];
		int n;
		float tong;
		dichVu hoadon[20];
	public:
		khachHang() {
			codekh[0] = '\0';
			namekh[0] = '\0';
			n = 0;
			tong = 0;
			
		}
		~khachHang() {
			if (codekh != NULL) delete codekh;
			if(namekh != NULL) delete namekh;
			
			if (n != 0) n = 0;
			if (tong != 0 ) tong = 0;
			
		}
		void nhap() {
			tong = 0;
			cin.ignore(1);
			cout<< " hay nhap ma khach hang: "<< endl;
			cin.getline(codekh,10);
			cout << "hay nhap ten khach hang: "<< endl;
			cin.getline(namekh,20);
			cout<<"nhap so lan su dung dich vu: "<< endl;
			cin>> n;
			for(int i=0; i<n; i++) {
					cout<<"dich vu lan "<<i+1<<endl;
            		hoadon[i].dichVu::nhap();
				}
		}
		void nhaplai() {
			for(int i=0; i<n; i++){
            		hoadon[i].dichVu::nhaplai();
				}
		}
		
		
		void in() {
        	for(int i=0;i<n;i++){
            	tong +=hoadon[i].dichVu::tinhTien();
            	cout<<"chi phi lan su dung dich vu thu "<<i+1<<endl;
            	hoadon[i].dichVu::in();
        	}
        cout<<"tong chi phi khach phai tra la   "<<tong <<endl;
    	}
    	
    	float gettong() {
        	return tong;
    	}
};


int main() {
	khachHang a[10];
    int i, n;
    float sum=0;
    cout<<"nhap so luong khach hang"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"khach hang thu "<<i+1<<endl;
        a[i].khachHang::nhap();
        a[i].khachHang::nhaplai();
        a[i].khachHang::in();
        sum+=a[i].khachHang::gettong();
        cout<<("\n");
    }
    cout<<"\n\ntong tien khach san thu duoc la "<<sum<<endl;
    getch();
 
    return 0;
}
