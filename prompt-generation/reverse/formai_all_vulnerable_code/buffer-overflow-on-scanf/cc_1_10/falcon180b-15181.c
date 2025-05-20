//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_WAIT_TIME 10

typedef struct {
    int id;
    int road;
    int speed;
    int wait_time;
} Car;

typedef struct {
    int id;
    int length;
    int wait_time;
} Road;

void init_road(Road *road, int id, int length) {
    road->id = id;
    road->length = length;
    road->wait_time = 0;
}

void init_car(Car *car, int id, int road, int speed) {
    car->id = id;
    car->road = road;
    car->speed = speed;
    car->wait_time = 0;
}

void move_car(Car *car, Road *road) {
    int distance = car->speed * road->length / 100;
    int wait_time = rand() % MAX_WAIT_TIME;

    if (distance + car->wait_time > road->length) {
        road->wait_time += distance + car->wait_time - road->length;
        car->wait_time = road->wait_time;
    } else {
        car->wait_time += wait_time;
        road->wait_time += wait_time;
    }

    car->wait_time -= distance;
    road->wait_time -= distance;
}

int main() {
    srand(time(NULL));

    Road roads[MAX_ROADS];
    Car cars[MAX_CARS];

    int num_roads = 0;
    int num_cars = 0;

    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);

    for (int i = 0; i < num_roads; i++) {
        int id, length;
        printf("Enter the ID and length of road %d: ", i + 1);
        scanf("%d %d", &id, &length);
        init_road(&roads[i], id, length);
    }

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    for (int i = 0; i < num_cars; i++) {
        int id, road, speed;
        printf("Enter the ID, road, and speed of car %d: ", i + 1);
        scanf("%d %d %d", &id, &road, &speed);
        init_car(&cars[i], id, road, speed);
    }

    while (1) {
        for (int i = 0; i < num_cars; i++) {
            move_car(&cars[i], &roads[cars[i].road]);
        }
    }

    return 0;
}