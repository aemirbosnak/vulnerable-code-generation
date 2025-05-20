//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

int main() {
    int current_light = RED_LIGHT;
    int next_light = GREEN_LIGHT;
    int light_duration = 5; // in seconds
    int cycle_duration = 30; // in seconds
    int cycle_count = 0;
    time_t start_time = 0;
    time_t current_time = 0;

    srand(time(NULL));

    printf("Traffic light controller started...\n");

    while (1) {
        current_time = time(NULL);

        if (start_time == 0) {
            start_time = current_time;
        }

        if (current_light == RED_LIGHT) {
            if ((current_time - start_time) >= light_duration) {
                current_light = YELLOW_LIGHT;
                start_time = current_time;
            }
        } else if (current_light == YELLOW_LIGHT) {
            if ((current_time - start_time) >= light_duration) {
                current_light = GREEN_LIGHT;
                start_time = current_time;
            }
        } else if (current_light == GREEN_LIGHT) {
            if ((current_time - start_time) >= light_duration) {
                current_light = YELLOW_LIGHT;
                start_time = current_time;
            }
        }

        if ((current_time - start_time) >= cycle_duration) {
            cycle_count++;
            start_time = current_time;
        }

        if (cycle_count >= 10) {
            current_light = next_light;
            cycle_count = 0;
        }

        printf("Current light: ");
        switch (current_light) {
            case RED_LIGHT:
                printf("RED\n");
                break;
            case YELLOW_LIGHT:
                printf("YELLOW\n");
                break;
            case GREEN_LIGHT:
                printf("GREEN\n");
                break;
            default:
                printf("UNKNOWN\n");
                break;
        }

        sleep(1);
    }

    return 0;
}