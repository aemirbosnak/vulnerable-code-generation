//MISTRAL-7B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50

typedef struct {
    int room_number;
    char status;
    char guest_name[50];
} Room;

void display_menu();
void add_room(Room rooms[], int *num_rooms);
void delete_room(Room rooms[], int *num_rooms);
void display_rooms(Room rooms[], int num_rooms);

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room(rooms, &num_rooms);
                break;
            case 2:
                delete_room(rooms, &num_rooms);
                break;
            case 3:
                display_rooms(rooms, num_rooms);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\nHotel Management System\n");
    printf("1. Add Room\n");
    printf("2. Delete Room\n");
    printf("3. Display Rooms\n");
    printf("0. Exit\n");
}

void add_room(Room rooms[], int *num_rooms) {
    if (*num_rooms == MAX_ROOMS) {
        printf("All rooms are occupied!\n");
        return;
    }

    Room new_room;
    printf("Enter room number: ");
    scanf("%d", &new_room.room_number);

    printf("Enter room status (O for Occupied, V for Vacant): ");
    scanf(" %c", &new_room.status);

    printf("Enter guest name: ");
    scanf("%s", new_room.guest_name);

    rooms[*num_rooms] = new_room;
    (*num_rooms)++;

    printf("Room added successfully!\n");
}

void delete_room(Room rooms[], int *num_rooms) {
    if (*num_rooms == 0) {
        printf("No rooms available!\n");
        return;
    }

    int room_number;
    printf("Enter room number to delete: ");
    scanf("%d", &room_number);

    int index = -1;
    for (int i = 0; i < *num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Room not found!\n");
        return;
    }

    for (int i = index; i < *num_rooms - 1; i++) {
        rooms[i] = rooms[i + 1];
    }

    (*num_rooms)--;

    printf("Room deleted successfully!\n");
}

void display_rooms(Room rooms[], int num_rooms) {
    printf("\nRooms Available:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].status == 'V') {
            printf("Room Number: %d, Guest Name: %s\n", rooms[i].room_number, rooms[i].guest_name);
        }
    }
}