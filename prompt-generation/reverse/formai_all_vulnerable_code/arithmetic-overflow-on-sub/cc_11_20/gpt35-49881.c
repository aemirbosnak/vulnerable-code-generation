//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_INTERSECTIONS 10
#define MAX_TIME 60

struct car {
    int id;
    int arrival_time;
    int intersection_start;
    int intersection_end;
};

struct intersection {
    int id;
    int green_time;
    int remaining_time;
};

int main() {
    srand(time(NULL));

    int num_cars = rand() % MAX_CARS + 1;
    struct car cars[MAX_CARS];

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i + 1;
        cars[i].arrival_time = rand() % MAX_TIME;
        cars[i].intersection_start = rand() % MAX_INTERSECTIONS;
        cars[i].intersection_end = rand() % MAX_INTERSECTIONS;
    }

    int num_intersections = rand() % MAX_INTERSECTIONS + 1;
    struct intersection intersections[MAX_INTERSECTIONS];

    for (int i = 0; i < num_intersections; i++) {
        intersections[i].id = i + 1;
        intersections[i].green_time = rand() % MAX_TIME;
        intersections[i].remaining_time = intersections[i].green_time;
    }

    printf("Simulation starting with %d cars and %d intersections\n", num_cars, num_intersections);

    for (int time = 0; time < MAX_TIME; time++) {
        printf("Time: %d\n", time);

        for (int i = 0; i < num_cars; i++) {
            if (cars[i].arrival_time == time) {
                printf("Car %d arriving at intersection %d\n", cars[i].id, cars[i].intersection_start);
            }
        }

        for (int i = 0; i < num_intersections; i++) {
            printf("Intersection %d: ", intersections[i].id);

            if (intersections[i].remaining_time == 0) {
                printf("Changing to Green\n");
                intersections[i].green_time = rand() % MAX_TIME;
                intersections[i].remaining_time = intersections[i].green_time;
            } else {
                printf("Green for %d more seconds\n", intersections[i].remaining_time);
                intersections[i].remaining_time--;
            }
        }

        for (int i = 0; i < num_cars; i++) {
            if (cars[i].arrival_time == time) {
                printf("Car %d starting to cross intersection %d\n", cars[i].id, cars[i].intersection_start);
                if (intersections[cars[i].intersection_start].remaining_time > 0) {
                    printf("Car %d waiting at intersection %d\n", cars[i].id, cars[i].intersection_start);
                } else {
                    printf("Car %d crossing intersection %d\n", cars[i].id, cars[i].intersection_start);
                    intersections[cars[i].intersection_start].remaining_time--;
                    printf("Car %d arriving at intersection %d\n", cars[i].id, cars[i].intersection_end);
                }
            }
        }
    }

    printf("Simulation complete\n");

    return 0;
}