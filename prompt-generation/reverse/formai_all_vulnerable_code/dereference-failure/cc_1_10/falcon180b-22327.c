//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 5
#define NUM_CARS 100
#define NUM_INTERSECTIONS 4
#define MAX_DELAY 5

typedef struct {
    int id;
    int road;
    int direction;
    int speed;
    int delay;
    int next_intersection;
} Car;

typedef struct {
    int id;
    int num_lanes;
    int speed_limit;
    Car *cars[NUM_CARS];
} Road;

typedef struct {
    int id;
    Road *roads[NUM_ROADS];
} Intersection;

void init_road(Road *road) {
    road->id = rand() % NUM_ROADS;
    road->num_lanes = rand() % 3 + 1;
    road->speed_limit = rand() % 50 + 20;

    for (int i = 0; i < NUM_CARS; i++) {
        Car *car = &road->cars[i];
        car->id = i;
        car->road = road->id;
        car->direction = rand() % 2;
        car->speed = rand() % road->speed_limit + 1;
        car->delay = rand() % MAX_DELAY;
        car->next_intersection = -1;
    }
}

void init_intersection(Intersection *intersection) {
    intersection->id = rand() % NUM_INTERSECTIONS;

    for (int i = 0; i < NUM_ROADS; i++) {
        Road *road = &intersection->roads[i];
        init_road(road);
    }
}

void print_road(Road *road) {
    printf("Road %d has %d lanes with a speed limit of %d.\n", road->id, road->num_lanes, road->speed_limit);

    for (int i = 0; i < NUM_CARS; i++) {
        Car *car = &road->cars[i];

        if (car->id == -1)
            continue;

        printf("  Car %d is traveling at %d mph in the %s direction.\n", car->id, car->speed, car->direction? "north" : "south");
    }
}

void print_intersection(Intersection *intersection) {
    printf("Intersection %d:\n", intersection->id);

    for (int i = 0; i < NUM_ROADS; i++) {
        Road *road = &intersection->roads[i];
        print_road(road);
    }
}

int main() {
    srand(time(NULL));

    Intersection intersection;
    init_intersection(&intersection);

    while (1) {
        system("clear");
        print_intersection(&intersection);
        sleep(1);
    }

    return 0;
}