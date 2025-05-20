//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANES 5
#define MIN_CARS 5
#define MAX_CARS 10
#define MIN_SPEED 20
#define MAX_SPEED 80
#define MIN_DIST 100
#define MAX_DIST 500

typedef struct Car {
    int lane;
    int position;
    int speed;
} Car;

int main() {
    int num_cars, num_lanes, time_step;
    srand(time(NULL));

    printf("Enter number of cars (5-10): ");
    scanf("%d", &num_cars);
    if (num_cars < MIN_CARS) {
        num_cars = MIN_CARS;
    } else if (num_cars > MAX_CARS) {
        num_cars = MAX_CARS;
    }

    printf("Enter number of lanes (1-5): ");
    scanf("%d", &num_lanes);
    if (num_lanes < 1) {
        num_lanes = 1;
    } else if (num_lanes > MAX_LANES) {
        num_lanes = MAX_LANES;
    }

    printf("Enter time step (s): ");
    scanf("%d", &time_step);

    Car cars[num_cars];
    for (int i = 0; i < num_cars; i++) {
        cars[i].lane = rand() % num_lanes;
        cars[i].position = MIN_DIST + rand() % (MAX_DIST - MIN_DIST);
        cars[i].speed = MIN_SPEED + rand() % (MAX_SPEED - MIN_SPEED);
    }

    while (1) {
        system("clear");  // clear terminal window
        for (int i = 0; i < num_cars; i++) {
            printf("Car %d (Lane %d): %d km/h at %d m\n",
                   i+1, cars[i].lane+1, cars[i].speed, cars[i].position);
        }
        printf("=============================\n");

        // update position of each car
        for (int i = 0; i < num_cars; i++) {
            int min_dist = MAX_DIST;
            for (int j = 0; j < num_cars; j++) {
                if (i != j && cars[i].lane == cars[j].lane) {
                    int dist = cars[j].position - cars[i].position;
                    if (dist < 0) {
                        dist += MAX_DIST;
                    }
                    if (dist < min_dist) {
                        min_dist = dist;
                    }
                }
            }
            if (min_dist < cars[i].speed * (time_step/3600.0)) {
                cars[i].speed = (int)(min_dist / (time_step/3600.0));
            }
            cars[i].position += cars[i].speed * (time_step/3600.0);
            if (cars[i].position >= MAX_DIST) {
                cars[i].position -= MAX_DIST;
            }
        }

        // sleep for time step
        printf("Press Ctrl+C to exit...\n");
        sleep(time_step);
    }
    
    return 0;
}