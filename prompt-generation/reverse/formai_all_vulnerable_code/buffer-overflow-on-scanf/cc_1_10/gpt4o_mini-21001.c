//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11

typedef struct {
    char customerName[NAME_LENGTH];
    char checkInDate[DATE_LENGTH];
    char checkOutDate[DATE_LENGTH];
    int roomNumber;
} Booking;

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

void displayMenu() {
    printf("\n=== Welcome to the Hotel Management System ===\n");
    printf("1. Add Booking\n");
    printf("2. View Bookings\n");
    printf("3. Exit\n");
    printf("==============================================\n");
    printf("Select an option: ");
}

void addBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking limit reached. Unable to add new booking.\n");
        return;
    }

    Booking newBooking;
    printf("Enter Customer Name: ");
    getchar(); // flush the new line character from previous input
    fgets(newBooking.customerName, NAME_LENGTH, stdin);
    newBooking.customerName[strcspn(newBooking.customerName, "\n")] = '\0'; // remove new line

    printf("Enter Check-In Date (YYYY-MM-DD): ");
    fgets(newBooking.checkInDate, DATE_LENGTH, stdin);
    newBooking.checkInDate[strcspn(newBooking.checkInDate, "\n")] = '\0';

    printf("Enter Check-Out Date (YYYY-MM-DD): ");
    fgets(newBooking.checkOutDate, DATE_LENGTH, stdin);
    newBooking.checkOutDate[strcspn(newBooking.checkOutDate, "\n")] = '\0';

    printf("Enter Room Number: ");
    scanf("%d", &newBooking.roomNumber);

    bookings[bookingCount] = newBooking;
    bookingCount++;

    printf("Booking added successfully!\n");
}

void viewBookings() {
    if (bookingCount == 0) {
        printf("No bookings found.\n");
        return;
    }

    printf("\n=== Current Bookings ===\n");
    for (int i = 0; i < bookingCount; ++i) {
        printf("Booking %d:\n", i + 1);
        printf("Customer Name: %s\n", bookings[i].customerName);
        printf("Check-In Date: %s\n", bookings[i].checkInDate);
        printf("Check-Out Date: %s\n", bookings[i].checkOutDate);
        printf("Room Number: %d\n\n", bookings[i].roomNumber);
    }
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                viewBookings();
                break;
            case 3:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}