//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define NAME_SIZE 50

typedef struct {
    int roomNumber;
    char guestName[NAME_SIZE];
    int nights;
    float pricePerNight;
    int isBooked; // 0 for free, 1 for booked
} Room;

Room rooms[MAX_ROOMS];

// Function prototypes
void initializeRooms();
void displayRooms();
void bookRoom();
void checkoutRoom();
void saveRoomData();
void loadRoomData();

int main() {
    loadRoomData();
    int choice;

    while (1) {
        printf("\n===== Hotel Management System =====\n");
        printf("1. Display Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Checkout Room\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                checkoutRoom();
                break;
            case 4:
                saveRoomData();
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].guestName, "None");
        rooms[i].nights = 0;
        rooms[i].pricePerNight = 100.0; // Example price
        rooms[i].isBooked = 0;
    }
}

void displayRooms() {
    printf("\n===== Room List =====\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d - Status: %s, Guest: %s, Nights: %d, Price/Night: %.2f\n",
               rooms[i].roomNumber,
               rooms[i].isBooked ? "Booked" : "Available",
               rooms[i].guestName,
               rooms[i].nights,
               rooms[i].pricePerNight);
    }
}

void bookRoom() {
    int roomNumber;
    char guestName[NAME_SIZE];
    int nights;

    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);
    if (roomNumber < 1 || roomNumber > MAX_ROOMS || rooms[roomNumber-1].isBooked) {
        printf("Invalid room number or already booked!\n");
        return;
    }

    printf("Enter guest name: ");
    scanf(" %[^\n]s", guestName); // to read string with spaces

    printf("Enter number of nights: ");
    scanf("%d", &nights);

    rooms[roomNumber-1].isBooked = 1;
    strcpy(rooms[roomNumber-1].guestName, guestName);
    rooms[roomNumber-1].nights = nights;

    printf("Room %d booked successfully for %s for %d nights.\n",
           roomNumber, guestName, nights);
}

void checkoutRoom() {
    int roomNumber;

    printf("Enter room number for checkout: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS || !rooms[roomNumber-1].isBooked) {
        printf("Invalid room number or not booked!\n");
        return;
    }

    printf("Checking out: %s\n", rooms[roomNumber-1].guestName);
    rooms[roomNumber-1].isBooked = 0;
    strcpy(rooms[roomNumber-1].guestName, "None");
    rooms[roomNumber-1].nights = 0;

    printf("Room %d checked out successfully.\n", roomNumber);
}

void saveRoomData() {
    FILE *file = fopen("rooms.dat", "wb");
    if (file != NULL) {
        fwrite(rooms, sizeof(Room), MAX_ROOMS, file);
        fclose(file);
    } else {
        printf("Error saving room data.\n");
    }
}

void loadRoomData() {
    FILE *file = fopen("rooms.dat", "rb");
    if (file != NULL) {
        fread(rooms, sizeof(Room), MAX_ROOMS, file);
        fclose(file);
    } else {
        printf("No previous room data found, initializing default rooms.\n");
        initializeRooms();
    }
}