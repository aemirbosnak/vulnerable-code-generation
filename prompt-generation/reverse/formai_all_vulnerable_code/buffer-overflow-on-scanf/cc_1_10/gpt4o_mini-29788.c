//GPT-4o-mini DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct {
    int roomNumber;
    char type[20];
    int isBooked;
    char guestName[50];
} Room;

Room rooms[MAX_ROOMS];
int totalRooms;

void initializeRooms() {
    for (int i = 0; i < totalRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = 0; // 0 means available
        if (i % 2 == 0) {
            strcpy(rooms[i].type, "Single");
        } else {
            strcpy(rooms[i].type, "Double");
        }
    }
}

void displayAvailableRooms() {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < totalRooms; i++) {
        if (!rooms[i].isBooked) {
            printf("Room Number: %d, Type: %s\n", rooms[i].roomNumber, rooms[i].type);
        }
    }
}

void checkIn() {
    char name[50];
    int roomNumber;

    displayAvailableRooms();
    
    printf("\nEnter Room Number to Check In: ");
    scanf("%d", &roomNumber);
    roomNumber--; // Adjust for zero indexing

    if (roomNumber < 0 || roomNumber >= totalRooms || rooms[roomNumber].isBooked) {
        printf("Invalid or already booked Room Number!\n");
        return;
    }

    printf("Enter Guest Name: ");
    scanf(" %[^\n]", name);

    rooms[roomNumber].isBooked = 1;
    strcpy(rooms[roomNumber].guestName, name);
    printf("Check-in successful for %s in Room %d!\n", name, rooms[roomNumber].roomNumber);
}

void checkOut() {
    int roomNumber;

    printf("\nEnter Room Number to Check Out: ");
    scanf("%d", &roomNumber);
    roomNumber--; // Adjust for zero indexing

    if (roomNumber < 0 || roomNumber >= totalRooms || !rooms[roomNumber].isBooked) {
        printf("Invalid Room Number or not booked!\n");
        return;
    }

    printf("Check-out successful for %s from Room %d!\n", rooms[roomNumber].guestName, rooms[roomNumber].roomNumber);
    rooms[roomNumber].isBooked = 0; // Mark room as available
    memset(rooms[roomNumber].guestName, 0, sizeof(rooms[roomNumber].guestName));
}

void displayBookingDetails() {
    printf("\nBooking Details:\n");
    for (int i = 0; i < totalRooms; i++) {
        if (rooms[i].isBooked) {
            printf("Room Number: %d, Type: %s, Guest Name: %s\n",
                   rooms[i].roomNumber, rooms[i].type, rooms[i].guestName);
        }
    }
}

int main() {
    printf("Welcome to the Hotel Management System!\n");
    printf("Enter the total number of rooms: ");
    scanf("%d", &totalRooms);

    if (totalRooms > MAX_ROOMS || totalRooms <= 0) {
        printf("Invalid number of rooms!\n");
        return 1;
    }

    initializeRooms();

    int choice;
    do {
        printf("\n1. Check In\n2. Check Out\n3. View Available Rooms\n4. View Booking Details\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkIn();
                break;
            case 2:
                checkOut();
                break;
            case 3:
                displayAvailableRooms();
                break;
            case 4:
                displayBookingDetails();
                break;
            case 5:
                printf("Exiting the Hotel Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}