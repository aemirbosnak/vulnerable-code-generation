//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a room
typedef struct Room {
    int room_number;
    char room_type;
    int available;
    char guest_name[50];
    int num_guests;
} Room;

// Define a function to manage rooms
void manage_rooms(Room *rooms, int num_rooms) {
    // Loop over the rooms
    for (int i = 0; i < num_rooms; i++) {
        // Check if the room is available
        if (rooms[i].available) {
            // Get the guest name and number of guests
            printf("Enter guest name: ");
            scanf("%s", rooms[i].guest_name);

            printf("Enter number of guests: ");
            scanf("%d", &rooms[i].num_guests);

            // Set the room as occupied
            rooms[i].available = 0;
        } else {
            // Print an error message
            printf("Error: room is not available.\n");
        }
    }
}

int main() {
    // Create an array of rooms
    Room rooms[10];

    // Initialize the rooms
    for (int i = 0; i < 10; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].room_type = 'A';
        rooms[i].available = 1;
        rooms[i].guest_name[0] = '\0';
        rooms[i].num_guests = 0;
    }

    // Manage the rooms
    manage_rooms(rooms, 10);

    return 0;
}