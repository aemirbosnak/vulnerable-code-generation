//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100

typedef struct {
    int roomNumber;
    char guestName[50];
    int bookingDate;
    int checkInDate;
    int checkOutDate;
} Booking;

Booking bookings[MAX_BOOKINGS];
int numBookings = 0;

void addBooking() {
    if (numBookings >= MAX_BOOKINGS) {
        printf("Sorry, no more bookings available.\n");
        return;
    }

    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    char guestName[50];
    printf("Enter guest name: ");
    scanf("%s", guestName);

    int bookingDate;
    printf("Enter booking date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &bookingDate, &bookingDate, &bookingDate);

    int checkInDate;
    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &checkInDate, &checkInDate, &checkInDate);

    int checkOutDate;
    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &checkOutDate, &checkOutDate, &checkOutDate);

    bookings[numBookings].roomNumber = roomNumber;
    strcpy(bookings[numBookings].guestName, guestName);
    bookings[numBookings].bookingDate = bookingDate;
    bookings[numBookings].checkInDate = checkInDate;
    bookings[numBookings].checkOutDate = checkOutDate;

    numBookings++;
    printf("Booking added successfully.\n");
}

void viewBookings() {
    if (numBookings == 0) {
        printf("No bookings available.\n");
        return;
    }

    printf("Bookings:\n");
    for (int i = 0; i < numBookings; i++) {
        printf("Room number: %d\n", bookings[i].roomNumber);
        printf("Guest name: %s\n", bookings[i].guestName);
        printf("Booking date: %d-%d-%d\n", bookings[i].bookingDate / 10000, (bookings[i].bookingDate / 100) % 100, bookings[i].bookingDate % 100);
        printf("Check-in date: %d-%d-%d\n", bookings[i].checkInDate / 10000, (bookings[i].checkInDate / 100) % 100, bookings[i].checkInDate % 100);
        printf("Check-out date: %d-%d-%d\n", bookings[i].checkOutDate / 10000, (bookings[i].checkOutDate / 100) % 100, bookings[i].checkOutDate % 100);
        printf("\n");
    }
}

void main() {
    int choice;

    while (1) {
        printf("Hotel Management System\n");
        printf("1. Add booking\n");
        printf("2. View bookings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addBooking();
            break;
        case 2:
            viewBookings();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}