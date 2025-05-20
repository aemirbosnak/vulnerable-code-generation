//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define ROAD_LENGTH 100
#define CAR_SPEED 1

struct road {
    int cars[MAX_ROADS];
};

void init_road(struct road *road) {
    for (int i = 0; i < MAX_ROADS; i++) {
        road->cars[i] = 0;
    }
}

void print_road(struct road *road) {
    for (int i = 0; i < MAX_ROADS; i++) {
        printf("%d ", road->cars[i]);
    }
    printf("\n");
}

void add_car(struct road *road, int road_index) {
    road->cars[road_index]++;
}

void remove_car(struct road *road, int road_index) {
    road->cars[road_index]--;
}

int main() {
    srand(time(NULL));

    struct road road;
    init_road(&road);

    int cars_on_road = 0;

    while (1) {
        system("clear");
        print_road(&road);

        int road_index = rand() % MAX_ROADS;

        if (road.cars[road_index] < ROAD_LENGTH - cars_on_road) {
            add_car(&road, road_index);
            cars_on_road++;
        }

        int car_speed = rand() % (CAR_SPEED * 2) + 1;

        for (int i = 0; i < MAX_CARS; i++) {
            if (road.cars[i] > 0) {
                road.cars[i] += car_speed;

                if (road.cars[i] >= ROAD_LENGTH - cars_on_road) {
                    remove_car(&road, i);
                    cars_on_road--;
                }
            }
        }

        usleep(100000);
    }

    return 0;
}