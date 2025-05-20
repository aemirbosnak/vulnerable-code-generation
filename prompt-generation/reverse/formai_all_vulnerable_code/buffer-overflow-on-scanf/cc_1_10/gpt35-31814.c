//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a struct for each guest
struct Guest {
    char name[30];
    int roomNumber;
    int nightsStayed;
    float billAmount;
};

// defining a struct for the hotel's room inventory
struct Room {
    int number;
    int capacity;
    float pricePerNight;
    int availability;
};

// function to display the hotel's room inventory
void displayInventory(struct Room rooms[], int count) {
    printf("Room Number\tCapacity\tPrice per Night\tAvailability\n");
    for(int i=0; i<count; i++) {
        printf("%d\t\t%d\t\t%.2f\t\t", rooms[i].number, rooms[i].capacity, rooms[i].pricePerNight);
        if(rooms[i].availability) {
            printf("Available\n");
        } else {
            printf("Booked\n");
        }
    }
}

// function to check if a room is available
int isRoomAvailable(struct Room rooms[], int count, int roomNumber) {
    for(int i=0; i<count; i++) {
        if(rooms[i].number == roomNumber && rooms[i].availability) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int numRooms, numGuests;
    printf("Welcome to the C Hotel Management System!\n");

    // get number of rooms and guests from user
    printf("Please enter the number of rooms in the hotel:");
    scanf("%d", &numRooms);
    printf("Please enter the maximum number of guests that can stay in the hotel:");
    scanf("%d", &numGuests);

    // create room inventory and guest list
    struct Room rooms[numRooms];
    struct Guest guests[numGuests];

    // initialize room inventory with default values
    for(int i=0; i<numRooms; i++) {
        rooms[i].number = i+1;
        rooms[i].capacity = 2;
        rooms[i].pricePerNight = 100;
        rooms[i].availability = 1;
    }

    // display room inventory
    displayInventory(rooms, numRooms);

    // book a room for a guest
    int roomNumber, nightsStayed;
    char name[30];
    printf("Please enter your name:");
    scanf("%s", name);
    printf("Please enter the room number:");
    scanf("%d", &roomNumber);
    if(isRoomAvailable(rooms, numRooms, roomNumber)) {
        printf("Please enter the number of nights you will be staying:");
        scanf("%d", &nightsStayed);
        // update room inventory and guest list
        for(int i=0; i<numRooms; i++) {
            if(rooms[i].number == roomNumber) {
                rooms[i].availability = 0;
                break;
            }
        }
        for(int i=0; i<numGuests; i++) {
            if(guests[i].roomNumber == 0) {
                guests[i].roomNumber = roomNumber;
                guests[i].nightsStayed = nightsStayed;
                guests[i].billAmount = nightsStayed * rooms[roomNumber-1].pricePerNight;
                // only copy up to 30 characters of name to ensure it fits in struct
                strncpy(guests[i].name, name, 29);
                break;
            }
        }
        printf("Congratulations! Room %d has been booked for you.\n", roomNumber);
    } else {
        printf("Sorry, room %d is not available at this time.\n", roomNumber);
    }

    // display updated room inventory
    displayInventory(rooms, numRooms);

    // display guest list
    printf("Name\tRoom Number\tNights Stayed\tBill Amount\n");
    for(int i=0; i<numGuests; i++) {
        if(guests[i].roomNumber != 0) {
            printf("%s\t%d\t\t%d\t\t%.2f\n", guests[i].name, guests[i].roomNumber, guests[i].nightsStayed, guests[i].billAmount);
        }
    }

    return 0;
}