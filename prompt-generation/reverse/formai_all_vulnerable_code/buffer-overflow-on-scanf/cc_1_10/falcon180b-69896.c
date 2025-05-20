//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define RED_LIGHT_DURATION 20
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 30

void traffic_light_controller(int road_width) {
    int current_light = RED_LIGHT;
    int light_duration = RED_LIGHT_DURATION;
    int pedestrian_light = RED_LIGHT;
    int pedestrian_duration = 30;

    printf("Traffic light controller started for road with width %d\n", road_width);

    while (1) {
        printf("Current light: %d\n", current_light);
        printf("Pedestrian light: %d\n", pedestrian_light);

        switch (current_light) {
            case RED_LIGHT:
                printf("Cars stopped, pedestrians can cross\n");
                break;
            case YELLOW_LIGHT:
                printf("Cars slowing down, pedestrians should not cross\n");
                break;
            case GREEN_LIGHT:
                printf("Cars moving, pedestrians should not cross\n");
                break;
        }

        if (current_light == RED_LIGHT) {
            pedestrian_light = GREEN_LIGHT;
        } else if (current_light == GREEN_LIGHT) {
            pedestrian_light = RED_LIGHT;
        }

        if (light_duration == 0) {
            if (current_light == RED_LIGHT) {
                current_light = GREEN_LIGHT;
            } else {
                current_light = YELLOW_LIGHT;
            }

            light_duration = (rand() % 10) + 1;
        }

        if (pedestrian_duration == 0) {
            pedestrian_light = RED_LIGHT;
            pedestrian_duration = 30;
        }

        light_duration--;
        pedestrian_duration--;

        sleep(1);
    }
}

int main() {
    int road_width;

    printf("Enter road width: ");
    scanf("%d", &road_width);

    traffic_light_controller(road_width);

    return 0;
}