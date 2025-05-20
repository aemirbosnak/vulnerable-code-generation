//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    printf("\nBookings:\n");
    printf("ID\tRoom Number\tGuest Name\n");

    for (int i = 0; i < num_bookings; i++) {
        printf("%d\t%d\t%s\n", i+1, bookings[i].room_number, bookings[i].guest_name);
    }
}

void main() {
    int choice;

    do {
        printf("\nCyberpunk Hotel Management System\n");
        printf("1. Add Booking\n");
        printf("2. View Bookings\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_booking();
                break;
            case 2:
                view_bookings();
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice!= 3);
}