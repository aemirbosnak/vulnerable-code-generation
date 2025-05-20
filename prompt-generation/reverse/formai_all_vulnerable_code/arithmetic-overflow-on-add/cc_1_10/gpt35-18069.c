//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the states of traffic signal */
#define RED 0
#define YELLOW 1
#define GREEN 2

/* Define the lanes */
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

/* Define the simuation time */
#define SIMULATION_TIME 100

/* Define the time interval for each state */
#define STATE_TIME 30

/* Define structure for traffic light */
struct TrafficLight {
    int state;
    int time[3]; // Array to store time for each state
    int current_time; // Current time for the current state
};

/* Define structure for traffic lane */
struct TrafficLane {
    int cars; // Number of cars in the lane
    int max_cars; // Maximum number of cars allowed in the lane
    int direction; // Direction of the lane
    struct TrafficLight* light; // Traffic light controlling the lane
};

/* Function to change traffic light state */
void changeState(struct TrafficLight* light) {
    light->state = (light->state + 1) % 3; // Update state to the next state
    light->current_time = light->time[light->state]; // Reset current time for the new state
}

/* Function to update lane cars */
void updateCars(struct TrafficLane* lane) {
    // Generate random number for incoming cars
    int incoming_cars = rand() % 5;
    
    // Check if maximum number of cars will be exceeded
    if (lane->cars + incoming_cars > lane->max_cars) {
        lane->cars = lane->max_cars; // Set cars to maximum capacity
    }
    else {
        lane->cars += incoming_cars; // Add incoming cars to lane
    }
}

/* Function to simulate traffic light */
void simulateTrafficLight(struct TrafficLane* lanes, int num_lanes) {
    int i, j;
    for (i = 0; i < num_lanes; i++) {
        if (lanes[i].light->current_time == 0) { // Check if current state time has ended
            changeState(lanes[i].light); // Change traffic light state
            int next_lane = (i + 1) % num_lanes; // Get the next lane
            lanes[next_lane].light->state = lanes[i].light->state; // Update the next lane's traffic light state
        }
        // Update current time for the current state
        lanes[i].light->current_time = (lanes[i].light->current_time + 1) % lanes[i].light->time[lanes[i].light->state]; 
    }
}

/* Function to simulate traffic flow */
void simulateTrafficFlow(struct TrafficLane* lanes, int num_lanes) {
    int i;
    for (i = 0; i < num_lanes; i++) {
        updateCars(&lanes[i]); // Update lane cars
    }
}

/* Function to print traffic statistics */
void printTrafficStats(struct TrafficLane* lanes, int num_lanes) {
    int i;
    for (i = 0; i < num_lanes; i++) {
        printf("Lane %d (%d cars)\n", lanes[i].direction, lanes[i].cars);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize the traffic lights
    struct TrafficLight north_south_light = {RED, {STATE_TIME, STATE_TIME, STATE_TIME}, 0};
    struct TrafficLight east_west_light = {GREEN, {STATE_TIME, STATE_TIME, STATE_TIME}, 0};
    
    // Initialize the traffic lanes
    struct TrafficLane north_lane = {0, 10, NORTH, &north_south_light};
    struct TrafficLane east_lane = {0, 10, EAST, &east_west_light};
    struct TrafficLane south_lane = {0, 10, SOUTH, &north_south_light};
    struct TrafficLane west_lane = {0, 10, WEST, &east_west_light};
    
    // Array to hold all the lanes
    struct TrafficLane lanes[] = {north_lane, east_lane, south_lane, west_lane};
    int num_lanes = sizeof(lanes) / sizeof(struct TrafficLane);
    
    int i, t;
    for (t = 0; t < SIMULATION_TIME; t++) {
        printf("Tick: %d\n", t);
        simulateTrafficLight(lanes, num_lanes); // Simulate traffic light
        simulateTrafficFlow(lanes, num_lanes); // Simulate traffic flow
        printTrafficStats(lanes, num_lanes); // Print traffic statistics
    }
    
    return 0;
}