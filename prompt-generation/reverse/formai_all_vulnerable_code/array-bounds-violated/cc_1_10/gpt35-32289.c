//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the hotel guest record
struct hotelGuest {
    int roomNumber;
    char firstName[20];
    char lastName[20];
    int daysStayed;
};

// Global array to hold all hotel guest records
struct hotelGuest guests[100];

// Function to add a new guest record
void addGuest() {
    int roomNum;
    char fName[20], lName[20];
    int days;

    printf("Enter guest room number: ");
    scanf("%d", &roomNum);

    printf("Enter guest first name: ");
    scanf("%s", fName);

    printf("Enter guest last name: ");
    scanf("%s", lName);

    printf("Enter number of days stayed: ");
    scanf("%d", &days);

    guests[roomNum].roomNumber = roomNum;
    strcpy(guests[roomNum].firstName, fName);
    strcpy(guests[roomNum].lastName, lName);
    guests[roomNum].daysStayed = days;

    printf("Guest record added successfully.\n");
}

// Function to update an existing guest record
void updateGuest() {
    int roomNum;

    printf("Enter guest room number to update: ");
    scanf("%d", &roomNum);

    if(guests[roomNum].roomNumber == 0) {
        printf("Guest with room number %d not found.\n", roomNum);
        return;
    }

    printf("Enter new guest first name: ");
    scanf("%s", guests[roomNum].firstName);

    printf("Enter new guest last name: ");
    scanf("%s", guests[roomNum].lastName);

    printf("Enter new number of days stayed: ");
    scanf("%d", &guests[roomNum].daysStayed);

    printf("Guest record updated successfully.\n");
}

// Function to display a guest record
void displayGuest(int roomNum) {
    printf("\nRoom Number: %d\n", guests[roomNum].roomNumber);
    printf("Guest Name: %s %s\n", guests[roomNum].firstName, guests[roomNum].lastName);
    printf("Days Stayed: %d\n", guests[roomNum].daysStayed);
}

// Function to display all guest records
void displayAllGuests() {
    for(int i=0; i<100; i++) {
        if(guests[i].roomNumber != 0) {
            displayGuest(i);
        }
    }
}

// Main function to run the hotel management system
int main() {
    int menuChoice;

    while(1) {
        printf("\nHotel Management System\n");
        printf("=======================\n");
        printf("1. Add Guest\n");
        printf("2. Update Guest\n");
        printf("3. Display Guest\n");
        printf("4. Display All Guests\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &menuChoice);

        switch(menuChoice) {
            case 1:
                addGuest();
                break;

            case 2:
                updateGuest();
                break;

            case 3:
                {
                    int roomNum;
                    printf("Enter guest room number to display: ");
                    scanf("%d", &roomNum);
                    displayGuest(roomNum);
                }
                break;

            case 4:
                displayAllGuests();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}