//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define PEDESTRIAN 3

int main() {
    int state = RED;
    int pedestrianState = PEDESTRIAN;
    int cycleTime = 10; // in seconds
    int pedestrianCycleTime = 30; // in seconds
    time_t startTime;
    time_t endTime;
    time_t pedestrianStartTime;
    time_t pedestrianEndTime;

    srand(time(NULL));

    startTime = time(NULL);
    endTime = startTime + cycleTime;

    while (1) {
        if (state == RED) {
            printf("Traffic light is red.\n");
        } else if (state == YELLOW) {
            printf("Traffic light is yellow.\n");
        } else if (state == GREEN) {
            printf("Traffic light is green.\n");
        } else if (state == PEDESTRIAN) {
            printf("Pedestrian crossing is active.\n");
        }

        if (difftime(time(NULL), startTime) >= cycleTime) {
            switch (state) {
                case RED:
                    state = GREEN;
                    break;
                case YELLOW:
                    state = RED;
                    break;
                case GREEN:
                    state = YELLOW;
                    break;
                case PEDESTRIAN:
                    state = RED;
                    break;
            }

            startTime = time(NULL);
        }

        if (difftime(time(NULL), pedestrianStartTime) >= pedestrianCycleTime) {
            pedestrianState = PEDESTRIAN;
            pedestrianStartTime = time(NULL);
        }

        if (state == PEDESTRIAN) {
            if (difftime(time(NULL), pedestrianEndTime) >= pedestrianCycleTime) {
                state = RED;
                pedestrianEndTime = time(NULL);
            }
        }
    }

    return 0;
}