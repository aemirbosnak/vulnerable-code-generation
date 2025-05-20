//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel room information
typedef struct {
    int roomNumber;
    char roomType[10];
    float roomCost;
    int numOccupied;
    int numVacant;
} Room;

int main() {
    // Array of Rooms to hold the hotel information
    Room hotel[5];
    int choice, roomNum, numRooms, i;

    // Initialize hotel data
    for (i = 0; i < 5; i++) {
        hotel[i].roomNumber = i + 1;
        strcpy(hotel[i].roomType, "Standard");
        hotel[i].roomCost = 100.0;
        hotel[i].numOccupied = 0;
        hotel[i].numVacant = 1;
    }

    // Menu to interact with the hotel system
    do {
        printf("Welcome to the Hotel Management System!\n");
        printf("1. View all rooms\n");
        printf("2. Book a room\n");
        printf("3. Check out of a room\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // View all rooms
            case 1:
                printf("Room#\tType\tCost\tOccupied\tVacant\n");
                for (i = 0; i < 5; i++) {
                    printf("%d\t%s\t%.2f\t%d\t\t%d\n", hotel[i].roomNumber, hotel[i].roomType, hotel[i].roomCost, hotel[i].numOccupied, hotel[i].numVacant);
                }
                break;
            // Book a room
            case 2:
                printf("Please enter the room number you would like to book: ");
                scanf("%d", &roomNum);
                if (hotel[roomNum - 1].numVacant == 0) {
                    printf("Sorry, that room is already occupied.\n");
                } else {
                    printf("How many rooms would you like to book? ");
                    scanf("%d", &numRooms);
                    if (numRooms > hotel[roomNum - 1].numVacant) {
                        printf("Sorry, there are not enough rooms available in that category.\n");
                    } else {
                        hotel[roomNum - 1].numOccupied += numRooms;
                        hotel[roomNum - 1].numVacant -= numRooms;
                        printf("Thank you for booking %d room(s)!\n", numRooms);
                    }
                }
                break;
            // Check out of a room
            case 3:
                printf("Please enter the room number you are checking out of: ");
                scanf("%d", &roomNum);
                if (hotel[roomNum - 1].numOccupied == 0) {
                    printf("Sorry, that room is not occupied.\n");
                } else {
                    printf("How many rooms would you like to check out of? ");
                    scanf("%d", &numRooms);
                    if (numRooms > hotel[roomNum - 1].numOccupied) {
                        printf("Sorry, you cannot check out of more rooms than are occupied.\n");
                    } else {
                        hotel[roomNum - 1].numOccupied -= numRooms;
                        hotel[roomNum - 1].numVacant += numRooms;
                        printf("Thank you for checking out of %d room(s)!\n", numRooms);
                    }
                }
                break;
            // Exit the program
            case 4:
                printf("Thank you for using the Hotel Management System!\n");
                break;
            // Invalid menu option
            default:
                printf("Invalid choice, please try again!\n");
        }
    } while (choice != 4);

    return 0;
}