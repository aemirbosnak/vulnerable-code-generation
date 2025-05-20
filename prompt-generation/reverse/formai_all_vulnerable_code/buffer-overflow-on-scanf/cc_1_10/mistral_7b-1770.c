//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NUM_ROOMS 10

typedef struct {
    int number;
    int occupied;
} Room;

void print_room_status(Room rooms[]) {
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d: %s\n", rooms[i].number,
            rooms[i].occupied ? "Occupied" : "Vacant");
    }
}

float calculate_occupancy_rate(Room rooms[]) {
    int num_occupied = 0;
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i].occupied) num_occupied++;
    }
    return (float) num_occupied / NUM_ROOMS;
}

int main() {
    srand(time(NULL));

    Room rooms[NUM_ROOMS];
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].number = i + 1;
        rooms[i].occupied = rand() % 2;
    }

    int choice, room_number;
    while (1) {
        print_room_status(rooms);
        printf("1. Book room\n2. Cancel room\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                if (room_number < 1 || room_number > NUM_ROOMS || rooms[room_number - 1].occupied) {
                    printf("Room not available.\n");
                    continue;
                }
                rooms[room_number - 1].occupied = 1;
                printf("Room %d booked.\n", room_number);
                break;

            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                if (room_number < 1 || room_number > NUM_ROOMS || !rooms[room_number - 1].occupied) {
                    printf("Room not occupied.\n");
                    continue;
                }
                rooms[room_number - 1].occupied = 0;
                printf("Room %d cancelled.\n", room_number);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}