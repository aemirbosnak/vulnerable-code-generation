//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a hotel room
typedef struct Room {
    int room_number;
    char room_type;
    int number_of_guests;
    float room_rate;
} Room;

// Define a function to manage rooms
void manage_rooms(Room *rooms) {
    // Display the list of rooms
    printf("List of rooms:\n");
    for (int i = 0; i < 10; i++) {
        printf("Room number: %d, Room type: %c, Number of guests: %d, Room rate: %.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].number_of_guests, rooms[i].room_rate);
    }

    // Get the room number of the guest
    int room_number = 0;
    printf("Enter the room number of the guest: ");
    scanf("%d", &room_number);

    // Find the room of the guest
    Room *guest_room = NULL;
    for (int i = 0; i < 10; i++) {
        if (rooms[i].room_number == room_number) {
            guest_room = &rooms[i];
        }
    }

    // If the guest room is found, display its information
    if (guest_room) {
        printf("Room number: %d, Room type: %c, Number of guests: %d, Room rate: %.2f\n", guest_room->room_number, guest_room->room_type, guest_room->number_of_guests, guest_room->room_rate);
    } else {
        printf("Room not found.\n");
    }
}

int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {1, 'A', 2, 50.0},
        {2, 'B', 4, 60.0},
        {3, 'C', 3, 40.0},
        // ...
    };

    // Manage the rooms
    manage_rooms(rooms);

    return 0;
}