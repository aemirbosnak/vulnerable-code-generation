//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct {
    int room_no;
    char type[20];
    int price;
    int status;
} Room;

typedef struct {
    char name[50];
    char address[100];
    int phone;
} Customer;

void main() {
    int choice, i, j, k, n;
    char ch;
    Room hotel[MAX];
    Customer customer[MAX];

    printf("\n\n\t\t\tWELCOME TO HOTEL MANAGEMENT SYSTEM\n");
    printf("\n\nEnter 1 to book a room\n");
    printf("Enter 2 to check room status\n");
    printf("Enter 3 to check customer details\n");
    printf("Enter 4 to check vacant rooms\n");
    printf("Enter 5 to exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter your name: ");
                scanf("%s", &customer[n].name);

                printf("Enter your address: ");
                scanf("%s", &customer[n].address);

                printf("Enter your phone number: ");
                scanf("%d", &customer[n].phone);

                printf("\nEnter room type (Single/Double/Suite): ");
                scanf("%s", &hotel[n].type);

                printf("Enter room number: ");
                scanf("%d", &hotel[n].room_no);

                printf("Enter room price: ");
                scanf("%d", &hotel[n].price);

                hotel[n].status = 1;
                n++;
                break;

            case 2:
                printf("\nEnter room number: ");
                scanf("%d", &k);

                for(i=0; i<n; i++) {
                    if(hotel[i].room_no == k) {
                        printf("\nRoom number %d is %s", k, hotel[i].status == 1? "booked" : "available");
                        break;
                    }
                }

                break;

            case 3:
                printf("\nEnter customer name: ");
                scanf("%s", &ch);

                for(i=0; i<n; i++) {
                    if(strcmp(customer[i].name, ch) == 0) {
                        printf("\nName: %s", customer[i].name);
                        printf("\nAddress: %s", customer[i].address);
                        printf("\nPhone number: %d", customer[i].phone);
                        break;
                    }
                }

                break;

            case 4:
                printf("\nVacant rooms:\n");

                for(i=0; i<n; i++) {
                    if(hotel[i].status == 0) {
                        printf("\nRoom number %d is available", hotel[i].room_no);
                    }
                }

                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    } while(1);
}