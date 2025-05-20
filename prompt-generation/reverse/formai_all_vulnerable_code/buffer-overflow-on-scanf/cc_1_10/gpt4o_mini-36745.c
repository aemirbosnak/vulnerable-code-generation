//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    int roomNumber;
    int isAvailable;
    char guestName[MAX_NAME_LENGTH];
} Room;

void initializeHotel(Room* rooms);
void displayAvailableRooms(Room* rooms);
void bookRoom(Room* rooms);
void checkOut(Room* rooms);
void saveRoomData(Room* rooms);
void loadRoomData(Room* rooms);

int main() {
    Room rooms[MAX_ROOMS];
    int choice;

    loadRoomData(rooms);
    while (1) {
        printf("\nWelcome to the Hotel Management System\n");
        printf("1. Display Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableRooms(rooms);
                break;
            case 2:
                bookRoom(rooms);
                break;
            case 3:
                checkOut(rooms);
                break;
            case 4:
                saveRoomData(rooms);
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void initializeHotel(Room* rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isAvailable = 1; // All rooms are initially available
        strcpy(rooms[i].guestName, "");
    }
}

void displayAvailableRooms(Room* rooms) {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].isAvailable) {
            printf("Room Number: %d\n", rooms[i].roomNumber);
        }
    }
}

void bookRoom(Room* rooms) {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];

    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);
    printf("Enter guest name: ");
    getchar(); // Consume newline character
    fgets(guestName, MAX_NAME_LENGTH, stdin);
    guestName[strcspn(guestName, "\n")] = 0; // Remove the newline character

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number! Please try again.\n");
        return;
    }

    if (rooms[roomNumber - 1].isAvailable) {
        rooms[roomNumber - 1].isAvailable = 0;
        strcpy(rooms[roomNumber - 1].guestName, guestName);
        printf("Room %d booked successfully for %s.\n", roomNumber, guestName);
    } else {
        printf("Room %d is already booked.\n", roomNumber);
    }
}

void checkOut(Room* rooms) {
    int roomNumber;

    printf("Enter room number to check out: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number! Please try again.\n");
        return;
    }

    if (!rooms[roomNumber - 1].isAvailable) {
        rooms[roomNumber - 1].isAvailable = 1;
        strcpy(rooms[roomNumber - 1].guestName, "");
        printf("Checked out from room %d successfully.\n", roomNumber);
    } else {
        printf("Room %d is not booked.\n", roomNumber);
    }
}

void saveRoomData(Room* rooms) {
    FILE* file = fopen("roomdata.txt", "w");
    if (file == NULL) {
        printf("Error saving room data!\n");
        return;
    }
    fwrite(rooms, sizeof(Room), MAX_ROOMS, file);
    fclose(file);
}

void loadRoomData(Room* rooms) {
    FILE* file = fopen("roomdata.txt", "r");
    if (file) {
        fread(rooms, sizeof(Room), MAX_ROOMS, file);
        fclose(file);
    } else {
        initializeHotel(rooms); // Initializes if file does not exist
    }
}