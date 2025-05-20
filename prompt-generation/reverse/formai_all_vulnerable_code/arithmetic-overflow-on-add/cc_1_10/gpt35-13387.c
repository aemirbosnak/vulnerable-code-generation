//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 5

int main(void) {

    // Initialize variables
    int cars[MAX_CARS];
    int speed[MAX_CARS];
    int num_cars = 0;
    srand(time(NULL)); // Seed random number generator

    // Generate random number of cars
    num_cars = rand() % MAX_CARS + 1;

    // Generate random speeds for each car
    for (int i = 0; i < num_cars; i++) {
        speed[i] = rand() % MAX_SPEED + 1;
    }

    // Simulate traffic flow
    for (int i = 0; i < 60; i++) { // Simulate 1 minute of traffic

        // Check for collisions
        for (int j = 0; j < num_cars; j++) {
            for (int k = j + 1; k < num_cars; k++) {
                if (cars[j] == cars[k]) {
                    printf("Oops! Car %d and Car %d collided!", j + 1, k + 1);
                    exit(1);
                }
            }
        }

        // Move each car
        for (int j = 0; j < num_cars; j++) {
            if (rand() % 2) { // 50/50 chance of changing speed
                speed[j] += rand() % 3 - 1; // Random speed change between -1 and 1
                if (speed[j] < 1) { // Don't go below 1
                    speed[j] = 1;
                }
                if (speed[j] > MAX_SPEED) { // Don't go above MAX_SPEED
                    speed[j] = MAX_SPEED;
                }
            }
            cars[j] += speed[j]; // Move the car
            printf("Car %d moved %d units.\n", j + 1, speed[j]);
        }
    }

    printf("Simulation complete! No collisions occurred.\n");

    return 0;
}