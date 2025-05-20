//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_DURATION 10 // seconds
#define YELLOW_DURATION 3 // seconds
#define RED_DURATION 15 // seconds
#define TOTAL_DURATION (GREEN_DURATION + YELLOW_DURATION + RED_DURATION) // seconds

enum traffic_light_state {
    GREEN,
    YELLOW,
    RED
};

void traffic_light_controller(int duration) {
    enum traffic_light_state current_state = GREEN;
    time_t start_time = time(NULL);
    time_t end_time = start_time + duration;

    while (difftime(time(NULL), start_time) < duration) {
        switch (current_state) {
            case GREEN:
                printf("Green light is on.\n");
                break;
            case YELLOW:
                printf("Yellow light is on.\n");
                break;
            case RED:
                printf("Red light is on.\n");
                break;
        }
        sleep(1);

        if (current_state == GREEN) {
            current_state = YELLOW;
        } else if (current_state == YELLOW) {
            current_state = RED;
        } else if (current_state == RED) {
            current_state = GREEN;
        }
    }
}

int main() {
    int duration = TOTAL_DURATION;
    srand(time(NULL));
    int random_duration = rand() % (duration / 2) + duration / 2; // random duration between 50% and 100% of total duration

    printf("Traffic light controller starting...\n");
    traffic_light_controller(random_duration);

    return 0;
}