//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of strings
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_ROOM_NUMBER_LENGTH 20

// Define structure for guest details
struct Guest {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char room_number[MAX_ROOM_NUMBER_LENGTH];
};

// Define function to display main menu
void displayMainMenu();

// Define function to add guest details
void addGuestDetails();

// Define function to display guest details
void displayGuestDetails();

// Define function to search for guest details
void searchGuestDetails();

// Define global variable for storing guest details
struct Guest guests[10];

// Define global variable for keeping track of number of guests
int numGuests = 0;

int main() {
    int choice;

    // Loop to display menu and handle user input
    while (1) {
        displayMainMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuestDetails();
                break;
            case 2:
                displayGuestDetails();
                break;
            case 3:
                searchGuestDetails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void displayMainMenu() {
    printf("\nHotel Management System\n");
    printf("-----------------------\n");
    printf("1. Add Guest Details\n");
    printf("2. Display Guest Details\n");
    printf("3. Search for Guest Details\n");
    printf("4. Exit\n");
}

void addGuestDetails() {
    // Temporary variables for storing user input
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char room_number[MAX_ROOM_NUMBER_LENGTH];

    // Get user input for guest details
    printf("\nEnter Guest Name: ");
    scanf("%s", name);

    printf("Enter Guest Address: ");
    scanf("%s", address);

    printf("Enter Guest Room Number: ");
    scanf("%s", room_number);

    // Add guest details to global array
    strcpy(guests[numGuests].name, name);
    strcpy(guests[numGuests].address, address);
    strcpy(guests[numGuests].room_number, room_number);

    printf("\nGuest Details Added Successfully!\n");

    // Increment number of guests
    numGuests++;
}

void displayGuestDetails() {
    int i;

    if (numGuests == 0) {
        printf("\nNo Guest Details Found!\n");
    } else {
        printf("\nGuest Details\n");
        printf("-------------\n");

        for (i = 0; i < numGuests; i++) {
            printf("Guest Name: %s\n", guests[i].name);
            printf("Guest Address: %s\n", guests[i].address);
            printf("Guest Room Number: %s\n", guests[i].room_number);
        }
    }
}

void searchGuestDetails() {
    int i;
    char search_query[MAX_NAME_LENGTH];
    int guest_found = 0;

    printf("\nEnter Guest Name to Search: ");
    scanf("%s", search_query);

    for (i = 0; i < numGuests; i++) {
        if (strcmp(guests[i].name, search_query) == 0) {
            printf("\nGuest Details Found!\n");
            printf("Guest Name: %s\n", guests[i].name);
            printf("Guest Address: %s\n", guests[i].address);
            printf("Guest Room Number: %s\n", guests[i].room_number);
            guest_found = 1;
            break;
        }
    }

    if (!guest_found) {
        printf("\nGuest Details Not Found!\n");
    }
}