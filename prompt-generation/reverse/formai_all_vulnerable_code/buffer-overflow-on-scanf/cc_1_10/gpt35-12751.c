//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the function for the simulation
void start_simulation(int n);

int main() {
    int num_vehicles;
    printf("Enter the number of remote control vehicles: ");
    scanf("%d", &num_vehicles);
    start_simulation(num_vehicles);
    return 0;
}

void start_simulation(int n) {
    // Declare a 2D array to store the current and previous positions of the vehicles
    int positions[2][n];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the positions of the vehicles randomly
    for (int i = 0; i < n; i++) {
        positions[0][i] = rand() % 10;
        positions[1][i] = rand() % 10;
    }

    printf("Starting positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Vehicle %d:\t(%d,%d)\n", i+1, positions[0][i], positions[1][i]);
    }

    // Loop to simulate movement of the vehicles
    int num_moves = 5;
    for (int move = 1; move <= num_moves; move++) {
        printf("\n\nMove %d:\n", move);

        // Loop over each vehicle and randomly change its position
        for (int i = 0; i < n; i++) {
            // Generate a random number between -1 and 1 for both x and y positions
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;

            // Move the vehicle to its new position
            positions[1][i] += dy;
            positions[0][i] += dx;

            // If the vehicle goes outside the bounds of the simulation, reset its position to a random location
            if (positions[0][i] < 0 || positions[0][i] > 9 || positions[1][i] < 0 || positions[1][i] > 9) {
                positions[0][i] = rand() % 10;
                positions[1][i] = rand() % 10;
            }

            // Print the new position of the vehicle
            printf("Vehicle %d: (%d,%d)\n", i+1, positions[0][i], positions[1][i]);
        }
    }

    printf("\n\nSimulation complete.\n");
}