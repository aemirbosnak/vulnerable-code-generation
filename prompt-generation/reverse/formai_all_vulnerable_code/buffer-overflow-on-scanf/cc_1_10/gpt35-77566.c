//FormAI DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for hotel room
struct room {
    int roomNumber;
    char type[10];
    float price;
    int availability;
};

// Function to display menu
void displayMenu() {
    printf("\n===========================\n");
    printf("Welcome to C Hotel Management System");
    printf("\n===========================\n");
    printf("1. Book a room\n");
    printf("2. Check room availability\n");
    printf("3. Show available rooms\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
}

// Function to book a room
void bookRoom(struct room h[]) {
    int roomNumber;
    int foundRoom = 0;
    for (int i = 0; i < 10; i++) {
        printf("Enter the room number you want to book: ");
        scanf("%d", &roomNumber);

        if (h[i].roomNumber == roomNumber) {
            foundRoom = 1;
            if (h[i].availability == 0) {
                printf("\nSorry, room is not available.");
            }
            else {
                h[i].availability = 0;
                printf("\nRoom booked successfully.");
            }
            break;
        }
    }
    if (!foundRoom) {
        printf("\nRoom not found.");
    }
}

// Function to check room availability
void checkAvailability(struct room h[]) {
    int roomNumber;
    int foundRoom = 0;
    for (int i = 0; i < 10; i++) {
        printf("Enter the room number you want to check: ");
        scanf("%d", &roomNumber);

        if (h[i].roomNumber == roomNumber) {
            foundRoom = 1;
            if (h[i].availability == 0) {
                printf("\nSorry, room is not available.");
            }
            else {
                printf("\nRoom is available.");
            }
            break;
        }
    }
    if (!foundRoom) {
        printf("\nRoom not found.");
    }
}

// Function to show available rooms
void showAvailableRooms(struct room h[]) {
    printf("\nAvailable rooms:\n");
    printf("Room Number\tType\tPrice\n");
    for (int i = 0; i < 10; i++) {
        if (h[i].availability == 1) {
            printf("%d\t\t%s\t%.2f\n", h[i].roomNumber, h[i].type, h[i].price);
        }
    }
}

// Function to checkout
void checkout(struct room h[]) {
    int roomNumber;
    int foundRoom = 0;
    for (int i = 0; i < 10; i++) {
        printf("Enter the room number to checkout: ");
        scanf("%d", &roomNumber);

        if (h[i].roomNumber == roomNumber) {
            foundRoom = 1;
            if (h[i].availability == 0) {
                h[i].availability = 1;
                printf("\nRoom checked out successfully.");
            }
            else {
                printf("\nRoom is not currently booked.");
            }
            break;
        }
    }
    if (!foundRoom) {
        printf("\nRoom not found.");
    }
}

int main() {
    struct room hotel[10] = {
        {1, "Single", 50.00, 1},
        {2, "Single", 50.00, 1},
        {3, "Single", 50.00, 1},
        {4, "Single", 50.00, 1},
        {5, "Double", 75.00, 1},
        {6, "Double", 75.00, 1},
        {7, "Double", 75.00, 1},
        {8, "Family", 100.00, 1},
        {9, "Family", 100.00, 1},
        {10, "Suite", 150.00, 1},
    };

    int choice;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                bookRoom(hotel);
                break;
            case 2:
                checkAvailability(hotel);
                break;
            case 3:
                showAvailableRooms(hotel);
                break;
            case 4:
                checkout(hotel);
                break;
            case 5:
                printf("\nThank you for using C Hotel Management System.");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while(choice != 5);

    return 0;
}