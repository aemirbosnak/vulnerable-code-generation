//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CARS 1000
#define MAX_ROADS 1000

struct Car {
    int id;
    int road_id;
    int speed;
};

struct Road {
    int id;
    int capacity;
    int cars_count;
};

int main() {
    srand(time(NULL)); // seed random number generator

    int num_cars = 1000;
    int num_roads = 1000;

    struct Road* roads = malloc(num_roads * sizeof(struct Road));
    struct Car* cars = malloc(num_cars * sizeof(struct Car));

    for (int i = 0; i < num_roads; i++) {
        roads[i].id = i;
        roads[i].capacity = (int)(rand() / (RAND_MAX / 100.0)); // generate random capacity between 0 and 100
        roads[i].cars_count = 0;
    }

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].road_id = -1;
        cars[i].speed = (int)(rand() / (RAND_MAX / 10.0)); // generate random speed between 0 and 10
    }

    while (1) {
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].road_id == -1) {
                for (int j = 0; j < num_roads; j++) {
                    if (roads[j].cars_count < roads[j].capacity) {
                        cars[i].road_id = j;
                        cars[i].speed *= 1.1; // increase speed by 10%
                        break;
                    }
                }
            }
            if (cars[i].road_id!= -1) {
                int distance = sqrt(pow(roads[cars[i].road_id].capacity / 2, 2) - pow(cars[i].speed, 2));
                if (distance <= 0) {
                    cars[i].speed = 0;
                    cars[i].road_id = -1;
                } else {
                    cars[i].speed -= (distance / 2);
                }
                if (cars[i].speed <= 0) {
                    cars[i].road_id = -1;
                }
            }
        }

        for (int i = 0; i < num_roads; i++) {
            if (roads[i].cars_count > 0) {
                roads[i].cars_count--;
            }
        }

        for (int i = 0; i < num_cars; i++) {
            if (cars[i].road_id == -1) {
                continue;
            }
            int distance = sqrt(pow(roads[cars[i].road_id].capacity / 2, 2) - pow(cars[i].speed, 2));
            if (distance <= 0) {
                cars[i].speed = 0;
                cars[i].road_id = -1;
            } else {
                cars[i].speed += (distance / 2);
            }
            if (cars[i].speed >= 10) {
                cars[i].speed = 10;
            }
        }

        for (int i = 0; i < num_roads; i++) {
            if (roads[i].cars_count < roads[i].capacity) {
                int j = rand() % num_cars;
                cars[j].road_id = i;
            }
        }
    }

    return 0;
}