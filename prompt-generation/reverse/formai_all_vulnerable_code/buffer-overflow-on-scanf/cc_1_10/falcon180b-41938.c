//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100
#define MAX_BOOKINGS 100

typedef struct {
    int roomNumber;
    char guestName[50];
    int checkInDate;
    int checkOutDate;
    int bookingID;
} Booking;

typedef struct {
    int roomNumber;
    char roomType[10];
    int pricePerNight;
    int availability;
} Room;

typedef struct {
    char name[50];
    char address[100];
    int phoneNumber;
} Guest;

int main() {
    Room rooms[MAX_ROOMS];
    Guest guests[MAX_GUESTS];
    Booking bookings[MAX_BOOKINGS];

    int numRooms, numGuests, numBookings;

    printf("Enter the number of rooms: ");
    scanf("%d", &numRooms);

    printf("Enter the number of guests: ");
    scanf("%d", &numGuests);

    printf("Enter the number of bookings: ");
    scanf("%d", &numBookings);

    for (int i = 0; i < numRooms; i++) {
        printf("Enter the details for room %d:\n", i + 1);
        printf("Room number: ");
        scanf("%d", &rooms[i].roomNumber);
        printf("Room type: ");
        scanf("%s", rooms[i].roomType);
        printf("Price per night: ");
        scanf("%d", &rooms[i].pricePerNight);
        printf("Availability: ");
        scanf("%d", &rooms[i].availability);
    }

    for (int i = 0; i < numGuests; i++) {
        printf("Enter the details for guest %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", guests[i].name);
        printf("Address: ");
        scanf("%s", guests[i].address);
        printf("Phone number: ");
        scanf("%d", &guests[i].phoneNumber);
    }

    for (int i = 0; i < numBookings; i++) {
        printf("Enter the details for booking %d:\n", i + 1);
        printf("Room number: ");
        scanf("%d", &bookings[i].roomNumber);
        printf("Guest name: ");
        scanf("%s", bookings[i].guestName);
        printf("Check-in date: ");
        scanf("%d", &bookings[i].checkInDate);
        printf("Check-out date: ");
        scanf("%d", &bookings[i].checkOutDate);
    }

    return 0;
}