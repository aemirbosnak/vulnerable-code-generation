//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_number;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void manage_guests() {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        printf("%s - Room No. %d, Status: %c\n", guests[i].name, guests[i].room_number, guests[i].status);
    }
}

int main() {
    int i, choice;
    char name[50];
    int room_number;
    char status;

    // Initialize guests
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].status = 'O';
    }

    // Main loop
    while (1) {
        // Display menu options
        printf("1. Register Guest\n");
        printf("2. Check Guest Status\n");
        printf("3. Exit\n");

        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Register guest
                printf("Enter guest name: ");
                scanf("%s", guests[i].name);

                printf("Enter room number: ");
                scanf("%d", &guests[i].room_number);

                printf("Enter guest status: ");
                scanf(" %c", &guests[i].status);

                break;
            case 2:
                // Check guest status
                manage_guests();
                break;
            case 3:
                // Exit
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}