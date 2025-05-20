//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100  // Maximum number of rooms in the hotel

// Room structure
typedef struct Room {
    int roomNumber;
    char guestName[50];
    char guestAddress[100];
    int guestAge;
    int roomType;
    int numDays;
    int price;
} Room;

// Global variables
Room rooms[MAX_ROOMS]; // List of rooms
int numRooms = 0; // Number of rooms in use

// Function prototypes
void addRoom();
void displayRooms();
void bookRoom();
void checkoutRoom();

int main() {
    int choice;

    // Main menu loop
    do {
        printf("\nWelcome to the Hotel Management System!\n");
        printf("1. Add a room\n");
        printf("2. Display all rooms\n");
        printf("3. Book a room\n");
        printf("4. Checkout a room\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRoom();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                checkoutRoom();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Add a new room to the system
void addRoom() {
    // Check if there's space for a new room
    if (numRooms == MAX_ROOMS) {
        printf("Sorry, the hotel is full!\n");
        return;
    }

    Room newRoom;

    // Get room details from the user
    printf("Enter the room number: ");
    scanf("%d", &newRoom.roomNumber);

    // Check if the room already exists
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == newRoom.roomNumber) {
            printf("Sorry, that room already exists!\n");
            return;
        }
    }

    printf("Enter the guest name: ");
    scanf("%s", newRoom.guestName);

    printf("Enter the guest address: ");
    scanf("%s", newRoom.guestAddress);

    printf("Enter the guest age: ");
    scanf("%d", &newRoom.guestAge);

    printf("Enter the room type (1 for single, 2 for double, 3 for suite): ");
    scanf("%d", &newRoom.roomType);

    printf("Enter the number of days for booking: ");
    scanf("%d", &newRoom.numDays);

    // Calculate the price based on the room type and number of days
    switch (newRoom.roomType) {
        case 1:
            newRoom.price = newRoom.numDays * 50;
            break;
        case 2:
            newRoom.price = newRoom.numDays * 75;
            break;
        case 3:
            newRoom.price = newRoom.numDays * 120;
            break;
        default:
            printf("Invalid room type!\n");
            return;
    }

    // Add the new room to the list
    rooms[numRooms++] = newRoom;

    printf("Room added successfully!\n");
}

// Display all the rooms in the system
void displayRooms() {
    if (numRooms == 0) {
        printf("The hotel is currently empty!\n");
        return;
    }

    printf("Room #\tGuest Name\t\tGuest Address\t\tGuest Age\tRoom Type\t# of Days\tPrice\n");

    for (int i = 0; i < numRooms; i++) {
        printf("%d\t%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\n", rooms[i].roomNumber, rooms[i].guestName, rooms[i].guestAddress, rooms[i].guestAge, rooms[i].roomType, rooms[i].numDays, rooms[i].price);
    }
}

// Book a room
void bookRoom() {
    if (numRooms == 0) {
        printf("The hotel is currently empty!\n");
        return;
    }

    int roomNumber;
    int numDays;

    printf("Enter the room number you would like to book: ");
    scanf("%d", &roomNumber);

    // Find the room in the list
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            // Check if the room is already booked
            if (rooms[i].guestName[0] != '\0') {
                printf("Sorry, that room is already booked!\n");
                return;
            }

            printf("Enter your name: ");
            scanf("%s", rooms[i].guestName);

            printf("Enter your address: ");
            scanf("%s", rooms[i].guestAddress);

            printf("Enter your age: ");
            scanf("%d", &rooms[i].guestAge);

            printf("Enter the number of days for booking: ");
            scanf("%d", &numDays);

            // Update the room price
            switch (rooms[i].roomType) {
                case 1:
                    rooms[i].price = numDays * 50;
                    break;
                case 2:
                    rooms[i].price = numDays * 75;
                    break;
                case 3:
                    rooms[i].price = numDays * 120;
                    break;
            }

            rooms[i].numDays = numDays;

            printf("Room booked successfully!\n");
            return;
        }
    }

    printf("Sorry, that room does not exist!\n");
}

// Checkout a room
void checkoutRoom() {
    if (numRooms == 0) {
        printf("The hotel is currently empty!\n");
        return;
    }

    int roomNumber;

    printf("Enter the room number you would like to checkout: ");
    scanf("%d", &roomNumber);

    // Find the room in the list
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            // Check if the room is already empty
            if (rooms[i].guestName[0] == '\0') {
                printf("Sorry, that room is already empty!\n");
                return;
            }

            printf("Room checkout summary for Room #%d:\n\n", rooms[i].roomNumber);
            printf("Guest Name: %s\n", rooms[i].guestName);
            printf("Guest Address: %s\n", rooms[i].guestAddress);
            printf("Guest Age: %d\n", rooms[i].guestAge);
            printf("Room Type: %d\n", rooms[i].roomType);
            printf("# of Days Booked: %d\n", rooms[i].numDays);
            printf("Total Price: %d\n", rooms[i].price);

            // Clear the room details
            memset(&rooms[i], 0, sizeof(Room));

            printf("Room checkout successful!\n");
            return;
        }
    }

    printf("Sorry, that room does not exist!\n");
}