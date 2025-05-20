//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of struct for the room information 
struct Room {
    int roomNumber;
    int capacity;
    float price;
    char availability[10];
};

// Global variable for the array of rooms and the size of the array
struct Room rooms[10];
int numRooms = 0;

// Function to add Room information to the array of rooms
void addRoom() {
    printf("Enter room number: ");
    scanf("%d", &rooms[numRooms].roomNumber);
    printf("Enter max capacity: ");
    scanf("%d", &rooms[numRooms].capacity);
    printf("Enter price: $");
    scanf("%f", &rooms[numRooms].price);
    strcpy(rooms[numRooms].availability, "available");
    numRooms++;
    printf("Room added successfully.\n");
}

// Function to display all the rooms in the system
void displayRooms() {
    printf("Rooms currently available:\n");
    for(int i = 0; i < numRooms; i++) {
        printf("Room #%d - Capacity: %d - Price: $%.2f - Availability: %s\n", rooms[i].roomNumber, rooms[i].capacity, rooms[i].price, rooms[i].availability);
    }
}

// Function to book a room based on the user's input
void bookRoom() {
    int roomToBook;
    printf("Enter the room number you'd like to book: ");
    scanf("%d", &roomToBook);
    for(int i = 0; i < numRooms; i++) {
        if(rooms[i].roomNumber == roomToBook && strcmp(rooms[i].availability, "available") == 0) {
            printf("Booking room #%d for $%.2f.\n", rooms[i].roomNumber, rooms[i].price);
            strcpy(rooms[i].availability, "booked");
            return;
        }
    }
    printf("Room not found or already booked.\n");
}

int main() {
    // Adding sample rooms to the system
    struct Room room1 = {101, 2, 89.99, "available"};
    rooms[0] = room1;
    struct Room room2 = {102, 4, 129.99, "available"};
    rooms[1] = room2;
    struct Room room3 = {103, 5, 149.99, "available"};
    rooms[2] = room3;
    numRooms = 3;
    
    // Game loop - continuously prompt user for the action they want to take
    while(1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add a room to the system\n");
        printf("2. Display all available rooms\n");
        printf("3. Book a room\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addRoom();
                break;
            case 2:
                displayRooms();
                break;
            case 3:
                bookRoom();
                break;
            case 4:
                printf("Quitting hotel management system.\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
    return 0;
}