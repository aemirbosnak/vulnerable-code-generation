//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 10

typedef struct {
    char name[50];
    int num_guests;
    int room_number;
} guest_t;

typedef struct {
    char name[20];
    int num_guests;
} room_t;

void add_guest(guest_t *guest, int room_number) {
    if (room_number == -1) {
        printf("No available rooms found\n");
        return;
    }

    if (guest->num_guests >= MAX_GUESTS) {
        printf("Room %d is full\n", room_number);
        return;
    }

    guest->room_number = room_number;
    guest->num_guests++;

    if (room_number == 0) {
        printf("Welcome, %s! You have been assigned room %d\n", guest->name, room_number);
    } else {
        printf("Welcome, %s! You have been assigned room %d\n", guest->name, room_number);
    }

    if (guest->num_guests == MAX_GUESTS) {
        printf("Room %d is full\n", room_number);
    }
}

void check_in(guest_t *guest) {
    if (guest->room_number == -1) {
        printf("No available rooms found\n");
        return;
    }

    if (guest->num_guests >= MAX_GUESTS) {
        printf("Room %d is full\n", guest->room_number);
        return;
    }

    guest->num_guests++;

    if (guest->num_guests == MAX_GUESTS) {
        printf("Room %d is full\n", guest->room_number);
    }
}

void check_out(guest_t *guest) {
    if (guest->room_number == -1) {
        printf("No available rooms found\n");
        return;
    }

    guest->num_guests--;

    if (guest->num_guests == 0) {
        printf("Room %d is now available\n", guest->room_number);
    }
}

void manage_rooms(int num_guests) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        room_t room;
        room.num_guests = 0;
        room.name[0] = '\0';

        if (i == 0) {
            room.name[0] = 'A';
        } else if (i == 1) {
            room.name[0] = 'B';
        } else if (i == 2) {
            room.name[0] = 'C';
        }

        for (int j = 0; j < num_guests; j++) {
            add_guest(&room, i);
        }

        if (room.num_guests == 0) {
            room.name[0] = 'F';
        }

        manage_rooms(room.num_guests);
    }
}

int main() {
    int num_guests = 5;
    guest_t guests[5];

    for (int i = 0; i < 5; i++) {
        strcpy(guests[i].name, "Guest ");
        guests[i].num_guests = 0;
    }

    manage_rooms(num_guests);

    return 0;
}