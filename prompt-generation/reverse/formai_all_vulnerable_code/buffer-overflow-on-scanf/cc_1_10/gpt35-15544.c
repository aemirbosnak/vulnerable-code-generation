//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for hotel rooms
struct room {
    int roomNumber;
    char roomType[10];
    int occupancy;
    float price;
};

// Define function to add rooms
void addRooms(struct room rooms[], int numRooms) {
    int count = 0;
    for (int i = 0; i < numRooms; i++) {
        printf("Enter room number: ");
        scanf("%d", &rooms[i].roomNumber);
        printf("Enter room type (Single, Double, Suite): ");
        scanf("%s", rooms[i].roomType);
        printf("Enter occupancy: ");
        scanf("%d", &rooms[i].occupancy);
        printf("Enter price: ");
        scanf("%f", &rooms[i].price);
        count++;
    }
    printf("%d rooms successfully added!\n\n", count);
}

// Define function to display room information
void displayRooms(struct room rooms[], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d - Type: %s | Occupancy: %d | Price: $%.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].occupancy, rooms[i].price);
    }
    printf("\n");
}

int main() {
    // Welcome Message
    printf("Welcome to HappyHotel Management System!\n");

    // Declare and initialize variables
    int choice, numRooms = 0;
    struct room rooms[50];

    // Display menu options
    while (1) {
        printf("Please choose an option:\n1. Add rooms\n2. Display rooms\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many rooms would you like to add? ");
                scanf("%d", &numRooms);
                addRooms(rooms, numRooms);
                break;
            case 2:
                displayRooms(rooms, numRooms);
                break;
            case 3:
                printf("Thank you for using HappyHotel Management System! Goodbye!");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}