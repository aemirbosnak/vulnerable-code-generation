//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a room
typedef struct {
    int roomNumber;
    int roomType;
    int roomRate;
    int numGuests;
    char guestName[50];
} Room;

// Define the structure of a guest
typedef struct {
    char name[50];
    int age;
    char address[100];
    int phoneNumber;
} Guest;

// Function to display the room details
void displayRoomDetails(Room r) {
    printf("Room Number: %d\n", r.roomNumber);
    printf("Room Type: %d\n", r.roomType);
    printf("Room Rate: $%d\n", r.roomRate);
    printf("Number of Guests: %d\n", r.numGuests);
    printf("Guest Name: %s\n", r.guestName);
}

// Function to display the guest details
void displayGuestDetails(Guest g) {
    printf("Name: %s\n", g.name);
    printf("Age: %d\n", g.age);
    printf("Address: %s\n", g.address);
    printf("Phone Number: %d\n", g.phoneNumber);
}

// Function to check if a room is available
int isRoomAvailable(Room r) {
    if (r.numGuests == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a guest is checked in
int isGuestCheckedIn(Guest g) {
    if (g.age!= 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check out a guest
void checkOutGuest(Room *r, Guest *g) {
    r->numGuests = 0;
    strcpy(g->name, "");
    g->age = 0;
    strcpy(g->address, "");
    g->phoneNumber = 0;
}

// Function to reserve a room
void reserveRoom(Room *r, Guest *g) {
    if (isRoomAvailable(*r)) {
        r->numGuests = 1;
        strcpy(r->guestName, g->name);
    } else {
        printf("Room is not available.\n");
    }
}

// Function to check in a guest
void checkInGuest(Room *r, Guest *g) {
    if (isRoomAvailable(*r)) {
        r->numGuests = 1;
        strcpy(r->guestName, g->name);
        g->age = 25;
        strcpy(g->address, "123 Main St.");
        g->phoneNumber = 5551234;
    } else {
        printf("Room is not available.\n");
    }
}

// Function to display the hotel menu
void displayMenu() {
    printf("Hotel Management System\n");
    printf("1. Reserve Room\n");
    printf("2. Check In\n");
    printf("3. Check Out\n");
    printf("4. Display Room Details\n");
    printf("5. Display Guest Details\n");
    printf("6. Exit\n");
}

// Main function
int main() {
    Room r;
    Guest g;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            reserveRoom(&r, &g);
            break;
        case 2:
            checkInGuest(&r, &g);
            break;
        case 3:
            checkOutGuest(&r, &g);
            break;
        case 4:
            displayRoomDetails(r);
            break;
        case 5:
            displayGuestDetails(g);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}