//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000

typedef struct {
    int roomNumber;
    char guestName[50];
    int numOfGuests;
    int numOfNights;
    double totalCost;
} Guest;

Guest guests[MAX_GUESTS];

int numOfGuests = 0;

void addGuest() {
    printf("Enter guest name: ");
    scanf("%s", guests[numOfGuests].guestName);
    printf("Enter number of guests: ");
    scanf("%d", &guests[numOfGuests].numOfGuests);
    printf("Enter number of nights: ");
    scanf("%d", &guests[numOfGuests].numOfNights);
    guests[numOfGuests].totalCost = guests[numOfGuests].numOfGuests * guests[numOfGuests].numOfNights * 100;
    numOfGuests++;
}

void displayGuests() {
    printf("\nGuest Details:\n");
    for (int i = 0; i < numOfGuests; i++) {
        printf("Guest Name: %s\n", guests[i].guestName);
        printf("Number of Guests: %d\n", guests[i].numOfGuests);
        printf("Number of Nights: %d\n", guests[i].numOfNights);
        printf("Total Cost: $%.2f\n\n", guests[i].totalCost);
    }
}

int main() {
    int choice;

    do {
        printf("\nHotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. Display Guest Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addGuest();
            break;
        case 2:
            displayGuests();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}