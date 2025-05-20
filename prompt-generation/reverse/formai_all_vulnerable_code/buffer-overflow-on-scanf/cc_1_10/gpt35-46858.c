//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 1000 // Maximum number of rooms in the hotel
#define MAX_NIGHTS 31 // Maximum number of nights a guest can stay

// Define the structure of a guest
typedef struct {
    char name[50];
    int nights;
    int roomNum;
    float roomRate;
    float totalBill;
} Guest;

// Define the structure of a room
typedef struct {
    int roomNum;
    char type[15];
    float rate;
    int maxNights;
    int booked[MAX_NIGHTS];
} Room;

// Declare global variables
Guest guests[MAX_ROOMS];
Room rooms[MAX_ROOMS];
int numGuests = 0;
int numRooms = 0;

// Function to add a guest to the hotel system
void addGuest() {
    // Check if there are any available rooms
    if (numGuests >= numRooms) {
        printf("Sorry, all rooms are booked.\n");
        return;
    }
    
    // Get guest details
    Guest newGuest;
    printf("Enter guest name: ");
    fgets(newGuest.name, sizeof(newGuest.name), stdin);
    newGuest.name[strcspn(newGuest.name, "\n")] = 0; // Remove newline character
    printf("Enter number of nights: ");
    scanf("%d", &newGuest.nights);
    
    // Display available room types and rates
    printf("Available room types: \n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].maxNights >= newGuest.nights) {
            printf("%d. %s - $%.2f/night\n", rooms[i].roomNum, rooms[i].type, rooms[i].rate);
        }
    }
    
    // Get room number and rate
    do {
        printf("Enter room number: ");
        scanf("%d", &newGuest.roomNum);
        for (int i = 0; i < numRooms; i++) {
            if (newGuest.roomNum == rooms[i].roomNum) {
                if (rooms[i].maxNights >= newGuest.nights) {
                    newGuest.roomRate = rooms[i].rate;
                }
                else {
                    printf("Sorry, this room is only available for a maximum of %d nights.\n", rooms[i].maxNights);
                    newGuest.roomNum = -1; // Set room number to invalid value
                    break;
                }
            }
        }
        if (newGuest.roomNum == -1) continue;
        else if (newGuest.roomRate == 0) printf("Sorry, this room number does not exist or cannot be booked for %d nights.\n", newGuest.nights);
    } while (newGuest.roomNum == -1 || newGuest.roomRate == 0);
    
    // Calculate and store total bill
    newGuest.totalBill = newGuest.nights * newGuest.roomRate;
    
    // Add guest to system
    guests[numGuests] = newGuest;
    numGuests++;
    
    printf("Guest successfully added!\n");
}

// Function to display guest information
void displayGuest() {
    int guestNum;
    printf("Enter guest number (1-%d): ", numGuests);
    scanf("%d", &guestNum);
    if (guestNum < 1 || guestNum > numGuests) printf("Invalid guest number.\n");
    else {
        Guest guest = guests[guestNum-1];
        printf("Guest name: %s\n", guest.name);
        printf("Number of nights: %d\n", guest.nights);
        printf("Room number: %d\n", guest.roomNum);
        printf("Room rate: $%.2f/night\n", guest.roomRate);
        printf("Total bill: $%.2f\n", guest.totalBill);
    }
}

// Function to display the status of all rooms for a given date range
void displayRoomStatus() {
    int startDay, endDay;
    printf("Enter start day (1-%d): ", MAX_NIGHTS);
    scanf("%d", &startDay);
    printf("Enter end day (1-%d): ", MAX_NIGHTS);
    scanf("%d", &endDay);
    if (startDay < 1 || startDay > MAX_NIGHTS || endDay < 1 || endDay > MAX_NIGHTS || endDay < startDay) printf("Invalid date range.\n");
    else {
        printf("Room status for days %d-%d:\n", startDay, endDay);
        for (int i = 0; i < numRooms; i++) {
            printf("Room %d (%s) - $%.2f/night: ", rooms[i].roomNum, rooms[i].type, rooms[i].rate);
            for (int j = startDay-1; j < endDay; j++) {
                printf("%c ", (rooms[i].booked[j] == 0) ? '-' : 'X');
            }
            printf("\n");
        }
    }
}

// Function to quit the program
void quit() {
    printf("Thank you for using the hotel management system. Goodbye!\n");
    exit(0);
}

int main() {
    // Add sample room data
    Room room1 = {1, "Single", 75.0, 31, {0}};
    Room room2 = {2, "Double", 125.0, 14, {0}};
    Room room3 = {3, "Suite", 200.0, 7, {0}};
    rooms[0] = room1;
    rooms[1] = room2;
    rooms[2] = room3;
    numRooms = 3;
    
    printf("Welcome to the hotel management system!\n");
    
    // Main program loop
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add guest\n");
        printf("2. Display guest information\n");
        printf("3. Display room status for a date range\n");
        printf("4. Quit\n");
        
        int choice;
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Remove newline character from stdin
        
        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                displayGuest();
                break;
            case 3:
                displayRoomStatus();
                break;
            case 4:
                quit();
                break;
            default:
                printf("Invalid choice. Please enter a value from 1-4.\n");
        }
    }
    
    return 0;
}