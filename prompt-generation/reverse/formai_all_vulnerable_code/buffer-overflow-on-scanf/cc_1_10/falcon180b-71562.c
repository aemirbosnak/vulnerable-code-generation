//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_STAFF 50

typedef struct {
    int roomId;
    char guestName[50];
    char staffName[50];
    int bookingId;
    int arrivalDate;
    int departureDate;
    int duration;
    int totalCost;
} Booking;

typedef struct {
    int staffId;
    char staffName[50];
    char staffAddress[100];
    int staffPhone;
    int staffEmail;
    char staffGender[10];
    int staffSalary;
} Staff;

typedef struct {
    int guestId;
    char guestName[50];
    char guestAddress[100];
    int guestPhone;
    int guestEmail;
    char guestGender[10];
} Guest;

typedef struct {
    int roomId;
    int roomType;
    int roomPrice;
    int roomCapacity;
    int roomStatus;
} Room;

int main() {

    int choice;
    while (1) {
        printf("\n\nWelcome to the Hotel Management System\n");
        printf("1. Book a room\n");
        printf("2. Check-in\n");
        printf("3. Check-out\n");
        printf("4. Manage staff\n");
        printf("5. Manage guests\n");
        printf("6. Manage rooms\n");
        printf("7. View bookings\n");
        printf("8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            //Book a room code goes here
            break;
        case 2:
            //Check-in code goes here
            break;
        case 3:
            //Check-out code goes here
            break;
        case 4:
            //Manage staff code goes here
            break;
        case 5:
            //Manage guests code goes here
            break;
        case 6:
            //Manage rooms code goes here
            break;
        case 7:
            //View bookings code goes here
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}