//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Struct definition for each room in the hotel
struct Room {
    int id;
    int capacity;
    int price;
    int occupied;
};

// Function to display all available rooms in the hotel
void displayRooms(struct Room rooms[], int n) {
    printf("Available Rooms:\n");
    for (int i = 0; i < n; i++) {
        if (!rooms[i].occupied) {
            printf("Room %d - Capacity: %d - Price: %d\n", rooms[i].id, rooms[i].capacity, rooms[i].price);
        }
    }
}

int main() {
    // Initialize the available rooms in the hotel
    struct Room rooms[10];
    rooms[0] = (struct Room){1, 2, 50, 0};
    rooms[1] = (struct Room){2, 2, 50, 0};
    rooms[2] = (struct Room){3, 2, 50, 0};
    rooms[3] = (struct Room){4, 4, 100, 0};
    rooms[4] = (struct Room){5, 4, 100, 0};
    rooms[5] = (struct Room){6, 4, 100, 0};
    rooms[6] = (struct Room){7, 6, 150, 0};
    rooms[7] = (struct Room){8, 6, 150, 0};
    rooms[8] = (struct Room){9, 6, 150, 0};
    rooms[9] = (struct Room){10, 8, 200, 0};
    
    // Display the available rooms
    displayRooms(rooms, 10);
    
    // Prompt the user to select a room
    int choice;
    printf("\nEnter the room number you would like to book: ");
    scanf("%d", &choice);
    
    // Validate the user's choice
    if (choice < 1 || choice > 10 || rooms[choice-1].occupied) {
        printf("\nInvalid Room Selection\n");
        return 0;
    }
    
    // Prompt the user for the number of guests
    int guests;
    printf("Enter the number of guests: ");
    scanf("%d", &guests);
    
    // Validate the maximum capacity for the room
    if (guests > rooms[choice-1].capacity) {
        printf("\nRoom capacity exceeded\n");
        return 0;
    }
    
    // Calculate the total cost of the stay
    int nights;
    printf("Enter the number of nights: ");
    scanf("%d", &nights);
    int cost = nights * rooms[choice-1].price;
    
    // Update the room status to occupied
    rooms[choice-1].occupied = 1;
    
    // Display the booking confirmation
    printf("\nBooking Confirmation:\n");
    printf("Room %d - Capacity: %d - Price: %d per night\n", rooms[choice-1].id, rooms[choice-1].capacity, rooms[choice-1].price);
    printf("Guests: %d - Nights: %d\n", guests, nights);
    printf("Total Cost: %d\n", cost);
    
    return 0;
}