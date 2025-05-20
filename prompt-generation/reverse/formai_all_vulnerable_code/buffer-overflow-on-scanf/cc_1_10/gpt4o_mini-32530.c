//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roomNumber;
    char guestName[50];
    char checkInDate[11]; // format: YYYY-MM-DD
    int nightsStay;
    double pricePerNight;
    double totalAmount;
} Room;

void displayMenu();
void checkIn(Room rooms[], int *roomCount);
void checkOut(Room rooms[], int roomCount);
void displayRooms(const Room rooms[], int roomCount);
void calculateTotalAmount(Room *room);

int main() {
    Room rooms[100];
    int roomCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn(rooms, &roomCount);
                break;
            case 2:
                checkOut(rooms, roomCount);
                break;
            case 3:
                displayRooms(rooms, roomCount);
                break;
            case 4:
                printf("Thank you for using the Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. Display Rooms\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void checkIn(Room rooms[], int *roomCount) {
    if (*roomCount >= 100) {
        printf("Hotel is full! Cannot check in more guests.\n");
        return;
    }

    Room newRoom;
    printf("Enter Room Number: ");
    scanf("%d", &newRoom.roomNumber);
    printf("Enter Guest Name: ");
    scanf("%s", newRoom.guestName);
    printf("Enter Check In Date (YYYY-MM-DD): ");
    scanf("%s", newRoom.checkInDate);
    printf("Enter Number of Nights Stay: ");
    scanf("%d", &newRoom.nightsStay);
    printf("Enter Price Per Night: ");
    scanf("%lf", &newRoom.pricePerNight);

    calculateTotalAmount(&newRoom);

    rooms[*roomCount] = newRoom;
    (*roomCount)++;

    printf("Check In successful! Total Amount: %.2lf\n", newRoom.totalAmount);
}

void checkOut(Room rooms[], int roomCount) {
    int roomNumber, found = 0;

    printf("Enter Room Number to Check Out: ");
    scanf("%d", &roomNumber);

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            found = 1;
            printf("Checking out: %s (Room Number: %d)\n", rooms[i].guestName, rooms[i].roomNumber);
            // Shift remaining rooms down
            for (int j = i; j < roomCount - 1; j++) {
                rooms[j] = rooms[j + 1];
            }
            roomCount--;
            break;
        }
    }

    if (!found) {
        printf("Room Number %d not found! Please check again.\n", roomNumber);
    }
}

void displayRooms(const Room rooms[], int roomCount) {
    printf("\n--- Current Guests ---\n");
    if (roomCount == 0) {
        printf("No guests currently checked in.\n");
        return;
    }

    for (int i = 0; i < roomCount; i++) {
        printf("Room Number: %d, Guest Name: %s, Check-In: %s, Nights: %d, Total Amount: %.2lf\n",
            rooms[i].roomNumber, rooms[i].guestName, rooms[i].checkInDate,
            rooms[i].nightsStay, rooms[i].totalAmount);
    }
}

void calculateTotalAmount(Room *room) {
    room->totalAmount = room->nightsStay * room->pricePerNight;
}