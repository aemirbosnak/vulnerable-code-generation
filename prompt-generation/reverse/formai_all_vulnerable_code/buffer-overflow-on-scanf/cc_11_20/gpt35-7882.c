//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 50 // maximum distance between cars
#define MAX_CARS 10 // maximum number of cars on the road

int main() {
    int num_cars;
    srand(time(NULL)); // seed the random number generator
    
    printf("Enter number of cars on the road (1 to %d): ", MAX_CARS);
    scanf("%d", &num_cars);
    
    if (num_cars < 1 || num_cars > MAX_CARS) {
        printf("Invalid number of cars.\n");
        exit(1);
    }
    
    int distances[MAX_CARS]; // distances between cars
    int speeds[MAX_CARS]; // speeds of cars
    int positions[MAX_CARS]; // positions of cars on the road
    
    // initialize distances to a random value between 1 and MAX_DISTANCE
    for (int i = 0; i < num_cars; i++) {
        distances[i] = rand() % MAX_DISTANCE + 1;
    }
    
    // initialize speeds to a random value between 1 and 5
    for (int i = 0; i < num_cars; i++) {
        speeds[i] = rand() % 5 + 1;
    }
    
    // initialize positions to 0
    for (int i = 0; i < num_cars; i++) {
        positions[i] = 0;
    }
    
    // simulate traffic flow for 10 time steps
    for (int t = 0; t < 10; t++) {
        printf("Time step %d:\n", t);
        
        // update positions of cars
        for (int i = 0; i < num_cars; i++) {
            positions[i] += speeds[i];
        }
        
        // check for collisions
        for (int i = 0; i < num_cars - 1; i++) {
            if (positions[i+1] - positions[i] <= distances[i]) {
                speeds[i] = speeds[i+1] = 0;
            }
        }
        
        // update speeds of cars
        for (int i = 0; i < num_cars; i++) {
            if (i == 0) {
                speeds[i] = rand() % 5 + 1; // random speed for first car
            } else {
                int gap = positions[i-1] - positions[i] - distances[i-1];
                if (gap >= 0) {
                    speeds[i] = speeds[i-1] + (gap > 5 ? 1 : 0);
                } else {
                    speeds[i] = 0;
                }
            }
            
            // speed limit of 5
            if (speeds[i] > 5) {
                speeds[i] = 5;
            }
        }
        
        // print out positions and speeds of cars
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d: position = %d, speed = %d\n", i+1, positions[i], speeds[i]);
        }
    }
    
    return 0;
}