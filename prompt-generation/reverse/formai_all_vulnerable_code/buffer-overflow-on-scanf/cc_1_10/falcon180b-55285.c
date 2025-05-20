//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200
#define MAX_BOOKINGS 500

typedef struct {
    int roomNumber;
    char guestName[50];
    int bookingId;
    int checkInDate;
    int checkOutDate;
    int roomRate;
} Booking;

typedef struct {
    int roomNumber;
    int roomType;
    int roomRate;
    char roomStatus;
} Room;

int main() {
    int choice;
    char ch;

    while(1) {
        system("clear");
        printf("\n\n\t\t\t\t\tHotel Management System\n");
        printf("\n1. Room Booking\n2. Room Availability\n3. Guest Details\n4. Room Status\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter guest name: ");
                scanf("%s", &ch);
                break;
            case 2:
                printf("\nEnter check-in date (dd/mm/yyyy): ");
                scanf("%s", &ch);
                break;
            case 3:
                printf("\nEnter guest name: ");
                scanf("%s", &ch);
                break;
            case 4:
                printf("\nEnter room number: ");
                scanf("%d", &ch);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}