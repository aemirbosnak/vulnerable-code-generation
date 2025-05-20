//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define ROOM_CAPACITY 2

typedef struct {
    int room_number;
    int is_occupied;
    char guest_name[50];
} Room;

void print_menu();
void manage_rooms(Room rooms[MAX_ROOMS]);
void check_in(Room *room, char *guest_name);
void check_out(Room *room);

int main() {
    Room hotel[MAX_ROOMS];
    int choice;

    for (int i = 0; i < MAX_ROOMS; i++) {
        hotel[i].room_number = i + 1;
        hotel[i].is_occupied = 0;
    }

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manage_rooms(hotel);
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Manage Rooms\n");
    printf("2. Exit\n");
}

void manage_rooms(Room rooms[MAX_ROOMS]) {
    int room_number;
    char guest_name[50];
    int operation;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    if (room_number < 1 || room_number > MAX_ROOMS) {
        printf("Invalid room number! Please try again.\n");
        return;
    }

    rooms[room_number - 1].room_number = room_number;

    printf("Choose operation:\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            printf("Enter guest name: ");
            scanf("%s", guest_name);
            check_in(&(rooms[room_number - 1]), guest_name);
            break;
        case 2:
            check_out(&(rooms[room_number - 1]));
            break;
        default:
            printf("Invalid operation! Please try again.\n");
    }
}

void check_in(Room *room, char *guest_name) {
    if (room->is_occupied) {
        printf("Room %d is already occupied!\n", room->room_number);
        return;
    }

    room->is_occupied = 1;
    strcpy(room->guest_name, guest_name);

    printf("Check-in successful for room %d with guest %s!\n", room->room_number, guest_name);
}

void check_out(Room *room) {
    if (!room->is_occupied) {
        printf("Room %d is not occupied!\n", room->room_number);
        return;
    }

    room->is_occupied = 0;

    printf("Check-out successful for room %d!\n", room->room_number);
}