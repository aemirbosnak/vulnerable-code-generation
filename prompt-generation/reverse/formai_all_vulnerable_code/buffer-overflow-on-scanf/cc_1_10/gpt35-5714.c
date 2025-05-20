//FormAI DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100 // maximum number of rooms for the hotel
#define MAX_NAME_LENGTH 50 // maximum length for guest name

typedef struct {
    int room_number;
    char guest_name[MAX_NAME_LENGTH];
    int num_nights;
    float cost_per_night;
    float total_cost;
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void add_room() {
    if (num_rooms >= MAX_ROOMS) {
        printf("Hotel is full. Cannot add more rooms.\n");
        return;
    }

    printf("Enter room number: ");
    scanf("%d", &rooms[num_rooms].room_number);

    printf("Enter guest name: ");
    scanf("%s", rooms[num_rooms].guest_name);

    printf("Enter number of nights: ");
    scanf("%d", &rooms[num_rooms].num_nights);

    printf("Enter cost per night: ");
    scanf("%f", &rooms[num_rooms].cost_per_night);

    rooms[num_rooms].total_cost = rooms[num_rooms].num_nights * rooms[num_rooms].cost_per_night;

    printf("Room added successfully!\n");
    num_rooms++;
}

void show_room(int room_number) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Guest Name: %s\n", rooms[i].guest_name);
            printf("Number of Nights: %d\n", rooms[i].num_nights);
            printf("Cost per Night: %.2f\n", rooms[i].cost_per_night);
            printf("Total Cost: %.2f\n", rooms[i].total_cost);
            return;
        }
    }

    printf("Room not found!\n");
}

void show_all_rooms() {
    int i;
    for (i = 0; i < num_rooms; i++) {
        printf("Room Number: %d\n", rooms[i].room_number);
        printf("Guest Name: %s\n", rooms[i].guest_name);
        printf("Number of Nights: %d\n", rooms[i].num_nights);
        printf("Cost per Night: %.2f\n", rooms[i].cost_per_night);
        printf("Total Cost: %.2f\n", rooms[i].total_cost);
        printf("\n");
    }

    if (num_rooms == 0) {
        printf("No rooms found!\n");
    }
}

void search_rooms_by_guest_name(char guest_name[MAX_NAME_LENGTH]) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (strcmp(rooms[i].guest_name, guest_name) == 0) {
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Guest Name: %s\n", rooms[i].guest_name);
            printf("Number of Nights: %d\n", rooms[i].num_nights);
            printf("Cost per Night: %.2f\n", rooms[i].cost_per_night);
            printf("Total Cost: %.2f\n", rooms[i].total_cost);
            printf("\n");
        }
    }

    if (num_rooms == 0) {
        printf("No matching rooms found!\n");
    }
}

int main() {
    int choice, room_number;
    char guest_name[MAX_NAME_LENGTH];

    do {
        printf("--------------------------------------------------------\n");
        printf("                          MENU                            \n");
        printf("--------------------------------------------------------\n");
        printf(" 1. Add Room\n");
        printf(" 2. Show Room\n");
        printf(" 3. Show All Rooms\n");
        printf(" 4. Search Rooms by Guest Name\n");
        printf(" 5. Exit\n");
        printf("--------------------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                show_room(room_number);
                break;
            case 3:
                show_all_rooms();
                break;
            case 4:
                printf("Enter guest name: ");
                scanf("%s", guest_name);
                search_rooms_by_guest_name(guest_name);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}