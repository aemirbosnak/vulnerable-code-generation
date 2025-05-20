//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int roomNumber;
    double pricePerNight;
    int occupancy;
} Room;

typedef struct {
    char name[100];
    int checkInDate;
    int checkOutDate;
    int roomNumber;
} Booking;

int main() {
    Room* rooms = malloc(5 * sizeof(Room));
    Booking* bookings = malloc(10 * sizeof(Booking));

    printf("Enter the number of rooms: ");
    int numRooms = scanf("%d", &numRooms);
    for (int i = 0; i < numRooms; i++) {
        printf("Enter room details for room %d:\n", i+1);
        scanf("%s %d %lf %d", rooms[i].name, &rooms[i].roomNumber, &rooms[i].pricePerNight, &rooms[i].occupancy);
    }

    printf("Enter the number of bookings: ");
    int numBookings = scanf("%d", &numBookings);
    for (int i = 0; i < numBookings; i++) {
        printf("Enter booking details for booking %d:\n", i+1);
        scanf("%s %d %d %d", bookings[i].name, &bookings[i].checkInDate, &bookings[i].checkOutDate, &bookings[i].roomNumber);
    }

    printf("Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %s, %d, $%.2lf, %d\n", i+1, rooms[i].name, rooms[i].roomNumber, rooms[i].pricePerNight, rooms[i].occupancy);
    }

    printf("Bookings:\n");
    for (int i = 0; i < numBookings; i++) {
        printf("Booking %d: %s, %d-%d, %d\n", i+1, bookings[i].name, bookings[i].checkInDate, bookings[i].checkOutDate, bookings[i].roomNumber);
    }

    int totalPrice = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].occupancy == 1) {
            totalPrice += rooms[i].pricePerNight * (bookings[i].checkOutDate - bookings[i].checkInDate);
        }
    }

    printf("Total price: $%.2lf\n", totalPrice);

    free(rooms);
    free(bookings);

    return 0;
}