//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_STAY_DAYS 100

typedef struct {
    int room_number;
    char name[50];
    int stay_days;
} Guest;

typedef struct {
    int room_number;
    int is_available;
} Room;

Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];

int main() {
    int num_rooms, num_guests;

    printf("Enter the number of rooms: ");
    scanf("%d", &num_rooms);

    printf("Enter the number of guests: ");
    scanf("%d", &num_guests);

    int i, j;
    for (i = 0; i < num_rooms; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].is_available = 1;
    }

    for (i = 0; i < num_guests; i++) {
        printf("Enter the name of guest %d: ", i + 1);
        scanf("%s", guests[i].name);
        printf("Enter the room number for guest %s: ", guests[i].name);
        scanf("%d", &guests[i].room_number);
        printf("Enter the number of stay days for guest %s: ", guests[i].name);
        scanf("%d", &guests[i].stay_days);

        int room_number = guests[i].room_number - 1;
        if (room_number >= 0 && room_number < num_rooms) {
            rooms[room_number].is_available = 0;
        }
    }

    printf("\nRoom Status:\n");
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].is_available) {
            printf("%d is available\n", rooms[i].room_number);
        } else {
            printf("%d is occupied by %s for %d days\n", rooms[i].room_number, guests[rooms[i].room_number - 1].name, guests[rooms[i].room_number - 1].stay_days);
        }
    }

    return 0;
}