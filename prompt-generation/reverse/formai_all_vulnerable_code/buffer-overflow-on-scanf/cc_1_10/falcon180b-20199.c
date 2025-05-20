//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Struct to represent a room
typedef struct {
    char name[20];
    int isHaunted;
} Room;

// Initialize the room array with default values
void initRooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].isHaunted = 0;
        sprintf(rooms[i].name, "Room %d", i + 1);
    }
}

// Function to check if a room is haunted
int isHaunted(Room rooms[], int roomNumber) {
    if (roomNumber >= 0 && roomNumber < MAX_ROOMS) {
        return rooms[roomNumber].isHaunted;
    } else {
        return 0;
    }
}

// Function to haunt a room
void hauntRoom(Room rooms[], int roomNumber) {
    if (roomNumber >= 0 && roomNumber < MAX_ROOMS) {
        rooms[roomNumber].isHaunted = 1;
    }
}

// Function to unhaunt a room
void unhauntRoom(Room rooms[], int roomNumber) {
    if (roomNumber >= 0 && roomNumber < MAX_ROOMS) {
        rooms[roomNumber].isHaunted = 0;
    }
}

// Function to display the current state of the house
void displayHouse(Room rooms[]) {
    printf("Current state of the house:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%s: %s\n", rooms[i].name, isHaunted(rooms, i)? "Haunted" : "Not Haunted");
    }
}

// Function to simulate the haunting process
void simulate(Room rooms[], int numRooms) {
    srand(time(NULL));
    for (int i = 0; i < numRooms; i++) {
        int roomNumber = rand() % MAX_ROOMS;
        hauntRoom(rooms, roomNumber);
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    initRooms(rooms);

    int numRooms;
    printf("Enter the number of rooms to simulate: ");
    scanf("%d", &numRooms);

    simulate(rooms, numRooms);
    displayHouse(rooms);

    return 0;
}