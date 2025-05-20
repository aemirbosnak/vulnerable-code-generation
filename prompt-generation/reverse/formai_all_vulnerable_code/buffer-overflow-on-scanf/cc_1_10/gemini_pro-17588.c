//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of guests and rooms
#define MAX_GUESTS 100
#define MAX_ROOMS 50

// Define the data structure for a guest
typedef struct guest {
    int id;
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
} guest;

// Define the data structure for a room
typedef struct room {
    int id;
    char type[20];
    int capacity;
    float price;
    int availability;
} room;

// Define the data structure for a reservation
typedef struct reservation {
    int id;
    int guest_id;
    int room_id;
    char check_in[20];
    char check_out[20];
} reservation;

// Function to add a new guest
void add_guest(guest *guests, int *num_guests) {
    // Get the guest's details
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);

    printf("Enter guest address: ");
    scanf("%s", guests[*num_guests].address);

    printf("Enter guest phone number: ");
    scanf("%s", guests[*num_guests].phone);

    printf("Enter guest email address: ");
    scanf("%s", guests[*num_guests].email);

    // Increment the number of guests
    (*num_guests)++;
}

// Function to add a new room
void add_room(room *rooms, int *num_rooms) {
    // Get the room's details
    printf("Enter room type: ");
    scanf("%s", rooms[*num_rooms].type);

    printf("Enter room capacity: ");
    scanf("%d", &rooms[*num_rooms].capacity);

    printf("Enter room price: ");
    scanf("%f", &rooms[*num_rooms].price);

    // Set the room's availability to 1 (available)
    rooms[*num_rooms].availability = 1;

    // Increment the number of rooms
    (*num_rooms)++;
}

// Function to make a new reservation
void make_reservation(guest *guests, room *rooms, reservation *reservations, int *num_reservations) {
    // Get the guest's ID
    int guest_id;
    printf("Enter guest ID: ");
    scanf("%d", &guest_id);

    // Get the room's ID
    int room_id;
    printf("Enter room ID: ");
    scanf("%d", &room_id);

    // Get the check-in date
    char check_in[20];
    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", check_in);

    // Get the check-out date
    char check_out[20];
    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", check_out);

    // Create a new reservation
    reservation new_reservation;
    new_reservation.id = *num_reservations;
    new_reservation.guest_id = guest_id;
    new_reservation.room_id = room_id;
    strcpy(new_reservation.check_in, check_in);
    strcpy(new_reservation.check_out, check_out);

    // Add the new reservation to the array of reservations
    reservations[*num_reservations] = new_reservation;

    // Increment the number of reservations
    (*num_reservations)++;
}

// Function to display all guests
void display_guests(guest *guests, int num_guests) {
    printf("\nGuests:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%d. %s\n", guests[i].id, guests[i].name);
    }
}

// Function to display all rooms
void display_rooms(room *rooms, int num_rooms) {
    printf("\nRooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%d. %s (%d guests, $%.2f/night)\n", rooms[i].id, rooms[i].type, rooms[i].capacity, rooms[i].price);
    }
}

// Function to display all reservations
void display_reservations(reservation *reservations, int num_reservations) {
    printf("\nReservations:\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("%d. Guest %d, Room %d, Check-in: %s, Check-out: %s\n", reservations[i].id, reservations[i].guest_id, reservations[i].room_id, reservations[i].check_in, reservations[i].check_out);
    }
}

// Main function
int main() {
    // Create arrays to store the guests, rooms, and reservations
    guest guests[MAX_GUESTS];
    room rooms[MAX_ROOMS];
    reservation reservations[MAX_GUESTS];

    // Initialize the number of guests, rooms, and reservations to 0
    int num_guests = 0;
    int num_rooms = 0;
    int num_reservations = 0;

    // Main loop
    while (1) {
        // Display the menu
        printf("\nHotel Management System\n");
        printf("1. Add a new guest\n");
        printf("2. Add a new room\n");
        printf("3. Make a new reservation\n");
        printf("4. Display all guests\n");
        printf("5. Display all rooms\n");
        printf("6. Display all reservations\n");
        printf("7. Exit\n");

        // Get the user's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_guest(guests, &num_guests);
                break;
            case 2:
                add_room(rooms, &num_rooms);
                break;
            case 3:
                make_reservation(guests, rooms, reservations, &num_reservations);
                break;
            case 4:
                display_guests(guests, num_guests);
                break;
            case 5:
                display_rooms(rooms, num_rooms);
                break;
            case 6:
                display_reservations(reservations, num_reservations);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}