//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store hotel room information
typedef struct Room {
    int room_no;
    char room_type;
    int occupancy;
    float rate;
} Room;

// Define a function to manage hotel room bookings
void manage_bookings(Room *rooms, int num_rooms) {
    // Create a list of available rooms
    int available_rooms = 0;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].occupancy == 0) {
            available_rooms++;
        }
    }

    // Get the number of rooms required
    int num_rooms_required = 0;
    printf("Enter the number of rooms you need: ");
    scanf("%d", &num_rooms_required);

    // Check if there are enough available rooms
    if (num_rooms_required > available_rooms) {
        printf("Sorry, there are not enough available rooms.\n");
    } else {
        // Allocate rooms
        int rooms_allocated = 0;
        for (int i = 0; i < num_rooms_required; i++) {
            for (int j = 0; j < num_rooms; j++) {
                if (rooms[j].occupancy == 0) {
                    rooms[j].occupancy = 1;
                    rooms_allocated++;
                    printf("Room number: %d\n", rooms[j].room_no);
                }
            }
        }

        // Print the number of rooms allocated
        printf("Total number of rooms allocated: %d\n", rooms_allocated);
    }
}

int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {1, 'A', 0, 100},
        {2, 'B', 1, 120},
        {3, 'A', 0, 100},
        {4, 'B', 2, 120},
        {5, 'A', 0, 100},
        {6, 'B', 0, 120},
        {7, 'A', 0, 100},
        {8, 'B', 1, 120},
        {9, 'A', 0, 100},
        {10, 'B', 2, 120}
    };

    // Manage hotel room bookings
    manage_bookings(rooms, 10);

    return 0;
}