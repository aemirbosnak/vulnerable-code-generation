//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void addGuest();
void displayGuests();
void searchGuest();
void modifyGuest();
void deleteGuest();

// Struct for storing Guest info
struct guestData {
    char name[50];
    int roomNum;
    int nights;
    int balance;
};

// Global variable for storing guests
struct guestData guests[100];
int numGuests = 0;

int main() {
    int choice;
    do {
        // Display main menu and prompt for input
        printf("Welcome to the C Hotel Management System!\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Search Guest\n");
        printf("4. Modify Guest\n");
        printf("5. Delete Guest\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        // Process selected option
        switch(choice) {
            case 1:
                addGuest();
                break;
            case 2:
                displayGuests();
                break;
            case 3:
                searchGuest();
                break;
            case 4:
                modifyGuest();
                break;
            case 5:
                deleteGuest();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}

void addGuest() {
    struct guestData guest;

    // Prompt user for guest info
    printf("Enter guest name: ");
    scanf("%s", guest.name);
    printf("Enter room number: ");
    scanf("%d", &guest.roomNum);
    printf("Enter number of nights: ");
    scanf("%d", &guest.nights);
    printf("Enter balance: ");
    scanf("%d", &guest.balance);

    // Add guest to guests array
    guests[numGuests] = guest;
    numGuests++;

    printf("Guest added successfully.\n");
}

void displayGuests() {
    if(numGuests == 0) {
        printf("No guests to display.\n");
    } else {
        printf("Name\tRoom\tNights\tBalance\n");
        for(int i = 0; i < numGuests; i++) {
            printf("%s\t%d\t%d\t%d\n", guests[i].name, guests[i].roomNum, guests[i].nights, guests[i].balance);
        }
    }
}

void searchGuest() {
    char name[50];
    printf("Enter guest name to search: ");
    scanf("%s", name);

    int found = 0;
    for(int i = 0; i < numGuests; i++) {
        if(strcmp(name, guests[i].name) == 0) {
            printf("Name\tRoom\tNights\tBalance\n");
            printf("%s\t%d\t%d\t%d\n", guests[i].name, guests[i].roomNum, guests[i].nights, guests[i].balance);
            found = 1;
        }
    }

    if(!found) {
        printf("Guest not found.\n");
    }
}

void modifyGuest() {
    char name[50];
    printf("Enter guest name to modify: ");
    scanf("%s", name);

    int found = 0;
    for(int i = 0; i < numGuests; i++) {
        if(strcmp(name, guests[i].name) == 0) {
            printf("Name\tRoom\tNights\tBalance\n");
            printf("%s\t%d\t%d\t%d\n", guests[i].name, guests[i].roomNum, guests[i].nights, guests[i].balance);
            printf("Enter new room number: ");
            scanf("%d", &guests[i].roomNum);
            printf("Enter new number of nights: ");
            scanf("%d", &guests[i].nights);
            printf("Enter new balance: ");
            scanf("%d", &guests[i].balance);
            found = 1;
        }
    }

    if(!found) {
        printf("Guest not found.\n");
    } else {
        printf("Guest modified successfully.\n");
    }
}

void deleteGuest() {
    char name[50];
    printf("Enter guest name to delete: ");
    scanf("%s", name);

    int found = 0;
    for(int i = 0; i < numGuests; i++) {
        if(strcmp(name, guests[i].name) == 0) {
            found = 1;
            for(int j = i; j < numGuests - 1; j++) {
                guests[j] = guests[j + 1];
            }
            numGuests--;
        }
    }

    if(!found) {
        printf("Guest not found.\n");
    } else {
        printf("Guest deleted successfully.\n");
    }
}