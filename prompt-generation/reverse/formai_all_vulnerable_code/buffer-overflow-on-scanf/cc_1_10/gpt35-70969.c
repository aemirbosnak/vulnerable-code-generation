//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>

// Declare struct for hotel rooms
typedef struct {
    int roomNumber;
    double price;
    int occupied;
} Room;

// Declare struct for guests
typedef struct {
    char name[50];
    int roomNumber;
} Guest;

// Function to display room information
void displayRooms(Room rooms[], int numRooms) {
    printf("Room Number\tPrice\tOccupied\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d\t\t%.2f\t%s\n", rooms[i].roomNumber,
               rooms[i].price, rooms[i].occupied ? "Yes" : "No");
    }
}

// Function to book a room
void bookRoom(Room rooms[], int numRooms, Guest guests[], int numGuests) {
    int roomNumber;
    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);

    // Find the room with the matching room number
    int roomIndex = -1;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            roomIndex = i;
            break;
        }
    }

    // If the room is found and not occupied, book it
    if (roomIndex != -1 && !rooms[roomIndex].occupied) {
        rooms[roomIndex].occupied = 1;
        printf("Room %d successfully booked!\n", roomNumber);

        // Prompt for guest information
        printf("Enter guest name: ");
        scanf("%s", guests[numGuests].name);
        guests[numGuests].roomNumber = roomNumber;
    } else {
        printf("Room %d is already occupied or does not exist.\n", roomNumber);
    }
}

int main() {
    // Initialize rooms
    Room rooms[] = {
        {101, 75.00, 0},
        {102, 85.00, 1},
        {103, 90.00, 0},
        {104, 100.00, 1},
    };
    int numRooms = sizeof(rooms) / sizeof(Room);

    // Initialize guests
    Guest guests[100];
    int numGuests = 0;

    int option;
    do {
        // Display menu
        printf("\nHotel Management System Menu\n");
        printf("1. Display room information\n");
        printf("2. Book a room\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        // Call appropriate function based on user input
        switch (option) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms, guests, numGuests);
                numGuests++;
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}