//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a hotel room
typedef struct HotelRoom {
    int roomNumber;
    char roomType[20];
    int availability;
    float price;
} HotelRoom;

// Function to display the main menu
void mainMenu() {
    printf("====================================================================\n");
    printf("Welcome to the Hotel Management System\n");
    printf("====================================================================\n");
    printf("1. Add a new room\n");
    printf("2. Display all rooms\n");
    printf("3. Search for a room\n");
    printf("4. Book a room\n");
    printf("5. Cancel a booking\n");
    printf("6. Exit\n");
    printf("====================================================================\n");
    printf("Enter your choice: ");
}

// Function to add a new room to the hotel
void addNewRoom(HotelRoom *rooms, int *numRooms) {
    printf("Enter the room number: ");
    scanf("%d", &rooms[*numRooms].roomNumber);
    printf("Enter the room type: ");
    scanf("%s", rooms[*numRooms].roomType);
    printf("Enter the room availability (0 for unavailable, 1 for available): ");
    scanf("%d", &rooms[*numRooms].availability);
    printf("Enter the room price: ");
    scanf("%f", &rooms[*numRooms].price);
    (*numRooms)++;
}

// Function to display all the rooms in the hotel
void displayAllRooms(HotelRoom *rooms, int numRooms) {
    printf("====================================================================\n");
    printf("Room Number\tRoom Type\tAvailability\tPrice\n");
    printf("====================================================================\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].availability, rooms[i].price);
    }
    printf("====================================================================\n");
}

// Function to search for a room in the hotel
void searchForRoom(HotelRoom *rooms, int numRooms) {
    int roomNumber;
    printf("Enter the room number you want to search for: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            printf("====================================================================\n");
            printf("Room Number\tRoom Type\tAvailability\tPrice\n");
            printf("====================================================================\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].availability, rooms[i].price);
            printf("====================================================================\n");
            return;
        }
    }
    printf("Room not found!\n");
}

// Function to book a room in the hotel
void bookRoom(HotelRoom *rooms, int numRooms) {
    int roomNumber;
    printf("Enter the room number you want to book: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].availability == 1) {
                rooms[i].availability = 0;
                printf("Room booked successfully!\n");
                return;
            } else {
                printf("Room is not available!\n");
                return;
            }
        }
    }
    printf("Room not found!\n");
}

// Function to cancel a booking in the hotel
void cancelBooking(HotelRoom *rooms, int numRooms) {
    int roomNumber;
    printf("Enter the room number you want to cancel the booking for: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].availability == 0) {
                rooms[i].availability = 1;
                printf("Booking cancelled successfully!\n");
                return;
            } else {
                printf("Room is not booked!\n");
                return;
            }
        }
    }
    printf("Room not found!\n");
}

// Main function
int main() {
    // Array of hotel rooms
    HotelRoom rooms[100];
    int numRooms = 0;

    // Main loop of the program
    while (1) {
        // Display the main menu
        mainMenu();

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                addNewRoom(rooms, &numRooms);
                break;
            case 2:
                displayAllRooms(rooms, numRooms);
                break;
            case 3:
                searchForRoom(rooms, numRooms);
                break;
            case 4:
                bookRoom(rooms, numRooms);
                break;
            case 5:
                cancelBooking(rooms, numRooms);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}