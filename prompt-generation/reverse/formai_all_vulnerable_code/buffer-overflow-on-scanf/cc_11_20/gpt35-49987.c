//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_TIME 100
#define MAX_SPEED 5

typedef struct {
    int x;
    int speed;
} Car;

int main() {
    srand((unsigned int) time(NULL));
    Car cars[MAX_CARS];
    int i, j, time, num_cars, road_length, new_car_chance;
    printf("Enter the length of the road: ");
    scanf("%d", &road_length);
    printf("Enter the initial number of cars: ");
    scanf("%d", &num_cars);
    printf("Enter the probability of a new car being added in each time step (0-100): ");
    scanf("%d", &new_car_chance);
    for (i = 0; i < num_cars; i++) {
        cars[i].x = rand() % road_length;
        cars[i].speed = 1;
    }
    for (time = 0; time < MAX_TIME; time++) {
        // Move cars
        for (i = 0; i < num_cars; i++) {
            if (cars[i].x + cars[i].speed < road_length) {
                cars[i].x += cars[i].speed;
            }
        }
        // Check for collisions
        for (i = 0; i < num_cars; i++) {
            for (j = i + 1; j < num_cars; j++) {
                if (cars[i].x == cars[j].x && cars[i].speed > 0 && cars[i].speed == cars[j].speed) {
                    cars[i].speed = cars[i].speed > 1 ? cars[i].speed - 1 : 0;
                    cars[j].speed = cars[j].speed > 1 ? cars[j].speed - 1 : 0;
                }
            }
        }
        // Add new car with probability new_car_chance
        if (rand() % 100 < new_car_chance) {
            if (num_cars < MAX_CARS) {
                cars[num_cars].x = 0;
                cars[num_cars].speed = rand() % MAX_SPEED + 1;
                num_cars++;
            }
        }
        // Print current state of the road
        for (i = 0; i < road_length; i++) {
            int car_printed = 0;
            for (j = 0; j < num_cars; j++) {
                if (cars[j].x == i && cars[j].speed > 0) {
                    printf("X");
                    car_printed = 1;
                    break;
                }
            }
            if (!car_printed) {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}