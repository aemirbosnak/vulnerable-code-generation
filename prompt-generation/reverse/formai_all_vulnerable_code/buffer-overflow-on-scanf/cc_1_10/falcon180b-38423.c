//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: statistical
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
    printf("Enter room number: ");
    scanf("%d", &bookings[num_bookings].room_number);

    printf("Enter guest name: ");
    scanf("%s", bookings[num_bookings].guest_name);

    printf("Enter booking ID: ");
    scanf("%d", &bookings[num_bookings].booking_id);

    num_bookings++;
}

void view_bookings() {
    printf("Bookings:\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("Room number: %d\nGuest name: %s\nBooking ID: %d\n", bookings[i].room_number, bookings[i].guest_name, bookings[i].booking_id);
    }
}

void search_booking_by_id(int id) {
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].booking_id == id) {
            printf("Booking found:\n");
            printf("Room number: %d\nGuest name: %s\n", bookings[i].room_number, bookings[i].guest_name);
        }
    }
}

void main() {
    int choice;

    do {
        printf("\nHotel Management System\n");
        printf("1. Add booking\n2. View bookings\n3. Search booking by ID\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_booking();
                break;
            case 2:
                view_bookings();
                break;
            case 3:
                printf("Enter booking ID: ");
                int id;
                scanf("%d", &id);
                search_booking_by_id(id);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
}