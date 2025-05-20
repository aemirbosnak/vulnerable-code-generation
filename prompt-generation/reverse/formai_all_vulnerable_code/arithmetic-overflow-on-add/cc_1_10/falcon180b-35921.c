//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define PEDESTRIAN_GREEN_LIGHT 3
#define PEDESTRIAN_RED_LIGHT 4

int main() {
    int current_light = RED_LIGHT;
    int pedestrian_light = PEDESTRIAN_RED_LIGHT;
    time_t start_time, current_time;

    srand(time(NULL));
    start_time = time(NULL) + rand() % 10;

    while (1) {
        current_time = time(NULL);

        if (current_time >= start_time) {
            if (current_light == RED_LIGHT) {
                current_light = GREEN_LIGHT;
                pedestrian_light = PEDESTRIAN_RED_LIGHT;
            } else if (current_light == GREEN_LIGHT) {
                current_light = YELLOW_LIGHT;
                pedestrian_light = PEDESTRIAN_GREEN_LIGHT;
            } else if (current_light == YELLOW_LIGHT) {
                current_light = RED_LIGHT;
                pedestrian_light = PEDESTRIAN_RED_LIGHT;
            }

            start_time = current_time + rand() % 10;
        }

        printf("Current light: %d\n", current_light);
        printf("Pedestrian light: %d\n", pedestrian_light);

        if (current_light == GREEN_LIGHT && pedestrian_light == PEDESTRIAN_RED_LIGHT) {
            printf("Cars can go, pedestrians must stop.\n");
        } else if (current_light == RED_LIGHT && pedestrian_light == PEDESTRIAN_GREEN_LIGHT) {
            printf("Cars must stop, pedestrians can go.\n");
        } else {
            printf("Cars and pedestrians must stop.\n");
        }

        fflush(stdout);
        sleep(1);
    }

    return 0;
}