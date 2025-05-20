//FormAI DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void addRoom();
void viewRooms();
void bookRoom();
void viewBookings();

// Structure for rooms
struct Room {
    int roomNo;
    int status;  // 0 for available, 1 for booked
};

// Structure for bookings
struct Booking {
    int roomNo;
    char name[30];
    char checkInDate[15];
    char checkOutDate[15];
};

// Global variables
struct Room rooms[10];
struct Booking bookings[10];
int numRooms = 0;
int numBookings = 0;

int main() {
    int choice;

    do {
        printf("\n\n---- Welcome to C Hotel Management System! ----\n\n");
        printf("1. Add room\n");
        printf("2. View available rooms\n");
        printf("3. Book room\n");
        printf("4. View bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRoom();
                break;
            case 2:
                viewRooms();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                printf("Thank you for using C Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// Function to add a room
void addRoom() {
    if(numRooms >= 10) {
        printf("Sorry, maximum number of rooms exceeded.\n");
        return;
    }

    int roomNo;
    printf("Enter new room number: ");
    scanf("%d", &roomNo);

    // Check if room already exists
    for(int i=0; i<numRooms; i++) {
        if(rooms[i].roomNo == roomNo) {
            printf("Error: Room %d already exists.\n", roomNo);
            return;
        }
    }

    rooms[numRooms].roomNo = roomNo;
    rooms[numRooms].status = 0;
    printf("Room %d has been added successfully.\n", roomNo);
    numRooms++;
}

// Function to view available rooms
void viewRooms() {
    printf("List of available rooms:\n");
    for(int i=0; i<numRooms; i++) {
        if(rooms[i].status == 0) {
            printf("* Room %d\n", rooms[i].roomNo);
        }
    }
}

// Function to book a room
void bookRoom() {
    if(numBookings >= 10) {
        printf("Sorry, maximum number of bookings exceeded.\n");
        return;
    }

    int roomNo;
    printf("Enter room number to book: ");
    scanf("%d", &roomNo);

    // Check if room exists
    int roomIndex = -1;
    for(int i=0; i<numRooms; i++) {
        if(rooms[i].roomNo == roomNo) {
            roomIndex = i;
            break;
        }
    }

    if(roomIndex == -1) {
        printf("Error: Room %d not found.\n", roomNo);
        return;
    }

    if(rooms[roomIndex].status == 1) {
        printf("Error: Room %d is already booked.\n", roomNo);
        return;
    }

    char name[30], checkInDate[15], checkOutDate[15];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter check-in date: ");
    scanf("%s", checkInDate);
    printf("Enter check-out date: ");
    scanf("%s", checkOutDate);

    // Create a new booking
    bookings[numBookings].roomNo = roomNo;
    strcpy(bookings[numBookings].name, name);
    strcpy(bookings[numBookings].checkInDate, checkInDate);
    strcpy(bookings[numBookings].checkOutDate, checkOutDate);
    printf("Room %d has been booked successfully.\n", roomNo);

    // Update room status
    rooms[roomIndex].status = 1;

    numBookings++;
}

// Function to view all bookings
void viewBookings() {
    printf("List of all bookings:\n");
    for(int i=0; i<numBookings; i++) {
        printf("* Room %d booked by %s on %s to %s\n", bookings[i].roomNo, bookings[i].name,
        bookings[i].checkInDate, bookings[i].checkOutDate);
    }
}