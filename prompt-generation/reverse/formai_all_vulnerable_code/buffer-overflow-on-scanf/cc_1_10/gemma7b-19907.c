//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void check_in(int room_no, char name[]) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].room_no == room_no && guests[i].status == 'O') {
            strcpy(guests[i].name, name);
            guests[i].status = 'C';
            printf("Welcome, %s! You have been checked in to room %d.\n", name, room_no);
            return;
        }
    }

    printf("Sorry, room %d is not available.\n", room_no);
}

void check_out(int room_no) {
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].room_no == room_no && guests[i].status == 'C') {
            guests[i].status = 'O';
            printf("Goodbye, %s. We hope you enjoyed your stay.\n", guests[i].name);
            return;
        }
    }

    printf("Sorry, room %d is not occupied.\n", room_no);
}

int main() {
    int choice;
    char name[50];
    int room_no;

    printf("Please select an option:\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", name);
            printf("Enter the room number: ");
            scanf("%d", &room_no);
            check_in(room_no, name);
            break;
        case 2:
            printf("Enter the room number: ");
            scanf("%d", &room_no);
            check_out(room_no);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}