//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100
#define NAME_LEN 50

typedef struct {
    char guestName[NAME_LEN];
    int roomNumber;
    char checkInDate[11];  // Format: YYYY-MM-DD
    char checkOutDate[11]; // Format: YYYY-MM-DD
} Booking;

Booking bookings[MAX_BOOKINGS];
int bookingCount = 0;

void addBooking() {
    if (bookingCount >= MAX_BOOKINGS) {
        printf("Booking limit reached, cannot add more bookings.\n");
        return;
    }

    Booking newBooking;
    printf("Enter Guest Name: ");
    getchar(); // Consume newline character
    fgets(newBooking.guestName, NAME_LEN, stdin);
    newBooking.guestName[strcspn(newBooking.guestName, "\n")] = 0; // Remove newline character

    printf("Enter Room Number: ");
    scanf("%d", &newBooking.roomNumber);
    
    printf("Enter Check-In Date (YYYY-MM-DD): ");
    scanf("%s", newBooking.checkInDate);
    
    printf("Enter Check-Out Date (YYYY-MM-DD): ");
    scanf("%s", newBooking.checkOutDate);
    
    bookings[bookingCount++] = newBooking;
    printf("Booking added successfully.\n");
}

void viewBookings() {
    if (bookingCount == 0) {
        printf("No bookings available.\n");
        return;
    }

    printf("\nCurrent Bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("Booking #%d:\n", i + 1);
        printf("Guest Name: %s\n", bookings[i].guestName);
        printf("Room Number: %d\n", bookings[i].roomNumber);
        printf("Check-In Date: %s\n", bookings[i].checkInDate);
        printf("Check-Out Date: %s\n\n", bookings[i].checkOutDate);
    }
}

void deleteBooking() {
    if (bookingCount == 0) {
        printf("No bookings available to delete.\n");
        return;
    }

    int bookingNumber;
    printf("Enter the booking number to delete (1-%d): ", bookingCount);
    scanf("%d", &bookingNumber);

    if (bookingNumber < 1 || bookingNumber > bookingCount) {
        printf("Invalid booking number.\n");
        return;
    }

    for (int i = bookingNumber - 1; i < bookingCount - 1; i++) {
        bookings[i] = bookings[i + 1];
    }

    bookingCount--;
    printf("Booking #%d deleted successfully.\n", bookingNumber);
}

void displayMenu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Add Booking\n");
    printf("2. View Bookings\n");
    printf("3. Delete Booking\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                viewBookings();
                break;
            case 3:
                deleteBooking();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}