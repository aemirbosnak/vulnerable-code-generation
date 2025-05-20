//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel room data
typedef struct room {
    int room_number;
    char room_type[20];
    int capacity;
    float price;
    int availability;
} room;

// Function to display the list of available rooms
void display_rooms(room rooms[], int num_rooms) {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].availability == 1) {
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Room Type: %s\n", rooms[i].room_type);
            printf("Capacity: %d\n", rooms[i].capacity);
            printf("Price: %.2f\n", rooms[i].price);
            printf("\n");
        }
    }
}

// Function to book a room
void book_room(room rooms[], int num_rooms) {
    int room_number, num_guests;

    printf("\nEnter the room number you want to book: ");
    scanf("%d", &room_number);

    int room_index = -1;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            room_index = i;
            break;
        }
    }

    if (room_index == -1) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    if (rooms[room_index].availability == 0) {
        printf("Sorry, the room is not available. Please try again.\n");
        return;
    }

    printf("\nEnter the number of guests: ");
    scanf("%d", &num_guests);

    if (num_guests > rooms[room_index].capacity) {
        printf("Sorry, the room capacity is not enough for the number of guests. Please try again.\n");
        return;
    }

    rooms[room_index].availability = 0;
    printf("\nRoom booked successfully.\n");
}

// Function to check out a room
void check_out_room(room rooms[], int num_rooms) {
    int room_number;

    printf("\nEnter the room number of the guest checking out: ");
    scanf("%d", &room_number);

    int room_index = -1;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            room_index = i;
            break;
        }
    }

    if (room_index == -1) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    if (rooms[room_index].availability == 1) {
        printf("The guest has already checked out.\n");
        return;
    }

    rooms[room_index].availability = 1;
    printf("\nGuest checked out successfully.\n");
}

// Main function
int main() {
    // Initialize the list of hotel rooms
    room rooms[] = {
        {101, "Standard", 2, 50.00, 1},
        {102, "Deluxe", 4, 75.00, 1},
        {103, "Suite", 6, 100.00, 1},
        {104, "Presidential Suite", 8, 150.00, 1}
    };

    int num_rooms = sizeof(rooms) / sizeof(rooms[0]);

    // Display the main menu
    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Display Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Check Out a Room\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_rooms(rooms, num_rooms);
                break;
            case 2:
                book_room(rooms, num_rooms);
                break;
            case 3:
                check_out_room(rooms, num_rooms);
                break;
            case 4:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}