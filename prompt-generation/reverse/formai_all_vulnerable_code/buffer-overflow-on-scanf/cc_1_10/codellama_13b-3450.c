//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for hotel rooms
struct HotelRoom {
    int room_number;
    char room_type[20];
    int room_price;
    int room_status;
};

// Define structure for hotel guests
struct HotelGuest {
    int guest_id;
    char guest_name[50];
    char guest_address[100];
    char guest_contact[20];
};

// Define structure for hotel bookings
struct HotelBooking {
    int booking_id;
    int guest_id;
    int room_number;
    char check_in_date[20];
    char check_out_date[20];
    int total_price;
};

// Define function to create a new hotel room
void create_new_room(struct HotelRoom* room) {
    printf("Enter room number: ");
    scanf("%d", &room->room_number);
    printf("Enter room type (e.g. single, double, suite): ");
    scanf("%s", room->room_type);
    printf("Enter room price: ");
    scanf("%d", &room->room_price);
    printf("Enter room status (0 for available, 1 for occupied): ");
    scanf("%d", &room->room_status);
}

// Define function to create a new hotel guest
void create_new_guest(struct HotelGuest* guest) {
    printf("Enter guest ID: ");
    scanf("%d", &guest->guest_id);
    printf("Enter guest name: ");
    scanf("%s", guest->guest_name);
    printf("Enter guest address: ");
    scanf("%s", guest->guest_address);
    printf("Enter guest contact: ");
    scanf("%s", guest->guest_contact);
}

// Define function to create a new hotel booking
void create_new_booking(struct HotelBooking* booking) {
    printf("Enter booking ID: ");
    scanf("%d", &booking->booking_id);
    printf("Enter guest ID: ");
    scanf("%d", &booking->guest_id);
    printf("Enter room number: ");
    scanf("%d", &booking->room_number);
    printf("Enter check-in date (DD/MM/YYYY): ");
    scanf("%s", booking->check_in_date);
    printf("Enter check-out date (DD/MM/YYYY): ");
    scanf("%s", booking->check_out_date);
    printf("Enter total price: ");
    scanf("%d", &booking->total_price);
}

// Define function to display hotel rooms
void display_rooms(struct HotelRoom* rooms, int num_rooms) {
    printf("Hotel Rooms\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%d. Room number: %d, Room type: %s, Room price: %d, Room status: %d\n", i + 1, rooms[i].room_number, rooms[i].room_type, rooms[i].room_price, rooms[i].room_status);
    }
}

// Define function to display hotel guests
void display_guests(struct HotelGuest* guests, int num_guests) {
    printf("Hotel Guests\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%d. Guest ID: %d, Guest name: %s, Guest address: %s, Guest contact: %s\n", i + 1, guests[i].guest_id, guests[i].guest_name, guests[i].guest_address, guests[i].guest_contact);
    }
}

// Define function to display hotel bookings
void display_bookings(struct HotelBooking* bookings, int num_bookings) {
    printf("Hotel Bookings\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("%d. Booking ID: %d, Guest ID: %d, Room number: %d, Check-in date: %s, Check-out date: %s, Total price: %d\n", i + 1, bookings[i].booking_id, bookings[i].guest_id, bookings[i].room_number, bookings[i].check_in_date, bookings[i].check_out_date, bookings[i].total_price);
    }
}

int main() {
    // Create an array of hotel rooms
    struct HotelRoom rooms[10];
    int num_rooms = 10;

    // Create an array of hotel guests
    struct HotelGuest guests[10];
    int num_guests = 10;

    // Create an array of hotel bookings
    struct HotelBooking bookings[10];
    int num_bookings = 10;

    // Create a new hotel room
    create_new_room(&rooms[0]);

    // Create a new hotel guest
    create_new_guest(&guests[0]);

    // Create a new hotel booking
    create_new_booking(&bookings[0]);

    // Display hotel rooms
    display_rooms(rooms, num_rooms);

    // Display hotel guests
    display_guests(guests, num_guests);

    // Display hotel bookings
    display_bookings(bookings, num_bookings);

    return 0;
}