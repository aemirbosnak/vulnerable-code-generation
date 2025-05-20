//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel room details
typedef struct HotelRoom {
    int roomNumber;
    char roomType[20];
    int capacity;
    float price;
    int isOccupied;
} HotelRoom;

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Hotel Management System\n");
    printf("1. Add a new room\n");
    printf("2. Display all rooms\n");
    printf("3. Search for a room\n");
    printf("4. Book a room\n");
    printf("5. Check out of a room\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new room
void addNewRoom(HotelRoom *rooms, int *numRooms) {
    printf("Enter room number: ");
    scanf("%d", &rooms[*numRooms].roomNumber);
    printf("Enter room type: ");
    scanf("%s", rooms[*numRooms].roomType);
    printf("Enter room capacity: ");
    scanf("%d", &rooms[*numRooms].capacity);
    printf("Enter room price: ");
    scanf("%f", &rooms[*numRooms].price);
    rooms[*numRooms].isOccupied = 0;
    (*numRooms)++;
}

// Function to display all rooms
void displayAllRooms(HotelRoom *rooms, int numRooms) {
    printf("Room Number\tRoom Type\tCapacity\tPrice\tIs Occupied\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%d\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].capacity, rooms[i].price, rooms[i].isOccupied);
    }
}

// Function to search for a room
void searchForRoom(HotelRoom *rooms, int numRooms) {
    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            printf("Room Number\tRoom Type\tCapacity\tPrice\tIs Occupied\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\t\t%d\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].capacity, rooms[i].price, rooms[i].isOccupied);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

// Function to book a room
void bookARoom(HotelRoom *rooms, int numRooms) {
    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isOccupied) {
                printf("Room is already occupied.\n");
            } else {
                rooms[i].isOccupied = 1;
                printf("Room booked successfully.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

// Function to check out of a room
void checkOutRoom(HotelRoom *rooms, int numRooms) {
    int roomNumber;
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    int found = 0;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (!rooms[i].isOccupied) {
                printf("Room is already empty.\n");
            } else {
                rooms[i].isOccupied = 0;
                printf("Checked out of room successfully.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Room not found.\n");
    }
}

// Main function
int main() {
    // Initialize the hotel rooms array
    HotelRoom rooms[100];
    int numRooms = 0;

    // Display the menu
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addNewRoom(rooms, &numRooms);
                break;
            case 2:
                displayAllRooms(rooms, numRooms);
                break;
            case 3:
                searchForRoom(rooms, numRooms);
                break;
            case 4:
                bookARoom(rooms, numRooms);
                break;
            case 5:
                checkOutRoom(rooms, numRooms);
                break;
            case 6:
                printf("Thank you for using the Hotel Management System.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 6);

    return 0;
}