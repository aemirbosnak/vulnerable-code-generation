//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100

typedef struct {
    int room_number;
    char guest_name[50];
    int booking_date;
    int booking_duration;
} Booking;

void add_booking(Booking bookings[], int num_bookings) {
    printf("Enter room number: ");
    int room_number;
    scanf("%d", &room_number);

    printf("Enter guest name: ");
    char guest_name[50];
    scanf("%s", guest_name);

    printf("Enter booking date (YYYY-MM-DD): ");
    int booking_date;
    scanf("%d", &booking_date);

    printf("Enter booking duration: ");
    int booking_duration;
    scanf("%d", &booking_duration);

    Booking booking;
    booking.room_number = room_number;
    strcpy(booking.guest_name, guest_name);
    booking.booking_date = booking_date;
    booking.booking_duration = booking_duration;

    bookings[num_bookings] = booking;
    num_bookings++;
}

void view_bookings(Booking bookings[], int num_bookings) {
    printf("Bookings:\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("%d - %s - %d - %d\n", bookings[i].room_number, bookings[i].guest_name, bookings[i].booking_date, bookings[i].booking_duration);
    }
}

int main() {
    Booking bookings[MAX_BOOKINGS];
    int num_bookings = 0;

    while (1) {
        printf("\nHotel Management System\n");
        printf("1. Add booking\n");
        printf("2. View bookings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_booking(bookings, num_bookings);
            break;
        case 2:
            view_bookings(bookings, num_bookings);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}