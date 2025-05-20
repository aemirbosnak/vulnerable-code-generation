//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    char roomType[20];
    int capacity;
    float price;
    int availability;
};

struct Booking {
    int bookingId;
    char customerName[50];
    char checkInDate[11];
    char checkOutDate[11];
    int numOfRooms;
    struct Room rooms[10];
    float totalAmount;
};

// Function to display the menu
void displayMenu() {
    printf("\n***** Hotel Management System *****\n");
    printf("1. Add a new room\n");
    printf("2. Display all rooms\n");
    printf("3. Add a new booking\n");
    printf("4. Display all bookings\n");
    printf("5. Check room availability\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new room
void addRoom(struct Room* rooms, int* numRooms) {
    printf("\nEnter room number: ");
    scanf("%d", &rooms[*numRooms].roomNumber);
    printf("Enter room type: ");
    scanf("%s", rooms[*numRooms].roomType);
    printf("Enter room capacity: ");
    scanf("%d", &rooms[*numRooms].capacity);
    printf("Enter room price: ");
    scanf("%f", &rooms[*numRooms].price);
    rooms[*numRooms].availability = 1;
    (*numRooms)++;
}

// Function to display all rooms
void displayRooms(struct Room* rooms, int numRooms) {
    printf("\n***** Room List *****\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room Number: %d\n", rooms[i].roomNumber);
        printf("Room Type: %s\n", rooms[i].roomType);
        printf("Room Capacity: %d\n", rooms[i].capacity);
        printf("Room Price: %.2f\n", rooms[i].price);
        printf("Room Availability: %d\n", rooms[i].availability);
        printf("-------------------------\n");
    }
}

// Function to add a new booking
void addBooking(struct Booking* bookings, int* numBookings, struct Room* rooms, int numRooms) {
    printf("\nEnter booking ID: ");
    scanf("%d", &bookings[*numBookings].bookingId);
    printf("Enter customer name: ");
    scanf("%s", bookings[*numBookings].customerName);
    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf("%s", bookings[*numBookings].checkInDate);
    printf("Enter check-out date (dd/mm/yyyy): ");
    scanf("%s", bookings[*numBookings].checkOutDate);
    printf("Enter number of rooms: ");
    scanf("%d", &bookings[*numBookings].numOfRooms);

    // Get room details
    for (int i = 0; i < bookings[*numBookings].numOfRooms; i++) {
        printf("\nEnter room number for room %d: ", i + 1);
        scanf("%d", &bookings[*numBookings].rooms[i].roomNumber);

        // Check if room is available
        int roomFound = 0;
        for (int j = 0; j < numRooms; j++) {
            if (bookings[*numBookings].rooms[i].roomNumber == rooms[j].roomNumber && rooms[j].availability == 1) {
                bookings[*numBookings].rooms[i] = rooms[j];
                roomFound = 1;
                break;
            }
        }

        if (!roomFound) {
            printf("Room not available. Please enter another room number.\n");
            i--;
        }
    }

    // Calculate total amount
    bookings[*numBookings].totalAmount = 0;
    for (int i = 0; i < bookings[*numBookings].numOfRooms; i++) {
        bookings[*numBookings].totalAmount += bookings[*numBookings].rooms[i].price;
    }

    (*numBookings)++;
}

// Function to display all bookings
void displayBookings(struct Booking* bookings, int numBookings) {
    printf("\n***** Booking List *****\n");
    for (int i = 0; i < numBookings; i++) {
        printf("Booking ID: %d\n", bookings[i].bookingId);
        printf("Customer Name: %s\n", bookings[i].customerName);
        printf("Check-In Date: %s\n", bookings[i].checkInDate);
        printf("Check-Out Date: %s\n", bookings[i].checkOutDate);
        printf("Number of Rooms: %d\n", bookings[i].numOfRooms);
        for (int j = 0; j < bookings[i].numOfRooms; j++) {
            printf("Room %d:\n", j + 1);
            printf("Room Number: %d\n", bookings[i].rooms[j].roomNumber);
            printf("Room Type: %s\n", bookings[i].rooms[j].roomType);
            printf("Room Capacity: %d\n", bookings[i].rooms[j].capacity);
            printf("Room Price: %.2f\n", bookings[i].rooms[j].price);
            printf("-------------------------\n");
        }
        printf("Total Amount: %.2f\n", bookings[i].totalAmount);
        printf("-------------------------\n");
    }
}

// Function to check room availability
void checkAvailability(struct Room* rooms, int numRooms) {
    printf("\nEnter check-in date (dd/mm/yyyy): ");
    char checkInDate[11];
    scanf("%s", checkInDate);
    printf("Enter check-out date (dd/mm/yyyy): ");
    char checkOutDate[11];
    scanf("%s", checkOutDate);

    printf("\n***** Available Rooms *****\n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].availability == 1) {
            printf("Room Number: %d\n", rooms[i].roomNumber);
            printf("Room Type: %s\n", rooms[i].roomType);
            printf("Room Capacity: %d\n", rooms[i].capacity);
            printf("Room Price: %.2f\n", rooms[i].price);
            printf("-------------------------\n");
        }
    }
}

int main() {
    // Initialize the hotel management system
    struct Room rooms[100];
    int numRooms = 0;
    struct Booking bookings[100];
    int numBookings = 0;

    // Display the menu and get the user's choice
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                addRoom(rooms, &numRooms);
                break;
            case 2:
                displayRooms(rooms, numRooms);
                break;
            case 3:
                addBooking(bookings, &numBookings, rooms, numRooms);
                break;
            case 4:
                displayBookings(bookings, numBookings);
                break;
            case 5:
                checkAvailability(rooms, numRooms);
                break;
            case 6:
                printf("\nExiting the Hotel Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}