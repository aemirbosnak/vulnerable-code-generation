//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_number;
    int num_days;
    float total_cost;
} Guest;

typedef struct Room {
    int room_number;
    int occupancy;
    float rate;
} Room;

Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];

void update_room_status(int room_number, int occupancy) {
    rooms[room_number].occupancy = occupancy;
}

void calculate_guest_cost(Guest *guest) {
    guest->total_cost = guest->num_days * rooms[guest->room_number].rate;
}

void check_in(Guest *guest) {
    int room_number = find_available_room();
    guest->room_number = room_number;
    update_room_status(room_number, 1);
}

void check_out(Guest *guest) {
    update_room_status(guest->room_number, 0);
}

int find_available_room() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].occupancy == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    int i;

    // Initialize guests and rooms
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].num_days = 0;
        guests[i].total_cost = 0.0f;
    }

    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].occupancy = 0;
    }

    // Check in a guest
    Guest guest1;
    strcpy(guest1.name, "John Doe");
    guest1.num_days = 3;
    check_in(&guest1);

    // Check out a guest
    Guest guest2;
    strcpy(guest2.name, "Jane Doe");
    guest2.num_days = 2;
    check_out(&guest2);

    // Print total cost for each guest
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].num_days > 0) {
            calculate_guest_cost(&guests[i]);
            printf("%s's total cost is $%.2f\n", guests[i].name, guests[i].total_cost);
        }
    }

    return 0;
}