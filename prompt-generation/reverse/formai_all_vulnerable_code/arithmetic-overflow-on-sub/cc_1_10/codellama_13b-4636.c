//Code Llama-13B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
// C Traffic Flow Simulation Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SECONDS 1000

// Structures for Cars and Traffic Light
struct car {
    int id;
    int x;
    int y;
    int direction;
};

struct traffic_light {
    int id;
    int state;
};

// Function to generate a random number between 0 and 1
int random_number(int max) {
    return rand() % max;
}

// Function to simulate traffic light
void simulate_traffic_light(struct traffic_light *light) {
    int state = light->state;
    int next_state;

    switch (state) {
        case 0: // Green
            next_state = 1;
            break;
        case 1: // Yellow
            next_state = 2;
            break;
        case 2: // Red
            next_state = 0;
            break;
    }

    light->state = next_state;
}

// Function to simulate car movement
void simulate_car_movement(struct car *car, struct traffic_light *light) {
    int state = light->state;
    int direction = car->direction;
    int x = car->x;
    int y = car->y;

    switch (state) {
        case 0: // Green
            if (direction == 0) {
                x++;
            } else {
                x--;
            }
            break;
        case 1: // Yellow
            if (direction == 0) {
                y++;
            } else {
                y--;
            }
            break;
        case 2: // Red
            if (direction == 0) {
                x--;
            } else {
                x++;
            }
            break;
    }

    car->x = x;
    car->y = y;
}

// Function to check if car is at intersection
int check_intersection(struct car *car, struct traffic_light *light) {
    int x = car->x;
    int y = car->y;
    int state = light->state;
    int intersection = 0;

    switch (state) {
        case 0: // Green
            if (x == 0 && y == 0) {
                intersection = 1;
            }
            break;
        case 1: // Yellow
            if (x == 0 && y == 1) {
                intersection = 1;
            }
            break;
        case 2: // Red
            if (x == 0 && y == 2) {
                intersection = 1;
            }
            break;
    }

    return intersection;
}

// Main function
int main() {
    // Initialize cars and traffic light
    struct car cars[MAX_CARS];
    struct traffic_light light;
    light.id = 0;
    light.state = 0;

    // Initialize random seed
    srand(time(NULL));

    // Loop for simulation
    for (int i = 0; i < MAX_SECONDS; i++) {
        // Generate random number for cars
        int num_cars = random_number(MAX_CARS);

        // Simulate cars movement
        for (int j = 0; j < num_cars; j++) {
            // Generate random direction for each car
            int direction = random_number(2);

            // Simulate car movement
            simulate_car_movement(&cars[j], &light);

            // Check if car is at intersection
            if (check_intersection(&cars[j], &light)) {
                // If car is at intersection, change traffic light state
                simulate_traffic_light(&light);
            }
        }
    }

    // Print final state of cars and traffic light
    for (int i = 0; i < MAX_CARS; i++) {
        printf("Car %d: (%d, %d) at intersection: %d\n", i, cars[i].x, cars[i].y, check_intersection(&cars[i], &light));
    }
    printf("Traffic light: %d\n", light.state);

    return 0;
}