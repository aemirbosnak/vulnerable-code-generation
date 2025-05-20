//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_SPEED 100
#define MAX_DISTANCE 1000
#define MIN_DISTANCE 100

typedef struct Car {
    int id;
    int speed;
    int location;
} Car;

void update_locations(Car* cars, int num_cars, int time_elapsed) {
    for (int i = 0; i < num_cars; i++) {
        cars[i].location += (time_elapsed * cars[i].speed);
    }
}

void print_cars(Car* cars, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        printf("Car %d - Location: %d, Speed: %d\n", cars[i].id, cars[i].location, cars[i].speed);
    }
}

void simulate_traffic_flow(int num_cars) {
    Car cars[MAX_CARS];
    srand(time(NULL));

    // Initialize cars
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i+1;
        cars[i].speed = rand() % MAX_SPEED + 1;
        cars[i].location = (i * MAX_DISTANCE / num_cars) + (rand() % (MAX_DISTANCE / num_cars - MIN_DISTANCE)) + MIN_DISTANCE;
    }

    int time_elapsed = 0;
    while (time_elapsed < 60) {
        printf("Time elapsed: %d seconds\n", time_elapsed);
        print_cars(cars, num_cars);
        update_locations(cars, num_cars, 1);
        printf("\n");
        time_elapsed++;
    }

    printf("Simulation complete.\n");
}

int main() {
    simulate_traffic_flow(10);

    return 0;
}