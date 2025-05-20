//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

struct guest {
    char name[20];
    int arrival_date;
    int departure_date;
    int room_number;
};

struct room {
    char name[20];
    int capacity;
    int occupancy;
};

int main() {
    // Initialize guest and room structures
    struct guest guests[MAX_GUESTS];
    struct room rooms[MAX_ROOMS];

    // Generate random arrival and departure dates for guests
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i].arrival_date = (int)(time(NULL) + (double)i / 100);
        guests[i].departure_date = guests[i].arrival_date + (int)(rand() % 3) + 1;
    }

    // Generate random room capacities and occupancies
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].capacity = (int)(rand() % 10) + 1;
        rooms[i].occupancy = (int)(rand() % rooms[i].capacity) + 1;
    }

    // Simulate check-in and check-out operations
    for (int i = 0; i < MAX_GUESTS; i++) {
        int room_number = (int)(rand() % MAX_ROOMS);
        while (rooms[room_number].occupancy == rooms[room_number].capacity) {
            room_number = (int)(rand() % MAX_ROOMS);
        }
        guests[i].room_number = room_number;
        rooms[room_number].occupancy++;
    }

    // Calculate and print statistics
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: Occupancy %d, Capacity %d\n", i + 1, rooms[i].occupancy, rooms[i].capacity);
    }

    for (int i = 0; i < MAX_GUESTS; i++) {
        printf("Guest %d: Name %s, Arrival %d, Departure %d, Room %d\n",
            i + 1, guests[i].name, guests[i].arrival_date, guests[i].departure_date, guests[i].room_number);
    }

    return 0;
}