//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100
#define MAX_BOOKINGS 1000

typedef struct {
    int room_number;
    char customer_name[50];
    int booking_date;
    int booking_days;
} Booking;

typedef struct {
    char name[50];
    char address[100];
    int phone_number;
} Customer;

typedef struct {
    int room_number;
    int room_type;
    int room_price;
    int room_status;
} Room;

void create_customer(Customer* customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer address: ");
    scanf("%s", customer->address);
    printf("Enter customer phone number: ");
    scanf("%d", &customer->phone_number);
}

void create_room(Room* room) {
    printf("Enter room number: ");
    scanf("%d", &room->room_number);
    printf("Enter room type: ");
    scanf("%d", &room->room_type);
    printf("Enter room price: ");
    scanf("%d", &room->room_price);
    printf("Enter room status: ");
    scanf("%d", &room->room_status);
}

void create_booking(Booking* booking) {
    printf("Enter room number: ");
    scanf("%d", &booking->room_number);
    printf("Enter customer name: ");
    scanf("%s", booking->customer_name);
    printf("Enter booking date: ");
    scanf("%d", &booking->booking_date);
    printf("Enter booking days: ");
    scanf("%d", &booking->booking_days);
}

void display_bookings(Booking* bookings, int count) {
    printf("Bookings:\n");
    for (int i = 0; i < count; i++) {
        printf("Room number: %d\nCustomer name: %s\nBooking date: %d\nBooking days: %d\n\n", bookings[i].room_number, bookings[i].customer_name, bookings[i].booking_date, bookings[i].booking_days);
    }
}

void main() {
    Customer customer;
    create_customer(&customer);

    Room rooms[MAX_ROOMS];
    int room_count = 0;
    while (room_count < MAX_ROOMS) {
        create_room(&rooms[room_count]);
        room_count++;
    }

    Booking bookings[MAX_BOOKINGS];
    int booking_count = 0;
    while (booking_count < MAX_BOOKINGS) {
        create_booking(&bookings[booking_count]);
        booking_count++;
    }

    display_bookings(bookings, booking_count);
}