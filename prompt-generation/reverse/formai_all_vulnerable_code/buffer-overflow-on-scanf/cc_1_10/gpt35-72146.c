//FormAI DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define global variables
int numOfRooms = 20; // total number of rooms
int occupiedRooms = 0; // number of occupied rooms
float pricePerNight = 200.0; // price per night

// Define a structure to hold guest information
typedef struct {
    char name[20];
    int roomNumber;
    int numOfNights;
    float totalPrice;
} Guest;

Guest guests[20]; // Create an array to hold guest info

// Define a function to check if a room is available
int isAvailable(int roomNum) {
    for (int i = 0; i < occupiedRooms; i++) {
        if (guests[i].roomNumber == roomNum) {
            return 0; // Room is occupied
        }
    }
    return 1; // Room is available
}

// Define a function to add a new guest
void addGuest() {
    Guest g;
    int roomNum;
    printf("Enter guest name: ");
    scanf("%s", g.name);
    
    // Check for available rooms before assigning one to the guest
    do {
        printf("Enter room number (1-%d): ", numOfRooms);
        scanf("%d", &roomNum);
    } while (roomNum < 1 || roomNum > numOfRooms || !isAvailable(roomNum));
    g.roomNumber = roomNum;
    printf("Enter number of nights: ");
    scanf("%d", &g.numOfNights);
    
    // Calculate total price
    g.totalPrice = g.numOfNights * pricePerNight;
    
    guests[occupiedRooms] = g; // Add guest to array
    occupiedRooms++; // Increment occupied rooms counter
    printf("Guest %s successfully added to Room %d.\n", g.name, g.roomNumber);
}

// Define a function to remove a guest
void removeGuest() {
    int roomNum;
    printf("Enter room number of guest to remove: ");
    scanf("%d", &roomNum);
    
    for (int i = 0; i < occupiedRooms; i++) {
        if (guests[i].roomNumber == roomNum) {
            // Shift the remaining guests in the array to the left
            for (int j = i; j < occupiedRooms - 1; j++) {
                guests[j] = guests[j+1];
            }
            occupiedRooms--;
            printf("Guest in Room %d successfully removed.\n", roomNum);
            return;
        }
    }
    printf("No guest found in Room %d.\n", roomNum);
}

// Define a function to display guest information
void displayGuests() {
    printf("Total number of rooms: %d\n", numOfRooms);
    printf("Number of occupied rooms: %d\n", occupiedRooms);
    printf("Price per night: $%.2f\n", pricePerNight);
    printf("===============================\n");
    printf("Guest Name\tRoom Number\tNights\tTotal Price\n");
    printf("===============================\n");
    for (int i = 0; i < occupiedRooms; i++) {
        printf("%-20s\t%-10d\t%d\t$%.2f\n", guests[i].name, guests[i].roomNumber, guests[i].numOfNights, guests[i].totalPrice);
    }
    printf("===============================\n");
}

int main() {
    int choice;
    do {
        printf("\nWelcome to the Hotel Management System!\n");
        printf("1. Add guest\n");
        printf("2. Remove guest\n");
        printf("3. Display guests\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                removeGuest();
                break;
            case 3:
                displayGuests();
                break;
            case 4:
                printf("Thank you, come again!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}