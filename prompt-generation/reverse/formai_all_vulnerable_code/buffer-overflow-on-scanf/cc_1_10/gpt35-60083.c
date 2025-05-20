//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a room
struct Room {
    int roomNumber;
    int capacity;
    char available;
};

// Define the structure of a guest
struct Guest {
    char name[50];
    int age;
    char gender[10];
};

// Define the structure of a booking
struct Booking {
    int roomNumber;
    struct Guest guest;
    char checkInDate[20];
    char checkOutDate[20];
};

// Define the function to add a new room to the hotel
void addRoom(struct Room *rooms, int *numRooms) {
    // Increase the number of rooms by 1
    *numRooms += 1;
    // Resize the rooms array
    rooms = (struct Room*)realloc(rooms, *numRooms*sizeof(struct Room));
    // Get the room details from the user
    printf("Enter the room number: ");
    scanf("%d", &rooms[*numRooms-1].roomNumber);
    printf("Enter the room capacity: ");
    scanf("%d", &rooms[*numRooms-1].capacity);
    // Set the room as available
    rooms[*numRooms-1].available = 'Y';
    // Print a message to confirm the room has been added
    printf("Room %d has been added to the hotel.\n", rooms[*numRooms-1].roomNumber);
}

// Define the function to display the available rooms in the hotel
void displayAvailableRooms(struct Room *rooms, int numRooms) {
    printf("Available Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].available == 'Y') {
            printf("%d (Capacity: %d)\n", rooms[i].roomNumber, rooms[i].capacity);
        }
    }
}

// Define the function to book a room
void bookRoom(struct Booking *bookings, int *numBookings, struct Room *rooms, int numRooms) {
    // Get the booking details from the user
    printf("Enter the room number: ");
    int roomNumber;
    scanf("%d", &roomNumber);
    // Check if the room is available
    int roomIndex = -1;
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber && rooms[i].available == 'Y') {
            roomIndex = i;
        }
    }
    if (roomIndex == -1) {
        printf("Room %d is not available.\n", roomNumber);
        return;
    }
    // Set the room as unavailable
    rooms[roomIndex].available = 'N';
    // Increase the number of bookings by 1
    *numBookings = *numBookings + 1;
    // Resize the bookings array
    bookings = (struct Booking*)realloc(bookings, *numBookings*sizeof(struct Booking));
    // Get the guest details from the user
    printf("Enter the guest name: ");
    scanf("%s", bookings[*numBookings-1].guest.name);
    printf("Enter the guest age: ");
    scanf("%d", &bookings[*numBookings-1].guest.age);
    printf("Enter the guest gender: ");
    scanf("%s", bookings[*numBookings-1].guest.gender);
    // Set the booking details
    bookings[*numBookings-1].roomNumber = roomNumber;
    printf("Enter the check-in date (YYYY-MM-DD): ");
    scanf("%s", bookings[*numBookings-1].checkInDate);
    printf("Enter the check-out date (YYYY-MM-DD): ");
    scanf("%s", bookings[*numBookings-1].checkOutDate);
    // Print a message to confirm the booking
    printf("Room %d has been booked by %s.\n", roomNumber, bookings[*numBookings-1].guest.name);
}

// Define the function to display all bookings in the hotel
void displayBookings(struct Booking *bookings, int numBookings) {
    printf("All Bookings:\n");
    for (int i = 0; i < numBookings; i++) {
        printf("Booking %d:\n", i+1);
        printf("   Room Number: %d\n", bookings[i].roomNumber);
        printf("   Guest Name: %s\n", bookings[i].guest.name);
        printf("   Guest Age: %d\n", bookings[i].guest.age);
        printf("   Guest Gender: %s\n", bookings[i].guest.gender);
        printf("   Check-in Date: %s\n", bookings[i].checkInDate);
        printf("   Check-out Date: %s\n", bookings[i].checkOutDate);
    }
}

int main() {
    // Initialize the rooms array
    struct Room *rooms = (struct Room*)malloc(sizeof(struct Room));
    int numRooms = 0;
    // Initialize the bookings array
    struct Booking *bookings = (struct Booking*)malloc(sizeof(struct Booking));
    int numBookings = 0;

    // Display the menu
    int choice = -1;
    while (choice != 0) {
        printf("\n");
        printf("Hotel Management System\n");
        printf("-----------------------\n");
        printf("1. Add Room\n");
        printf("2. Display Available Rooms\n");
        printf("3. Book Room\n");
        printf("4. Display All Bookings\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute the selected option
        switch (choice) {
            case 1:
                addRoom(rooms, &numRooms);
                break;
            case 2:
                displayAvailableRooms(rooms, numRooms);
                break;
            case 3:
                bookRoom(bookings, &numBookings, rooms, numRooms);
                break;
            case 4:
                displayBookings(bookings, numBookings);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    // Free the dynamically allocated memory
    free(rooms);
    free(bookings);

    return 0;
}