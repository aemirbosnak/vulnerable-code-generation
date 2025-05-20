//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 50

// Structure to store hotel information
typedef struct {
    int num_rooms;
    int num_guests;
    int avail_rooms;
    int avail_guests;
    int check_in_time;
    int check_out_time;
} hotel_info;

// Function to initialize hotel information
void init_hotel(hotel_info *hotel) {
    hotel->num_rooms = 0;
    hotel->num_guests = 0;
    hotel->avail_rooms = MAX_ROOMS;
    hotel->avail_guests = MAX_GUESTS;
    hotel->check_in_time = time(NULL);
    hotel->check_out_time = time(NULL) + 3600; // 1 hour from current time
}

// Function to check if a room is available
int is_room_available(hotel_info *hotel, int room_number) {
    if (room_number < 0 || room_number >= hotel->num_rooms) {
        return 0;
    }
    if (hotel->avail_rooms <= 0) {
        return 0;
    }
    return 1;
}

// Function to check if a guest is available
int is_guest_available(hotel_info *hotel, int guest_number) {
    if (guest_number < 0 || guest_number >= hotel->num_guests) {
        return 0;
    }
    if (hotel->avail_guests <= 0) {
        return 0;
    }
    return 1;
}

// Function to book a room
void book_room(hotel_info *hotel, int room_number) {
    if (!is_room_available(hotel, room_number)) {
        printf("Sorry, there are no available rooms.\n");
        return;
    }
    hotel->avail_rooms--;
    hotel->num_rooms++;
    printf("Room %d has been booked.\n", room_number);
}

// Function to check out a guest
void check_out(hotel_info *hotel, int guest_number) {
    if (!is_guest_available(hotel, guest_number)) {
        printf("Sorry, there is no guest with that number.\n");
        return;
    }
    hotel->avail_guests++;
    hotel->num_guests--;
    printf("Guest %d has checked out.\n", guest_number);
}

// Function to display hotel information
void display_hotel_info(hotel_info *hotel) {
    printf("Hotel Information:\n");
    printf("  Num Rooms: %d\n", hotel->num_rooms);
    printf("  Num Guests: %d\n", hotel->num_guests);
    printf("  Avail Rooms: %d\n", hotel->avail_rooms);
    printf("  Avail Guests: %d\n", hotel->avail_guests);
    printf("  Check-in Time: %d\n", hotel->check_in_time);
    printf("  Check-out Time: %d\n", hotel->check_out_time);
}

int main() {
    hotel_info hotel;
    init_hotel(&hotel);

    int room_number;
    int guest_number;

    // Example usage of the functions
    book_room(&hotel, 10); // Book room 10
    book_room(&hotel, 20); // Book room 20
    check_out(&hotel, 30); // Check out guest 30

    display_hotel_info(&hotel);

    return 0;
}