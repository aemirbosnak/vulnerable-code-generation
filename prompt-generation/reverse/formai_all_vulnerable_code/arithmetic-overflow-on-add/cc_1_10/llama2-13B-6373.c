//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

struct guest {
    char name[20];
    int arrival_date;
    int departure_date;
    int room_id;
};

struct room {
    char name[20];
    int capacity;
    int occupied;
};

int main() {
    // Initialize guest and room arrays
    struct guest guests[MAX_GUESTS];
    struct room rooms[MAX_ROOMS];

    // Generate random data for guests and rooms
    for (int i = 0; i < MAX_GUESTS; i++) {
        sprintf(guests[i].name, "Guest %d", i);
        guests[i].arrival_date = (int)(time(NULL) + (i * 100));
        guests[i].departure_date = guests[i].arrival_date + (rand() % 10) + 1;
        guests[i].room_id = (int)(rand() % MAX_ROOMS);
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].name, "Room %d", i);
        rooms[i].capacity = (int)(rand() % 10) + 1;
        rooms[i].occupied = (rand() % 10) + 1;
    }

    // Display statistics for guests and rooms
    printf("Guests Statistics:\n");
    printf("Total Guests: %d\n", MAX_GUESTS);
    printf("Average Arrival Date: %d\n", (int)((double)guests[0].arrival_date / MAX_GUESTS));
    printf("Average Departure Date: %d\n", (int)((double)guests[0].departure_date / MAX_GUESTS));
    printf("Average Stay Duration: %d\n", (int)((double)(guests[0].departure_date - guests[0].arrival_date) / MAX_GUESTS));

    printf("\nRooms Statistics:\n");
    printf("Total Rooms: %d\n", MAX_ROOMS);
    printf("Average Occupancy: %d\n", (int)((double)rooms[0].occupied / MAX_ROOMS));
    printf("Average Capacity: %d\n", (int)((double)rooms[0].capacity / MAX_ROOMS));

    return 0;
}