//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a room
typedef struct Room {
    int room_no;
    char type;
    int available;
    struct Room *next;
} Room;

// Define a function to insert a room at the end
void insertRoom(Room **head) {
    Room *newRoom = (Room *)malloc(sizeof(Room));
    newRoom->room_no = 101 + (*head)->room_no;
    newRoom->type = 'A';
    newRoom->available = 1;
    newRoom->next = NULL;

    if (*head == NULL) {
        *head = newRoom;
    } else {
        ((*head)->next) = newRoom;
    }
}

// Define a function to check if a room is available
int isRoomAvailable(int room_no, Room *head) {
    Room *currentRoom = head;

    while (currentRoom) {
        if (currentRoom->room_no == room_no && currentRoom->available) {
            return 1;
        }
        currentRoom = currentRoom->next;
    }

    return 0;
}

// Define a function to book a room
void bookRoom(int room_no, Room *head) {
    Room *currentRoom = head;

    while (currentRoom) {
        if (currentRoom->room_no == room_no && currentRoom->available) {
            currentRoom->available = 0;
            printf("Room booked successfully.\n");
            return;
        }
        currentRoom = currentRoom->next;
    }

    printf("Room not available.\n");
}

int main() {
    Room *head = NULL;
    insertRoom(&head);
    insertRoom(&head);
    insertRoom(&head);

    if (isRoomAvailable(1, head)) {
        bookRoom(1, head);
    }

    if (isRoomAvailable(2, head)) {
        bookRoom(2, head);
    }

    if (isRoomAvailable(3, head)) {
        bookRoom(3, head);
    }

    return 0;
}