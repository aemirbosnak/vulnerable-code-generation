//FormAI DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Room {
    int number;
    int capacity;
    bool occupied;
    float price;
} Room;

int main() {
    int menuChoice = 0;
    int numberOfRooms = 5;
    Room hotelRooms[5] = {{101, 2, false, 50.00},
                          {102, 2, false, 50.00},
                          {103, 4, false, 100.00},
                          {104, 4, false, 100.00},
                          {105, 6, false, 150.00}};

    printf("Welcome to the Chuck Norris Hotel Management System!\n");

    while (menuChoice != 4) {
        printf("\n\nPlease choose an option:\n\n");
        printf("1. Display all rooms\n");
        printf("2. Book a room\n");
        printf("3. Check out of a room\n");
        printf("4. Exit\n\n");
        scanf("%d", &menuChoice);

        if (menuChoice == 1) {
            printf("\n\nROOMS AVAILABLE\n\n");
            for (int i = 0; i < numberOfRooms; i++) {
                printf("Room Number: %d\n", hotelRooms[i].number);
                printf("Capacity: %d\n", hotelRooms[i].capacity);
                printf("Occupied: %s\n", hotelRooms[i].occupied ? "Yes" : "No");
                printf("Price: $%.2f\n", hotelRooms[i].price);
                printf("\n");
            }
        }

        else if (menuChoice == 2) {
            int roomNumber;
            printf("\n\nPlease enter the room number you wish to book: ");
            scanf("%d", &roomNumber);

            for (int i = 0; i < numberOfRooms; i++) {
                if (hotelRooms[i].number == roomNumber) {
                    if (hotelRooms[i].occupied) {
                        printf("\n\nSorry, that room is already occupied. Please try another.\n");
                        break;
                    } else {
                        hotelRooms[i].occupied = true;
                        printf("\n\nRoom %d has been booked! Enjoy your stay...\n", roomNumber);
                        break;
                    }
                }
            }
        }

        else if (menuChoice == 3) {
            int roomNumber;
            printf("\n\nPlease enter the room number you wish to check out of: ");
            scanf("%d", &roomNumber);

            for (int i = 0; i < numberOfRooms; i++) {
                if (hotelRooms[i].number == roomNumber) {
                    if (!hotelRooms[i].occupied) {
                        printf("\n\nSorry, that room is not occupied. Please try another.\n");
                        break;
                    } else {
                        hotelRooms[i].occupied = false;
                        printf("\n\nThank you for staying with us in room %d!\n", roomNumber);
                        break;
                    }
                }
            }
        }

        else if (menuChoice == 4) {
            printf("\n\nThank you for using the Chuck Norris Hotel Management System. Have a nice day!\n\n");
        } 
        
        else { 
            printf("\n\nInvalid choice. Please try again.\n\n"); 
        }
    }

    return 0;
}