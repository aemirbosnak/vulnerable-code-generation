//FormAI DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hotel room structure
typedef struct {
    int roomNumber;
    int capacity;
    char* guestName;
    int isOccupied;
} Room;

// function prototypes
void createRooms(Room rooms[], int numRooms);
void displayRooms(Room rooms[], int numRooms);
void bookRoom(Room rooms[], int numRooms);
void checkOut(Room rooms[], int numRooms);

int main() {
    int numRooms;
    printf("Enter the number of rooms: ");
    scanf("%d", &numRooms);
    // allocate memory for rooms array
    Room* rooms = (Room*)malloc(numRooms * sizeof(Room));
    createRooms(rooms, numRooms);
    int choice;
    do {
        printf("\n--- Hotel Management System Menu ---\n");
        printf("1. Display all rooms\n");
        printf("2. Book a room\n");
        printf("3. Check out of a room\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms);
                break;
            case 3:
                checkOut(rooms, numRooms);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1-4.\n");
                break;
        }
    } while (choice != 4);

    // free memory for rooms array
    for (int i = 0; i < numRooms; i++) {
        free(rooms[i].guestName);
    }
    free(rooms);

    return 0;
}

// function to create rooms and initialize their properties
void createRooms(Room rooms[], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].capacity = rand() % 3 + 1;
        rooms[i].guestName = (char*)malloc(sizeof(char));
        rooms[i].isOccupied = 0;
    }
    printf("%d rooms created successfully.\n", numRooms);
}

// function to display all rooms and their properties
void displayRooms(Room rooms[], int numRooms) {
    printf("\n--- All Rooms ---\n");
    printf("%-10s%-15s%-20s\n", "Room No.", "Capacity", "Guest Name");
    for (int i = 0; i < numRooms; i++) {
        printf("%-10d%-15d%-20s\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].guestName);
    }
}

// function to book a room
void bookRoom(Room rooms[], int numRooms) {
    int roomNum;
    int found = 0;
    printf("Enter the room number you want to book: ");
    scanf("%d", &roomNum);
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNum) {
            found = 1;
            if (rooms[i].isOccupied == 1) {
                printf("Sorry, the room is already occupied.\n");
            } else {
                printf("Enter the name of the guest: ");
                char tempName[20];
                scanf("%s", tempName);
                rooms[i].guestName = (char*)realloc(rooms[i].guestName, strlen(tempName) + 1);
                strcpy(rooms[i].guestName, tempName);
                rooms[i].isOccupied = 1;
                printf("Room %d booked successfully.\n", roomNum);
            }
            break;
        }
    }
    if (!found) {
        printf("Invalid room number. Please enter a valid room number.\n");
    }
}

// function to check out of a room
void checkOut(Room rooms[], int numRooms) {
    int roomNum;
    int found = 0;
    printf("Enter the room number you want to check out of: ");
    scanf("%d", &roomNum);
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNum) {
            found = 1;
            if (rooms[i].isOccupied == 0) {
                printf("The room is not occupied. No check out necessary.\n");
            } else {
                printf("Room %d checked out successfully.\n", roomNum);
                rooms[i].guestName[0] = '\0';
                rooms[i].isOccupied = 0;
            }
            break;
        }
    }
    if (!found) {
        printf("Invalid room number. Please enter a valid room number.\n");
    }
}