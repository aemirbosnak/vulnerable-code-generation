//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int roomNumber;
    int guestCount;
    double pricePerNight;
} Room;

typedef struct {
    char name[50];
    int arrivalDate;
    int departureDate;
} Guest;

typedef struct {
    int roomNumber;
    int guestCount;
    int bookingsCount;
} RoomStatus;

void addGuest(Guest *guest) {
    printf("Guest added successfully!\n");
}

void removeGuest(Guest *guest) {
    printf("Guest removed successfully!\n");
}

void bookRoom(Guest *guest, RoomStatus *roomStatus) {
    printf("Room booked successfully!\n");
}

void unbookRoom(Guest *guest, RoomStatus *roomStatus) {
    printf("Room unbooked successfully!\n");
}

double calculateRevenue(int totalBookings) {
    return (totalBookings * 100.00);
}

int main() {
    srand(time(NULL));
    Room rooms[10];
    Guest guests[10];
    RoomStatus roomStatus[10];
    int totalGuests = 0;
    int totalBookings = 0;

    for (int i = 0; i < 10; i++) {
        rooms[i].roomNumber = rand() % 10 + 1;
        rooms[i].guestCount = 0;
        rooms[i].pricePerNight = rand() % 100 + 1.00;
    }

    for (int i = 0; i < 10; i++) {
        guests[i].name[0] = 'G';
        guests[i].arrivalDate = rand() % 100 + 1;
        guests[i].departureDate = rand() % 100 + 1;
        totalGuests++;
    }

    for (int i = 0; i < 10; i++) {
        roomStatus[i].roomNumber = rand() % 10 + 1;
        roomStatus[i].guestCount = 0;
        roomStatus[i].bookingsCount = 0;
    }

    int numGuests = 0;
    int numRooms = 0;
    int numBooking = 0;

    for (int i = 0; i < 10; i++) {
        numGuests += guests[i].arrivalDate - guests[i].departureDate;
        numRooms += rand() % 10 + 1;
        numBooking += rand() % 10 + 1;
    }

    printf("Number of guests: %d\n", numGuests);
    printf("Number of rooms: %d\n", numRooms);
    printf("Number of bookings: %d\n", numBooking);

    for (int i = 0; i < numGuests; i++) {
        Guest *guest = &guests[i];
        RoomStatus *roomStatus = &roomStatus[guest->arrivalDate - 1];

        if (roomStatus->guestCount < rooms[guest->arrivalDate - 1].guestCount) {
            bookRoom(guest, roomStatus);
            printf("Room %d booked for guest %s on %d\n", guest->arrivalDate - 1, guest->name, guest->arrivalDate);
            totalBookings++;
        } else {
            printf("No room available for guest %s on %d\n", guest->name, guest->arrivalDate);
        }
    }

    printf("Total revenue: $%.2f\n", calculateRevenue(totalBookings));

    return 0;
}