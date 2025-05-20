//Code Llama-13B DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
/*
 * Traffic Flow Simulation
 *
 * This program simulates a traffic flow system with configurable
 * parameters such as number of cars, arrival rate, and service rate.
 * The program uses a single-server, first-come-first-served
 * (FCFS) queueing system to handle the cars.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 1000

typedef struct {
    int arrival_time;
    int service_time;
} car_t;

int main() {
    int n_cars;
    car_t cars[MAX_CARS];
    int total_arrival_time = 0;
    int total_service_time = 0;
    int total_waiting_time = 0;
    int total_queue_length = 0;
    int current_time = 0;
    int i;

    printf("Enter the number of cars: ");
    scanf("%d", &n_cars);

    // Initialize cars
    for (i = 0; i < n_cars; i++) {
        cars[i].arrival_time = i + 1;
        cars[i].service_time = rand() % 5 + 1;
        total_arrival_time += cars[i].arrival_time;
    }

    // Simulate the traffic flow
    while (current_time < MAX_TIME) {
        // Check for arriving cars
        for (i = 0; i < n_cars; i++) {
            if (cars[i].arrival_time <= current_time) {
                // Add car to the queue
                total_queue_length++;
            }
        }

        // Check for departing cars
        for (i = 0; i < n_cars; i++) {
            if (cars[i].service_time <= current_time) {
                // Remove car from the queue
                total_queue_length--;
            }
        }

        // Calculate waiting time and service time
        for (i = 0; i < n_cars; i++) {
            if (cars[i].arrival_time <= current_time && cars[i].service_time <= current_time) {
                total_waiting_time += (current_time - cars[i].arrival_time);
                total_service_time += cars[i].service_time;
            }
        }

        current_time++;
    }

    // Calculate average waiting time and service time
    double average_waiting_time = (double)total_waiting_time / n_cars;
    double average_service_time = (double)total_service_time / n_cars;

    // Print the results
    printf("Average waiting time: %.2f\n", average_waiting_time);
    printf("Average service time: %.2f\n", average_service_time);

    return 0;
}