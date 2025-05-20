//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants
#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 1000

// Defining structures
typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int numDays;
    float roomRate;
    float totalBill;
} RoomRecord;
typedef struct {
    RoomRecord records[MAX_RECORDS];
    int numRoomsBooked;
} Hotel;

// Function to get user input
void getUserInput(RoomRecord *roomRecord) {
    printf("Enter room number: ");
    scanf("%d", &(roomRecord->roomNumber));
    printf("Enter guest name: ");
    scanf("%s", roomRecord->guestName);
    printf("Enter number of days: ");
    scanf("%d", &(roomRecord->numDays));
    printf("Enter room rate: ");
    scanf("%f", &(roomRecord->roomRate));
}

// Function to calculate total bill
void calculateTotalBill(RoomRecord *roomRecord) {
    roomRecord->totalBill = roomRecord->numDays * roomRecord->roomRate;
}

// Function to display room record
void displayRoomRecord(RoomRecord roomRecord) {
    printf("Room Number: %d\n", roomRecord.roomNumber);
    printf("Guest Name: %s\n", roomRecord.guestName);
    printf("Number of Days: %d\n", roomRecord.numDays);
    printf("Room Rate: %.2f\n", roomRecord.roomRate);
    printf("Total Bill: %.2f\n", roomRecord.totalBill);
}

// Function to add a room record to the hotel
void addRoomRecord(Hotel *hotel, RoomRecord *roomRecord) {
    calculateTotalBill(roomRecord);
    hotel->records[hotel->numRoomsBooked] = *roomRecord;
    hotel->numRoomsBooked++;
}

// Function to display all room records in the hotel
void displayAllRoomRecords(Hotel hotel) {
    printf("Room Records:\n");
    for (int i = 0; i < hotel.numRoomsBooked; i++) {
        printf("Record Number: %d\n", i + 1);
        displayRoomRecord(hotel.records[i]);
        printf("\n");
    }
}

int main() {
    // Initializing hotel
    Hotel hotel;
    hotel.numRoomsBooked = 0;

    // Menu loop
    int choice = -1;
    while (choice != 3) {
        // Displaying menu
        printf("Hotel Management System\n");
        printf("1. Book a Room\n");
        printf("2. Display All Rooms\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Handling choice
        switch (choice) {
            case 1:
                // Adding a room record
                if (hotel.numRoomsBooked == MAX_ROOMS) {
                    printf("Max rooms booked! Cannot book any more rooms.\n");
                } else {
                    RoomRecord roomRecord;
                    getUserInput(&roomRecord);
                    addRoomRecord(&hotel, &roomRecord);
                    printf("Room booked successfully!\n");
                }
                break;
            case 2:
                // Displaying all room records
                displayAllRoomRecords(hotel);
                break;
            case 3:
                // Quitting program
                printf("Exiting program...\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}