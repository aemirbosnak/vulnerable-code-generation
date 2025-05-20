//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROADS 100
#define MAX_CARS 100

typedef struct {
    int x;
    int y;
    int speed;
    int direction;
    int road;
} Car;

typedef struct {
    int x;
    int y;
} Road;

int main() {
    int numRoads, numCars;
    printf("Enter the number of roads: ");
    scanf("%d", &numRoads);
    printf("Enter the number of cars: ");
    scanf("%d", &numCars);

    Car* cars = malloc(numCars * sizeof(Car));
    Road* roads = malloc(numRoads * sizeof(Road));

    for (int i = 0; i < numRoads; i++) {
        printf("Enter the coordinates of road %d: ", i + 1);
        scanf("%d %d", &roads[i].x, &roads[i].y);
    }

    for (int i = 0; i < numCars; i++) {
        printf("Enter the coordinates and speed of car %d: ", i + 1);
        scanf("%d %d %d %d", &cars[i].x, &cars[i].y, &cars[i].speed, &cars[i].direction);
        cars[i].road = rand() % numRoads;
    }

    for (int i = 0; i < numRoads; i++) {
        printf("Road %d: %d %d\n", i + 1, roads[i].x, roads[i].y);
    }

    for (int i = 0; i < numCars; i++) {
        printf("Car %d: %d %d %d %d\n", i + 1, cars[i].x, cars[i].y, cars[i].speed, cars[i].direction);
    }

    for (int i = 0; i < numCars; i++) {
        int index = (cars[i].x + cars[i].y) * 2 % numRoads;
        cars[i].road = roads[index].x + (roads[index].y + 1) * (cars[i].direction == 1? 1 : -1);
    }

    for (int i = 0; i < numRoads; i++) {
        printf("Road %d: %d %d\n", i + 1, roads[i].x, roads[i].y);
    }

    for (int i = 0; i < numCars; i++) {
        printf("Car %d: %d %d %d %d\n", i + 1, cars[i].x, cars[i].y, cars[i].speed, cars[i].direction);
    }

    for (int i = 0; i < numCars; i++) {
        int j = (cars[i].x + cars[i].y) * 2 % numRoads;
        int index = cars[i].road - (roads[j].x + (roads[j].y + 1) * (cars[i].direction == 1? 1 : -1));
        if (index >= 0 && index < numRoads) {
            int distance = sqrt((roads[index].x - cars[i].x) * (roads[index].x - cars[i].x) + (roads[index].y - cars[i].y) * (roads[index].y - cars[i].y));
            if (distance < cars[i].speed) {
                cars[i].speed -= distance;
            } else {
                cars[i].speed = 0;
            }
        }
    }

    for (int i = 0; i < numCars; i++) {
        printf("Car %d: %d %d %d %d\n", i + 1, cars[i].x, cars[i].y, cars[i].speed, cars[i].direction);
    }

    free(roads);
    free(cars);

    return 0;
}