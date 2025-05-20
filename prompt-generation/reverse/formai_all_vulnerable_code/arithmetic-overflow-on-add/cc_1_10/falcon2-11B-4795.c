//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of cars
#define MAX_CARS 100

// Define the size of the array for cars
#define CAR_SIZE 10

// Define the number of roads
#define NUM_ROADS 3

// Define the number of lanes per road
#define NUM_LANES 2

// Define the maximum number of cars per lane
#define MAX_CARS_PER_LANE 10

// Define the maximum number of cars per road
#define MAX_CARS_PER_ROAD 30

// Define the array for cars
int cars[CAR_SIZE];

// Define the array for roads
int roads[NUM_ROADS][NUM_LANES];

// Define the array for lanes
int lanes[NUM_LANES];

// Define the array for car types
int car_types[3] = {1, 2, 3};

// Define the function to initialize the cars
void init_cars(int cars[]) {
    for (int i = 0; i < CAR_SIZE; i++) {
        cars[i] = 0;
    }
}

// Define the function to initialize the roads
void init_roads(int roads[NUM_ROADS][NUM_LANES]) {
    for (int i = 0; i < NUM_ROADS; i++) {
        for (int j = 0; j < NUM_LANES; j++) {
            roads[i][j] = 0;
        }
    }
}

// Define the function to initialize the lanes
void init_lanes(int lanes[NUM_LANES]) {
    for (int i = 0; i < NUM_LANES; i++) {
        lanes[i] = 0;
    }
}

// Define the function to initialize the car types
void init_car_types(int car_types[]) {
    car_types[0] = 1;
    car_types[1] = 2;
    car_types[2] = 3;
}

// Define the function to start the simulation
void start_simulation() {
    int car_index = 0;
    int road_index = 0;
    int lane_index = 0;
    int car_type = 0;
    int lane_num = 0;
    int car_num = 0;
    int num_cars = 0;
    int num_roads = 0;
    int num_lanes = 0;
    int num_car_types = 0;

    // Initialize the cars
    init_cars(cars);

    // Initialize the roads
    init_roads(roads);

    // Initialize the lanes
    init_lanes(lanes);

    // Initialize the car types
    init_car_types(car_types);

    // Generate the traffic flow
    while (num_cars < MAX_CARS) {
        // Generate the number of cars
        num_cars = (rand() % MAX_CARS_PER_LANE) + 1;

        // Generate the number of roads
        num_roads = (rand() % MAX_CARS_PER_ROAD) + 1;

        // Generate the number of lanes
        num_lanes = (rand() % MAX_CARS_PER_LANE) + 1;

        // Generate the car type
        car_type = (rand() % 3) + 1;

        // Generate the lane number
        lane_num = (rand() % NUM_LANES) + 1;

        // Generate the car number
        car_num = (rand() % (MAX_CARS_PER_LANE - num_cars)) + 1;

        // Generate the car
        cars[car_index] = (car_type << 24) | (lane_num << 16) | (car_num << 8) | 1;

        // Update the car index
        car_index = (car_index + 1) % CAR_SIZE;

        // Update the road index
        road_index = (road_index + 1) % NUM_ROADS;

        // Update the lane index
        lane_index = (lane_index + 1) % NUM_LANES;

        // Update the number of cars
        num_cars = num_cars + 1;
    }

    // Print the cars
    for (int i = 0; i < CAR_SIZE; i++) {
        printf("%d\n", cars[i]);
    }
}

int main() {
    start_simulation();
    return 0;
}