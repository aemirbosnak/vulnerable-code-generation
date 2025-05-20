//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the maximum number of cars that can be simulated */
#define MAX_CARS 500

/* Define the minimum time between car arrivals in seconds */
#define MIN_ARRIVAL_TIME 1

/* Define the maximum time between car arrivals in seconds */
#define MAX_ARRIVAL_TIME 5

/* Define the minimum amount of time it takes for a car to cross the intersection in seconds */
#define MIN_CROSSING_TIME 3

/* Define the maximum amount of time it takes for a car to cross the intersection in seconds */
#define MAX_CROSSING_TIME 10

/* Define a structure to represent a single car */
typedef struct {
    int arrival_time;       /* The time the car arrived at the intersection */
    int crossing_time;      /* The time it takes for the car to cross the intersection */
} car_t;

/* Define a function to simulate the traffic flow */
void simulate_traffic() {
    int i, j;                       /* Loop counters */
    int num_cars;                   /* The number of cars in the simulation */
    car_t cars[MAX_CARS];           /* An array to hold the cars */

    /* Seed the random number generator */
    srand(time(0));

    /* Get the user's input for the number of cars to simulate */
    printf("Enter the number of cars to simulate (maximum %d): ", MAX_CARS);
    scanf("%d", &num_cars);

    /* Check that the user's input is within the range */
    if (num_cars <= 0 || num_cars > MAX_CARS) {
        printf("Error: invalid input.\n");
        exit(1);
    }

    /* Simulate the arrival and crossing of each car */
    for (i = 0; i < num_cars; i++) {
        /* Wait for the next car to arrive */
        int arrival_time = rand() % (MAX_ARRIVAL_TIME - MIN_ARRIVAL_TIME + 1) + MIN_ARRIVAL_TIME;
        printf("Car %d arrived at time %d.\n", i+1, arrival_time);
        sleep(arrival_time);

        /* Determine how long it takes for the car to cross the intersection */
        int crossing_time = rand() % (MAX_CROSSING_TIME - MIN_CROSSING_TIME + 1) + MIN_CROSSING_TIME;
        printf("Car %d will take %d seconds to cross the intersection.\n", i+1, crossing_time);

        /* Add the car to the array */
        cars[i].arrival_time = arrival_time;
        cars[i].crossing_time = crossing_time;
    }

    /* Simulate the traffic flow by printing out when each car crosses the intersection */
    int current_time = 0;
    for (i = 0; i < num_cars; i++) {
        /* Wait for the car to arrive at the intersection */
        int time_to_wait = cars[i].arrival_time - current_time;
        printf("Waiting for car %d (%d seconds)...\n", i+1, time_to_wait);
        sleep(time_to_wait);
        current_time += time_to_wait;

        /* Print out when the car crosses the intersection */
        printf("Car %d crosses the intersection at time %d.\n", i+1, current_time + cars[i].crossing_time);
        current_time += cars[i].crossing_time;
    }
}

/* The main function */
int main() {
    simulate_traffic();
    return 0;
}