//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "bookings.txt"
#define MAX_BOOKINGS 100
#define NAME_LENGTH 50

typedef struct {
    int bookingID;
    char guestName[NAME_LENGTH];
    int roomNumber;
} Booking;

// Function declarations
void addBooking();
void viewBookings();
void deleteBooking(int bookingID);
int getNextBookingID();

int main() {
    int choice;
    while (1) {
        printf("---- Hotel Management System ----\n");
        printf("1. Add Booking\n");
        printf("2. View Bookings\n");
        printf("3. Delete Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                viewBookings();
                break;
            case 3: {
                int bookingID;
                printf("Enter Booking ID to delete: ");
                scanf("%d", &bookingID);
                deleteBooking(bookingID);
                break;
            }
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add a booking
void addBooking() {
    Booking booking;
    booking.bookingID = getNextBookingID();

    printf("Enter Guest Name: ");
    scanf(" %[^\n]%*c", booking.guestName); // Read string with spaces
    printf("Enter Room Number: ");
    scanf("%d", &booking.roomNumber);

    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d,%s,%d\n", booking.bookingID, booking.guestName, booking.roomNumber);
    fclose(file);

    printf("Booking added successfully! Booking ID: %d\n", booking.bookingID);
}

// Function to view all bookings
void viewBookings() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "No bookings found.\n");
        return;
    }

    Booking booking;
    printf("\n---- Current Bookings ----\n");
    while (fscanf(file, "%d,%49[^,],%d\n", &booking.bookingID, booking.guestName, &booking.roomNumber) != EOF) {
        printf("Booking ID: %d, Guest Name: %s, Room Number: %d\n", booking.bookingID, booking.guestName, booking.roomNumber);
    }
    fclose(file);
}

// Function to delete a booking
void deleteBooking(int bookingID) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        fprintf(stderr, "No bookings found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "Error creating temporary file.\n");
        fclose(file);
        return;
    }

    Booking booking;
    int found = 0;
    while (fscanf(file, "%d,%49[^,],%d\n", &booking.bookingID, booking.guestName, &booking.roomNumber) != EOF) {
        if (booking.bookingID == bookingID) {
            found = 1;
            printf("Booking ID %d deleted successfully!\n", bookingID);
        } else {
            fprintf(tempFile, "%d,%s,%d\n", booking.bookingID, booking.guestName, booking.roomNumber);
        }
    }
    fclose(file);
    fclose(tempFile);

    // Replace old file with new file
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (!found) {
        printf("Booking ID %d not found.\n", bookingID);
    }
}

// Function to get the next available booking ID
int getNextBookingID() {
    FILE *file = fopen(FILENAME, "r");
    int maxID = 0;

    if (file == NULL) {
        return 1; // Start from ID 1 if file does not exist
    }

    Booking booking;
    while (fscanf(file, "%d,%49[^,],%d\n", &booking.bookingID, booking.guestName, &booking.roomNumber) != EOF) {
        if (booking.bookingID > maxID) {
            maxID = booking.bookingID;
        }
    }
    fclose(file);
    return maxID + 1;
}