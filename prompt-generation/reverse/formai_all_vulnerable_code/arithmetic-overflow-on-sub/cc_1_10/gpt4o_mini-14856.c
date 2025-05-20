//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100  // Maximum number of cars in simulation
#define SIMULATION_TIME 60 // Total time of simulation in seconds
#define CAR_ARRIVAL_RATE 5 // Average cars per minute
#define GREEN_LIGHT_DURATION 20 // Duration of green light in seconds
#define YELLOW_LIGHT_DURATION 5 // Duration of yellow light in seconds
#define RED_LIGHT_DURATION 15 // Duration of red light in seconds

// Enum for traffic light state
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// Struct for a car
typedef struct {
    int id;
    int wait_time; // Time spent waiting in seconds
} Car;

// Function to simulate the traffic flow
void simulateTrafficFlow() {
    TrafficLightState lightState = GREEN;
    Car cars[MAX_CARS];
    int car_count = 0;
    int total_wait_time = 0;
    int total_cars_passed = 0;

    time_t start_time = time(NULL);
    time_t end_time = start_time + SIMULATION_TIME;
    srand(time(NULL));

    printf("Traffic Flow Simulation Started...\n");
    printf("Simulation time: %d seconds\n", SIMULATION_TIME);

    while (time(NULL) < end_time) {
        // Car arrival simulation based on average rate
        if (rand() % 60 < CAR_ARRIVAL_RATE) {
            if (car_count < MAX_CARS) {
                cars[car_count].id = car_count + 1;
                cars[car_count].wait_time = 0; // Reset wait time when car arrives
                car_count++;
                printf("Car %d arrived at time %ld seconds.\n", cars[car_count - 1].id, time(NULL) - start_time);
            }
        }

        // Manage traffic light state
        switch (lightState) {
            case GREEN:
                if (rand() % GREEN_LIGHT_DURATION == 0) {
                    lightState = YELLOW;
                    printf("Traffic light changed to YELLOW.\n");
                }
                break;

            case YELLOW:
                if (rand() % YELLOW_LIGHT_DURATION == 0) {
                    lightState = RED;
                    printf("Traffic light changed to RED.\n");
                }
                break;

            case RED:
                if (rand() % RED_LIGHT_DURATION == 0) {
                    lightState = GREEN;
                    printf("Traffic light changed to GREEN.\n");
                }
                break;
        }

        // Process cars based on current traffic light state
        if (lightState == GREEN && total_cars_passed < car_count) {
            printf("Car %d passed the intersection.\n", cars[total_cars_passed].id);
            cars[total_cars_passed].wait_time = time(NULL) - start_time - (total_cars_passed * (GREEN_LIGHT_DURATION + YELLOW_LIGHT_DURATION + RED_LIGHT_DURATION)); // Wait time calculation
            total_wait_time += cars[total_cars_passed].wait_time;
            total_cars_passed++;
        }

        // Simulating wait time for cars in RED state
        if (lightState == RED) {
            for (int i = 0; i < total_cars_passed; i++) {
                cars[i].wait_time++;
            }
        }

        // Brief pause to limit the simulation speed
        sleep(1);  // Wait for 1 second
    }

    // Statistics report
    printf("\nTraffic Flow Simulation Ended...\n");
    printf("Total cars arrived: %d\n", car_count);
    printf("Total cars passed: %d\n", total_cars_passed);
    printf("Average wait time: %.2f seconds\n", (total_cars_passed > 0) ? (float)total_wait_time / total_cars_passed : 0.0);
}

int main() {
    simulateTrafficFlow();
    return 0;
}