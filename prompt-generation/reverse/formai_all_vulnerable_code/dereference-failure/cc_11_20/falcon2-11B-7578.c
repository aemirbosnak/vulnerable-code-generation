//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 1000
#define MAX_CARS 10000

typedef struct {
    int id;
    int start_road;
    int end_road;
    int speed;
} Car;

typedef struct {
    int id;
    int start_road;
    int end_road;
} Road;

int main() {
    srand(time(NULL));

    int num_roads, num_cars;
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    Road *roads = (Road*)malloc(num_roads * sizeof(Road));
    Car *cars = (Car*)malloc(num_cars * sizeof(Car));

    for (int i = 0; i < num_roads; i++) {
        roads[i].id = i;
        roads[i].start_road = rand() % MAX_ROADS;
        roads[i].end_road = rand() % MAX_ROADS;
    }

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].start_road = rand() % MAX_ROADS;
        cars[i].end_road = rand() % MAX_ROADS;
        cars[i].speed = rand() % 100 + 1;
    }

    int num_moves = 0;
    while (num_moves < 10000) {
        for (int i = 0; i < num_cars; i++) {
            int next_road = -1;
            for (int j = 0; j < MAX_ROADS; j++) {
                if (roads[j].start_road == cars[i].start_road && roads[j].end_road == cars[i].end_road) {
                    next_road = j;
                    break;
                }
            }

            if (next_road == -1) {
                continue;
            }

            if (next_road!= cars[i].end_road) {
                cars[i].end_road = next_road;
            }

            if (next_road!= cars[i].start_road) {
                cars[i].start_road = next_road;
            }

            if (next_road!= cars[i].end_road) {
                cars[i].start_road = next_road;
            }

            cars[i].end_road = next_road;

            if (next_road!= cars[i].start_road) {
                cars[i].start_road = next_road;
            }

            if (next_road!= cars[i].end_road) {
                cars[i].start_road = next_road;
            }

            cars[i].end_road = next_road;
        }

        num_moves++;
    }

    for (int i = 0; i < num_cars; i++) {
        printf("Car %d: %d -> %d (%d)\n", cars[i].id, cars[i].start_road, cars[i].end_road, cars[i].speed);
    }

    for (int i = 0; i < num_roads; i++) {
        printf("Road %d: %d -> %d\n", roads[i].id, roads[i].start_road, roads[i].end_road);
    }

    return 0;
}