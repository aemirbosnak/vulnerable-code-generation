//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define MAX_TIME 600

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
    int i;
    for (i = 0; i < num_roads; i++) {
        roads[i].length = rand() % 100 + 1;
        roads[i].speed_limit = rand() % 100 + 1;
        roads[i].num_cars = 0;
    }
}

// Function to initialize cars
void init_cars(Car cars[], int num_cars) {
    int i;
    for (i = 0; i < num_cars; i++) {
        cars[i].position = 0;
        cars[i].speed = rand() % 100 + 1;
    }
}

// Function to move cars
void move_cars(Road roads[], Car cars[], int num_roads, int num_cars) {
    int i, j;
    for (i = 0; i < num_cars; i++) {
        int road_index = cars[i].position / roads[cars[i].position % MAX_ROADS].length;
        if (roads[road_index].num_cars >= roads[road_index].length) {
            printf("Car %d is stuck in traffic on road %d\n", i, road_index);
            continue;
        }
        roads[road_index].num_cars++;
        cars[i].position += cars[i].speed;
        if (cars[i].position >= roads[road_index].length) {
            cars[i].position = 0;
            roads[road_index].num_cars--;
        }
    }
}

// Function to print roads
void print_roads(Road roads[], int num_roads) {
    int i;
    for (i = 0; i < num_roads; i++) {
        printf("Road %d: Length %d, Speed Limit %d, Num Cars %d\n", i, roads[i].length, roads[i].speed_limit, roads[i].num_cars);
    }
}

// Function to print cars
void print_cars(Car cars[], int num_cars) {
    int i;
    for (i = 0; i < num_cars; i++) {
        printf("Car %d: Position %d, Speed %d\n", i, cars[i].position, cars[i].speed);
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    int num_roads = rand() % MAX_ROADS + 1;
    int num_cars = rand() % MAX_CARS + 1;

    Road roads[MAX_ROADS];
    Car cars[MAX_CARS];

    init_roads(roads, num_roads);
    init_cars(cars, num_cars);

    int total_time = 0;
    while (total_time < MAX_TIME) {
        move_cars(roads, cars, num_roads, num_cars);
        total_time++;

        if (total_time % 100 == 0) {
            printf("Time: %d\n", total_time);
            print_roads(roads, num_roads);
            print_cars(cars, num_cars);
        }
    }

    return 0;
}