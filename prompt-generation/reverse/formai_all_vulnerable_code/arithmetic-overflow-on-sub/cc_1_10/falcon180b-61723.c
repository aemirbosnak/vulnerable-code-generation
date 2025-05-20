//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RED 1
#define GREEN 2
#define YELLOW 3
#define PEDESTRIAN 4
#define EMERGENCY 5
#define NUM_LANES 4
#define NUM_PEDESTRIANS 2
#define NUM_EMERGENCY 1
#define TOTAL_LIGHTS (NUM_LANES + NUM_PEDESTRIANS + NUM_EMERGENCY)
#define DELAY 1

int main() {
    int lights[TOTAL_LIGHTS];
    int current_light = 0;
    int num_lights = NUM_LANES;
    int i;
    time_t start_time, end_time;

    srand(time(NULL));
    for (i = 0; i < TOTAL_LIGHTS; i++) {
        lights[i] = rand() % (RED + 1);
    }

    start_time = time(NULL);
    while (1) {
        if (current_light == TOTAL_LIGHTS) {
            current_light = 0;
            end_time = time(NULL);
            printf("Cycle completed in %ld seconds\n", end_time - start_time);
            start_time = end_time;
        }
        printf("Current light: %d\n", lights[current_light]);
        if (lights[current_light] == RED) {
            printf("Stop!\n");
            sleep(DELAY);
        } else if (lights[current_light] == GREEN) {
            printf("Go!\n");
            sleep(DELAY);
        } else if (lights[current_light] == YELLOW) {
            printf("Slow down!\n");
            sleep(DELAY);
        } else if (lights[current_light] == PEDESTRIAN) {
            printf("Stop for pedestrians!\n");
            sleep(DELAY);
        } else if (lights[current_light] == EMERGENCY) {
            printf("Emergency vehicle approaching!\n");
            sleep(DELAY);
        }
        current_light++;
    }

    return 0;
}