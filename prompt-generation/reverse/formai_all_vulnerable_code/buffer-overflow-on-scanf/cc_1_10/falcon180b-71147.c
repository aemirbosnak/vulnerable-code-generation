//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LANES 4
#define MAX_CARS 20
#define MAX_TIME 600

typedef struct {
    int id;
    int lane;
    int speed;
    int time_left;
} Car;

void generate_cars(int num_cars) {
    Car cars[MAX_CARS];
    int i;
    for (i = 0; i < num_cars; i++) {
        cars[i].id = i + 1;
        cars[i].lane = rand() % MAX_LANES;
        cars[i].speed = rand() % 6 + 1;
        cars[i].time_left = rand() % MAX_TIME + 1;
    }
    printf("Generated %d cars:\n", num_cars);
    for (i = 0; i < num_cars; i++) {
        printf("Car %d: Lane %d, Speed %d, Time left %d\n", cars[i].id, cars[i].lane, cars[i].speed, cars[i].time_left);
    }
}

void move_cars(Car cars[], int num_cars, int time_elapsed) {
    int i;
    for (i = 0; i < num_cars; i++) {
        cars[i].time_left -= time_elapsed;
        if (cars[i].time_left <= 0) {
            printf("Car %d reached the end of the road.\n", cars[i].id);
            exit(0);
        }
        cars[i].lane += cars[i].speed;
        if (cars[i].lane >= MAX_LANES) {
            cars[i].lane = 0;
        }
    }
}

int main() {
    int num_cars;
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);
    srand(time(NULL));
    Car cars[MAX_CARS];
    generate_cars(num_cars);
    int time_elapsed = 0;
    while (1) {
        system("clear");
        printf("Time elapsed: %d seconds\n", time_elapsed);
        move_cars(cars, num_cars, time_elapsed);
        time_elapsed += 1;
        usleep(1000000);
    }
    return 0;
}