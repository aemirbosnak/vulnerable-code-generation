//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define NAME_LENGTH 30

typedef struct {
    int room_number;
    char guest_name[NAME_LENGTH];
    int is_occupied;
} Room;

void check_in(Room *rooms, int room_number, const char *guest_name) {
    if (rooms[room_number].is_occupied) {
        printf("Oh, lament! The room %d is taken, dear guest.\n", room_number + 1);
    } else {
        rooms[room_number].is_occupied = 1;
        strcpy(rooms[room_number].guest_name, guest_name);
        printf("Hark! The guest %s has been graciously welcomed into room %d.\n", guest_name, room_number + 1);
    }
}

void check_out(Room *rooms, int room_number) {
    if (rooms[room_number].is_occupied) {
        printf("Alas! The guest %s has departed from room %d.\n", rooms[room_number].guest_name, room_number + 1);
        rooms[room_number].is_occupied = 0;
        strcpy(rooms[room_number].guest_name, "");
    } else {
        printf("Oh, wherefore art thou? Room %d is already empty.\n", room_number + 1);
    }
}

void display_rooms(Room *rooms) {
    printf("\nRoom Status:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i].is_occupied ? rooms[i].guest_name : "Vacant");
    }
}

int main() {
    Room rooms[MAX_ROOMS] = {0};
    int choice, room_number;
    char guest_name[NAME_LENGTH];

    do {
        printf("\n--- Welcome to Verona Inn ---\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Display Rooms\n");
        printf("4. Exit\n");
        printf("Choose thy fate: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number (1-%d): ", MAX_ROOMS);
                scanf("%d", &room_number);
                room_number -= 1; // Adjust for zero-based index
                
                if (room_number >= 0 && room_number < MAX_ROOMS) {
                    printf("Enter thy name: ");
                    scanf(" %[^\n]%*c", guest_name); // Read string with spaces
                    check_in(rooms, room_number, guest_name);
                } else {
                    printf("Alas! Invalid room number.\n");
                }
                break;

            case 2:
                printf("Enter room number to check out (1-%d): ", MAX_ROOMS);
                scanf("%d", &room_number);
                room_number -= 1; // Adjust for zero-based index
                
                if (room_number >= 0 && room_number < MAX_ROOMS) {
                    check_out(rooms, room_number);
                } else {
                    printf("Alas! Invalid room number.\n");
                }
                break;

            case 3:
                display_rooms(rooms);
                break;

            case 4:
                printf("Farewell! Until we meet again in the world of love and dreams.\n");
                break;

            default:
                printf("Prithee! Choose a valid option.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}