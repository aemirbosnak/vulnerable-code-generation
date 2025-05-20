//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_ROOMS 10

typedef struct {
    int room_number;
    int is_occupied;
    char guest_name[50];
    char check_in_date[11];
} Room;

void add_guest(Room *room, char *guest_name) {
    room->is_occupied = 1;
    strcpy(room->guest_name, guest_name);
}

int check_availability(Room *room) {
    return room->is_occupied;
}

void print_room_info(Room *room) {
    printf("Room Number: %d\n", room->room_number);
    if (room->is_occupied) {
        printf("Guest Name: %s\n", room->guest_name);
        printf("Check-in Date: %s\n", room->check_in_date);
    } else {
        printf("Room is vacant.\n");
    }
}

int main() {
    Room rooms[NUM_ROOMS];

    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].room_number = i + 1;
        printf("Enter guest name for Room %d: ", i + 1);
        scanf("%s", rooms[i].guest_name);
        add_guest(&rooms[i], rooms[i].guest_name);
    }

    printf("\nRoom Availability:\n");
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d", i + 1);
        if (check_availability(&rooms[i])) {
            print_room_info(&rooms[i]);
        } else {
            printf(" is occupied.\n");
        }
    }

    return 0;
}