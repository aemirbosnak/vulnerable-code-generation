//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 2

typedef struct Room {
    int room_no;
    char status;
    char guest_name[MAX_GUESTS];
    int num_guests;
    struct Room* next;
} Room;

void insert_room(Room** head) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_no = ++(*head)->room_no;
    new_room->status = 'O';
    new_room->num_guests = 0;
    new_room->next = NULL;

    (*head)->next = new_room;
    *head = new_room;
}

void check_in(Room** head, char* name, int num_guests) {
    Room* current = *head;
    while (current) {
        if (current->status == 'O' && current->num_guests < MAX_GUESTS) {
            current->status = 'B';
            strcpy(current->guest_name, name);
            current->num_guests = num_guests;
            return;
        }
        current = current->next;
    }

    printf("No rooms available.\n");
}

void check_out(Room** head, char* name) {
    Room* current = *head;
    while (current) {
        if (strcmp(current->guest_name, name) == 0) {
            current->status = 'O';
            current->num_guests = 0;
            return;
        }
        current = current->next;
    }

    printf("Guest not found.\n");
}

int main() {
    Room* head = (Room*)malloc(sizeof(Room));
    head = NULL;

    insert_room(&head);
    insert_room(&head);
    insert_room(&head);

    check_in(&head, "John Doe", 2);
    check_in(&head, "Jane Doe", 1);

    check_out(&head, "John Doe");

    return 0;
}