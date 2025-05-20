//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
// C Hotel Management System example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Struct for each room
typedef struct {
    int roomNumber;
    char guestName[MAX_STRING_LENGTH];
    char guestContact[MAX_STRING_LENGTH];
    float ratePerDay;
    int occupancyStatus;
} Room;

// Function to display the menu
void displayMenu() {
    printf("\n---------- HOTEL MANAGEMENT SYSTEM ----------\n\n");
    printf("1. Display Room Details\n");
    printf("2. Book a Room\n");
    printf("3. Check Out\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

// Function to display the details of a room
void displayRoom(Room room) {
    printf("\n---------- ROOM DETAILS ----------\n\n");
    printf("Room Number: %d\n", room.roomNumber);
    printf("Guest Name: %s\n", room.guestName);
    printf("Guest Contact: %s\n", room.guestContact);
    printf("Rate per Day: %.2f\n", room.ratePerDay);
    printf("Occupancy Status: %d\n", room.occupancyStatus);
    printf("\n----------------------------------\n");
}

// Function to book a room
void bookRoom(Room *room) {
    printf("\nEnter the guest name: ");
    scanf("%s", room->guestName);
    printf("Enter the guest contact: ");
    scanf("%s", room->guestContact);
    printf("Enter the rate per day: ");
    scanf("%f", &room->ratePerDay);
    room->occupancyStatus = 1;

    printf("\nRoom booked successfully!\n");
}

// Function to check out from a room
void checkOut(Room *room) {
    room->guestName[0] = '\0';
    room->guestContact[0] = '\0';
    room->ratePerDay = 0.0;
    room->occupancyStatus = 0;

    printf("\nRoom checked out successfully!\n");
}

// Main function
int main() {
    int numRooms, choice, roomNumber, i;
    Room *rooms;

    // Getting the number of rooms
    printf("Enter the number of rooms: ");
    scanf("%d", &numRooms);

    // Dynamically allocating rooms
    rooms = (Room*)malloc(numRooms * sizeof(Room));

    // Initializing rooms
    for(i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].guestName[0] = '\0';
        rooms[i].guestContact[0] = '\0';
        rooms[i].ratePerDay = 0.0;
        rooms[i].occupancyStatus = 0;
    }

    // Looping through the menu until the user exits
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the room number: ");
                scanf("%d", &roomNumber);

                // Checking if the room number is valid
                if(roomNumber > 0 && roomNumber <= numRooms) {
                    displayRoom(rooms[roomNumber - 1]);
                } else {
                    printf("\nInvalid room number. Please try again.\n");
                }
                break;
            case 2:
                printf("\nEnter the room number: ");
                scanf("%d", &roomNumber);

                // Checking if the room number is valid and if the room is not already occupied
                if(roomNumber > 0 && roomNumber <= numRooms) {
                    if(rooms[roomNumber - 1].occupancyStatus == 0) {
                        bookRoom(&rooms[roomNumber - 1]);
                    } else {
                        printf("\nRoom already occupied. Please try again.\n");
                    }
                } else {
                    printf("\nInvalid room number. Please try again.\n");
                }
                break;
            case 3:
                printf("\nEnter the room number: ");
                scanf("%d", &roomNumber);

                // Checking if the room number is valid and if the room is already occupied
                if(roomNumber > 0 && roomNumber <= numRooms) {
                    if(rooms[roomNumber - 1].occupancyStatus == 1) {
                        checkOut(&rooms[roomNumber - 1]);
                    } else {
                        printf("\nRoom not occupied. Please try again.\n");
                    }
                } else {
                    printf("\nInvalid room number. Please try again.\n");
                }
                break;
            case 4:
                printf("\nThank you for using the Hotel Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    // Freeing the dynamically allocated memory for rooms
    free(rooms);

    return 0;
}