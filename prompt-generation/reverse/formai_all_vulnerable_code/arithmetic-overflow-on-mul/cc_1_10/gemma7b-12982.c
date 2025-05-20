//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_no;
    int num_days;
    float total_cost;
} Guest;

typedef struct Room {
    int room_no;
    int occupancy;
    float rate;
} Room;

void calculate_guest_cost(Guest *guest) {
    int days = guest->num_days;
    float rate = guest->room_no * guest->room_no * 0.05f;
    guest->total_cost = days * rate;
}

void manage_guests(Guest *guests) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        printf("Guest name: %s\n", guests[i].name);
        printf("Room number: %d\n", guests[i].room_no);
        printf("Number of days: %d\n", guests[i].num_days);
        printf("Total cost: %.2f\n", guests[i].total_cost);
        printf("\n");
    }
}

void manage_rooms(Room *rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room number: %d\n", rooms[i].room_no);
        printf("Occupancy: %d\n", rooms[i].occupancy);
        printf("Rate: %.2f\n", rooms[i].rate);
        printf("\n");
    }
}

int main() {
    Guest guests[MAX_GUESTS];
    Room rooms[MAX_ROOMS];

    // Initialize guests and rooms

    // Calculate guest costs
    for (int i = 0; i < MAX_GUESTS; i++) {
        calculate_guest_cost(&guests[i]);
    }

    // Manage guests
    manage_guests(guests);

    // Manage rooms
    manage_rooms(rooms);

    return 0;
}