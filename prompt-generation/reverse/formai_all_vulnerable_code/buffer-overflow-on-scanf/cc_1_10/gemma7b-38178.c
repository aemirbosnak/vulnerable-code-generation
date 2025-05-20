//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

struct Room {
    int number;
    char status;
    struct Guest {
        char name[50];
        int room_number;
        struct Reservation {
            char date[50];
            int duration;
            float cost;
        } reservation;
    } guest;
} room;

void create_room(struct Room *room) {
    room->number = rand() % MAX_ROOMS + 1;
    room->status = 'O';
    room->guest.name[0] = '\0';
    room->guest.room_number = 0;
    room->guest.reservation.date[0] = '\0';
    room->guest.reservation.duration = 0;
    room->guest.reservation.cost = 0.0f;
}

void check_in(struct Room *room) {
    printf("Enter your name: ");
    scanf("%s", room->guest.name);
    room->guest.room_number = room->number;
    room->status = 'H';
}

void check_out(struct Room *room) {
    room->status = 'O';
    room->guest.name[0] = '\0';
    room->guest.room_number = 0;
    room->guest.reservation.date[0] = '\0';
    room->guest.reservation.duration = 0;
    room->guest.reservation.cost = 0.0f;
}

int main() {
    struct Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        create_room(&rooms[i]);
    }

    int choice;
    printf("1. Check in\n2. Check out\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            check_in(&rooms[0]);
            break;
        case 2:
            check_out(&rooms[0]);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}