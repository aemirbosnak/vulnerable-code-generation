//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Initialize variables
    int numCars = 0;
    int totalCars = 0;
    int maxCars = 100;
    int laneWidth = 3;
    int intersection = 5;

    // Create an array to represent the road
    int road[laneWidth][intersection];

    // Simulate traffic flow
    srand(time(NULL)); // Set random seed for reproducibility
    for (int i = 0; i < intersection; i++) {
        for (int j = 0; j < laneWidth; j++) {
            road[j][i] = rand() % 2; // 0 = empty, 1 = car
        }
    }

    while (numCars < maxCars) {
        int randomLane = rand() % laneWidth;
        int randomIntersection = rand() % intersection;

        // Check if the lane is empty and if the intersection is available
        if (road[randomLane][randomIntersection] == 0 && randomIntersection!= (intersection - 1)) {
            // Add a car to the road
            road[randomLane][randomIntersection] = 1;
            numCars++;

            // Check if there are cars at the intersection
            if (road[randomLane][randomIntersection + 1] == 1 && road[randomLane][randomIntersection - 1] == 1) {
                // Car can move forward
                road[randomLane][randomIntersection] = 0;
                numCars--;
            } else if (road[randomLane][randomIntersection - 1] == 1) {
                // Car can move backward
                road[randomLane][randomIntersection] = 0;
                numCars--;
            } else if (road[randomLane][randomIntersection + 1] == 1) {
                // Car can move forward
                road[randomLane][randomIntersection] = 0;
                numCars--;
            }
        }
    }

    // Print the road state
    for (int i = 0; i < intersection; i++) {
        for (int j = 0; j < laneWidth; j++) {
            printf("%d ", road[j][i]);
        }
        printf("\n");
    }

    return 0;
}