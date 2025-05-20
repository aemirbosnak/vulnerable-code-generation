//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for hotels
struct Hotel {
    char name[50];
    int num_rooms;
    int num_occupied;
};

// Function to check if a hotel has available rooms
int available_rooms(struct Hotel hotel) {
    return hotel.num_rooms - hotel.num_occupied;
}

int main() {

    // Declare and initialize array of hotels
    struct Hotel hotels[3] = {
        {"Hilton", 100, 50},
        {"Marriot", 200, 100},
        {"Sheraton", 150, 75}
    };

    // Get user input for hotel name
    char hotel_name[50];
    printf("Enter hotel name: ");
    scanf("%s", hotel_name);

    // Find hotel in array
    struct Hotel selected_hotel;
    int hotel_found = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(hotels[i].name, hotel_name) == 0) {
            selected_hotel = hotels[i];
            hotel_found = 1;
            break;
        }
    }

    // If hotel is not found, exit program
    if (!hotel_found) {
        printf("Hotel not found.\n");
        return 0;
    }

    // Display hotel information
    printf("%s has %d rooms, %d of which are occupied.\n", selected_hotel.name, selected_hotel.num_rooms, selected_hotel.num_occupied);

    // Check if hotel has available rooms
    int available = available_rooms(selected_hotel);

    // Ask user how many rooms they want to book
    int num_rooms;
    printf("How many rooms do you want to book? (There are %d rooms available)\n", available);
    scanf("%d", &num_rooms);

    // If there are not enough available rooms, exit program
    if (num_rooms > available) {
        printf("There are not enough available rooms.\n");
        return 0;
    }

    // Update number of occupied rooms
    selected_hotel.num_occupied += num_rooms;

    // Display booking information
    printf("You have booked %d rooms at %s.\n", num_rooms, selected_hotel.name);
    printf("%s now has %d rooms occupied.\n", selected_hotel.name, selected_hotel.num_occupied);

    return 0;
}