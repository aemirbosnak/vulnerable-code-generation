//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000
#define MAX_BOOKINGS 10000

typedef struct {
    int room_number;
    char guest_name[50];
    int booking_id;
} Booking;

Booking bookings[MAX_BOOKINGS];
int num_bookings = 0;

void add_booking() {
    int room_number, booking_id;
    char guest_name[50];

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter guest name: ");
    scanf("%s", guest_name);

    printf("Enter booking ID: ");
    scanf("%d", &booking_id);

    if (num_bookings >= MAX_BOOKINGS) {
        printf("Sorry, no more bookings can be added.\n");
        return;
    }

    bookings[num_bookings].room_number = room_number;
    strcpy(bookings[num_bookings].guest_name, guest_name);
    bookings[num_bookings].booking_id = booking_id;

    num_bookings++;
}

void view_bookings() {
    int i;

    printf("\nBookings:\n");
    for (i = 0; i < num_bookings; i++) {
        printf("Room number: %d\nGuest name: %s\nBooking ID: %d\n", bookings[i].room_number, bookings[i].guest_name, bookings[i].booking_id);
    }
}

void main() {
    int choice;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add booking\n2. View bookings\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_booking();
                break;
            case 2:
                view_bookings();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}