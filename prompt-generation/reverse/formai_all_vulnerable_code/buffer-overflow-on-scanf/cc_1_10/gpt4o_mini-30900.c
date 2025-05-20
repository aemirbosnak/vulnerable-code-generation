//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <string.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Vehicle;

void displayGrid(Vehicle vehicle) {
    system("clear"); // Clear the console
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == vehicle.y && j == vehicle.x) {
                printf(" RV "); // Display the vehicle
            } else {
                printf(" . "); // Display empty space
            }
        }
        printf("\n");
    }
    printf("Control the vehicle with: w (up), a (left), s (down), d (right), q (quit)\n");
}

void moveVehicle(Vehicle *vehicle, char direction) {
    if (direction == 'w' && vehicle->y > 0) vehicle->y--;
    if (direction == 's' && vehicle->y < GRID_SIZE - 1) vehicle->y++;
    if (direction == 'a' && vehicle->x > 0) vehicle->x--;
    if (direction == 'd' && vehicle->x < GRID_SIZE - 1) vehicle->x++;
}

int main() {
    Vehicle vehicle = {2, 2}; // Start vehicle at center of the grid
    char command;

    printf("Welcome to the Peaceful Remote Control Vehicle Simulation!\n");
    sleep(2);

    while (1) {
        displayGrid(vehicle);
        printf("Enter your command: ");
        scanf(" %c", &command); // Space before %c to ignore previous newline

        if (command == 'q') {
            printf("Thank you for participating in this serene simulation. Goodbye!\n");
            break;
        }

        moveVehicle(&vehicle, command);
        if (command != 'w' && command != 'a' && command != 's' && command != 'd') {
            printf("Invalid command. Please use 'w', 'a', 's', 'd', or 'q'.\n");
        }
        sleep(1); // Add a small delay for peaceful effect
    }

    return 0;
}