//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100

typedef struct {
    int room_number;
    char guest_name[50];
    char check_in_date[10];
    char check_out_date[10];
    int booking_status;
} Booking;

Booking bookings[MAX_BOOKINGS];
int num_bookings = 0;

void add_booking() {
    printf("Enter room number: ");
    scanf("%d", &bookings[num_bookings].room_number);
    printf("Enter guest name: ");
    scanf("%s", bookings[num_bookings].guest_name);
    printf("Enter check-in date (dd/mm/yyyy): ");
    scanf("%s", bookings[num_bookings].check_in_date);
    printf("Enter check-out date (dd/mm/yyyy): ");
    scanf("%s", bookings[num_bookings].check_out_date);
    bookings[num_bookings].booking_status = 1;
    num_bookings++;
    printf("\nBooking added successfully.\n");
}

void view_bookings() {
    printf("\nBookings:\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("Room number: %d\nGuest name: %s\nCheck-in date: %s\nCheck-out date: %s\nBooking status: %d\n\n", bookings[i].room_number, bookings[i].guest_name, bookings[i].check_in_date, bookings[i].check_out_date, bookings[i].booking_status);
    }
}

void cancel_booking() {
    printf("Enter booking ID: ");
    int id;
    scanf("%d", &id);
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].booking_status == 1 && bookings[i].room_number == id) {
            bookings[i].booking_status = 0;
            printf("\nBooking cancelled successfully.\n");
            return;
        }
    }
    printf("\nBooking not found.\n");
}

void main() {
    int choice;
    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add booking\n2. View bookings\n3. Cancel booking\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_booking();
                break;
            case 2:
                view_bookings();
                break;
            case 3:
                cancel_booking();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}