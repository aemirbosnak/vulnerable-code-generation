//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[20];
    int room_number;
    char status;
} Guest;

Guest guests[MAX_GUESTS];

void update_guest_status(int guest_id, char status) {
    guests[guest_id].status = status;
}

int main() {
    int i, guest_id, choice;
    char status;

    // Initialize guests
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_number = 0;
        guests[i].status = 'O';
    }

    // Main loop
    while (1) {
        // Display options
        printf("1. Check in\n");
        printf("2. Check out\n");
        printf("3. Change status\n");
        printf("4. List guests\n");
        printf("Enter your choice: ");

        // Get user choice
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get guest name and room number
                printf("Enter your name: ");
                scanf("%s", guests[guest_id].name);

                printf("Enter your room number: ");
                scanf("%d", &guests[guest_id].room_number);

                // Update guest status
                update_guest_status(guest_id, 'H');
                break;
            case 2:
                // Get guest id
                printf("Enter your guest ID: ");
                scanf("%d", &guest_id);

                // Update guest status
                update_guest_status(guest_id, 'O');
                break;
            case 3:
                // Get guest id
                printf("Enter your guest ID: ");
                scanf("%d", &guest_id);

                // Get new status
                printf("Enter new status: ");
                scanf("%c", &status);

                // Update guest status
                update_guest_status(guest_id, status);
                break;
            case 4:
                // List guests
                for (i = 0; i < MAX_GUESTS; i++) {
                    if (guests[i].name[0] != '\0') {
                        printf("Name: %s, Room number: %d, Status: %c\n", guests[i].name, guests[i].room_number, guests[i].status);
                    }
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}