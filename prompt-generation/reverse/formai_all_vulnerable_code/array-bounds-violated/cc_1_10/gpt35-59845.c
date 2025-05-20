//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200

// Define a structure for a room
typedef struct Room {
    int number;
    char type[20];
    int price;
    int occupied;
} Room;

// Define a structure for a guest
typedef struct Guest {
    char name[50];
    char phone[15];
    char email[50];
    int roomNumber;
} Guest;

// Define an array of rooms
Room rooms[MAX_ROOMS];

// Define an array of guests
Guest guests[MAX_GUESTS];

// Define variables for counting rooms and guests
int numRooms = 0;
int numGuests = 0;

// Function to add a room
void addRoom(int number, char* type, int price) {
    rooms[numRooms].number = number;
    strcpy(rooms[numRooms].type, type);
    rooms[numRooms].price = price;
    rooms[numRooms].occupied = 0;
    numRooms++;
}

// Function to add a guest
void addGuest(char* name, char* phone, char* email, int roomNumber) {
    strcpy(guests[numGuests].name, name);
    strcpy(guests[numGuests].phone, phone);
    strcpy(guests[numGuests].email, email);
    guests[numGuests].roomNumber = roomNumber;
    rooms[roomNumber-1].occupied = 1;
    numGuests++;
}

// Function to print all rooms
void printRooms() {
    printf("Rooms:\n");
    printf("Number\tType\tPrice\tOccupied\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d\t%s\t%d\t%s\n", rooms[i].number, rooms[i].type, rooms[i].price, rooms[i].occupied ? "Yes" : "No");
    }
}

// Function to print all guests
void printGuests() {
    printf("Guests:\n");
    printf("Name\tPhone\tEmail\tRoom Number\n");
    for (int i = 0; i < numGuests; i++) {
        printf("%s\t%s\t%s\t%d\n", guests[i].name, guests[i].phone, guests[i].email, guests[i].roomNumber);
    }
}

int main() {
    // Add some rooms
    addRoom(101, "Standard", 100);
    addRoom(102, "Standard", 100);
    addRoom(103, "Deluxe", 150);
    addRoom(104, "Suite", 200);

    // Add some guests
    addGuest("John Smith", "555-1234", "john.smith@example.com", 101);
    addGuest("Jane Doe", "555-5678", "jane.doe@example.com", 103);

    // Print all rooms and guests
    printRooms();
    printGuests();

    // Exit program
    return 0;
}