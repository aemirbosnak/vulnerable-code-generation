//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000

typedef struct {
    int roomNumber;
    char guestName[50];
    int numOfGuests;
    int numOfDays;
    float totalCost;
} Guest;

Guest guests[MAX_GUESTS];

int numOfGuests = 0;

void addGuest() {
    printf("Enter room number: ");
    scanf("%d", &guests[numOfGuests].roomNumber);

    printf("Enter guest name: ");
    scanf("%s", guests[numOfGuests].guestName);

    printf("Enter number of guests: ");
    scanf("%d", &guests[numOfGuests].numOfGuests);

    printf("Enter number of days: ");
    scanf("%d", &guests[numOfGuests].numOfDays);

    guests[numOfGuests].totalCost = (guests[numOfGuests].numOfGuests * guests[numOfGuests].numOfDays) * 50;

    numOfGuests++;
}

void displayGuests() {
    printf("\n");
    printf("ROOM\tGUEST NAME\tNUMBER OF GUESTS\tNUMBER OF DAYS\tTOTAL COST\n");

    for(int i=0; i<numOfGuests; i++) {
        printf("%d\t%s\t%d\t%d\t%.2f\n", guests[i].roomNumber, guests[i].guestName, guests[i].numOfGuests, guests[i].numOfDays, guests[i].totalCost);
    }
}

int main() {
    int choice;

    do {
        printf("\n");
        printf("HOTEL MANAGEMENT SYSTEM\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addGuest();
                break;

            case 2:
                displayGuests();
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}