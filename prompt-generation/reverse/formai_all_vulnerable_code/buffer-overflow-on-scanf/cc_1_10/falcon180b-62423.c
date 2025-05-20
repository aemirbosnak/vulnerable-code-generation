//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct room{
    int room_number;
    char type[20];
    int price;
    int status;
};

struct customer{
    char name[50];
    int age;
    char gender[10];
    char address[100];
    int phone_number;
};

void add_room(struct room *room,int count){
    printf("Enter room number: ");
    scanf("%d",&room[count].room_number);
    printf("Enter room type: ");
    scanf("%s",room[count].type);
    printf("Enter room price: ");
    scanf("%d",&room[count].price);
    printf("Enter room status (0 for vacant, 1 for occupied): ");
    scanf("%d",&room[count].status);
}

void display_room(struct room room,int count){
    printf("\nRoom Number: %d",room.room_number);
    printf("\nRoom Type: %s",room.type);
    printf("\nRoom Price: %d",room.price);
    printf("\nRoom Status: %d",room.status);
    printf("\n");
}

void add_customer(struct customer *customer,int count){
    printf("Enter customer name: ");
    scanf("%s",customer[count].name);
    printf("Enter customer age: ");
    scanf("%d",&customer[count].age);
    printf("Enter customer gender: ");
    scanf("%s",customer[count].gender);
    printf("Enter customer address: ");
    scanf("%s",customer[count].address);
    printf("Enter customer phone number: ");
    scanf("%d",&customer[count].phone_number);
}

void display_customer(struct customer customer,int count){
    printf("\nCustomer Name: %s",customer.name);
    printf("\nCustomer Age: %d",customer.age);
    printf("\nCustomer Gender: %s",customer.gender);
    printf("\nCustomer Address: %s",customer.address);
    printf("\nCustomer Phone Number: %d",customer.phone_number);
    printf("\n");
}

void main(){
    struct room room[MAX];
    int count=0;
    while(count<MAX){
        add_room(room,count);
        count++;
    }
    int choice;
    while(1){
        printf("\n1.Add Room\n2.Display Room\n3.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(count<MAX){
                    add_room(room,count);
                    count++;
                }
                else{
                    printf("\nMaximum number of rooms reached!");
                }
                break;
            case 2:
                printf("\nRoom Details:\n");
                for(int i=0;i<count;i++){
                    display_room(room[i],i);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
}