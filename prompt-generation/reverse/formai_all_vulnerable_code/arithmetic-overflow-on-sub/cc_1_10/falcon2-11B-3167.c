//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a hotel room
struct Room {
    char name[50];
    int price;
};

// Function to add a new room to the hotel
void addRoom(struct Room *rooms, int size) {
    int newRoomIndex = size;
    printf("Enter room name: ");
    scanf("%s", rooms[newRoomIndex].name);
    printf("Enter room price: ");
    scanf("%d", &rooms[newRoomIndex].price);
}

// Function to remove a room from the hotel
void removeRoom(struct Room *rooms, int size) {
    printf("Enter room name to remove: ");
    scanf("%s", rooms[size - 1].name);
    printf("Room %s removed.\n", rooms[size - 1].name);
}

// Function to display all rooms in the hotel
void displayRooms(struct Room *rooms, int size) {
    printf("Rooms in the hotel:\n");
    for (int i = 0; i < size; i++) {
        printf("Room %d: %s, Price: $%.2f\n", i + 1, rooms[i].name, rooms[i].price);
    }
}

// Main function
int main() {
    struct Room rooms[5]; // Array of rooms with size 5
    int size = 0; // Size of the array

    printf("Welcome to the Hotel Management System!\n");

    // Add rooms to the hotel
    printf("Enter number of rooms to add: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        addRoom(rooms, size);
    }

    // Display all rooms in the hotel
    printf("\nAll rooms in the hotel:\n");
    displayRooms(rooms, size);

    // Remove a room from the hotel
    printf("\nRemove a room from the hotel:\n");
    removeRoom(rooms, size);

    // Display all rooms in the hotel again
    printf("\nAll rooms in the hotel after removal:\n");
    displayRooms(rooms, size);

    return 0;
}