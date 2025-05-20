//FormAI DATASET v1.0 Category: Hotel Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct {
    int roomNumber;
    char guestName[50];
    int numOfNights;
} Booking;

Booking bookings[MAX_ROOMS];
int currentNumOfBookings = 0;

void displayMainMenu();
void addBooking();
void viewBooking();
void deleteBooking();
void displayBookings();
int findBooking(int roomNumber);

int main() {
    displayMainMenu();
    return 0;
}

void displayMainMenu() {
    char choice;
    do {
        printf("\n\nWelcome to the Chuckle Hotel Management System!");
        printf("\nSelect an option:");
        printf("\n1. Add Booking");
        printf("\n2. View Booking");
        printf("\n3. Delete Booking");
        printf("\n4. Display All Bookings");
        printf("\n5. Exit");
        printf("\nChoice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addBooking();
                break;
            case '2':
                viewBooking();
                break;
            case '3':
                deleteBooking();
                break;
            case '4':
                displayBookings();
                break;
            case '5':
                printf("\nThanks for using Chuckle Hotel Management System!");
                break;
            default:
                printf("\nInvalid input. Please try again.");
                break;
        }

    } while (choice != '5');
}

void addBooking() {
    if (currentNumOfBookings >= MAX_ROOMS) {
        printf("\nSorry, all rooms are currently booked.");
        return;
    }
    Booking booking;

    printf("\nEnter Room Number: ");
    scanf("%d", &booking.roomNumber);

    if (findBooking(booking.roomNumber) != -1) {
        printf("\nRoom #%d is already booked. Please choose a different room.", booking.roomNumber);
        return;
    }

    printf("Enter Guest Name: ");
    scanf(" %[^\n]", booking.guestName);

    printf("Enter Number of Nights: ");
    scanf("%d", &booking.numOfNights);

    bookings[currentNumOfBookings++] = booking;

    printf("\nBooking successfully added!");
}

void viewBooking() {
    int roomNumber;
    printf("\nEnter Room Number: ");
    scanf("%d", &roomNumber);

    int index = findBooking(roomNumber);
    if (index == -1) {
        printf("\nNo booking found for Room #%d.", roomNumber);
        return;
    }

    printf("\nBooking Details:");
    printf("\nRoom Number: %d", bookings[index].roomNumber);
    printf("\nGuest Name: %s", bookings[index].guestName);
    printf("\nNumber of Nights: %d", bookings[index].numOfNights);

}

void deleteBooking() {
    int roomNumber;
    printf("\nEnter Room Number: ");
    scanf("%d", &roomNumber);

    int index = findBooking(roomNumber);
    if (index == -1) {
        printf("\nNo booking found for Room #%d.", roomNumber);
        return;
    }

    printf("\nAre you sure you want to delete booking for Room #%d? [y/n]: ", roomNumber);
    char confirmation;
    scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y') {
        for (int i = index; i < currentNumOfBookings - 1; i++) {
            bookings[i] = bookings[i + 1];
        }
        currentNumOfBookings--;
        printf("\nBooking for Room #%d successfully deleted!", roomNumber);
    } else {
        printf("\nBooking deletion cancelled.");
    }
}

void displayBookings() {
    if (currentNumOfBookings == 0) {
        printf("\nNo bookings found.");
        return;
    }

    printf("\nCurrent Bookings:");

    for (int i = 0; i < currentNumOfBookings; i++) {
        printf("\nRoom Number: %d", bookings[i].roomNumber);
        printf("\nGuest Name: %s", bookings[i].guestName);
        printf("\nNumber of Nights: %d\n", bookings[i].numOfNights);
    }
}

int findBooking(int roomNumber) {
    for (int i = 0; i < currentNumOfBookings; i++) {
        if (bookings[i].roomNumber == roomNumber) {
            return i;
        }
    }
    return -1;
}