//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define SPEED_LIMIT 50

// Struct for a road
typedef struct {
    int length;
    int speed_limit;
    int num_cars;
} Road;

// Struct for a car
typedef struct {
    int position;
    int speed;
} Car;

// Function to initialize roads
void init_roads(Road roads[], int num_roads) {
    for (int i = 0; i < num_roads; i++) {
        roads[i].length = rand() % 100 + 1;
        roads[i].speed_limit = SPEED_LIMIT;
        roads[i].num_cars = 0;
    }
}

// Function to initialize cars
void init_cars(Car cars[], int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        cars[i].position = 0;
        cars[i].speed = rand() % SPEED_LIMIT + 1;
    }
}

// Function to move cars
void move_cars(Road roads[], Car cars[], int num_roads, int num_cars) {
    for (int i = 0; i < num_cars; i++) {
        int road_index = cars[i].position / roads[cars[i].position % num_roads].length;
        if (roads[road_index].num_cars >= roads[road_index].length) {
            printf("Traffic jam on road %d\n", road_index + 1);
            exit(1);
        }
        roads[road_index].num_cars++;
        cars[i].position += cars[i].speed;
        if (cars[i].position >= roads[cars[i].position % num_roads].length) {
            cars[i].position -= roads[cars[i].position % num_roads].length;
        }
    }
}

// Main function
int main() {
    srand(time(NULL));

    int num_roads, num_cars;
    printf("Enter number of roads: ");
    scanf("%d", &num_roads);
    printf("Enter number of cars: ");
    scanf("%d", &num_cars);

    Road roads[MAX_ROADS];
    Car cars[MAX_CARS];

    init_roads(roads, num_roads);
    init_cars(cars, num_cars);

    while (1) {
        move_cars(roads, cars, num_roads, num_cars);
    }

    return 0;
}