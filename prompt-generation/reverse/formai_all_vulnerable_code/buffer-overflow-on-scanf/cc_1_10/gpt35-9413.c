//FormAI DATASET v1.0 Category: Hotel Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Global Variables
int numRooms = 10;
int numGuests = 0;
int maxGuests = 20;

//Structures
struct guest {
    char name[50];
    int roomNum;
    bool checkedIn;
};

//Function Prototypes
void printMenu();
void addGuest(struct guest* guests);
void deleteGuest(struct guest* guests);
void viewGuests(struct guest* guests);
void checkIn(struct guest* guests);
void checkOut(struct guest* guests);

//Main Function
int main() {
    struct guest guests[maxGuests];
    int choice;

    //Print Intro
    printf("\n------Welcome to the Apocalypse Hotel Management System------\n\n");
    printf("The world has come to an end, and this hotel is the last hope for the survivors. \nAs the manager, it is your job to ensure the safety and comfortability of all your guests. \n\n");

    //Loop through Main Menu
    do {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest(guests);
                break;
            case 2:
                deleteGuest(guests);
                break;
            case 3:
                viewGuests(guests);
                break;
            case 4:
                checkIn(guests);
                break;
            case 5:
                checkOut(guests);
                break;
            case 6:
                printf("Thank you for using the Apocalypse Hotel Management System. Good luck out there!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

//Function Definitions
void printMenu() {
    printf("\n----Main Menu----\n");
    printf("1. Add Guest\n");
    printf("2. Delete Guest\n");
    printf("3. View Guests\n");
    printf("4. Check In\n");
    printf("5. Check Out\n");
    printf("6. Exit\n");
}

void addGuest(struct guest* guests) {
    if (numGuests < maxGuests) {
        char name[50];
        printf("\nEnter guest name: ");
        scanf(" %[^\n]", name);
        
        int roomNum;
        do {
            printf("Enter room number (1-10): ");
            scanf("%d", &roomNum);
            if (roomNum < 1 || roomNum > 10) {
                printf("Invalid room number. Please try again.\n");
            }
            for (int i = 0; i < numGuests; i++) {
                if (guests[i].roomNum == roomNum) {
                    printf("Room number already occupied. Please try again.\n");
                    roomNum = 0;
                    break;
                }
            }
        } while (roomNum < 1 || roomNum > 10);

        guests[numGuests].roomNum = roomNum;
        strcpy(guests[numGuests].name, name);
        guests[numGuests].checkedIn = false;
        numGuests++;
        printf("%s has been added to the guest list.\n", name);
    } else {
        printf("Maximum number of guests reached.\n");
    }
}

void deleteGuest(struct guest* guests) {
    if (numGuests > 0) {
        char name[50];
        printf("\nEnter guest name: ");
        scanf(" %[^\n]", name);

        for (int i = 0; i < numGuests; i++) {
            if (strcmp(guests[i].name, name) == 0) {
                printf("%s has been removed from the guest list.\n", guests[i].name);
                guests[i].roomNum = 0;
                guests[i].checkedIn = false;
                for (int j = i; j < numGuests - 1; j++) {
                    guests[j] = guests[j + 1];
                }
                numGuests--;
                return;
            }
        }
        printf("Guest not found.\n");
    } else {
        printf("No guests to delete.\n");
    }
}

void viewGuests(struct guest* guests) {
    if (numGuests > 0) {
        printf("\n----Guest List----\n");
        printf("Name\t\tRoom Number\tChecked In\n");

        for (int i = 0; i < numGuests; i++) {
            char checkedIn[4];
            if (guests[i].checkedIn == true) {
                strcpy(checkedIn, "Yes");
            } else {
                strcpy(checkedIn, "No");
            }
            printf("%s\t\t%d\t\t%s\n", guests[i].name, guests[i].roomNum, checkedIn);
        }
    } else {
        printf("No guests to display.\n");
    }
}

void checkIn(struct guest* guests) {
    if (numGuests > 0) {
        char name[50];
        printf("\nEnter guest name: ");
        scanf(" %[^\n]", name);

        for (int i = 0; i < numGuests; i++) {
            if (strcmp(guests[i].name, name) == 0) {
                if (guests[i].checkedIn == true) {
                    printf("%s has already checked in.\n", guests[i].name);
                } else {
                    guests[i].checkedIn = true;
                    printf("%s has checked in to room %d.\n", guests[i].name, guests[i].roomNum);
                }
                return;
            }
        }
        printf("Guest not found.\n");
    } else {
        printf("No guests to check in.\n");
    }
}

void checkOut(struct guest* guests) {
    if (numGuests > 0) {
        char name[50];
        printf("\nEnter guest name: ");
        scanf(" %[^\n]", name);

        for (int i = 0; i < numGuests; i++) {
            if (strcmp(guests[i].name, name) == 0) {
                if (guests[i].checkedIn == false) {
                    printf("%s has not checked in.\n", guests[i].name);
                } else {
                    guests[i].checkedIn = false;
                    printf("%s has checked out of room %d.\n", guests[i].name, guests[i].roomNum);
                }
                return;
            }
        }
        printf("Guest not found.\n");
    } else {
        printf("No guests to check out.\n");
    }
}