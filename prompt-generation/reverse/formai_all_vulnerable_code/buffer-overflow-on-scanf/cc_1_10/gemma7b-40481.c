//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store hotel room information
typedef struct Room {
    int number;
    char type;
    int occupancy;
    float rate;
} Room;

// Define a function to calculate the total cost of a room
float calculate_cost(Room *room) {
    int days = 1;
    float total_cost = 0;

    // Calculate the number of days the room is booked for
    printf("Enter the number of days you will be staying: ");
    scanf("%d", &days);

    // Calculate the total cost of the room
    total_cost = days * room->rate;

    // Return the total cost
    return total_cost;
}

// Define a function to display room information
void display_room(Room *room) {
    printf("Room Number: %d\n", room->number);
    printf("Room Type: %c\n", room->type);
    printf("Occupancy: %d\n", room->occupancy);
    printf("Rate: %.2f\n", room->rate);
}

// Main function
int main() {
    // Create an array of rooms
    Room rooms[10] = {
        {1, 'A', 2, 100.0},
        {2, 'B', 1, 80.0},
        {3, 'A', 3, 120.0},
        {4, 'B', 2, 90.0},
        {5, 'A', 1, 105.0},
        {6, 'B', 3, 85.0},
        {7, 'A', 2, 110.0},
        {8, 'B', 1, 95.0},
        {9, 'A', 3, 125.0},
        {10, 'B', 2, 100.0}
    };

    // Display the room information
    display_room(&rooms[0]);

    // Calculate the total cost of the room
    float total_cost = calculate_cost(&rooms[0]);

    // Display the total cost
    printf("Total Cost: %.2f\n", total_cost);

    return 0;
}