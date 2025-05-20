//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: visionary
// A visionary C Hotel Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encapsulating hotel data in a struct
typedef struct {
    int room_number;
    char room_type[50];
    float price;
    int availability;
} room;

// Array of rooms to simulate hotel inventory
room hotel_rooms[] = {
    {101, "Standard", 100.00, 1},
    {102, "Deluxe", 150.00, 1},
    {103, "Suite", 200.00, 1},
    {104, "Presidential", 500.00, 1}
};

// Function to display the available rooms
void display_available_rooms() {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < sizeof(hotel_rooms) / sizeof(room); i++) {
        if (hotel_rooms[i].availability) {
            printf("Room Number: %d, Room Type: %s, Price: %.2f\n", hotel_rooms[i].room_number, hotel_rooms[i].room_type, hotel_rooms[i].price);
        }
    }
}

// Function to book a room
void book_room() {
    int room_number;
    char choice;

    printf("\nEnter the room number you wish to book: ");
    scanf("%d", &room_number);

    // Checking room availability
    int room_index = -1;
    for (int i = 0; i < sizeof(hotel_rooms) / sizeof(room); i++) {
        if (hotel_rooms[i].room_number == room_number && hotel_rooms[i].availability) {
            room_index = i;
            break;
        }
    }

    if (room_index == -1) {
        printf("Sorry, the room is unavailable. Please try again.");
        return;
    }

    // Confirming booking
    printf("Confirm booking (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        hotel_rooms[room_index].availability = 0;
        printf("Room booked successfully!\n");
    } else {
        printf("Booking cancelled.\n");
    }
}

// Function to check out a guest
void check_out() {
    int room_number;

    printf("\nEnter the room number of the guest checking out: ");
    scanf("%d", &room_number);

    // Checking if the room is occupied
    int room_index = -1;
    for (int i = 0; i < sizeof(hotel_rooms) / sizeof(room); i++) {
        if (hotel_rooms[i].room_number == room_number && !hotel_rooms[i].availability) {
            room_index = i;
            break;
        }
    }

    if (room_index == -1) {
        printf("Sorry, the room is not occupied. Please try again.");
        return;
    }

    // Confirming checkout
    char choice;
    printf("Confirm checkout (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        hotel_rooms[room_index].availability = 1;
        printf("Guest checked out successfully!\n");
    } else {
        printf("Checkout cancelled.\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        // Displaying menu options
        printf("\nHotel Management System\n");
        printf("-------------------------\n");
        printf("1. Display Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Check Out a Guest\n");
        printf("4. Exit\n");
        printf("-------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Executing user choice
        switch (choice) {
            case 1:
                display_available_rooms();
                break;
            case 2:
                book_room();
                break;
            case 3:
                check_out();
                break;
            case 4:
                printf("Exiting the system. Thank you for using our services!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}