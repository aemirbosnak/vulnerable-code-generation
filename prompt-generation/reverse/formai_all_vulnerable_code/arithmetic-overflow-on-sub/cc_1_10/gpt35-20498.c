//FormAI DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to display menu
void displayMenu() {
    printf("\n\n1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Room status\n");
    printf("4. Exit\n");
}

// Function for check-in
void checkIn(int rooms[], int room_number) {
    if (rooms[room_number - 1] == 0) {
        printf("\nRoom %d is available for check-in.\n", room_number);
        printf("Please enter the guest name: ");
        char guest_name[20];
        scanf("%s", guest_name);
        rooms[room_number - 1] = 1; // Update room status as occupied
        printf("Guest %s is checked in to room %d.\n", guest_name, room_number);
    } else {
        printf("Sorry, room %d is already occupied.\n", room_number);
    }
}

// Function for check-out
void checkOut(int rooms[], int room_number) {
    if (rooms[room_number - 1] == 1) {
        rooms[room_number - 1] = 0; // Update room status as vacant
        printf("\nRoom %d is checked-out successfully.\n", room_number);
    } else {
        printf("\nSorry, room %d is already vacant.\n", room_number);
    }
}

// Function for room status
void roomStatus(int rooms[]) {
    printf("\n\nRoom Status:\n");
    for (int i = 0; i < 10; i++) {
        printf("Room %d: ", i + 1);
        if (rooms[i] == 0) {
            printf("Vacant\n");
        } else {
            printf("Occupied\n");
        }
    }
}

int main() {
    int rooms[10] = {0}; // Initialize all rooms as vacant
    int choice, room_number;

    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Check-in
                printf("\nEnter the room number: ");
                scanf("%d", &room_number);
                checkIn(rooms, room_number);
                break;

            case 2: // Check-out
                printf("\nEnter the room number: ");
                scanf("%d", &room_number);
                checkOut(rooms, room_number);
                break;

            case 3: // Room status
                roomStatus(rooms);
                break;

            case 4: // Exit
                printf("\nThank you for using the hotel management system.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}