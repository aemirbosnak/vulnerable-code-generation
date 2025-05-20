//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: active
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

typedef struct {
    char name[50];
    int age;
    char address[100];
} Guest;

typedef struct {
    int room_number;
    int price_per_night;
    int available;
} Room;

int main() {
    int choice;
    char ch;

    do {
        printf("\nHotel Management System\n");
        printf("1. Book a Room\n");
        printf("2. Check Availability\n");
        printf("3. View Booking Details\n");
        printf("4. Cancel Booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", &ch);
                printf("Enter your age: ");
                scanf("%d", &ch);
                printf("Enter your address: ");
                scanf("%s", &ch);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &ch);
                break;
            case 3:
                printf("Enter booking ID: ");
                scanf("%d", &ch);
                break;
            case 4:
                printf("Enter booking ID: ");
                scanf("%d", &ch);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}