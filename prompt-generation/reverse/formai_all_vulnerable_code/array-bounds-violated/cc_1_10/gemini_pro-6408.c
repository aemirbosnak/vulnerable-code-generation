//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define NUM_CARS 10
#define ROAD_LENGTH 100

// Define the road structure
typedef struct {
    int length;
    int num_cars;
    int cars[NUM_CARS];
} road_t;

// Define the car structure
typedef struct {
    int speed;
    int position;
} car_t;

// Create the roads
road_t roads[NUM_ROADS];

// Create the cars
car_t cars[NUM_CARS];

// Initialize the roads
void init_roads() {
    for (int i = 0; i < NUM_ROADS; i++) {
        roads[i].length = ROAD_LENGTH;
        roads[i].num_cars = 0;
    }
}

// Initialize the cars
void init_cars() {
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].speed = rand() % 10 + 1;
        cars[i].position = rand() % ROAD_LENGTH;
    }
}

// Move the cars
void move_cars() {
    for (int i = 0; i < NUM_CARS; i++) {
        // Get the car's current position and speed
        int position = cars[i].position;
        int speed = cars[i].speed;

        // Check if the car is at the end of the road
        if (position + speed >= ROAD_LENGTH) {
            // Wrap the car around to the beginning of the road
            position = 0;
        }

        // Move the car
        position += speed;

        // Update the car's position
        cars[i].position = position;
    }
}

// Print the roads
void print_roads() {
    for (int i = 0; i < NUM_ROADS; i++) {
        // Get the road's length and number of cars
        int length = roads[i].length;
        int num_cars = roads[i].num_cars;

        // Print the road
        for (int j = 0; j < length; j++) {
            // Print a car if there is one at the current position
            if (roads[i].cars[j] != -1) {
                printf("X");
            } else {
                printf(" ");
            }
        }

        // Print a newline
        printf("\n");
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the roads and cars
    init_roads();
    init_cars();

    // Simulate the traffic flow
    for (int i = 0; i < 100; i++) {
        // Move the cars
        move_cars();

        // Print the roads
        print_roads();

        // Sleep for a short period of time
        usleep(100000);
    }

    return 0;
}