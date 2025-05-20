//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 30
#define YELLOW_LIGHT_DURATION 10
#define GREEN_LIGHT_DURATION 40

void traffic_light_controller(void) {
    int state = 0;
    time_t start_time;
    time_t current_time;

    srand(time(NULL));
    start_time = rand() % (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION);

    while (1) {
        current_time = start_time + state * RED_LIGHT_DURATION;
        printf("Current state: %d\n", state);
        printf("Current time: %ld\n", current_time);
        fflush(stdout);

        switch (state) {
            case 0:
                printf("Red light on\n");
                break;
            case 1:
                printf("Yellow light on\n");
                break;
            case 2:
                printf("Green light on\n");
                break;
        }

        fflush(stdout);

        time_t next_state_time = current_time + state * GREEN_LIGHT_DURATION;
        if (next_state_time > start_time) {
            state = (state + 1) % 3;
        } else {
            state = 0;
        }

        time_t sleep_time = next_state_time - time(NULL);
        if (sleep_time > 0) {
            sleep(sleep_time);
        }
    }
}

int main(int argc, char *argv[]) {
    traffic_light_controller();
    return 0;
}