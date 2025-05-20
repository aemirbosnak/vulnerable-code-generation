//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define SECONDS_PER_CYCLE 100

int main() {
    int cycle_count = 0;
    int current_light = RED_LIGHT;
    int next_light = GREEN_LIGHT;
    int light_duration[3] = {SECONDS_PER_CYCLE/3, SECONDS_PER_CYCLE/3, SECONDS_PER_CYCLE/3};
    time_t start_time, end_time;

    srand(time(NULL));

    printf("Traffic Light Controller started\n");

    while(1) {
        start_time = time(NULL);
        current_light = next_light;
        next_light = (current_light + 1) % 3;

        printf("Current light: %d\n", current_light);
        printf("Next light: %d\n", next_light);

        switch(current_light) {
            case RED_LIGHT:
                printf("Stop!\n");
                break;
            case YELLOW_LIGHT:
                printf("Slow down!\n");
                break;
            case GREEN_LIGHT:
                printf("Go!\n");
                break;
        }

        end_time = start_time + light_duration[current_light];
        sleep(end_time - start_time);

        cycle_count++;
        if(cycle_count == 10) {
            printf("10 cycles completed\n");
            cycle_count = 0;
        }
    }

    return 0;
}