//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000

typedef struct {
    char name[50];
    char roomType;
    int numNights;
    float bill;
} Guest;

typedef struct {
    int roomNumber;
    char roomType;
    int occupancy;
} Room;

Guest guests[MAX_GUESTS];
Room rooms[MAX_ROOMS];

int numGuests = 0;
int numRooms = 0;

void addGuest() {
    printf("Enter guest name: ");
    scanf(" %s", guests[numGuests].name);

    printf("Enter room type (S, D, Q, K): ");
    scanf(" %c", &guests[numGuests].roomType);

    printf("Enter number of nights: ");
    scanf(" %d", &guests[numGuests].numNights);

    guests[numGuests].bill = 0;

    numGuests++;
}

void addRoom() {
    printf("Enter room number: ");
    scanf(" %d", &rooms[numRooms].roomNumber);

    printf("Enter room type (S, D, Q, K): ");
    scanf(" %c", &rooms[numRooms].roomType);

    rooms[numRooms].occupancy = 0;

    numRooms++;
}

void checkInGuest() {
    int guestIndex;
    int roomIndex;

    printf("Enter guest name: ");
    scanf(" %s", guests[guestIndex].name);

    printf("Enter room number: ");
    scanf(" %d", &rooms[roomIndex].roomNumber);

    if (rooms[roomIndex].occupancy == 0) {
        rooms[roomIndex].occupancy = 1;
        guests[guestIndex].bill += 100 * guests[guestIndex].numNights;
    } else {
        printf("Room is already occupied.\n");
    }
}

void checkOutGuest() {
    int guestIndex;
    int roomIndex;

    printf("Enter guest name: ");
    scanf(" %s", guests[guestIndex].name);

    printf("Enter room number: ");
    scanf(" %d", &rooms[roomIndex].roomNumber);

    if (rooms[roomIndex].occupancy == 1) {
        rooms[roomIndex].occupancy = 0;
        printf("Guest bill: $%.2f\n", guests[guestIndex].bill);
    } else {
        printf("Guest is not checked in.\n");
    }
}

void printGuests() {
    for (int i = 0; i < numGuests; i++) {
        printf("Guest %d:\n", i + 1);
        printf("Name: %s\n", guests[i].name);
        printf("Room type: %c\n", guests[i].roomType);
        printf("Number of nights: %d\n", guests[i].numNights);
        printf("Bill: $%.2f\n\n", guests[i].bill);
    }
}

void printRooms() {
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d:\n", rooms[i].roomNumber);
        printf("Room type: %c\n", rooms[i].roomType);
        printf("Occupancy: %d\n\n", rooms[i].occupancy);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add guest\n");
        printf("2. Add room\n");
        printf("3. Check in guest\n");
        printf("4. Check out guest\n");
        printf("5. Print guests\n");
        printf("6. Print rooms\n");
        printf("7. Quit\n");

        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                addRoom();
                break;
            case 3:
                checkInGuest();
                break;
            case 4:
                checkOutGuest();
                break;
            case 5:
                printGuests();
                break;
            case 6:
                printRooms();
                break;
            case 7:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}