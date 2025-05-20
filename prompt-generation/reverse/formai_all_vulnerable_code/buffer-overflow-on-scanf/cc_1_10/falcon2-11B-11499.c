//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int numVehicles, numLanes, numIntersections;
    scanf("%d %d %d", &numVehicles, &numLanes, &numIntersections);
    
    int *vehicles = malloc(numVehicles * sizeof(int));
    int *lanes = malloc(numLanes * sizeof(int));
    int *intersections = malloc(numIntersections * sizeof(int));
    
    for (int i = 0; i < numVehicles; i++) {
        scanf("%d", &vehicles[i]);
    }
    for (int i = 0; i < numLanes; i++) {
        scanf("%d", &lanes[i]);
    }
    for (int i = 0; i < numIntersections; i++) {
        scanf("%d", &intersections[i]);
    }
    
    // Simulate traffic flow
    for (int i = 0; i < numVehicles; i++) {
        int currentLane = vehicles[i];
        int currentIntersection = intersections[currentLane];
        int nextIntersection = (currentIntersection + 1) % numIntersections;
        
        while (nextIntersection == currentIntersection) {
            currentLane = (currentLane + 1) % numLanes;
            currentIntersection = intersections[currentLane];
            nextIntersection = (currentIntersection + 1) % numIntersections;
        }
        
        printf("Vehicle %d on lane %d is moving from intersection %d to intersection %d.\n", i+1, currentLane+1, currentIntersection+1, nextIntersection+1);
        
        // Move vehicle to next intersection
        vehicles[i] = nextIntersection;
        lanes[currentLane]--;
        if (lanes[currentLane] == 0) {
            lanes[currentLane] = numLanes;
        }
        intersections[nextIntersection]++;
        if (intersections[nextIntersection] == numIntersections) {
            intersections[nextIntersection] = 0;
        }
    }
    
    // Free memory
    free(vehicles);
    free(lanes);
    free(intersections);
    
    return 0;
}