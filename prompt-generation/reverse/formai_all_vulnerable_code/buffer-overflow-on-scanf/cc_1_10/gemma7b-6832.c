//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 2

typedef struct Room {
    int number;
    char status;
    struct Guest {
        char name[MAX_GUESTS];
        int room_number;
    } guests[MAX_GUESTS];
} Room;

Room rooms[MAX_ROOMS];

void initialize_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].number = i + 1;
        rooms[i].status = 'O';
        rooms[i].guests[0].name[0] = '\0';
        rooms[i].guests[0].room_number = 0;
    }
}

void check_in(char *name, int room_number) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].number == room_number && rooms[i].status == 'O') {
            rooms[i].guests[0].name[0] = name[0];
            rooms[i].guests[0].room_number = room_number;
            rooms[i].status = 'B';
            printf("Welcome, %s, to room %d!\n", name, room_number);
            return;
        }
    }

    printf("Sorry, room number %d is not available.\n", room_number);
}

void check_out(char *name) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].guests[0].name[0] == name[0]) {
            rooms[i].guests[0].name[0] = '\0';
            rooms[i].guests[0].room_number = 0;
            rooms[i].status = 'O';
            printf("Goodbye, %s!\n", name);
            return;
        }
    }

    printf("Sorry, %s is not registered.\n", name);
}

int main() {
    initialize_rooms();

    char command;
    char name[MAX_GUESTS];
    int room_number;

    printf("Enter command (C/c/O/o): ");
    scanf("%c", &command);

    switch (command) {
        case 'C':
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter room number: ");
            scanf("%d", &room_number);
            check_in(name, room_number);
            break;
        case 'O':
            printf("Enter your name: ");
            scanf("%s", name);
            check_out(name);
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}