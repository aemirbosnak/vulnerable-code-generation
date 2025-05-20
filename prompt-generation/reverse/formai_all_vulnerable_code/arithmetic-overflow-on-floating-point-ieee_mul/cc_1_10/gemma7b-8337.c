//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct guest_info {
    char name[50];
    int room_no;
    int num_days;
    float total_amount;
};

struct room_details {
    int room_no;
    int available;
    float room_rate;
};

void calculate_total_amount(struct guest_info *guest, struct room_details *room) {
    int days = guest->num_days;
    float rate = room->room_rate;
    guest->total_amount = days * rate;
}

void check_room_availability(struct room_details *room, int room_no) {
    if (room->available == 1 && room->room_no == room_no) {
        room->available = 0;
    }
}

int main() {
    struct guest_info guests[MAX_GUESTS];
    struct room_details rooms[10];

    // Initialize guests and rooms

    // Calculate total amount for each guest
    for (int i = 0; i < MAX_GUESTS; i++) {
        calculate_total_amount(&guests[i], &rooms[rooms[i].room_no]);
    }

    // Check room availability
    for (int i = 0; i < MAX_GUESTS; i++) {
        check_room_availability(&rooms[rooms[i].room_no], rooms[i].room_no);
    }

    // Print results

    return 0;
}