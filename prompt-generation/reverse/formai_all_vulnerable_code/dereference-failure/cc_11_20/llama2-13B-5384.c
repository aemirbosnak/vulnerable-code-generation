//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 10

struct guest {
    char name[20];
    int arrival_date;
    int departure_date;
    int room_number;
};

struct room {
    char name[20];
    int capacity;
    int occupied;
};

struct hotel {
    char name[20];
    struct room rooms[MAX_ROOMS];
};

int main() {
    struct hotel *hotel;
    struct guest *guest;
    int i, j;

    // Initialize hotel
    hotel = (struct hotel *) malloc(sizeof(struct hotel));
    strcpy(hotel->name, "Castlekeep Inn");
    for (i = 0; i < MAX_ROOMS; i++) {
        hotel->rooms[i].name[0] = '\0';
        hotel->rooms[i].capacity = 0;
        hotel->rooms[i].occupied = 0;
    }

    // Register guests
    while (1) {
        printf("Welcome, traveler! What is your name and destination? ");
        scanf("%s %d", guest->name, &guest->arrival_date);
        if (strcmp(guest->name, "Sir Cedric") == 0) {
            printf("Hail, Sir Cedric! I have a special room for thee. ");
            guest->room_number = 1;
        } else {
            for (i = 0; i < MAX_ROOMS; i++) {
                if (hotel->rooms[i].capacity > 0) {
                    guest->room_number = i + 1;
                    break;
                }
            }
        }
        if (guest->room_number == 0) {
            printf("Alas, all rooms are full! Wouldst thou like to wait for a room to become available? (y/n) ");
            scanf(" %c", &guest->name);
            if (guest->name == 'y') {
                printf("Patience, good sir/madam! I shall notify thee when a room becomes available. ");
                continue;
            }
        }
        break;
    }

    // Manage room occupancy
    for (i = 0; i < MAX_ROOMS; i++) {
        if (hotel->rooms[i].occupied < hotel->rooms[i].capacity) {
            hotel->rooms[i].occupied++;
        }
    }

    // Check for overbooking
    for (i = 0; i < MAX_ROOMS; i++) {
        if (hotel->rooms[i].occupied >= hotel->rooms[i].capacity) {
            printf("Oops! The castle is full! No more guests can be accommodated. ");
            break;
        }
    }

    // Print room occupancy
    for (i = 0; i < MAX_ROOMS; i++) {
        printf("%d. %s (%d occupied)\n", i + 1, hotel->rooms[i].name, hotel->rooms[i].occupied);
    }

    // Check for and handle special requests
    printf("Do thou have any special requests, such as a fireplace or a balcony? (y/n) ");
    scanf(" %c", &guest->name);
    if (guest->name == 'y') {
        printf("Verily, I shall do my best to accommodate thee. ");
        // Special request handling logic here
    }

    // Check for and handle no-shows
    for (i = 0; i < MAX_ROOMS; i++) {
        if (hotel->rooms[i].occupied == 0) {
            printf("Hark! A room is available. Who shall be the lucky guest? ");
            // No-show handling logic here
        }
    }

    // Print final room occupancy
    for (i = 0; i < MAX_ROOMS; i++) {
        printf("%d. %s (%d occupied)\n", i + 1, hotel->rooms[i].name, hotel->rooms[i].occupied);
    }

    return 0;
}