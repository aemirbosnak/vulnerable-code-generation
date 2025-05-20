//FormAI DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <string.h>

// Structure to store hotel room information
struct Room {
    int roomNumber;
    int price;
    int capacity;
    char type[20];
    char status[20];
};

// Function to create new rooms
void createRoom(struct Room *room, int i) {
    printf("Enter room number for room %d: ", i);
    scanf("%d", &room->roomNumber);
    printf("Enter price per night for room %d: ", i);
    scanf("%d", &room->price);
    printf("Enter capacity of room %d: ", i);
    scanf("%d", &room->capacity);
    printf("Enter type of room %d (Single/Double): ", i);
    scanf("%s", room->type);
    strcpy(room->status, "Available");
}

// Function to display all available rooms
void displayAvailableRooms(struct Room *roomList, int numRooms) {
    printf("\n--- Available Rooms ---\n");
    for(int i=0; i<numRooms; i++) {
        if(strcmp(roomList[i].status, "Available") == 0) {
            printf("Room Number: %d\n", roomList[i].roomNumber);
            printf("Price per night: %d\n", roomList[i].price);
            printf("Capacity: %d\n", roomList[i].capacity);
            printf("Type: %s\n\n", roomList[i].type);
        }
    }
}

// Function to book a room
void bookRoom(struct Room *roomList, int numRooms) {
    int roomNum;
    printf("Enter room number you wish to book: ");
    scanf("%d", &roomNum);
    for(int i=0; i<numRooms; i++) {
        if(roomList[i].roomNumber == roomNum) {
            if(strcmp(roomList[i].status, "Available") == 0) {
                strcpy(roomList[i].status, "Booked");
                printf("\nRoom %d has been booked!\n\n", roomList[i].roomNumber);
            }
            else {
                printf("\nRoom %d is not available.\n\n", roomList[i].roomNumber);
            }
            return;
        }
    }
    printf("\nRoom %d does not exist.\n\n", roomNum);
}

int main() {
    // Initializing hotel room information
    int numRooms = 5;
    struct Room roomList[numRooms];
    for(int i=0; i<numRooms; i++) {
        createRoom(&roomList[i], i+1);
    }

    // Main menu
    int choice;
    do {
        printf("----- C Hotel Management System -----\n");
        printf("1. Display available rooms\n");
        printf("2. Book a room\n");
        printf("3. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayAvailableRooms(roomList, numRooms);
                break;
            case 2:
                bookRoom(roomList, numRooms);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
    } while(choice != 3);

    return 0;
}