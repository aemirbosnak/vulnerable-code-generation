//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ROOMS 100
#define MAX_BOOKINGS 500

// Structs
typedef struct {
    int room_number;
    int capacity;
    double price;
    int available;
} Room;

typedef struct {
    char name[50];
    int room_number;
    int num_guests;
    int num_nights;
    double total_price;
    int paid;
} Booking;

// Global Variables
Room rooms[MAX_ROOMS];
Booking bookings[MAX_BOOKINGS];
int num_rooms = 0;
int num_bookings = 0;

// Function Prototypes
void add_room();
void book_room();
void print_bookings();
void print_available_rooms();

// Main Function
int main() {
    int choice;

    printf("Welcome to the C Hotel Management System\n");

    while (1) {
        printf("\nEnter an option:\n");
        printf("1. Add a room\n");
        printf("2. Book a room\n");
        printf("3. Print all bookings\n");
        printf("4. Print available rooms\n");
        printf("5. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room();
                break;

            case 2:
                book_room();
                break;

            case 3:
                print_bookings();
                break;

            case 4:
                print_available_rooms();
                break;

            case 5:
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option, try again.\n");
                break;
        }
    }

    return 0;
}

void add_room() {
    // Check if max number of rooms has been reached
    if (num_rooms == MAX_ROOMS) {
        printf("Max number of rooms have already been added.\n");
        return;
    }

    // Prompt user for room information
    int room_number, capacity;
    double price;

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter room capacity: ");
    scanf("%d", &capacity);

    printf("Enter room price: ");
    scanf("%lf", &price);

    // Add room to the array
    Room new_room = {room_number, capacity, price, 1};
    rooms[num_rooms++] = new_room;

    printf("Room %d added successfully!\n", room_number);
}

void book_room() {
    // Check if max number of bookings has been reached
    if (num_bookings == MAX_BOOKINGS) {
        printf("Max number of bookings have already been made.\n");
        return;
    }

    // Prompt user for booking information
    char name[50];
    int num_guests, num_nights;
    int room_number;
    int room_index, booking_index;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter number of guests: ");
    scanf("%d", &num_guests);

    printf("Enter number of nights: ");
    scanf("%d", &num_nights);

    printf("Enter desired room number: ");
    scanf("%d", &room_number);

    // Find the room and check availability
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].available) {
                // Book the room
                rooms[i].available = 0;

                // Add the booking
                Booking new_booking = {name, room_number, num_guests, num_nights, num_nights * rooms[i].price, 0};
                bookings[num_bookings++] = new_booking;

                printf("Booking successful! Your total price is $%.2lf.\n", num_nights * rooms[i].price);

                return;
            } else {
                printf("Room %d is unavailable.\n", room_number);
                return;
            }
        }
    }

    printf("Room %d does not exist.\n", room_number);
}

void print_bookings() {
    printf("Here are all the current bookings:\n");

    for (int i = 0; i < num_bookings; i++) {
        Booking current_booking = bookings[i];

        printf("Name: %s\n", current_booking.name);
        printf("Room number: %d\n", current_booking.room_number);
        printf("Number of guests: %d\n", current_booking.num_guests);
        printf("Number of nights: %d\n", current_booking.num_nights);
        printf("Total price: $%.2lf\n", current_booking.total_price);

        if (!current_booking.paid) {
            printf("Amount due: $%.2lf\n", current_booking.total_price);
        } else {
            printf("Amount paid: $%.2lf\n", current_booking.total_price);
        }
    }
}

void print_available_rooms() {
    printf("Here are all the available rooms:\n");

    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].available) {
            printf("Room number: %d\n", rooms[i].room_number);
            printf("Room capacity: %d\n", rooms[i].capacity);
            printf("Room price: $%.2lf\n", rooms[i].price);
        }
    }
}