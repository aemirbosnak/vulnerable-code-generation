//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_no;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void manage_guests() {
    int i, j, found = 0;
    char name[20];

    printf("Enter guest name: ");
    scanf("%s", name);

    for (i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Guest found: %s, Room No: %d, Status: %c\n", guests[i].name, guests[i].room_no, guests[i].status);
    } else {
        printf("Guest not found.\n");
    }
}

int main() {
    int choice;

    printf("C Hotel Management System\n");
    printf("1. Manage Guests\n");
    printf("2. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            manage_guests();
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}