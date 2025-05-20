//FormAI DATASET v1.0 Category: Hotel Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each hotel room
struct Room {
    char roomNumber[10];
    char roomType[15];
    char guestName[30];
    int numOfNights;
    float pricePerNight;
};

// Function to add a new room to the system
void addRoom(struct Room *rooms, int *numOfRooms) {
    printf("Enter room number: ");
    scanf("%s", rooms[*numOfRooms].roomNumber);
    printf("Enter room type: ");
    scanf("%s", rooms[*numOfRooms].roomType);
    printf("Enter price per night: ");
    scanf("%f", &rooms[*numOfRooms].pricePerNight);
    printf("Room added successfully!\n");

    (*numOfRooms)++;
}

// Function to display a list of all the rooms in the system
void displayRooms(struct Room *rooms, int numOfRooms) {
    printf("%-15s %-15s %-15s %-15s %-15s\n", "Room Number", "Room Type", "Guest Name", "Number of Nights", "Price per Night");
    for (int i = 0; i < numOfRooms; i++) {
        printf("%-15s %-15s %-15s %-15d %-15.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].guestName, rooms[i].numOfNights, rooms[i].pricePerNight);
    }
}

// Function to find a room by room number and return the index
int findRoom(struct Room *rooms, int numOfRooms, char *roomNumber) {
    for (int i = 0; i < numOfRooms; i++) {
        if (strcmp(rooms[i].roomNumber, roomNumber) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to check in a guest to a room
void checkIn(struct Room *rooms, int numOfRooms) {
    char roomNumber[10];
    printf("Enter room number: ");
    scanf("%s", roomNumber);

    int roomIndex = findRoom(rooms, numOfRooms, roomNumber);
    if (roomIndex == -1) {
        printf("Room not found!\n");
        return;
    }

    if (strcmp(rooms[roomIndex].guestName, "") != 0) {
        printf("Room is already occupied!\n");
        return;
    }

    printf("Enter guest name: ");
    scanf("%s", rooms[roomIndex].guestName);
    printf("Enter number of nights: ");
    scanf("%d", &rooms[roomIndex].numOfNights);

    printf("Guest checked in successfully!\n");
}

// Function to check out a guest from a room
void checkOut(struct Room *rooms, int numOfRooms) {
    char roomNumber[10];
    printf("Enter room number: ");
    scanf("%s", roomNumber);

    int roomIndex = findRoom(rooms, numOfRooms, roomNumber);
    if (roomIndex == -1) {
        printf("Room not found!\n");
        return;
    }

    if (strcmp(rooms[roomIndex].guestName, "") == 0) {
        printf("Room is not occupied!\n");
        return;
    }

    printf("Guest name: %s\n", rooms[roomIndex].guestName);
    printf("Room charge: %.2f\n", rooms[roomIndex].numOfNights * rooms[roomIndex].pricePerNight);
    strcpy(rooms[roomIndex].guestName, "");
    rooms[roomIndex].numOfNights = 0;
    printf("Guest checked out successfully!\n");
}

int main() {
    struct Room rooms[100];
    int numOfRooms = 0;

    int choice;
    while (1) {
        printf("\n");
        printf("1. Add room\n");
        printf("2. Display rooms\n");
        printf("3. Check in\n");
        printf("4. Check out\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom(rooms, &numOfRooms);
                break;
            case 2:
                displayRooms(rooms, numOfRooms);
                break;
            case 3:
                checkIn(rooms, numOfRooms);
                break;
            case 4:
                checkOut(rooms, numOfRooms);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}