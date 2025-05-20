//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50      // Maximum number of cars on road
#define MAX_CAPACITY 100 // Maximum car capacity on the road
#define MAX_SPEED 120    // Maximum speed limit on the road

// Function to simulate car movement on the road
void SimulateTrafficFlow(int cars[], int n_cars, int capacity, int speed_limit) {
    int i, j;
    int count = 0;

    // Print initial state of the road
    printf("Initial Traffic Flow:\n");
    for (i = 0; i < n_cars; i++) {
        printf("Car %d is at position %d\n", i+1, cars[i]);
    }

    // Randomize car speeds and move cars along the road
    srand(time(NULL));
    while (count < 10) {
        for (i = 0; i < n_cars; i++) {
            cars[i] += rand() % speed_limit + 1;
            if (cars[i] > capacity) {
                cars[i] = cars[i] % capacity;
            }

            // Check for car collisions
            for (j = i + 1; j < n_cars; j++) {
                if (cars[i] == cars[j]) {
                    printf("Collision detected between Car %d and Car %d!\n", i+1, j+1);
                }
            }
            printf("Car %d is at position %d\n", i+1, cars[i]);
        }
        count++;
    }
}

// Main function to initialize and run the traffic simulation
int main() {
    int n_cars;
    int capacity, speed_limit;

    // Prompt user input
    printf("Enter number of cars: ");
    scanf("%d", &n_cars);
    printf("Enter road capacity: ");
    scanf("%d", &capacity);
    printf("Enter speed limit: ");
    scanf("%d", &speed_limit);

    // Check input validity
    if (n_cars >= MAX_CARS) {
        printf("Error: Maximum number of cars is %d\n", MAX_CARS);
        return 1;
    }
    if (capacity >= MAX_CAPACITY) {
        printf("Error: Maximum capacity is %d\n", MAX_CAPACITY);
        return 1;
    }
    if (speed_limit >= MAX_SPEED) {
        printf("Error: Maximum speed limit is %d\n", MAX_SPEED);
        return 1;
    }

    // Initialize car positions on the road
    int i, cars[n_cars];
    srand(time(NULL));
    for (i = 0; i < n_cars; i++) {
        cars[i] = rand() % capacity + 1;
    }

    // Run simulation and print final state of the road
    SimulateTrafficFlow(cars, n_cars, capacity, speed_limit);
    printf("Final Traffic Flow:\n");
    for (i = 0; i < n_cars; i++) {
        printf("Car %d is at position %d\n", i+1, cars[i]);
    }

    return 0;
}