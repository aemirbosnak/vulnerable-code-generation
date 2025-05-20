//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel room information
struct Room {
    int roomNumber;
    char roomType[20];
    int occupancy;
    float price;
};

// Function to display room information
void displayRoom(struct Room room) {
    printf("Room Number: %d\n", room.roomNumber);
    printf("Room Type: %s\n", room.roomType);
    printf("Occupancy: %d\n", room.occupancy);
    printf("Price: %.2f\n\n", room.price);
}

// Function to add a new room to the hotel
void addRoom(struct Room rooms[], int *numRooms) {
    printf("\nEnter the Room Number: ");
    scanf("%d", &rooms[*numRooms].roomNumber);

    printf("Enter the Room Type (Single, Double, Suite, etc.): ");
    getchar();
    fgets(rooms[*numRooms].roomType, 20, stdin);

    printf("Enter the Occupancy: ");
    scanf("%d", &rooms[*numRooms].occupancy);

    printf("Enter the Price: ");
    scanf("%f", &rooms[*numRooms].price);

    printf("\nRoom Added Successfully!\n");
    *numRooms += 1;
}

// Function to remove a room from the hotel
void removeRoom(struct Room rooms[], int *numRooms) {
    int roomNumber = 0;
    int index = -1;

    printf("\nEnter the Room Number: ");
    scanf("%d", &roomNumber);

    // Find the room number in the list
    for (int i = 0; i < *numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            index = i;
            break;
        }
    }

    // Shift the elements in the array to remove the room
    if (index >= 0) {
        for (int i = index; i < *numRooms - 1; i++) {
            rooms[i] = rooms[i + 1];
        }
        *numRooms -= 1;
        printf("\nRoom Removed Successfully!\n");
    } else {
        printf("\nRoom Number Not Found.\n");
    }
}

int main() {
    int numRooms = 0;
    struct Room rooms[100];

    printf("Welcome to the Peaceful Hotel Management System\n\n");

    // Display the menu and accept user input
    while (1) {
        int choice = 0;

        printf("Menu:\n");
        printf("1. Display all Rooms\n");
        printf("2. Add a Room\n");
        printf("3. Remove a Room\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Display all rooms
        if (choice == 1) {
            if (numRooms == 0) {
                printf("\nNo Rooms Found.\n");
            } else {
                printf("\nRooms:\n");
                for (int i = 0; i < numRooms; i++) {
                    displayRoom(rooms[i]);
                }
            }
        }

        // Add a room
        else if (choice == 2) {
            addRoom(rooms, &numRooms);
        }

        // Remove a room
        else if (choice == 3) {
            removeRoom(rooms, &numRooms);
        }

        // Exit the program
        else if (choice == 4) {
            printf("\nThank you for using the Peaceful Hotel Management System.\n");
            exit(0);
        }

        // Invalid choice
        else {
            printf("\nInvalid Choice.\n");
        }
    }
    return 0;
}