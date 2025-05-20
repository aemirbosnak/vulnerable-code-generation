//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct guest_info {
    char name[50];
    int room_no;
    char email[50];
    int num_days;
    float total_cost;
};

struct room_details {
    int room_no;
    int occupancy;
    float room_rate;
};

void calculate_total_cost(struct guest_info *guest, struct room_details *room) {
    int num_days = guest->num_days;
    float room_rate = room->room_rate;
    guest->total_cost = num_days * room_rate;
}

void check_room_availability(struct room_details *room, int guest_room_no) {
    if (room->occupancy == guest_room_no) {
        printf("Room %d is occupied.\n", guest_room_no);
    } else {
        printf("Room %d is available.\n", guest_room_no);
    }
}

int main() {
    struct guest_info guests[MAX_GUESTS];
    struct room_details rooms[10];

    // Initialize guests and rooms

    // Create a guest
    struct guest_info new_guest;
    strcpy(new_guest.name, "John Doe");
    new_guest.room_no = 101;
    strcpy(new_guest.email, "john.doe@example.com");
    new_guest.num_days = 3;

    // Calculate total cost for the guest
    calculate_total_cost(&new_guest, rooms);

    // Check room availability
    check_room_availability(rooms, new_guest.room_no);

    return 0;
}