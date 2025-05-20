//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void display_guests() {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status != 'X') {
            printf("%s in room %d\n", guests[i].name, guests[i].room_no);
        }
    }
}

void check_in(char* name, int room_no) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'O' && guests[i].name == name) {
            printf("Error: Room already occupied.\n");
            return;
        }
    }

    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'X') {
            guests[i].status = 'O';
            strcpy(guests[i].name, name);
            guests[i].room_no = room_no;
            printf("Welcome, %s, to room %d.\n", name, room_no);
            return;
        }
    }

    printf("Error: No available rooms.\n");
}

void check_out(char* name) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].status == 'O' && guests[i].name == name) {
            guests[i].status = 'X';
            printf("Goodbye, %s.\n", name);
            return;
        }
    }

    printf("Error: Guest not found.\n");
}

int main() {
    char command;
    char name[50];
    int room_no;

    printf("Welcome to the Grand Hotel!\n");

    while (1) {
        printf("Enter command (C/c, R/r, O/o, Q/q): ");
        scanf("%c", &command);

        switch (command) {
            case 'C':
            case 'c':
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter room number: ");
                scanf("%d", &room_no);
                check_in(name, room_no);
                break;
            case 'R':
            case 'r':
                printf("Enter your name: ");
                scanf("%s", name);
                check_out(name);
                break;
            case 'O':
            case 'o':
                display_guests();
                break;
            case 'Q':
            case 'q':
                printf("Thank you for staying at the Grand Hotel.\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}