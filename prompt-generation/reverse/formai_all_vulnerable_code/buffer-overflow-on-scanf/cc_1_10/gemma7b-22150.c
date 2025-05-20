//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: authentic
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
Room* search_room(char* room_number) {
    // Create an array of rooms
    Room rooms[] = {
        {"101", "Standard", 2, 50.0},
        {"102", "Deluxe", 4, 75.0},
        {"103", "Suite", 6, 100.0}
    };

    // Iterate over the array of rooms to find the matching room
    for (int i = 0; i < 3; i++) {
        if (strcmp(rooms[i].room_number, room_number) == 0) {
            return &rooms[i];
        }
    }

    // Return NULL if the room is not found
    return NULL;
}

// Define a function to book a room
void book_room(Room* room) {
    // Update the room's availability
    room->available_beds--;

    // Print a confirmation message
    printf("Your room has been booked. Room number: %s, Room type: %s, Number of available beds: %d, Room rate: %.2f\n", room->room_number, room->room_type, room->available_beds, room->room_rate);
}

int main() {
    // Get the room number from the user
    char room_number[10];
    printf("Enter the room number: ");
    scanf("%s", room_number);

    // Search for the room
    Room* room = search_room(room_number);

    // If the room is found, book it
    if (room) {
        book_room(room);
    } else {
        // Print an error message
        printf("Room not found.\n");
    }

    return 0;
}