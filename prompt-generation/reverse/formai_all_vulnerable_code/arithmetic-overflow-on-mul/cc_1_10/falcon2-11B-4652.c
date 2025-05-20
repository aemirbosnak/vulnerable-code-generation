//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for a hotel room
struct HotelRoom {
    int roomNumber;
    int bedCount;
    int ratePerNight;
};

// Define the data structure for the hotel
struct Hotel {
    int totalRooms;
    struct HotelRoom* rooms;
};

// Function to create a new hotel
struct Hotel* createHotel(int totalRooms) {
    struct Hotel* hotel = (struct Hotel*) malloc(sizeof(struct Hotel));
    hotel->totalRooms = totalRooms;
    hotel->rooms = (struct HotelRoom*) malloc(totalRooms * sizeof(struct HotelRoom));
    return hotel;
}

// Function to add a new room to the hotel
void addRoom(struct Hotel* hotel, int roomNumber, int bedCount, int ratePerNight) {
    if (hotel->totalRooms >= hotel->rooms) {
        printf("Sorry, the hotel is full.\n");
        return;
    }

    struct HotelRoom* newRoom = &(hotel->rooms[hotel->totalRooms]);
    newRoom->roomNumber = roomNumber;
    newRoom->bedCount = bedCount;
    newRoom->ratePerNight = ratePerNight;

    hotel->totalRooms++;
}

// Function to check the availability of a room
int checkRoomAvailability(struct Hotel* hotel, int roomNumber) {
    if (roomNumber >= hotel->totalRooms) {
        printf("Room number %d is not available.\n", roomNumber);
        return 0;
    }

    return 1;
}

// Function to book a room
void bookRoom(struct Hotel* hotel, int roomNumber) {
    if (!checkRoomAvailability(hotel, roomNumber)) {
        printf("Sorry, room number %d is not available.\n", roomNumber);
        return;
    }

    printf("You have booked room number %d.\n", roomNumber);
}

// Function to check out of a room
void checkOut(struct Hotel* hotel, int roomNumber) {
    if (!checkRoomAvailability(hotel, roomNumber)) {
        printf("Sorry, room number %d is not available.\n", roomNumber);
        return;
    }

    printf("Room number %d has been checked out.\n", roomNumber);
}

// Function to calculate the total bill for a room
int calculateBill(struct Hotel* hotel, int roomNumber) {
    if (!checkRoomAvailability(hotel, roomNumber)) {
        printf("Sorry, room number %d is not available.\n", roomNumber);
        return -1;
    }

    int bedCount = hotel->rooms[roomNumber].bedCount;
    int ratePerNight = hotel->rooms[roomNumber].ratePerNight;
    int totalBill = bedCount * ratePerNight;

    printf("The total bill for room number %d is %d.\n", roomNumber, totalBill);
    return totalBill;
}

int main() {
    // Create a new hotel with 10 rooms
    struct Hotel* hotel = createHotel(10);

    // Add some rooms to the hotel
    addRoom(hotel, 1, 2, 100);
    addRoom(hotel, 2, 1, 200);
    addRoom(hotel, 3, 3, 150);

    // Check the availability of a room
    int roomNumber = 4;
    if (checkRoomAvailability(hotel, roomNumber)) {
        printf("Room number %d is available.\n", roomNumber);
    } else {
        printf("Room number %d is not available.\n", roomNumber);
    }

    // Book a room
    bookRoom(hotel, roomNumber);

    // Check out of a room
    checkOut(hotel, roomNumber);

    // Calculate the total bill for a room
    int totalBill = calculateBill(hotel, roomNumber);

    return 0;
}