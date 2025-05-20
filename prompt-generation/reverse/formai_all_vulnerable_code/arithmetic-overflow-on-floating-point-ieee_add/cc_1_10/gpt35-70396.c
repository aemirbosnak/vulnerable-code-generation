//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for room information
typedef struct Room {
    int roomNumber;
    char roomType[20];
    int numBeds;
    double rate;
    int occupied;
} Room;

// Function to print room information
void printRoom(Room r) {
    printf("Room Number: %d\n", r.roomNumber);
    printf("Room Type: %s\n", r.roomType);
    printf("Number of Beds: %d\n", r.numBeds);
    printf("Rate: $%.2f\n", r.rate);
    printf("Occupied: %d\n", r.occupied);
}

int main(void) {
    // Create array to hold room information
    Room rooms[10];

    // Initialize room information
    rooms[0].roomNumber = 101;
    strcpy(rooms[0].roomType, "Single");
    rooms[0].numBeds = 1;
    rooms[0].rate = 75.00;
    rooms[0].occupied = 0;

    rooms[1].roomNumber = 102;
    strcpy(rooms[1].roomType, "Single");
    rooms[1].numBeds = 1;
    rooms[1].rate = 75.00;
    rooms[1].occupied = 1;

    rooms[2].roomNumber = 103;
    strcpy(rooms[2].roomType, "Double");
    rooms[2].numBeds = 2;
    rooms[2].rate = 100.00;
    rooms[2].occupied = 0;

    // Initialize menu options
    int choice;
    double totalRevenue = 0;

    // Display menu options until user exits
    do {
        printf("\nWelcome to the Hotel Management System!\n");
        printf("\n1. View Room Information\n");
        printf("2. Reserve a Room\n");
        printf("3. Check Out\n");
        printf("4. View Total Revenue\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Print room information for all rooms
                for (int i = 0; i < 10; i++) {
                    printf("\nRoom %d Information:\n", rooms[i].roomNumber);
                    printRoom(rooms[i]);
                }
                break;

            case 2:
                // Reserve a room
                printf("\nEnter the room number you would like to reserve: ");
                int roomNumber;
                scanf("%d", &roomNumber);

                // Check if room is available
                int roomIndex = -1;
                for (int i = 0; i < 10; i++) {
                    if (rooms[i].roomNumber == roomNumber) {
                        if (rooms[i].occupied) {
                            printf("\nThis room is currently occupied.\n");
                        } else {
                            roomIndex = i;
                        }
                        break;
                    }
                }

                // Reserve the room if available
                if (roomIndex != -1) {
                    rooms[roomIndex].occupied = 1;
                    printf("\nRoom %d has been reserved.\n", rooms[roomIndex].roomNumber);
                } else {
                    printf("\nRoom %d does not exist.\n", roomNumber);
                }
                break;

            case 3:
                // Check out of a room
                printf("\nEnter the room number you are checking out of: ");
                int checkOutRoomNumber;
                scanf("%d", &checkOutRoomNumber);

                // Check if room is occupied
                int checkOutRoomIndex = -1;
                for (int i = 0; i < 10; i++) {
                    if (rooms[i].roomNumber == checkOutRoomNumber) {
                        if (rooms[i].occupied == 0) {
                            printf("\nThis room is not occupied.\n");
                        } else {
                            checkOutRoomIndex = i;
                        }
                        break;
                    }
                }

                // Check out of the room if occupied
                if (checkOutRoomIndex != -1) {
                    rooms[checkOutRoomIndex].occupied = 0;
                    totalRevenue += rooms[checkOutRoomIndex].rate;
                    printf("\nYou have been checked out of Room %d.\n", rooms[checkOutRoomIndex].roomNumber);
                } else {
                    printf("\nRoom %d does not exist.\n", checkOutRoomNumber);
                }
                break;

            case 4:
                // View total revenue
                printf("\nTotal Revenue: $%.2f\n", totalRevenue);
                break;

            case 5:
                // Exit
                printf("\nThank you for using the Hotel Management System!\n");
                break;

            default:
                // Invalid input
                printf("\nInvalid input. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}