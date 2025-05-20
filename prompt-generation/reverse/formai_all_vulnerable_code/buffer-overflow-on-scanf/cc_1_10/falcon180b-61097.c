//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct customer{
    char name[50];
    char address[100];
    int phone_no;
    char email[50];
}customer;

typedef struct room{
    int room_no;
    char type[20];
    float rent;
    int status;
}room;

typedef struct booking{
    char cust_name[50];
    char room_type[20];
    int from_date,to_date;
    float amount;
}booking;

void main(){
    int choice;
    customer cus;
    room r;
    booking b;
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("customer.txt","ab");
    fp2=fopen("room.txt","ab");
    fp3=fopen("booking.txt","ab");
    while(1){
        printf("\n\nHOTEL MANAGEMENT SYSTEM\n");
        printf("1.Customer Registration\n");
        printf("2.Room Booking\n");
        printf("3.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter Customer Details:\n");
                printf("Name:");
                scanf("%[^\n]",cus.name);
                printf("Address:");
                scanf("%[^\n]",cus.address);
                printf("Phone No:");
                scanf("%d",&cus.phone_no);
                printf("Email:");
                scanf("%[^\n]",cus.email);
                fprintf(fp1,"%s %s %d %s\n",cus.name,cus.address,cus.phone_no,cus.email);
                printf("\nRegistration Successful!\n");
                break;
            case 2:
                printf("\nEnter Room Details:\n");
                printf("Room No:");
                scanf("%d",&r.room_no);
                printf("Room Type:");
                scanf("%[^\n]",r.type);
                printf("Rent:");
                scanf("%f",&r.rent);
                printf("Status:");
                scanf("%d",&r.status);
                fprintf(fp2,"%d %s %.2f %d\n",r.room_no,r.type,r.rent,r.status);
                printf("\nBooking Successful!\n");
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    }
}