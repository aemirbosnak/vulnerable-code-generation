//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int number;
    char status;
    float rate;
} Room;

// Create an array of rooms
Room rooms[100];

// Function to find an empty room
int findEmptyRoom() {
    for (int i = 0; i < 100; i++) {
        if (rooms[i].status == 'E') {
            return i;
        }
    }
    return -1;
}

// Function to book a room
void bookRoom(int roomNumber, char status, float rate) {
    rooms[roomNumber].status = status;
    rooms[roomNumber].rate = rate;
}

// Function to get the room rate
float getRoomRate(int roomNumber) {
    return rooms[roomNumber].rate;
}

// Main function
int main() {
    // Find an empty room
    int roomNumber = findEmptyRoom();

    // If an empty room is found, book it
    if (roomNumber != -1) {
        bookRoom(roomNumber, 'B', 100);
    }

    // Get the room rate
    float rate = getRoomRate(roomNumber);

    // Print the room rate
    printf("The room rate is: $%f", rate);

    return 0;
}