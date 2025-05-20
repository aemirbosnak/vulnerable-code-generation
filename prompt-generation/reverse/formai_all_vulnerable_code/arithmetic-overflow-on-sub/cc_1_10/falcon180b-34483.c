//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2
#define RED_LIGHT 3

#define DURATION_GREEN 50
#define DURATION_YELLOW 5
#define DURATION_RED 100

void light_controller(int light) {
    switch(light) {
        case GREEN_LIGHT:
            printf("Green light is on.\n");
            break;
        case YELLOW_LIGHT:
            printf("Yellow light is on.\n");
            break;
        case RED_LIGHT:
            printf("Red light is on.\n");
            break;
        default:
            printf("Invalid light state.\n");
            break;
    }
}

int main() {
    int light = GREEN_LIGHT;
    int duration = DURATION_GREEN;

    while(1) {
        light_controller(light);

        if(light == GREEN_LIGHT) {
            printf("Switching to yellow light...\n");
            light = YELLOW_LIGHT;
        } else if(light == YELLOW_LIGHT) {
            printf("Switching to red light...\n");
            light = RED_LIGHT;
        } else if(light == RED_LIGHT) {
            printf("Switching to green light...\n");
            light = GREEN_LIGHT;
        }

        time_t start_time = time(NULL);
        while(duration--) {
            time_t current_time = time(NULL);
            if(current_time - start_time >= 1) {
                break;
            }
        }
    }

    return 0;
}