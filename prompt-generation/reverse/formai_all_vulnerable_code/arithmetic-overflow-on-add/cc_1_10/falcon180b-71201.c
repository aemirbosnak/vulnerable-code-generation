//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct room {
    int room_no;
    char type[20];
    int price;
    int status;
};

struct guest {
    char name[30];
    char address[50];
    int phone_no;
    int days_stay;
    int room_no;
};

void main() {
    int choice, i, j;
    char ch;
    struct room hotel[MAX];
    struct guest guest[MAX];

    printf("\n\n\t\t\t\tWELCOME TO HOTEL MANAGEMENT SYSTEM\n");
    printf("\n\n\t\t\t\tMENU\n");
    printf("\n1. Room Booking\n2. Guest Details\n3. Room Status\n4. Exit\n");

    do {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n\nEnter number of rooms to book: ");
            scanf("%d", &i);

            for (j = 0; j < i; j++) {
                printf("\n\nEnter room type (single/double/suite): ");
                scanf("%s", hotel[j].type);

                printf("\nEnter room price: ");
                scanf("%d", &hotel[j].price);

                printf("\nEnter room status (available/booked): ");
                scanf("%d", &hotel[j].status);
            }

            printf("\n\nRooms booked successfully!");
            break;

        case 2:
            printf("\n\nEnter guest name: ");
            scanf("%s", guest[0].name);

            printf("\nEnter guest address: ");
            scanf("%s", guest[0].address);

            printf("\nEnter guest phone number: ");
            scanf("%d", &guest[0].phone_no);

            printf("\nEnter number of days to stay: ");
            scanf("%d", &guest[0].days_stay);

            printf("\n\nGuest details saved successfully!");
            break;

        case 3:
            printf("\n\nEnter room number to check status: ");
            scanf("%d", &j);

            if (hotel[j].status == 0) {
                printf("\n\nRoom %d is available", j + 1);
            } else {
                printf("\n\nRoom %d is booked", j + 1);
            }

            break;

        case 4:
            printf("\n\nThank you for using Hotel Management System");
            exit(0);

        default:
            printf("\n\nInvalid choice! Please try again.");
        }

        printf("\n\nDo you want to continue? (y/n) ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
}