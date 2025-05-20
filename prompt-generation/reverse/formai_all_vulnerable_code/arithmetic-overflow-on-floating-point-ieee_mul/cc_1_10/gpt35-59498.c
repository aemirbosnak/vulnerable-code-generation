//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GUEST_LIMIT 100

// Structure for storing guest information
typedef struct guest {
    int roomNumber;
    char name[50];
    char checkInDate[20];
    char checkOutDate[20];
    int numNights;
    float roomRate;
    float totalBill;
} Guest;

Guest guests[GUEST_LIMIT];
int numGuests = 0;

// Function for adding a guest to the system
void addGuest() {
    if (numGuests < GUEST_LIMIT) {
        Guest newGuest;

        printf("Enter room number: ");
        scanf("%d", &newGuest.roomNumber);
        printf("Enter guest name: ");
        scanf("%s", newGuest.name);
        printf("Enter check-in date (MM/DD/YYYY): ");
        scanf("%s", newGuest.checkInDate);
        printf("Enter check-out date (MM/DD/YYYY): ");
        scanf("%s", newGuest.checkOutDate);
        printf("Enter number of nights: ");
        scanf("%d", &newGuest.numNights);
        printf("Enter room rate: ");
        scanf("%f", &newGuest.roomRate);

        // Calculate the total bill
        newGuest.totalBill = newGuest.numNights * newGuest.roomRate;

        // Add the guest to the array and increment the guest count
        guests[numGuests++] = newGuest;

        printf("Guest added successfully.\n");
    } else {
        printf("Error: Guest limit reached.\n");
    }
}

// Function for printing out a guest's bill
void printBill(int guestIndex) {
    printf("\nRoom Number: %d\n", guests[guestIndex].roomNumber);
    printf("Guest Name: %s\n", guests[guestIndex].name);
    printf("Check-In Date: %s\n", guests[guestIndex].checkInDate);
    printf("Check-Out Date: %s\n", guests[guestIndex].checkOutDate);
    printf("Number of Nights: %d\n", guests[guestIndex].numNights);
    printf("Room Rate: $%.2f\n", guests[guestIndex].roomRate);
    printf("Total Bill: $%.2f\n", guests[guestIndex].totalBill);
}

// Function for finding a guest by room number
int findGuestByRoomNumber(int roomNumber) {
    for (int i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            return i;
        }
    }

    return -1;
}

// Main function
int main() {
    int choice;

    while (1) {
        // Print out the menu options
        printf("\nWelcome to the Hotel Management System. Please choose an option:\n");
        printf("1. Add guest\n");
        printf("2. Print guest bill\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2: {
                int roomNumber;
                printf("Enter room number: ");
                scanf("%d", &roomNumber);

                int guestIndex = findGuestByRoomNumber(roomNumber);
                if (guestIndex != -1) {
                    printBill(guestIndex);
                } else {
                    printf("Error: Room not found.\n");
                }

                break;
            }
            case 3:
                printf("Exiting Hotel Management System. Thank you for using!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}