//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Defining the structure for hotel rooms
struct hotelRoom {
    int roomNumber;
    int numOfBeds;
    int price;
    char* guestName;
};

// Defining the structure for hotel booking details
struct booking {
    int roomNumber;
    char* guestName;
    int numOfNights;
    int totalPrice;
};

// Declaring global variables
struct hotelRoom rooms[10];
struct booking bookings[10];
int numRoomsBooked = 0;

// Function to initialize hotel room data
void initializeRooms() {
    for(int i=0; i<10; i++) {
        rooms[i].roomNumber = i+1;
        rooms[i].numOfBeds = (i<5) ? 2 : 3;
        rooms[i].price = (i<5) ? 50 : 75;
        rooms[i].guestName = NULL;
    }
}

// Function to display room details
void displayRoomDetails() {
    printf("\n--------------------------------------------------------------------\n");
    printf("| Room Number\t| Number of Beds\t| Price\t|\tGuest Name\t|\n");
    printf("--------------------------------------------------------------------\n");
    for(int i=0; i<10; i++) {
        printf("| %d\t\t| %d\t\t\t| $%d\t|\t%s\t\t|\n", rooms[i].roomNumber, rooms[i].numOfBeds, rooms[i].price, (rooms[i].guestName == NULL) ? "N/A" : rooms[i].guestName);
    }
    printf("--------------------------------------------------------------------\n");
}

// Function to find an empty room
int findEmptyRoom() {
    for(int i=0; i<10; i++) {
        if(rooms[i].guestName == NULL) {
            return i;
        }
    }
    return -1;
}

// Function to book a room
void bookRoom(int roomNum, char* guestName, int numOfNights) {
    rooms[roomNum-1].guestName = guestName;
    int price = rooms[roomNum-1].price*numOfNights;
    bookings[numRoomsBooked].roomNumber = roomNum;
    bookings[numRoomsBooked].guestName = guestName;
    bookings[numRoomsBooked].numOfNights = numOfNights;
    bookings[numRoomsBooked].totalPrice = price;
    numRoomsBooked++;
}

// Function to display booking details
void displayBookingDetails() {
    printf("\n--------------------------------------------------------------------\n");
    printf("| Room Number\t| Guest Name\t\t| Number of Nights\t| Total Price\t|\n");
    printf("--------------------------------------------------------------------\n");
    for(int i=0; i<numRoomsBooked; i++) {
        printf("| %d\t\t| %s\t\t\t| %d\t\t\t| $%d\t\t|\n", bookings[i].roomNumber, bookings[i].guestName, bookings[i].numOfNights, bookings[i].totalPrice);
    }
    printf("--------------------------------------------------------------------\n");
}

// Main function
int main() {
    int choice, roomNum, numOfNights;
    char* guestName = (char*)malloc(sizeof(char)*50);

    initializeRooms();

    do {
        printf("\nSelect an option:");
        printf("\n1. Display Room Details.");
        printf("\n2. Book a Room.");
        printf("\n3. Display Booking Details.");
        printf("\n4. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRoomDetails();
                break;

            case 2:
                roomNum = findEmptyRoom();
                if(roomNum == -1) {
                    printf("\nThere are no empty rooms currently available.");
                    break;
                }
                printf("\nEnter your name: ");
                scanf("%s", guestName);
                printf("\nEnter the number of nights: ");
                scanf("%d", &numOfNights);
                bookRoom(roomNum+1, guestName, numOfNights);
                printf("\nRoom has been successfully booked for %s with room number %d for %d night(s).", guestName, roomNum+1, numOfNights);
                break;

            case 3:
                if(numRoomsBooked == 0) {
                    printf("\nYou have not booked any rooms yet.");
                    break;
                }
                displayBookingDetails();
                break;

            case 4:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    free(guestName);
    return 0;
}