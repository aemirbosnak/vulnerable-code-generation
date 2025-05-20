//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
// C Hotel Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structures */

struct room {
    int id;
    char type[15];
    int price;
    int availability;
};

struct booking {
    int roomID;
    char customerName[30];
    char checkInDate[15];
    char checkOutDate[15];
};

/* Function Declarations */

void displayMenu();
void displayRooms(struct room rooms[], int numRooms);
void bookRoom(struct room rooms[], int numRooms, struct booking bookings[], int numBookings);
void displayBookings(struct booking bookings[], int numBookings);
void deleteBooking(struct booking bookings[], int numBookings);

/* Main Function */

int main() {

    /* Variables */

    int choice = 0;
    int numRooms = 4;
    int numBookings = 0;
    struct room rooms[4] = {{1, "Single", 100, 1}, {2, "Double", 150, 1}, {3, "Queen", 200, 1}, {4, "King", 250, 1}};
    struct booking bookings[100];

    /* Program Loop */

    while (choice != 5) {

        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms, bookings, numBookings);
                numBookings++;
                break;
            case 3:
                displayBookings(bookings, numBookings);
                break;
            case 4:
                deleteBooking(bookings, numBookings);
                numBookings--;
                break;
            case 5:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Function Definitions */

void displayMenu() {
    printf("\n         HOTEL MANAGEMENT SYSTEM\n");
    printf("------------------------------------------\n");
    printf("1. View Rooms\n");
    printf("2. Book a Room\n");
    printf("3. View Bookings\n");
    printf("4. Delete a Booking\n");
    printf("5. Exit\n");
    printf("------------------------------------------\n");
    printf("Please enter your choice: ");
}

void displayRooms(struct room rooms[], int numRooms) {
    printf("\n         AVAILABLE ROOMS\n");
    printf("------------------------------------------\n");
    printf("ID     Type      Price     Availability\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%-6d %-9s $%-8d ", rooms[i].id, rooms[i].type, rooms[i].price);
        if (rooms[i].availability == 1) {
            printf("Available\n");
        } else {
            printf("Booked\n");
        }
    }
    printf("------------------------------------------\n");
}

void bookRoom(struct room rooms[], int numRooms, struct booking bookings[], int numBookings) {
    int roomID;
    printf("\n         BOOK A ROOM\n");
    printf("------------------------------------------\n");
    printf("Please enter the ID of the room you would like to book: ");
    scanf("%d", &roomID);
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].id == roomID) {
            if (rooms[i].availability == 1) {
                struct booking booking;
                booking.roomID = roomID;
                printf("Please enter your name: ");
                scanf("%s", booking.customerName);
                printf("Please enter your check-in date (dd/mm/yyyy): ");
                scanf("%s", booking.checkInDate);
                printf("Please enter your check-out date (dd/mm/yyyy): ");
                scanf("%s", booking.checkOutDate);
                bookings[numBookings] = booking;
                rooms[i].availability = 0;
                printf("Room successfully booked!\n");
            } else {
                printf("Sorry, that room is not available.\n");
            }
            break;
        }
        if (i == numRooms - 1) {
            printf("Invalid room ID. Please try again.\n");
        }
    }
}

void displayBookings(struct booking bookings[], int numBookings) {
    printf("\n         BOOKINGS\n");
    printf("------------------------------------------\n");
    printf("Room ID     Customer Name      Check-In Date      Check-Out Date\n");
    printf("------------------------------------------------------------------\n");
    if (numBookings == 0) {
        printf("No bookings found.\n");
    } else {
        for (int i = 0; i < numBookings; i++) {
            printf("%-11d %-18s %-19s %-17s\n", bookings[i].roomID, bookings[i].customerName, bookings[i].checkInDate, bookings[i].checkOutDate);
        }
    }
}

void deleteBooking(struct booking bookings[], int numBookings) {
    int roomID;
    printf("\n         DELETE A BOOKING\n");
    printf("------------------------------------------\n");
    printf("Please enter the ID of the booking you would like to delete: ");
    scanf("%d", &roomID);
    for (int i = 0; i < numBookings; i++) {
        if (bookings[i].roomID == roomID) {
            bookings[i] = bookings[numBookings-1];
            printf("Booking successfully deleted!\n");
            break;
        }
        if (i == numBookings - 1) {
            printf("Invalid booking ID. Please try again.\n");
        }
    }
}