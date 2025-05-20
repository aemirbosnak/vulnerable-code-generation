//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the duration of each traffic light state in seconds
#define RED_DURATION 10
#define YELLOW_DURATION 5
#define GREEN_DURATION 15

// Define the number of intersections
#define NUM_INTERSECTIONS 4

// Define the intersection states
#define IDLE 0
#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

// Define the intersection structure
typedef struct {
    int state;
    int countdown;
    int duration;
} Intersection;

// Initialize the intersections
Intersection intersections[NUM_INTERSECTIONS];

void initIntersections() {
    int i;

    for (i = 0; i < NUM_INTERSECTIONS; i++) {
        intersections[i].state = IDLE;
        intersections[i].countdown = 0;
        intersections[i].duration = 0;
    }
}

// Change the traffic light state
void changeLight(int intersection, int newState) {
    intersections[intersection].state = newState;
    intersections[intersection].countdown = intersections[intersection].duration;
}

// Update the countdown for the current traffic light state
void updateCountdown(int intersection) {
    intersections[intersection].countdown--;

    if (intersections[intersection].countdown == 0) {
        changeLight(intersection, (intersections[intersection].state + 1) % 3);
    }
}

// Simulate the traffic lights for a given duration
void simulateTrafficLights(int duration) {
    int i;
    time_t startTime, endTime;

    srand(time(NULL));

    initIntersections();

    for (i = 0; i < NUM_INTERSECTIONS; i++) {
        intersections[i].duration = rand() % duration + 1;
    }

    time(&startTime);

    while (difftime(time(NULL), startTime) < duration) {
        for (i = 0; i < NUM_INTERSECTIONS; i++) {
            updateCountdown(i);
        }

        usleep(100000); // Sleep for 100ms
    }

    time(&endTime);

    printf("Simulation ended at %s\n", ctime(&endTime));
}

int main() {
    int duration;

    printf("Enter the duration of the simulation in seconds: ");
    scanf("%d", &duration);

    simulateTrafficLights(duration);

    return 0;
}