//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    char status[50];
} Guest;

Guest guests[MAX_GUESTS];

void addGuest() {
    Guest newGuest;

    printf("Enter guest name: ");
    scanf("%s", newGuest.name);

    printf("Enter room number: ");
    scanf("%d", &newGuest.room_no);

    printf("Enter guest status: ");
    scanf("%s", newGuest.status);

    for (int i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].room_no == newGuest.room_no) {
            printf("Error: Room number already taken.\n");
            return;
        }
    }

    guests[MAX_GUESTS - 1] = newGuest;
    printf("Guest added successfully.\n");
}

void checkGuest() {
    char guestName[50];

    printf("Enter guest name: ");
    scanf("%s", guestName);

    for (int i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, guestName) == 0) {
            printf("Guest name: %s\n", guests[i].name);
            printf("Room number: %d\n", guests[i].room_no);
            printf("Guest status: %s\n", guests[i].status);
            return;
        }
    }

    printf("Guest not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the Hotel Management System.\n");

    printf("1. Add Guest\n");
    printf("2. Check Guest\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addGuest();
            break;
        case 2:
            checkGuest();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}