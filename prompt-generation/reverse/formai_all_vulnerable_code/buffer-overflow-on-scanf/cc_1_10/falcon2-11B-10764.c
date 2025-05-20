//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100

typedef struct {
    char name[50];
    int room_number;
} Guest;

typedef struct {
    char name[50];
    int room_number;
    int price;
} Room;

int main() {
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_GUESTS];
    int n_rooms, n_guests, i, j;

    printf("Enter the number of rooms: ");
    scanf("%d", &n_rooms);

    for (i = 0; i < n_rooms; i++) {
        printf("Enter the name of Room %d: ", i + 1);
        scanf("%s", rooms[i].name);
        printf("Enter the price of Room %d: ", i + 1);
        scanf("%d", &rooms[i].price);
        printf("Enter the number of Guests for Room %d: ", i + 1);
        scanf("%d", &rooms[i].room_number);
    }

    printf("Enter the number of Guests: ");
    scanf("%d", &n_guests);

    for (i = 0; i < n_guests; i++) {
        printf("Enter the name of Guest %d: ", i + 1);
        scanf("%s", guests[i].name);
        printf("Enter the Room Number for Guest %d: ", i + 1);
        scanf("%d", &guests[i].room_number);
    }

    printf("Rooms:\n");
    for (i = 0; i < n_rooms; i++) {
        printf("%s\t%d\n", rooms[i].name, rooms[i].room_number);
    }

    printf("Guests:\n");
    for (i = 0; i < n_guests; i++) {
        printf("%s\t%d\n", guests[i].name, guests[i].room_number);
    }

    return 0;
}