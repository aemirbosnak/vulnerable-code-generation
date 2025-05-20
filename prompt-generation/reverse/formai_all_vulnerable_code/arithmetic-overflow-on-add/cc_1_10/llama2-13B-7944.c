//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20
#define MIN_STAY 1
#define MAX_STAY 30

typedef struct {
    char name[50];
    char room_num[5];
    int check_in;
    int check_out;
    int stay;
} guest_t;

typedef struct {
    char name[50];
    int num_guests;
    int available;
} room_t;

guest_t guests[MAX_GUESTS];
room_t rooms[MAX_ROOMS];

void init_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        strcpy(guests[i].name, "Guest");
        guests[i].check_in = time(NULL);
        guests[i].check_out = guests[i].check_in + MIN_STAY;
        guests[i].stay = (guests[i].check_out - guests[i].check_in) / 60;
    }
}

void init_rooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        strcpy(rooms[i].name, "Room");
        rooms[i].available = 1;
    }
}

void check_in(int guest_num) {
    guest_t *guest = &guests[guest_num];
    if (guest->check_in == 0) {
        guest->check_in = time(NULL);
    }
}

void check_out(int guest_num) {
    guest_t *guest = &guests[guest_num];
    if (guest->check_out == 0) {
        guest->check_out = time(NULL);
        guest->stay += (guest->check_out - guest->check_in) / 60;
    }
}

void assign_room(int guest_num) {
    guest_t *guest = &guests[guest_num];
    room_t *room = &rooms[rand() % MAX_ROOMS];
    if (room->available) {
        strcpy(guest->room_num, room->name);
        room->available = 0;
    }
}

void update_rooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        room_t *room = &rooms[i];
        if (!room->available) {
            room->available = 1;
        }
    }
}

void print_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        guest_t *guest = &guests[i];
        printf("%d. %s (%s) - Check-in: %d, Check-out: %d, Stay: %d hours\n",
            i + 1, guest->name, guest->room_num, guest->check_in, guest->check_out, guest->stay);
    }
}

int main() {
    srand(time(NULL));
    init_guests();
    init_rooms();

    while (1) {
        int guest_num = rand() % MAX_GUESTS;
        assign_room(guest_num);
        check_in(guest_num);
        update_rooms();
        print_guests();
    }

    return 0;
}