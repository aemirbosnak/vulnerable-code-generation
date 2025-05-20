//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define GREEN 2
#define YELLOW 3
#define PEDESTRIAN 4

int main() {
    int state = RED;
    int duration = 10; // in seconds
    int pedestrian_duration = 30; // in seconds
    time_t start_time;
    time_t end_time;
    time_t pedestrian_end_time;

    srand(time(NULL));

    start_time = time(NULL);
    end_time = start_time + duration;

    while (state!= PEDESTRIAN && state!= RED) {
        printf("Current state: %d\n", state);
        fflush(stdout);
        switch (state) {
            case RED:
                printf("Red light on\n");
                break;
            case GREEN:
                printf("Green light on\n");
                break;
            case YELLOW:
                printf("Yellow light on\n");
                break;
            case PEDESTRIAN:
                printf("Pedestrian light on\n");
                break;
        }
        state = rand() % 4;
        if (state == RED) {
            printf("Red light on\n");
        } else if (state == GREEN) {
            printf("Green light on\n");
        } else if (state == YELLOW) {
            printf("Yellow light on\n");
        } else if (state == PEDESTRIAN) {
            printf("Pedestrian light on\n");
        }
        end_time = start_time + duration;
        if (state == PEDESTRIAN) {
            pedestrian_end_time = end_time + pedestrian_duration;
        }
    }

    printf("Pedestrian light on\n");
    while (time(NULL) < pedestrian_end_time) {
        printf("Pedestrian light on\n");
        fflush(stdout);
        sleep(1);
    }

    printf("Red light on\n");
    state = RED;
    while (time(NULL) < end_time) {
        printf("Red light on\n");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}