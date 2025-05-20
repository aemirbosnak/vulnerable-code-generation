//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 1000
#define MAX_TIME 1000

struct road {
    int length;
    int speed_limit;
    int num_cars;
};

struct car {
    int speed;
    int position;
    int destination;
};

int main() {
    srand(time(NULL));

    struct road roads[MAX_ROADS];
    int num_roads = rand() % MAX_ROADS + 1;

    for (int i = 0; i < num_roads; i++) {
        roads[i].length = rand() % 100 + 1;
        roads[i].speed_limit = rand() % 100 + 1;
        roads[i].num_cars = 0;
    }

    struct car cars[MAX_CARS];
    int num_cars = rand() % MAX_CARS + 1;

    for (int i = 0; i < num_cars; i++) {
        cars[i].speed = rand() % 100 + 1;
        cars[i].position = 0;
        cars[i].destination = rand() % num_roads + 1;
    }

    int current_time = 0;

    while (current_time < MAX_TIME) {
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].position < roads[cars[i].destination].length) {
                cars[i].position++;
            } else {
                cars[i].position = 0;
            }
        }

        for (int i = 0; i < num_roads; i++) {
            roads[i].num_cars = 0;
        }

        for (int i = 0; i < num_cars; i++) {
            if (cars[i].position >= 0 && cars[i].position < roads[cars[i].destination].length) {
                roads[cars[i].destination].num_cars++;
            }
        }

        for (int i = 0; i < num_roads; i++) {
            if (roads[i].num_cars > 0) {
                int avg_speed = roads[i].speed_limit / roads[i].num_cars;
                for (int j = 0; j < roads[i].num_cars; j++) {
                    cars[j].speed = avg_speed;
                }
            }
        }

        current_time++;
    }

    return 0;
}