//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROAD_LENGTH 30
#define MAX_CARS 10
#define TIME_STEP 1

typedef struct {
    int position;   // Current position of the car
    int speed;      // Speed of the car
} Car;

void initializeCars(Car cars[], int carCount) {
    for (int i = 0; i < carCount; i++) {
        cars[i].position = i * 3; // initial spacing between cars
        cars[i].speed = rand() % 3 + 1; // speed between 1 and 3
    }
}

void moveCars(Car cars[], int carCount) {
    for (int i = 0; i < carCount; i++) {
        // Move the car according to its speed
        cars[i].position += cars[i].speed;

        // If car goes out of bounds, wrap around to the beginning
        if (cars[i].position >= ROAD_LENGTH) {
            cars[i].position -= ROAD_LENGTH;
        }
    }
}

void displayRoad(Car cars[], int carCount) {
    char road[ROAD_LENGTH + 1];
    for (int i = 0; i < ROAD_LENGTH; i++) {
        road[i] = '.';
    }
    road[ROAD_LENGTH] = '\0'; // Null-terminate the string

    for (int i = 0; i < carCount; i++) {
        road[cars[i].position] = 'C'; // Mark the car on the road
    }

    printf("%s\n", road); // Display the current state of the road
}

int main() {
    int carCount;
    Car cars[MAX_CARS];

    printf("Welcome to the Traffic Flow Simulation!\n");
    printf("Enter the number of cars (1 to %d): ", MAX_CARS);
    scanf("%d", &carCount);

    if (carCount < 1 || carCount > MAX_CARS) {
        printf("Invalid number of cars, exiting.\n");
        return 1;
    }

    // Initialize random seed
    srand(time(NULL));

    initializeCars(cars, carCount);

    // Run the simulation
    for (int time = 0; time < 20; time++) { // run for 20 time steps
        printf("Time Step %d:\n", time);
        displayRoad(cars, carCount);
        moveCars(cars, carCount);
        sleep(TIME_STEP); // sleep for a second to visualize the movement
    }

    printf("Simulation complete!\n");
    return 0;
}