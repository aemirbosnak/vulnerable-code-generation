//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 100
#define ROOM_TYPE_LENGTH 20
#define NAME_LENGTH 100

typedef struct {
    int roomNumber;
    char roomType[ROOM_TYPE_LENGTH];
    int isBooked; // 0 for available, 1 for booked
    char occupantName[NAME_LENGTH];
} Room;

Room hotelRooms[MAX_ROOMS];
int roomCount = 0;

void addRoom(int roomNumber, const char* roomType) {
    if (roomCount >= MAX_ROOMS) {
        printf("Unable to add more rooms. Maximum limit reached.\n");
        return;
    }
    hotelRooms[roomCount].roomNumber = roomNumber;
    strncpy(hotelRooms[roomCount].roomType, roomType, ROOM_TYPE_LENGTH - 1);
    hotelRooms[roomCount].roomType[ROOM_TYPE_LENGTH - 1] = '\0'; // Ensure null-termination
    hotelRooms[roomCount].isBooked = 0; // Room is initially available
    roomCount++;
    printf("Room %d of type %s added successfully.\n", roomNumber, roomType);
}

void bookRoom(int roomNumber, const char* name) {
    for (int i = 0; i < roomCount; i++) {
        if (hotelRooms[i].roomNumber == roomNumber) {
            if (hotelRooms[i].isBooked) {
                printf("Room %d is already booked.\n", roomNumber);
                return;
            }
            hotelRooms[i].isBooked = 1; // Mark room as booked
            strncpy(hotelRooms[i].occupantName, name, NAME_LENGTH - 1);
            hotelRooms[i].occupantName[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
            printf("Room %d booked successfully by %s.\n", roomNumber, name);
            return;
        }
    }
    printf("Room %d not found.\n", roomNumber);
}

void displayAvailableRooms() {
    printf("Available Rooms:\n");
    int found = 0;
    for (int i = 0; i < roomCount; i++) {
        if (!hotelRooms[i].isBooked) {
            printf("Room Number: %d, Room Type: %s\n", hotelRooms[i].roomNumber, hotelRooms[i].roomType);
            found = 1;
        }
    }
    if (!found) {
        printf("No available rooms.\n");
    }
}

int main() {
    int choice, roomNumber;
    char roomType[ROOM_TYPE_LENGTH];
    char name[NAME_LENGTH];

    while (1) {
        printf("\n---- Hotel Management System ----\n");
        printf("1. Add Room\n");
        printf("2. Book Room\n");
        printf("3. Display Available Rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Room Number: ");
                scanf("%d", &roomNumber);
                printf("Enter Room Type: ");
                scanf("%s", roomType);
                addRoom(roomNumber, roomType);
                break;

            case 2:
                printf("Enter Room Number to Book: ");
                scanf("%d", &roomNumber);
                printf("Enter Occupant Name: ");
                scanf("%s", name);
                bookRoom(roomNumber, name);
                break;

            case 3:
                displayAvailableRooms();
                break;

            case 4:
                printf("Exiting the system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}