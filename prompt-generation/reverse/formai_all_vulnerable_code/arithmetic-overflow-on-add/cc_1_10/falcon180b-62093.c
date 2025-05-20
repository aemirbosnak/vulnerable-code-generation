//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

#define LIGHT_CYCLE_TIME 10 // seconds
#define YELLOW_LIGHT_DURATION 3 // seconds

int main() {
    int current_light = RED_LIGHT;
    time_t start_time = time(NULL);
    time_t next_light_change = start_time + LIGHT_CYCLE_TIME;

    while (1) {
        time_t current_time = time(NULL);

        if (current_time >= next_light_change) {
            switch (current_light) {
                case RED_LIGHT:
                    printf("Changing to yellow light...\n");
                    current_light = YELLOW_LIGHT;
                    next_light_change = current_time + YELLOW_LIGHT_DURATION;
                    break;
                case YELLOW_LIGHT:
                    printf("Changing to green light...\n");
                    current_light = GREEN_LIGHT;
                    next_light_change = current_time + LIGHT_CYCLE_TIME - YELLOW_LIGHT_DURATION;
                    break;
                case GREEN_LIGHT:
                    printf("Changing to red light...\n");
                    current_light = RED_LIGHT;
                    next_light_change = current_time + LIGHT_CYCLE_TIME;
                    break;
            }
        }

        if (current_light == RED_LIGHT) {
            printf("Current light: red\n");
        } else if (current_light == YELLOW_LIGHT) {
            printf("Current light: yellow\n");
        } else {
            printf("Current light: green\n");
        }

        fflush(stdout);
        sleep(1);
    }

    return 0;
}