//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
    char name[50];
    int room_num;
    struct Guest* next;
} Guest;

typedef struct Room {
    int room_num;
    int occupancy;
    struct Room* next;
} Room;

Guest* insert_guest(Guest* head) {
    Guest* new_guest = (Guest*)malloc(sizeof(Guest));
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_num);
    new_guest->next = head;
    return new_guest;
}

Room* insert_room(Room* head) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    printf("Enter room number: ");
    scanf("%d", &new_room->room_num);
    new_room->occupancy = 0;
    new_room->next = head;
    return new_room;
}

void check_in(Guest* head, Room* head_room) {
    char guest_name[50];
    int room_num;
    printf("Enter guest name: ");
    scanf("%s", guest_name);
    Guest* current_guest = head;
    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            printf("Enter room number: ");
            scanf("%d", &room_num);
            Room* current_room = head_room;
            while (current_room) {
                if (current_room->room_num == room_num && current_room->occupancy == 0) {
                    current_room->occupancy = 1;
                    current_guest->room_num = room_num;
                    printf("Room assigned: %d", room_num);
                    return;
                }
            }
            printf("Room not available");
            return;
        }
        current_guest = current_guest->next;
    }
    printf("Guest not found");
    return;
}

void check_out(Guest* head, Room* head_room) {
    char guest_name[50];
    int room_num;
    printf("Enter guest name: ");
    scanf("%s", guest_name);
    Guest* current_guest = head;
    while (current_guest) {
        if (strcmp(current_guest->name, guest_name) == 0) {
            printf("Enter room number: ");
            scanf("%d", &room_num);
            Room* current_room = head_room;
            while (current_room) {
                if (current_room->room_num == room_num && current_room->occupancy == 1) {
                    current_room->occupancy = 0;
                    current_guest->room_num = 0;
                    printf("Room vacated: %d", room_num);
                    return;
                }
            }
            printf("Room not found");
            return;
        }
        current_guest = current_guest->next;
    }
    printf("Guest not found");
    return;
}

int main() {
    Guest* head_guest = NULL;
    Room* head_room = NULL;

    // Insert guests and rooms
    insert_guest(head_guest);
    insert_guest(head_guest);
    insert_room(head_room);
    insert_room(head_room);

    // Check in a guest
    check_in(head_guest, head_room);

    // Check out a guest
    check_out(head_guest, head_room);

    return 0;
}