//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int room_number;
    int occupied;
    char guest_name[MAX_NAME_LENGTH];
} Room;

int main() {
    Room hotel[MAX_ROOMS];
    int num_rooms, choice, room_choice;
    char guest_name[MAX_NAME_LENGTH];

    printf("Welcome to the C Hotel Management System!\n");
    printf("Please enter the number of rooms in the hotel: ");
    scanf("%d", &num_rooms);

    for (int i = 0; i < num_rooms; i++) {
        hotel[i].room_number = i + 1;
        hotel[i].occupied = 0;
        strcpy(hotel[i].guest_name, "");
    }

    while (1) {
        printf("\n\n\n");
        printf("1. Check-In\n");
        printf("2. Check-Out\n");
        printf("3. View Room Status\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the room number for check-in: ");
                scanf("%d", &room_choice);
                if (room_choice < 1 || room_choice > num_rooms) {
                    printf("Invalid room number.\n");
                    break;
                }

                if (hotel[room_choice - 1].occupied) {
                    printf("Room already occupied.\n");
                    break;
                }

                printf("Enter guest name: ");
                scanf("%s", guest_name);
                strcpy(hotel[room_choice - 1].guest_name, guest_name);
                hotel[room_choice - 1].occupied = 1;
                printf("Check-in successful.\n");
                break;
            case 2:
                printf("Enter the room number for check-out: ");
                scanf("%d", &room_choice);
                if (room_choice < 1 || room_choice > num_rooms) {
                    printf("Invalid room number.\n");
                    break;
                }

                if (!hotel[room_choice - 1].occupied) {
                    printf("Room not occupied.\n");
                    break;
                }

                printf("Guest %s checked out of room %d.\n", hotel[room_choice - 1].guest_name, room_choice);
                strcpy(hotel[room_choice - 1].guest_name, "");
                hotel[room_choice - 1].occupied = 0;
                break;
            case 3:
                printf("| %-11s| %-15s| %-15s|\n", "Room Number", "Guest Name", "Status");
                for (int i = 0; i < num_rooms; i++) {
                    printf("| %-11d| %-15s| %-15s|\n", hotel[i].room_number, hotel[i].guest_name, (hotel[i].occupied ? "Occupied" : "Not Occupied"));
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
        }
    }

    return 0;
}