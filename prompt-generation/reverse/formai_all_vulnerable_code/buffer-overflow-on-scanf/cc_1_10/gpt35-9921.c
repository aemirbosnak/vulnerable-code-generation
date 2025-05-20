//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold guest information
typedef struct {
    char name[50];
    int roomNumber;
    int daysStayed;
    float billTotal;
} Guest;

// Function to clear the input buffer
void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to add a new guest to the management system
void addGuest(Guest *guestList, int *guestCount) {
    printf("\nAdding New Guest...\n");

    // Get guest details from user input
    printf("Enter guest name: ");
    fgets(guestList[*guestCount].name, sizeof(guestList[*guestCount].name), stdin);
    printf("Enter room number: ");
    scanf("%d", &guestList[*guestCount].roomNumber);
    clearInputBuffer();
    printf("Enter number of days stayed: ");
    scanf("%d", &guestList[*guestCount].daysStayed);
    clearInputBuffer();

    // Calculate total bill for guest stay
    guestList[*guestCount].billTotal = guestList[*guestCount].daysStayed * 120.50;

    // Increment guest count
    *guestCount += 1;

    printf("Guest added successfully!\n\n");
}

// Function to display all guests in the management system
void displayGuests(Guest *guestList, int guestCount) {
    printf("\nGuest List: \n");

    // Loop through each guest in the list and print their details
    for (int i=0; i<guestCount; i++) {
        printf("Name: %s", guestList[i].name);
        printf("Room Number: %d\n", guestList[i].roomNumber);
        printf("Days stayed: %d\n", guestList[i].daysStayed);
        printf("Total bill: $%.2f\n", guestList[i].billTotal);
        printf("\n");
    }
}

// Main Function
int main() {
    const int MAX_GUESTS = 100;
    Guest guestList[MAX_GUESTS];
    int guestCount = 0;
    int menuChoice = 0;

    printf("Welcome to the C Hotel Management System!\n\n");

    do {
        // Display Menu
        printf("Choose an option: \n");
        printf("1. Add Guest\n");
        printf("2. Display All Guests\n");
        printf("3. Exit\n");

        // Get user menu choice
        scanf("%d", &menuChoice);
        clearInputBuffer();

        switch (menuChoice) {
            case 1:
                addGuest(guestList, &guestCount);
                break;
            case 2:
                displayGuests(guestList, guestCount);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    } while (menuChoice != 3);

    return 0;
}