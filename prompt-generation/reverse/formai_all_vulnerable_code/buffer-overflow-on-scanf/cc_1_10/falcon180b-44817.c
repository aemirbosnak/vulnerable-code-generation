//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct customer{
    char name[50];
    int age;
    char gender[10];
    char address[100];
    int phone;
};

struct room{
    int room_no;
    int room_type;
    int room_status;
    int room_price;
};

void main(){
    int choice;
    char ch;
    struct customer c;
    struct room r[10];
    int i,j;
    do{
        printf("\n\n ***WELCOME TO HOTEL MANAGEMENT SYSTEM***\n");
        printf("\n1.Customer Registration\n2.Room Booking\n3.Room Status\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter Customer details\n");
                printf("Name:");
                scanf("%s",c.name);
                printf("Age:");
                scanf("%d",&c.age);
                printf("Gender:");
                scanf("%s",c.gender);
                printf("Address:");
                scanf("%s",c.address);
                printf("Phone No.:");
                scanf("%d",&c.phone);
                break;
            case 2:
                printf("\nEnter Room details\n");
                printf("Room No.:");
                scanf("%d",&r[0].room_no);
                printf("Room Type:");
                scanf("%d",&r[0].room_type);
                printf("Room Status:");
                scanf("%d",&r[0].room_status);
                printf("Room Price:");
                scanf("%d",&r[0].room_price);
                break;
            case 3:
                printf("\nRoom Status\n");
                printf("Room No.  Status\n");
                for(i=0;i<10;i++){
                    if(r[i].room_status==1){
                        printf("%d   Available\n",r[i].room_no);
                    }
                    else{
                        printf("%d   Booked\n",r[i].room_no);
                    }
                }
                break;
            case 4:
                printf("\nThank you for using our service");
                break;
            default:
                printf("\nInvalid choice");
        }
        printf("\nDo you want to continue(y/n):");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
}