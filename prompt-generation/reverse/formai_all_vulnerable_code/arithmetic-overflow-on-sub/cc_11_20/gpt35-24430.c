//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int redTime = 15, yellowTime = 3, greenTime = 10;
    int timeRemaining = 0;
    int lightStatus = 0;
    int timerStarted = 0;

    srand(time(NULL));

    while(1) {
        // Check if the timer has started and if the current time has been reached
        if (timerStarted && time(NULL)-timerStarted >= timeRemaining) {
            timerStarted = 0;

            // Switch the traffic light status according to the current status
            if (lightStatus == 0) {
                lightStatus = 1;
                timeRemaining = yellowTime;
                printf("Yellow light: caution!\n");
            } else if (lightStatus == 1) {
                lightStatus = 2;
                timeRemaining = greenTime;
                printf("Green light: go!\n");
            } else if (lightStatus == 2) {
                lightStatus = 0;
                timeRemaining = redTime;
                printf("Red light: stop!\n");
            }
        }

        // If the timer hasn't started, randomly choose a new interval and start the timer
        if (!timerStarted) {
            timeRemaining = rand()%(greenTime+1-redTime) + redTime;

            if (lightStatus == 0) {
                printf("Red light: stop!\n");
            } else if (lightStatus == 1) {
                printf("Yellow light: caution!\n");
            } else if (lightStatus == 2) {
                printf("Green light: go!\n");
            }

            timerStarted = time(NULL);
        }
    }

    return 0;
}