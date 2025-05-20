//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 50
#define MAX_BOOKINGS 200

typedef struct {
    int roomNumber;
    char guestName[50];
    int bookingID;
} Booking;

Booking bookings[MAX_BOOKINGS];
int numBookings = 0;

int addBooking(int roomNumber, char guestName[]) {
    if (numBookings >= MAX_BOOKINGS) {
        printf("Sorry, no more bookings available.\n");
        return 0;
    }

    strcpy(bookings[numBookings].guestName, guestName);
    bookings[numBookings].roomNumber = roomNumber;
    bookings[numBookings].bookingID = numBookings + 1;
    numBookings++;

    printf("Booking added successfully with ID %d.\n", bookings[numBookings - 1].bookingID);
    return 1;
}

int viewBookings() {
    printf("Bookings:\n");
    for (int i = 0; i < numBookings; i++) {
        printf("ID: %d\n", bookings[i].bookingID);
        printf("Guest Name: %s\n", bookings[i].guestName);
        printf("Room Number: %d\n\n", bookings[i].roomNumber);
    }
}

int main() {
    int choice;

    while (1) {
        printf("Hotel Management System\n");
        printf("1. Add Booking\n2. View Bookings\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBooking(0, "John Doe");
            break;
        case 2:
            viewBookings();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}