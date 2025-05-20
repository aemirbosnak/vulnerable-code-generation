//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: all-encompassing
/*
 * hotel_management_system.c
 *
 * A unique C Hotel Management System example program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a guest in the hotel
typedef struct {
    char name[50];
    char address[50];
    char phone_number[20];
    int room_number;
    int stay_length;
    double room_rate;
} Guest;

// Structure to represent a room in the hotel
typedef struct {
    int room_number;
    int room_type;
    int capacity;
    int occupancy;
    double room_rate;
} Room;

// Structure to represent a reservation in the hotel
typedef struct {
    Guest guest;
    Room room;
    int stay_length;
    double room_rate;
    double total_cost;
} Reservation;

// Function to create a new guest
Guest create_guest(char name[50], char address[50], char phone_number[20]) {
    Guest guest;
    strcpy(guest.name, name);
    strcpy(guest.address, address);
    strcpy(guest.phone_number, phone_number);
    return guest;
}

// Function to create a new room
Room create_room(int room_number, int room_type, int capacity, int occupancy) {
    Room room;
    room.room_number = room_number;
    room.room_type = room_type;
    room.capacity = capacity;
    room.occupancy = occupancy;
    return room;
}

// Function to create a new reservation
Reservation create_reservation(Guest guest, Room room, int stay_length) {
    Reservation reservation;
    reservation.guest = guest;
    reservation.room = room;
    reservation.stay_length = stay_length;
    return reservation;
}

// Function to check if a room is available
int is_room_available(Room room) {
    return room.occupancy < room.capacity;
}

// Function to display a guest's information
void display_guest_info(Guest guest) {
    printf("Name: %s\n", guest.name);
    printf("Address: %s\n", guest.address);
    printf("Phone Number: %s\n", guest.phone_number);
}

// Function to display a room's information
void display_room_info(Room room) {
    printf("Room Number: %d\n", room.room_number);
    printf("Room Type: %d\n", room.room_type);
    printf("Capacity: %d\n", room.capacity);
    printf("Occupancy: %d\n", room.occupancy);
    printf("Room Rate: %lf\n", room.room_rate);
}

// Function to display a reservation's information
void display_reservation_info(Reservation reservation) {
    printf("Guest Information:\n");
    display_guest_info(reservation.guest);
    printf("Room Information:\n");
    display_room_info(reservation.room);
    printf("Stay Length: %d\n", reservation.stay_length);
    printf("Room Rate: %lf\n", reservation.room_rate);
    printf("Total Cost: %lf\n", reservation.total_cost);
}

// Function to make a reservation
void make_reservation(Guest guest, Room room, int stay_length) {
    Reservation reservation = create_reservation(guest, room, stay_length);
    reservation.total_cost = reservation.room_rate * reservation.stay_length;
    printf("Reservation Made!\n");
    display_reservation_info(reservation);
}

int main() {
    // Create a guest
    Guest guest = create_guest("John Doe", "123 Main St", "555-555-5555");

    // Create a room
    Room room = create_room(101, 1, 2, 0);

    // Check if the room is available
    if (is_room_available(room)) {
        // Make a reservation
        make_reservation(guest, room, 3);
    } else {
        printf("Sorry, the room is not available.\n");
    }

    return 0;
}