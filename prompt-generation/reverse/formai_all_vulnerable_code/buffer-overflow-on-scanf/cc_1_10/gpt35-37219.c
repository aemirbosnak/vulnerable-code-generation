//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum capacity for the hotel
#define MAX_CAPACITY 100

// Define structure for each hotel room
struct Room {
    int roomNumber;
    char guestName[50];
    int numGuests;
    int nightsStayed;
};

// Define function to print out all rooms in the hotel
void printRooms(struct Room rooms[]) {
    printf("\n---- CURRENT ROOMS ----\n");
    for (int i = 0; i < MAX_CAPACITY; i++) {
        if (rooms[i].roomNumber != 0) {
            printf("Room %d: %s, %d guests, %d nights\n", rooms[i].roomNumber, rooms[i].guestName, rooms[i].numGuests, rooms[i].nightsStayed);
        }
    }
}

int main() {
    struct Room rooms[MAX_CAPACITY]; // Create array of rooms
    int numRooms = 0; // Initialize current number of rooms to 0

    printf("Welcome to the Hotel Management System!\n\n");

    // Loop through menu until user quits
    while (1) {
        int choice = 0;
        printf("\nWhat would you like to do?\n");
        printf("1. Add a guest room\n");
        printf("2. Remove a guest room\n");
        printf("3. Update a guest room\n");
        printf("4. Print all guest rooms\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character from scanf

        switch (choice) {
            case 1: // Add a guest room
                if (numRooms >= MAX_CAPACITY) {
                    printf("\nSorry, the hotel is currently at maximum capacity.\n");
                    break;
                }

                struct Room newRoom; // Create new room to add
                printf("\nEnter the room number: ");
                scanf("%d", &newRoom.roomNumber);
                getchar(); // Consume newline character from scanf
                printf("Enter the guest name: ");
                fgets(newRoom.guestName, 50, stdin);
                newRoom.guestName[strcspn(newRoom.guestName, "\n")] = 0; // Remove trailing newline character
                printf("Enter the number of guests: ");
                scanf("%d", &newRoom.numGuests);
                printf("Enter the number of nights stayed: ");
                scanf("%d", &newRoom.nightsStayed);
                rooms[numRooms++] = newRoom; // Add new room to array
                printf("\nGuest room added successfully!\n");
                break;

            case 2: // Remove a guest room
                if (numRooms == 0) {
                    printf("\nSorry, there are no rooms to remove.\n");
                    break;
                }

                int removeRoomNumber;
                printf("\nEnter the room number to remove: ");
                scanf("%d", &removeRoomNumber);

                // Loop through array to find room to remove
                int foundRoom = 0;
                for (int i = 0; i < numRooms; i++) {
                    if (rooms[i].roomNumber == removeRoomNumber) {
                        for (int j = i; j < numRooms - 1; j++) {
                            rooms[j] = rooms[j + 1]; // Shift all rooms after removed room up one index
                        }
                        numRooms--; // Decrease current number of rooms
                        foundRoom = 1;
                        break;
                    }
                }

                if (foundRoom) {
                    printf("\nGuest room removed successfully!\n");
                } else {
                    printf("\nSorry, that room was not found.\n");
                }

                break;

            case 3: // Update a guest room
                if (numRooms == 0) {
                    printf("\nSorry, there are no rooms to update.\n");
                    break;
                }

                int updateRoomNumber;
                printf("\nEnter the room number to update: ");
                scanf("%d", &updateRoomNumber);

                // Loop through array to find room to update
                int updatedRoom = 0;
                for (int i = 0; i < numRooms; i++) {
                    if (rooms[i].roomNumber == updateRoomNumber) {
                        printf("\nEnter the new guest name (or leave blank to keep current name): ");
                        fgets(rooms[i].guestName, 50, stdin);
                        rooms[i].guestName[strcspn(rooms[i].guestName, "\n")] = 0; // Remove trailing newline character
                        printf("Enter the new number of guests (or enter 0 to keep current number): ");
                        scanf("%d", &rooms[i].numGuests);
                        printf("Enter the new number of nights stayed (or enter 0 to keep current number): ");
                        scanf("%d", &rooms[i].nightsStayed);
                        updatedRoom = 1;
                        break;
                    }
                }

                if (updatedRoom) {
                    printf("\nGuest room updated successfully!\n");
                } else {
                    printf("\nSorry, that room was not found.\n");
                }

                break;

            case 4: // Print all guest rooms
                printRooms(rooms);
                break;

            case 5: // Quit
                printf("\nThank you for using the Hotel Management System!\n");
                return 0;

            default: // Invalid choice
                printf("\nSorry, that is not a valid choice.\n");
                break;
        }
    }

    return 0;
}