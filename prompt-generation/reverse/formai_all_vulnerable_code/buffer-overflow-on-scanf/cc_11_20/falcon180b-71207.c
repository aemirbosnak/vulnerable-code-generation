//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PEDESTRIAN_RED 4
#define PEDESTRIAN_GREEN 5

#define LIGHT_INTERVAL 5 // in seconds
#define PEDESTRIAN_INTERVAL 15 // in seconds

int main() {
    int current_light = RED;
    int pedestrian_light = PEDESTRIAN_RED;
    int counter = 0;
    int pedestrian_counter = 0;

    printf("Traffic Light Controller\n");

    while (1) {
        printf("Current light: ");
        switch (current_light) {
            case RED:
                printf("Red\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case GREEN:
                printf("Green\n");
                break;
            default:
                printf("Unknown\n");
        }

        printf("Pedestrian light: ");
        switch (pedestrian_light) {
            case PEDESTRIAN_RED:
                printf("Red\n");
                break;
            case PEDESTRIAN_GREEN:
                printf("Green\n");
                break;
            default:
                printf("Unknown\n");
        }

        if (current_light == RED) {
            if (pedestrian_light == PEDESTRIAN_RED) {
                printf("Press Enter to change the light...\n");
                scanf("%d", &counter);
            }
        } else if (current_light == GREEN) {
            if (pedestrian_light == PEDESTRIAN_RED) {
                printf("Press Enter to change the light...\n");
                scanf("%d", &pedestrian_counter);
            }
        }

        if (counter == LIGHT_INTERVAL) {
            current_light++;
            if (current_light > GREEN) {
                current_light = RED;
            }
        }

        if (pedestrian_counter == PEDESTRIAN_INTERVAL) {
            pedestrian_light++;
            if (pedestrian_light > PEDESTRIAN_GREEN) {
                pedestrian_light = PEDESTRIAN_RED;
            }
        }

        if (current_light == RED && pedestrian_light == PEDESTRIAN_GREEN) {
            printf("Emergency! Stop the traffic!\n");
        }

        sleep(1);
    }

    return 0;
}