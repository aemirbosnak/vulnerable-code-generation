//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define RED_LIGHT_DURATION 20
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 30

int main() {
    int current_light = RED_LIGHT;
    time_t start_time;
    time_t end_time;

    srand(time(NULL));
    start_time = time(NULL);

    while(1) {
        switch(current_light) {
            case RED_LIGHT:
                printf("Red Light\n");
                end_time = start_time + RED_LIGHT_DURATION;
                while(difftime(time(NULL), end_time) > 0) {
                    printf("Waiting...\n");
                    fflush(stdout);
                    sleep(1);
                }
                current_light = YELLOW_LIGHT;
                break;

            case YELLOW_LIGHT:
                printf("Yellow Light\n");
                end_time = start_time + YELLOW_LIGHT_DURATION;
                while(difftime(time(NULL), end_time) > 0) {
                    printf("Waiting...\n");
                    fflush(stdout);
                    sleep(1);
                }
                current_light = GREEN_LIGHT;
                break;

            case GREEN_LIGHT:
                printf("Green Light\n");
                end_time = start_time + GREEN_LIGHT_DURATION;
                while(difftime(time(NULL), end_time) > 0) {
                    printf("Waiting...\n");
                    fflush(stdout);
                    sleep(1);
                }
                current_light = RED_LIGHT;
                break;
        }
    }

    return 0;
}