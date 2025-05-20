//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare Traffic Flow Simulation Parameters
#define LANE_LENGTH 20 // Length of the road lane
#define MAX_SPEED 5 // Maximum speed a car can go
#define MAX_CARS 10 // Maximum number of cars allowed on the lane
#define MIN_GAP 2 // Minimum gap between two cars

// Car Object structure
typedef struct car_object {
    int position;
    int speed;
} CarObject;

// Generate Random Number within a Range
int random_num(int min_value, int max_value) {
    return (rand() % (max_value - min_value + 1)) + min_value;
}

// Initialize Cars on the Lane    
void init_cars(CarObject *cars_array, int num_cars) {
    for(int i=0; i<num_cars; i++) {
        cars_array[i].position = (i+1) * (-MIN_GAP); // Initialize cars with minimum gap between them
        cars_array[i].speed = random_num(0, MAX_SPEED); // Assign random speed to each car
    }
}

// Update Position and Speed of each Car
void update_cars(CarObject *cars_array, int num_cars) {
    for(int i=0; i<num_cars; i++) {
        // Calculate acceleration and deceleration
        int gap_to_front = cars_array[i+1].position - cars_array[i].position;
        int speed_limit = (gap_to_front > MIN_GAP) ? MAX_SPEED : gap_to_front-1;
        int speed_difference = speed_limit - cars_array[i].speed;
        int acceleration = (speed_difference > 0) ? 1 : ((speed_difference < 0) ? -1 : 0);

        // Update car speed and position
        cars_array[i].speed += acceleration;
        cars_array[i].speed = (cars_array[i].speed < 0) ? 0 : ((cars_array[i].speed > MAX_SPEED) ? MAX_SPEED : cars_array[i].speed);
        cars_array[i].position += cars_array[i].speed;
    }
}

// Print Lane Status
void print_lane(CarObject *cars_array, int num_cars) {
    for(int i=0; i<num_cars; i++) {
        for(int j=0; j<cars_array[i].position; j++) {
            printf(" ");
        }
        printf("X\n");
    }
}

// Main Program
int main() {
    srand(time(NULL)); // Seed random number generator

    CarObject cars_array[MAX_CARS];
    int num_cars = random_num(1, MAX_CARS); // Randomly select a number of cars

    init_cars(cars_array, num_cars); // Initialize cars on the lane

    // Traffic Simulation Loop
    for(int i=0; i<5; i++) {
        printf("Lane Status (t=%d):\n\n", i);

        print_lane(cars_array, num_cars); // Print status of the lane

        update_cars(cars_array, num_cars); // Update position and speed of cars

        printf("\n"); // Add new line
    }

    return 0;
}