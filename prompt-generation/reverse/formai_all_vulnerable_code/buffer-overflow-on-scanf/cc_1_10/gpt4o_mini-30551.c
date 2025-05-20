//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_BOOKINGS 100
#define NAME_LENGTH 50
#define STATUS_LENGTH 20

typedef struct {
    int roomNumber;
    char type[20];
    double price;
    int isBooked;
} Room;

typedef struct {
    int bookingID;
    char customerName[NAME_LENGTH];
    int roomNumber;
    char checkInDate[11];
    char checkOutDate[11];
} Booking;

// Global arrays for rooms and bookings
Room rooms[MAX_ROOMS];
Booking bookings[MAX_BOOKINGS];
int roomCount = 0, bookingCount = 0;

// Function declarations
void initRooms();
void displayRooms();
void bookRoom();
void displayBookings();
void paranoidCheck();

int main() {
    paranoidCheck();
    
    int choice;
    do {
        printf("\n=== Hotel Management System ===\n");
        printf("1. Initialize Rooms\n");
        printf("2. Display Rooms\n");
        printf("3. Book Room\n");
        printf("4. Display Bookings\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                initRooms();
                break;
            case 2: 
                displayRooms();
                break;
            case 3: 
                bookRoom();
                break;
            case 4: 
                displayBookings();
                break;
            case 5: 
                printf("Exiting the system... Until next time, trust no one!\n");
                break;
            default: 
                printf("Invalid choice! Stay vigilant!\n");
        }
    } while (choice != 5);

    return 0;
}

void initRooms() {
    if (roomCount > 0) {
        printf("Rooms are already initialized! Stay alert!\n");
        return;
    }
    
    // Initialize some rooms with paranoia about room types and prices
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        if (i % 2 == 0) {
            strcpy(rooms[i].type, "Single");
            rooms[i].price = 100 + (rand() % 50);
        } else {
            strcpy(rooms[i].type, "Double");
            rooms[i].price = 150 + (rand() % 100);
        }
        rooms[i].isBooked = 0;
    }
    roomCount = MAX_ROOMS;
    printf("Rooms have been initialized! But, are they really safe?\n");
}

void displayRooms() {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < roomCount; i++) {
        if (!rooms[i].isBooked) {
            printf("Room Number: %d | Type: %s | Price: $%.2f\n",
                    rooms[i].roomNumber, rooms[i].type, rooms[i].price);
        }
    }
    printf("Always check twice! You never know...\n");
}

void bookRoom() {
    int roomNo;
    char name[NAME_LENGTH];
    char checkIn[11], checkOut[11];

    printf("Enter room number to book: ");
    scanf("%d", &roomNo);
    
    if (roomNo < 1 || roomNo > MAX_ROOMS || rooms[roomNo - 1].isBooked) {
        printf("Invalid room number or the room is already booked! Watch out!\n");
        return;
    }

    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", checkIn);
    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", checkOut);

    Booking newBooking;
    newBooking.bookingID = bookingCount + 1;
    strcpy(newBooking.customerName, name);
    newBooking.roomNumber = roomNo;
    strcpy(newBooking.checkInDate, checkIn);
    strcpy(newBooking.checkOutDate, checkOut);
    
    bookings[bookingCount++] = newBooking;
    rooms[roomNo - 1].isBooked = 1;

    printf("Room booked successfully! But remember, trust no one.\n");
}

void displayBookings() {
    printf("\nCurrent Bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("Booking ID: %d | Customer: %s | Room: %d | Check-in: %s | Check-out: %s\n",
                bookings[i].bookingID, bookings[i].customerName,
                bookings[i].roomNumber, bookings[i].checkInDate, bookings[i].checkOutDate);
    }
    printf("Stay vigilant! Always verify guests...\n");
}

void paranoidCheck() {
    // Just a precautionary function to keep things on edge.
    printf("Performing a paranoid security check...\n");
    // A mock check - you can enhance this with actual security measures
    if (rand() % 2 == 0) {
        printf("Security clearance passed. All is good! But, who's watching?\n");
    } else {
        printf("Security alert! Check logs for intruders! Be cautious!\n");
    }
}