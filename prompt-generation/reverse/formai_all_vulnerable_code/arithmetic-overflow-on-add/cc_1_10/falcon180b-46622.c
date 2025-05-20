//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_TIME 100

typedef struct {
    int id;
    int road;
    int position;
    int speed;
} Car;

typedef struct {
    int id;
    int length;
    int max_speed;
} Road;

int main() {
    srand(time(NULL));

    Road roads[MAX_ROADS];
    Car cars[MAX_CARS];

    int num_roads = rand() % MAX_ROADS + 1;
    for (int i = 0; i < num_roads; i++) {
        roads[i].id = i;
        roads[i].length = rand() % 100 + 1;
        roads[i].max_speed = rand() % 100 + 1;
    }

    int num_cars = rand() % MAX_CARS + 1;
    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        cars[i].road = rand() % num_roads;
        cars[i].position = 0;
        cars[i].speed = rand() % (roads[cars[i].road].max_speed - 1) + 1;
    }

    int time = 0;
    while (time < MAX_TIME) {
        printf("Time: %d\n", time);
        for (int i = 0; i < num_roads; i++) {
            printf("Road %d: ", i);
            for (int j = 0; j < roads[i].length; j++) {
                if (j < cars[i].position) {
                    printf(".");
                } else if (j == cars[i].position) {
                    printf("C");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for (int i = 0; i < num_cars; i++) {
            if (cars[i].position < roads[cars[i].road].length - 1) {
                cars[i].position++;
            } else {
                cars[i].road = rand() % num_roads;
                cars[i].position = 0;
            }
        }

        time++;
    }

    return 0;
}