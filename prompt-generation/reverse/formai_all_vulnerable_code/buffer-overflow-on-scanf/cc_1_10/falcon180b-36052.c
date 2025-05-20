//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_LIGHTS 10
#define RED_LIGHT 0
#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2

int road_length[MAX_ROADS];
int cars_on_road[MAX_ROADS];
int lights[MAX_LIGHTS];
int num_roads, num_lights;

void init_roads(int num) {
    num_roads = num;
    for (int i = 0; i < num_roads; i++) {
        road_length[i] = rand() % 100 + 1;
        cars_on_road[i] = 0;
    }
}

void init_lights(int num) {
    num_lights = num;
    for (int i = 0; i < num_lights; i++) {
        lights[i] = rand() % 3;
    }
}

void print_roads() {
    for (int i = 0; i < num_roads; i++) {
        printf("Road %d: %d cars\n", i+1, cars_on_road[i]);
    }
}

void print_lights() {
    for (int i = 0; i < num_lights; i++) {
        if (lights[i] == RED_LIGHT) {
            printf("Light %d is red\n", i+1);
        } else if (lights[i] == GREEN_LIGHT) {
            printf("Light %d is green\n", i+1);
        } else {
            printf("Light %d is yellow\n", i+1);
        }
    }
}

void move_cars() {
    for (int i = 0; i < num_roads; i++) {
        if (cars_on_road[i] > 0) {
            if (lights[i] == GREEN_LIGHT) {
                cars_on_road[i]--;
            } else if (lights[i] == YELLOW_LIGHT) {
                if (cars_on_road[i] > road_length[i]/2) {
                    cars_on_road[i]--;
                }
            }
        }
    }
}

void change_lights() {
    for (int i = 0; i < num_lights; i++) {
        if (lights[i] == GREEN_LIGHT) {
            lights[i] = YELLOW_LIGHT;
        } else if (lights[i] == YELLOW_LIGHT) {
            lights[i] = RED_LIGHT;
        } else {
            lights[i] = GREEN_LIGHT;
        }
    }
}

int main() {
    srand(time(NULL));
    int num_roads, num_lights;
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);
    printf("Enter the number of lights: ");
    scanf("%d", &num_lights);
    init_roads(num_roads);
    init_lights(num_lights);

    while (1) {
        move_cars();
        change_lights();
        print_roads();
        print_lights();
        sleep(1);
    }

    return 0;
}