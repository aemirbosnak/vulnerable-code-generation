//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    int roomFloor;
    int roomSize;
    int roomType;
    char guestName[50];
    char guestContact[20];
};
typedef struct Room Room;

void displayMenu();
void addRoom(Room *rooms, int *totalRooms);
void checkIn(Room *rooms, int totalRooms);
void checkOut(Room *rooms, int totalRooms);

int main() {
    int totalRooms = 0, choice;

    Room *rooms = malloc(sizeof(Room));

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addRoom(rooms, &totalRooms); break;
            case 2: checkIn(rooms, totalRooms); break;
            case 3: checkOut(rooms, totalRooms); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n"); break;
        }

        printf("\n");
    } while(choice != 4);

    free(rooms);

    return 0;
}

void displayMenu() {
    printf("==============================\n");
    printf("       HOTEL MANAGEMENT       \n");
    printf("==============================\n");
    printf("1. Add Room\n");
    printf("2. Check In\n");
    printf("3. Check Out\n");
    printf("4. Exit\n");
}

void addRoom(Room *rooms, int *totalRooms) {
    int roomNumber, roomFloor, roomSize, roomType;
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);
    printf("Enter Room Floor: ");
    scanf("%d", &roomFloor);
    printf("Enter Room Size: ");
    scanf("%d", &roomSize);
    printf("Enter Room Type: ");
    scanf("%d", &roomType);

    rooms[*totalRooms].roomNumber = roomNumber;
    rooms[*totalRooms].roomFloor = roomFloor;
    rooms[*totalRooms].roomSize = roomSize;
    rooms[*totalRooms].roomType = roomType;

    *totalRooms += 1;
    rooms = realloc(rooms, (*totalRooms+1) * sizeof(Room));
    printf("Room added successfully!\n");
}

void checkIn(Room *rooms, int totalRooms) {
    int roomNumber, i, flag = 0;
    char guestName[50], guestContact[20];

    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    for(i=0; i<totalRooms; i++) {
        if(rooms[i].roomNumber == roomNumber) {
            if(strlen(rooms[i].guestName) > 0) {
                printf("Room is already occupied by %s!\n", rooms[i].guestName);
            } else {
                printf("Enter Guest Name: ");
                scanf("%s", guestName);
                printf("Enter Guest Contact: ");
                scanf("%s", guestContact);
                strcpy(rooms[i].guestName, guestName);
                strcpy(rooms[i].guestContact, guestContact);
                printf("Checked in successfully!\n");
            }

            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Invalid room number!\n");
    }
}

void checkOut(Room *rooms, int totalRooms) {
    int roomNumber, i, flag = 0;

    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    for(i=0; i<totalRooms; i++) {
        if(rooms[i].roomNumber == roomNumber) {
            if(strlen(rooms[i].guestName) == 0) {
                printf("No guests are currently checked in to this room!\n");
            } else {
                printf("Guest %s has checked out of room %d.\n", rooms[i].guestName, rooms[i].roomNumber);
                strcpy(rooms[i].guestName, "");
                strcpy(rooms[i].guestContact, "");
            }

            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("Invalid room number!\n");
    }
}