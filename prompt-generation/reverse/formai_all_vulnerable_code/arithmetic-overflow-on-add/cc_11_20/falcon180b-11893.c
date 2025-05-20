//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define PEDESTRIAN_RED 3
#define PEDESTRIAN_GREEN 4

int main() {
    int state = RED;
    int pedestrianState = PEDESTRIAN_RED;
    int duration[5] = {10, 5, 10, 5, 10}; // seconds
    int i = 0;
    int j = 0;
    time_t startTime;
    time_t endTime;
    time_t currentTime;

    srand(time(NULL));

    startTime = time(NULL);
    endTime = startTime + duration[i];

    while (1) {
        currentTime = time(NULL);

        if (currentTime >= endTime) {
            i++;
            if (i >= 5) {
                i = 0;
            }
            j++;
            if (j >= 5) {
                j = 0;
            }
            endTime = currentTime + duration[i];
        }

        if (state == RED) {
            printf("Traffic Light: Red\n");
            printf("Pedestrian Light: ");
            if (pedestrianState == PEDESTRIAN_RED) {
                printf("Red\n");
            } else {
                printf("Green\n");
            }
        } else if (state == YELLOW) {
            printf("Traffic Light: Yellow\n");
            printf("Pedestrian Light: ");
            if (pedestrianState == PEDESTRIAN_RED) {
                printf("Red\n");
            } else {
                printf("Green\n");
            }
        } else if (state == GREEN) {
            printf("Traffic Light: Green\n");
            printf("Pedestrian Light: ");
            if (pedestrianState == PEDESTRIAN_RED) {
                printf("Red\n");
            } else {
                printf("Green\n");
            }
        } else if (state == PEDESTRIAN_RED) {
            printf("Traffic Light: ");
            if (pedestrianState == PEDESTRIAN_RED) {
                printf("Red\n");
            } else {
                printf("Green\n");
            }
            printf("Pedestrian Light: Red\n");
        } else if (state == PEDESTRIAN_GREEN) {
            printf("Traffic Light: ");
            if (pedestrianState == PEDESTRIAN_RED) {
                printf("Red\n");
            } else {
                printf("Green\n");
            }
            printf("Pedestrian Light: Green\n");
        }

        fflush(stdout);
        usleep(1000000); // 1 second
    }

    return 0;
}