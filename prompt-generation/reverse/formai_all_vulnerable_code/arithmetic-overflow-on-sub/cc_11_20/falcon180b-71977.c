//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define GREEN_LIGHT 2
#define YELLOW_LIGHT 3
#define PEDESTRIAN_LIGHT 4

#define LIGHT_CYCLE_SEC 10
#define PEDESTRIAN_CYCLE_SEC 30

int main() {
    int current_light = RED_LIGHT;
    int pedestrian_light = PEDESTRIAN_LIGHT;
    time_t start_time = time(NULL);
    time_t last_pedestrian_time = start_time;

    while (1) {
        time_t current_time = time(NULL);
        int elapsed_sec = difftime(current_time, start_time);

        if (elapsed_sec % LIGHT_CYCLE_SEC == 0) {
            switch (current_light) {
                case RED_LIGHT:
                    current_light = GREEN_LIGHT;
                    break;
                case GREEN_LIGHT:
                    current_light = YELLOW_LIGHT;
                    break;
                case YELLOW_LIGHT:
                    current_light = RED_LIGHT;
                    break;
            }
        }

        if (elapsed_sec % PEDESTRIAN_CYCLE_SEC == 0) {
            if (pedestrian_light == RED_LIGHT) {
                pedestrian_light = GREEN_LIGHT;
            } else if (pedestrian_light == GREEN_LIGHT) {
                pedestrian_light = YELLOW_LIGHT;
            } else if (pedestrian_light == YELLOW_LIGHT) {
                pedestrian_light = RED_LIGHT;
            }
        }

        if (current_light == RED_LIGHT) {
            printf("The traffic light is red.\n");
        } else if (current_light == GREEN_LIGHT) {
            printf("The traffic light is green.\n");
        } else if (current_light == YELLOW_LIGHT) {
            printf("The traffic light is yellow.\n");
        }

        if (pedestrian_light == RED_LIGHT) {
            printf("The pedestrian light is red.\n");
        } else if (pedestrian_light == GREEN_LIGHT) {
            printf("The pedestrian light is green.\n");
        } else if (pedestrian_light == YELLOW_LIGHT) {
            printf("The pedestrian light is yellow.\n");
        }

        if (elapsed_sec - last_pedestrian_time >= PEDESTRIAN_CYCLE_SEC) {
            last_pedestrian_time = current_time;
            printf("The pedestrian light has changed.\n");
        }
    }

    return 0;
}