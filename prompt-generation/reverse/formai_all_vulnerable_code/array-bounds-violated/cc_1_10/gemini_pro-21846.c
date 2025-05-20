//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the size of the grid
#define GRID_SIZE 10

// Define the number of cars per lane
#define NUM_CARS_PER_LANE 10

// Define the speed of the cars
#define CAR_SPEED 1

// Define the probability of a car turning left or right
#define TURN_PROBABILITY 0.1

// Create a 2D array to represent the grid
int grid[GRID_SIZE][GRID_SIZE];

// Create an array to store the cars
struct car {
    int x;
    int y;
    int direction;
};
struct car cars[NUM_CARS_PER_LANE * 4];

// Initialize the grid
void init_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// Initialize the cars
void init_cars() {
    int index = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Add a car to the grid
            cars[index].x = i;
            cars[index].y = j;
            cars[index].direction = rand() % 4;
            index++;
        }
    }
}

// Update the grid
void update_grid() {
    // Clear the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // Update the cars
    for (int i = 0; i < NUM_CARS_PER_LANE * 4; i++) {
        // Move the car
        switch (cars[i].direction) {
            case 0:
                cars[i].x++;
                break;
            case 1:
                cars[i].y++;
                break;
            case 2:
                cars[i].x--;
                break;
            case 3:
                cars[i].y--;
                break;
        }

        // Check if the car has reached the edge of the grid
        if (cars[i].x < 0 || cars[i].x >= GRID_SIZE || cars[i].y < 0 || cars[i].y >= GRID_SIZE) {
            // Wrap the car around to the other side of the grid
            if (cars[i].x < 0) {
                cars[i].x = GRID_SIZE - 1;
            } else if (cars[i].x >= GRID_SIZE) {
                cars[i].x = 0;
            } else if (cars[i].y < 0) {
                cars[i].y = GRID_SIZE - 1;
            } else if (cars[i].y >= GRID_SIZE) {
                cars[i].y = 0;
            }
        }

        // Check if the car is about to collide with another car
        for (int j = 0; j < NUM_CARS_PER_LANE * 4; j++) {
            if (i != j && cars[i].x == cars[j].x && cars[i].y == cars[j].y) {
                // The cars have collided
                cars[i].direction = rand() % 4;
                cars[j].direction = rand() % 4;
            }
        }

        // Add the car to the grid
        grid[cars[i].x][cars[i].y] = 1;
    }
}

// Print the grid
void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the grid
    init_grid();

    // Initialize the cars
    init_cars();

    // Run the simulation
    for (int i = 0; i < 1000; i++) {
        // Update the grid
        update_grid();

        // Print the grid
        print_grid();

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}