//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Hotel {
    char name[100];
    int capacity;
    int occupancy;
    int rooms[100];
} Hotel;

void initialize_hotel(Hotel* h) {
    memset(h, 0, sizeof(Hotel));
    srand(time(NULL));
    for (int i = 0; i < h->capacity; i++) {
        h->rooms[i] = rand() % (h->capacity - i);
    }
}

void display_hotel_info(Hotel* h) {
    printf("Hotel: %s\n", h->name);
    printf("Capacity: %d\n", h->capacity);
    printf("Occupancy: %d\n", h->occupancy);
    printf("Rooms: ");
    for (int i = 0; i < h->capacity; i++) {
        printf("%d ", h->rooms[i]);
    }
    printf("\n");
}

void check_in(Hotel* h, int room_number) {
    if (room_number < 0 || room_number >= h->capacity) {
        printf("Invalid room number.\n");
        return;
    }
    if (h->rooms[room_number] == 0) {
        h->rooms[room_number] = 1;
        h->occupancy++;
        printf("Checked in to room %d.\n", room_number);
    } else {
        printf("Room %d is already occupied.\n", room_number);
    }
}

void check_out(Hotel* h, int room_number) {
    if (room_number < 0 || room_number >= h->capacity) {
        printf("Invalid room number.\n");
        return;
    }
    if (h->rooms[room_number] == 1) {
        h->rooms[room_number] = 0;
        h->occupancy--;
        printf("Checked out from room %d.\n", room_number);
    } else {
        printf("Room %d is not occupied.\n", room_number);
    }
}

int main() {
    Hotel h;
    initialize_hotel(&h);
    display_hotel_info(&h);

    while (1) {
        printf("Enter command:\n");
        char cmd[100];
        scanf(" %s", cmd);

        if (strcmp(cmd, "info") == 0) {
            display_hotel_info(&h);
        } else if (strcmp(cmd, "checkin") == 0) {
            char room_number[10];
            scanf(" %s", room_number);
            check_in(&h, atoi(room_number));
        } else if (strcmp(cmd, "checkout") == 0) {
            char room_number[10];
            scanf(" %s", room_number);
            check_out(&h, atoi(room_number));
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}