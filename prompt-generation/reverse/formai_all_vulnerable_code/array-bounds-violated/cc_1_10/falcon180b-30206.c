//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 5
#define NUM_CARS 10
#define ROAD_LENGTH 1000
#define CAR_SPEED 10

int road_status[NUM_ROADS];
int car_pos[NUM_CARS];
int car_speed[NUM_CARS];
int car_direction[NUM_CARS];

void initialize() {
    for (int i = 0; i < NUM_ROADS; i++) {
        road_status[i] = 0;
    }
    for (int i = 0; i < NUM_CARS; i++) {
        car_pos[i] = 0;
        car_speed[i] = CAR_SPEED;
        car_direction[i] = 1;
    }
}

void print_road_status() {
    for (int i = 0; i < NUM_ROADS; i++) {
        printf("%d ", road_status[i]);
    }
    printf("\n");
}

void move_cars() {
    for (int i = 0; i < NUM_CARS; i++) {
        if (road_status[car_pos[i]] == 0) {
            car_pos[i] += car_speed[i] * car_direction[i];
            if (car_pos[i] >= ROAD_LENGTH) {
                car_pos[i] = 0;
            }
        } else {
            car_speed[i] = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    initialize();

    while (1) {
        system("clear");
        print_road_status();
        move_cars();
        usleep(100000);
    }

    return 0;
}