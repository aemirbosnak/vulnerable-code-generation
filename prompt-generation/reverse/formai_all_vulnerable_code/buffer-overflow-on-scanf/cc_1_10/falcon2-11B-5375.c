//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100

struct Room {
    char name[30];
    int price;
    int capacity;
    int occupied;
};

struct Guest {
    char name[30];
    int room_no;
};

int main() {
    struct Room rooms[MAX_ROOMS];
    struct Guest guests[MAX_GUESTS];
    int num_rooms = 0;
    int num_guests = 0;

    printf("Welcome to the C Hotel Management System!\n");
    printf("Please enter the number of rooms: ");
    scanf("%d", &num_rooms);

    for (int i = 0; i < num_rooms; i++) {
        printf("Please enter the name of room %d: ", i+1);
        fgets(rooms[i].name, sizeof(rooms[i].name), stdin);
        rooms[i].price = 0;
        rooms[i].capacity = 0;
        rooms[i].occupied = 0;
    }

    printf("Please enter the number of guests: ");
    scanf("%d", &num_guests);

    for (int i = 0; i < num_guests; i++) {
        printf("Please enter the name of guest %d: ", i+1);
        fgets(guests[i].name, sizeof(guests[i].name), stdin);
        guests[i].room_no = -1;
    }

    for (int i = 0; i < num_guests; i++) {
        printf("Please enter the room number of guest %d: ", i+1);
        scanf("%d", &guests[i].room_no);
    }

    printf("Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].occupied)
            printf("%s - Occupied\n", rooms[i].name);
        else
            printf("%s - Available\n", rooms[i].name);
    }

    printf("Guests:\n");
    for (int i = 0; i < num_guests; i++) {
        if (guests[i].room_no!= -1)
            printf("%s - Room %d\n", guests[i].name, guests[i].room_no);
        else
            printf("%s - Unassigned\n", guests[i].name);
    }

    return 0;
}