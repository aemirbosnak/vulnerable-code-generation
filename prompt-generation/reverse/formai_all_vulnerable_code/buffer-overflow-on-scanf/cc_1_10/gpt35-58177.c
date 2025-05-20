//FormAI DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
    int roomNumber;
    char roomType[10];
    char roomStatus[10];
    int roomPrice;
} Room;

void displayRooms(Room *rooms, int size) {
    printf("Room #\tType\tStatus\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%s\t%d\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].roomStatus, rooms[i].roomPrice);
    }
}

void bookRoom(Room *room) {
    if (strcmp(room->roomStatus, "available") == 0) {
        strcpy(room->roomStatus, "occupied");
        printf("Successfully booked room %d\n", room->roomNumber);
    } else {
        printf("Room %d is not available for booking\n", room->roomNumber);
    }
}

void checkoutRoom(Room *room) {
    if (strcmp(room->roomStatus, "occupied") == 0) {
        strcpy(room->roomStatus, "available");
        printf("Successfully checked out room %d\n", room->roomNumber);
    } else {
        printf("Room %d is not occupied\n", room->roomNumber);
    }
}

int main() {
    int roomCount = 3;
    Room rooms[3] = {
        {101, "standard", "available", 100},
        {102, "deluxe", "occupied", 200},
        {103, "suite", "available", 300}
    };

    int choice, roomNumber;
    do {
        printf("\nChoose an option:\n");
        printf("1. Display all rooms\n");
        printf("2. Book a room\n");
        printf("3. Checkout from a room\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, roomCount);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                for (int i = 0; i < roomCount; i++) {
                    if (rooms[i].roomNumber == roomNumber) {
                        bookRoom(&rooms[i]);
                        break;
                    }
                }
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                for (int i = 0; i < roomCount; i++) {
                    if (rooms[i].roomNumber == roomNumber) {
                        checkoutRoom(&rooms[i]);
                        break;
                    }
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 4);

    return 0;
}