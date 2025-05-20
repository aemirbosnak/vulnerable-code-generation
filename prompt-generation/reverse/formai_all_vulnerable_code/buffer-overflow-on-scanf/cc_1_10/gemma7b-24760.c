//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct guest {
    char name[20];
    int room_number;
    struct guest* next;
};

struct room {
    int number;
    int occupancy;
    struct room* next;
};

void insert_guest(struct guest** head) {
    struct guest* new_guest = (struct guest*)malloc(sizeof(struct guest));
    printf("Enter guest name: ");
    scanf("%s", new_guest->name);
    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);
    new_guest->next = NULL;

    if (*head == NULL) {
        *head = new_guest;
    } else {
        (*head)->next = new_guest;
    }
}

void check_room(struct room** head) {
    struct room* current_room = *head;
    int room_number;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    while (current_room) {
        if (current_room->number == room_number) {
            printf("Room is occupied by: %s", current_room->occupancy);
            break;
        } else {
            current_room = current_room->next;
        }
    }

    if (current_room == NULL) {
        printf("Room not found");
    }
}

int main() {
    struct guest* guests = NULL;
    struct room* rooms = NULL;

    insert_guest(&guests);
    insert_guest(&guests);
    insert_guest(&guests);

    check_room(&rooms);
    check_room(&rooms);

    return 0;
}