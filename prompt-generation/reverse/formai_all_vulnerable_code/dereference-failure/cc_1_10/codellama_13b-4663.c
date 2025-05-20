//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
/* Hotel Management System in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE_LENGTH 3
#define MAX_ROOM_NUMBER 100

struct Customer {
    char name[MAX_NAME_LENGTH];
    int age;
    int roomNumber;
};

struct Room {
    int roomNumber;
    int isOccupied;
    struct Customer customer;
};

struct Hotel {
    struct Room rooms[MAX_ROOM_NUMBER];
    int numRooms;
};

void initializeHotel(struct Hotel *hotel) {
    hotel->numRooms = 0;
}

void addRoom(struct Hotel *hotel, int roomNumber) {
    struct Room newRoom;
    newRoom.roomNumber = roomNumber;
    newRoom.isOccupied = 0;
    hotel->rooms[hotel->numRooms] = newRoom;
    hotel->numRooms++;
}

void printHotel(struct Hotel *hotel) {
    printf("Hotel\n");
    for (int i = 0; i < hotel->numRooms; i++) {
        printf("Room %d: %s\n", hotel->rooms[i].roomNumber, hotel->rooms[i].isOccupied ? "Occupied" : "Vacant");
    }
}

void bookRoom(struct Hotel *hotel, struct Customer *customer) {
    int roomNumber = customer->roomNumber;
    hotel->rooms[roomNumber].isOccupied = 1;
    hotel->rooms[roomNumber].customer = *customer;
}

void unbookRoom(struct Hotel *hotel, int roomNumber) {
    hotel->rooms[roomNumber].isOccupied = 0;
    hotel->rooms[roomNumber].customer.name[0] = '\0';
    hotel->rooms[roomNumber].customer.age = 0;
}

int main() {
    struct Hotel hotel;
    initializeHotel(&hotel);
    addRoom(&hotel, 101);
    addRoom(&hotel, 102);
    addRoom(&hotel, 103);

    struct Customer customer;
    strcpy(customer.name, "John");
    customer.age = 25;
    customer.roomNumber = 101;
    bookRoom(&hotel, &customer);

    printHotel(&hotel);

    unbookRoom(&hotel, 101);

    printHotel(&hotel);

    return 0;
}