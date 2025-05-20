//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    char room_number[10];
    char room_type[20];
    int available_beds;
    float room_rate;
} Room;

// Define a function to search for a room
int search_room(Room *rooms, int num_rooms, char *room_number) {
    for (int i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].room_number, room_number) == 0) {
            return i;
        }
    }

    return -1;
}

// Define a function to book a room
int book_room(Room *rooms, int num_rooms, char *room_number, int num_beds) {
    int room_index = search_room(rooms, num_rooms, room_number);

    if (room_index != -1) {
        if (rooms[room_index].available_beds >= num_beds) {
            rooms[room_index].available_beds -= num_beds;
            return 0;
        }
    }

    return -1;
}

int main() {
    // Create an array of rooms
    Room rooms[] = {
        {"101", "Standard", 2, 50.0},
        {"102", "Deluxe", 4, 70.0},
        {"103", "Suite", 6, 90.0}
    };

    // Number of rooms
    int num_rooms = 3;

    // Get the room number and number of beds from the user
    char room_number[10];
    int num_beds;

    // Search for the room
    int room_index = search_room(rooms, num_rooms, room_number);

    // Book the room
    if (room_index != -1) {
        book_room(rooms, num_rooms, room_number, num_beds);

        printf("Room booked successfully!\n");
    } else {
        printf("Room not found.\n");
    }

    return 0;
}