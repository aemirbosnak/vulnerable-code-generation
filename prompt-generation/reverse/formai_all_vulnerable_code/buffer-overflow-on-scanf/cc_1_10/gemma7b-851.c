//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void manage_guests() {
    int i;

    for (i = 0; i < MAX_GUESTS; i++) {
        printf("Name: %s, Room Number: %d, Status: %c\n", guests[i].name, guests[i].room_number, guests[i].status);
    }
}

void check_in(char* name, int room_number) {
    int i;

    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].room_number == room_number) {
            printf("Error: Room already occupied.\n");
            return;
        }
    }

    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'F') {
            strcpy(guests[i].name, name);
            guests[i].room_number = room_number;
            guests[i].status = 'O';
            printf("Welcome, %s! You have been assigned to room %d.\n", name, room_number);
            return;
        }
    }

    printf("Error: No available rooms.\n");
}

void check_out(char* name) {
    int i;

    for (i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            guests[i].status = 'F';
            printf("Thank you for your stay, %s. We hope to see you again.\n", name);
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

int main() {
    char command;
    char name[20];
    int room_number;

    printf("C Hotel Management System\n");

    while (1) {
        printf("Enter command (C/I/O/Q): ");
        scanf("%c", &command);

        switch (command) {
            case 'C':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter room number: ");
                scanf("%d", &room_number);
                check_in(name, room_number);
                break;
            case 'I':
                printf("Enter name: ");
                scanf("%s", name);
                check_out(name);
                break;
            case 'O':
                manage_guests();
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}