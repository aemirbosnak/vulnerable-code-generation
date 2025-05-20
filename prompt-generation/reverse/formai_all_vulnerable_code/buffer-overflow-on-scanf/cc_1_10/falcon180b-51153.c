//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_BOOKINGS 1000

typedef struct {
    int room_number;
    char guest_name[50];
    int booking_id;
} Booking;

Booking bookings[MAX_BOOKINGS];

int num_bookings = 0;

void add_booking() {
    int room_number, booking_id, i;
    char guest_name[50];

    printf("Enter room number: ");
    scanf("%d", &room_number);

    printf("Enter guest name: ");
    scanf("%s", guest_name);

    printf("Enter booking ID: ");
    scanf("%d", &booking_id);

    for (i = 0; i < num_bookings; i++) {
        if (bookings[i].room_number == room_number) {
            printf("Room already booked.\n");
            return;
        }
    }

    bookings[num_bookings].room_number = room_number;
    strcpy(bookings[num_bookings].guest_name, guest_name);
    bookings[num_bookings].booking_id = booking_id;
    num_bookings++;

    printf("Booking added.\n");
}

void view_bookings() {
    int i;

    printf("Booking details:\n");
    for (i = 0; i < num_bookings; i++) {
        printf("Room number: %d\n", bookings[i].room_number);
        printf("Guest name: %s\n", bookings[i].guest_name);
        printf("Booking ID: %d\n\n", bookings[i].booking_id);
    }
}

void main() {
    int choice, room_number, booking_id;
    char guest_name[50];

    printf("Welcome to the Hotel Management System!\n");
    printf("1. Add booking\n");
    printf("2. View bookings\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &room_number);

                printf("Enter guest name: ");
                scanf("%s", guest_name);

                printf("Enter booking ID: ");
                scanf("%d", &booking_id);

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