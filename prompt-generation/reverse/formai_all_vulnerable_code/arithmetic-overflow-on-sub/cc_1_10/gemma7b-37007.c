//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the remote control vehicle structure
typedef struct Vehicle
{
    int x;
    int y;
    int direction;
} Vehicle;

// Create a global variable to store the vehicle
Vehicle vehicle;

// Function to move the vehicle
void moveVehicle()
{
    switch (vehicle.direction)
    {
        case 0:
            vehicle.x++;
            break;
        case 1:
            vehicle.y++;
            break;
        case 2:
            vehicle.x--;
            break;
        case 3:
            vehicle.y--;
            break;
    }
}

// Function to change the direction of the vehicle
void changeDirection(int newDirection)
{
    vehicle.direction = newDirection;
}

// Main loop
int main()
{
    // Initialize the vehicle
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;

    // Simulate the remote control vehicle
    while (1)
    {
        // Get the direction of the vehicle
        int direction = getchar() - '0';

        // Change the direction of the vehicle
        changeDirection(direction);

        // Move the vehicle
        moveVehicle();

        // Print the position of the vehicle
        printf("x: %d, y: %d\n", vehicle.x, vehicle.y);
    }

    return 0;
}