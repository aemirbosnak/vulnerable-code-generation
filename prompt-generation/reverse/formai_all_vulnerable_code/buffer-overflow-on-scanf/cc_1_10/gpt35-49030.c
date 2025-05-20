//FormAI DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int room_number;
    char guest_name[50];
    int nights_stayed;
    float room_rate;
} Booking;

Booking bookings[100];
int num_bookings = 0;

void add_booking() {
    Booking booking;
    printf("Enter room number: ");
    scanf("%d", &booking.room_number);
    printf("Enter guest name: ");
    scanf("%s", booking.guest_name);
    printf("Enter nights stayed: ");
    scanf("%d", &booking.nights_stayed);
    printf("Enter room rate: ");
    scanf("%f", &booking.room_rate);
    bookings[num_bookings] = booking;
    num_bookings++;
}

void list_bookings() {
    printf("Room Number\tGuest Name\tNights Stayed\tRoom Rate\n");
    for (int i = 0; i < num_bookings; i++) {
        Booking booking = bookings[i];
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", booking.room_number, booking.guest_name, booking.nights_stayed, booking.room_rate);
    }
}

void save_bookings() {
    FILE *fptr;
    fptr = fopen("bookings.dat", "wb");
    fwrite(bookings, sizeof(Booking), num_bookings, fptr);
    fclose(fptr);
}

void load_bookings() {
    FILE *fptr;
    fptr = fopen("bookings.dat", "rb");
    if (fptr != NULL) {
        num_bookings = fread(bookings, sizeof(Booking), 100, fptr);
        fclose(fptr);
    }
}

int main() {
    load_bookings();

    int choice = 0;
    while (choice != 4) {
        printf("1. Add Booking\n");
        printf("2. List Bookings\n");
        printf("3. Save Bookings\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_booking();
                break;
            case 2:
                list_bookings();
                break;
            case 3:
                save_bookings();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}