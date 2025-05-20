//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each hotel room
typedef struct {
    int roomNumber;
    char guestName[50];
    int numDays;
    float rate;
} Room;

// Define functions to add and display rooms
void addRoom(Room *rooms, int numRooms);
void displayRooms(Room *rooms, int numRooms);

int main() {
    int numRooms;

    // Get the number of rooms the hotel has
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &numRooms);

    // Allocate space for an array of rooms
    Room *rooms = (Room*)malloc(numRooms * sizeof(Room));

    // Loop through each room and add it to the array
    for (int i = 0; i < numRooms; i++) {
        addRoom(&rooms[i], i+1);
    }

    // Display the information for all the rooms in the hotel
    printf("\nHotel Room Information:\n");
    displayRooms(rooms, numRooms);

    // Free the memory allocated for the array of rooms
    free(rooms);

    return 0;
}

// Define the add room function
void addRoom(Room *room, int roomNumber) {
    room->roomNumber = roomNumber;

    printf("Enter the name of the guest occupying Room %d: ", roomNumber);
    scanf("%s", room->guestName);

    printf("Enter the number of days the guest will be staying: ");
    scanf("%d", &room->numDays);

    printf("Enter the nightly rate for Room %d: ", roomNumber);
    scanf("%f", &room->rate);

    printf("\n");
}

// Define the display rooms function
void displayRooms(Room *rooms, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d\n", rooms[i].roomNumber);
        printf("Guest Name: %s\n", rooms[i].guestName);
        printf("Number of Days: %d\n", rooms[i].numDays);
        printf("Nightly Rate: $%.2f\n\n", rooms[i].rate);
    }
}