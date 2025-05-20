//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_TIME 100
#define MAX_SPEED 100

typedef struct {
    int id;
    int road;
    int speed;
} Car;

typedef struct {
    int id;
    int length;
    int capacity;
    int cars;
} Road;

int main() {
    srand(time(NULL));

    int num_roads = rand() % MAX_ROADS + 1;
    int num_cars = rand() % MAX_CARS + 1;

    Road roads[MAX_ROADS];
    Car cars[MAX_CARS];

    for (int i = 0; i < num_roads; i++) {
        roads[i].id = i;
        roads[i].length = rand() % MAX_TIME + 1;
        roads[i].capacity = rand() % MAX_CARS + 1;
        roads[i].cars = 0;
    }

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].road = rand() % num_roads;
        cars[i].speed = rand() % MAX_SPEED + 1;
    }

    int current_time = 0;

    while (current_time < MAX_TIME) {
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].road!= -1) {
                int distance_left = roads[cars[i].road].length - cars[i].speed * current_time;

                if (distance_left <= 0) {
                    cars[i].road = -1;
                    roads[cars[i].road].cars--;
                } else {
                    roads[cars[i].road].cars++;
                }
            }
        }

        for (int i = 0; i < num_roads; i++) {
            if (roads[i].cars >= roads[i].capacity) {
                for (int j = 0; j < num_cars; j++) {
                    if (cars[j].road == i && cars[j].speed > 0) {
                        cars[j].speed = 0;
                    }
                }
            }
        }

        current_time++;
    }

    return 0;
}