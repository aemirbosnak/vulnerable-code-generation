//FormAI DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice;
    int roomNumber;
    char guestName[30];
    char checkInDate[20];
    char checkOutDate[20];
    float roomRate;
    float totalCharge;

    do {
        printf("Welcome to the C Hotel Management System!\n\n");
        printf("Choose from the following options:\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. View guest list\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the guest name: ");
                scanf("%s", guestName);
                printf("\nEnter the room number: ");
                scanf("%d", &roomNumber);
                printf("\nEnter the check in date: ");
                scanf("%s", checkInDate);
                printf("\nEnter the check out date: ");
                scanf("%s", checkOutDate);
                printf("\nEnter the room rate: ");
                scanf("%f", &roomRate);

                totalCharge = roomRate * 2;
                printf("\n%s has been checked in to room %d from %s to %s. The total charge is %.2f.\n\n", guestName, roomNumber, checkInDate, checkOutDate, totalCharge);
                break;

            case 2:
                printf("\nEnter the guest name: ");
                scanf("%s", guestName);
                printf("\n%s has been checked out. Thank you for staying with us!\n\n", guestName);
                break;

            case 3:
                printf("\nGuest List:\n\n");
                printf("Guest Name\tRoom Number\tCheck In Date\tCheck Out Date\tTotal Charge\n");
                printf("-------------------------------------------------------------------------------------------------------\n");
                printf("%s\t\t%d\t\t%s\t%s\t\t%.2f", guestName, roomNumber, checkInDate, checkOutDate, totalCharge);
                printf("\n\n");
                break;

            case 4:
                printf("\nThank you for using the C Hotel Management System!\n\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }

    } while(choice != 4);

    return 0;
}