//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_WAIT 10

int roads[MAX_ROADS];
int cars[MAX_ROADS][MAX_CARS];
int wait[MAX_ROADS][MAX_WAIT];

int main() {
    int i, j, k, road, car, wait_time, num_cars, num_roads, num_wait;

    printf("Enter number of roads: ");
    scanf("%d", &num_roads);

    printf("Enter number of cars: ");
    scanf("%d", &num_cars);

    printf("Enter number of wait slots: ");
    scanf("%d", &num_wait);

    for (i = 0; i < num_roads; i++) {
        printf("Enter road %d: ", i);
        scanf("%d", &road);
        roads[i] = road;
    }

    for (i = 0; i < num_roads; i++) {
        for (j = 0; j < num_cars; j++) {
            cars[i][j] = -1;
        }
    }

    srand(time(NULL));
    for (i = 0; i < num_roads; i++) {
        for (j = 0; j < num_wait; j++) {
            wait[i][j] = rand() % num_cars;
        }
    }

    for (i = 0; i < num_cars; i++) {
        car = rand() % num_roads;
        for (j = 0; j < num_wait; j++) {
            if (wait[car][j] == -1) {
                wait[car][j] = i;
                break;
            }
        }
    }

    for (i = 0; i < num_roads; i++) {
        for (j = 0; j < num_wait; j++) {
            if (wait[i][j]!= -1) {
                printf("Car %d is waiting at road %d\n", wait[i][j], i);
            }
        }
    }

    return 0;
}