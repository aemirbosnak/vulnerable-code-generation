//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cryptic
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

const int cycleSeconds = 120;

int main() {
    int currentColor = RED;
    time_t start_time;
    bool isCycleFinished = true;

    while (true) {
        if (isCycleFinished) {
            start_time = time(NULL);
            isCycleFinished = false;
        }

        time_t current_time = time(NULL);
        int elapsedTime = current_time - start_time;
        int timeLeft = cycleSeconds - elapsedTime;

        if (timeLeft <= 0) {
            isCycleFinished = true;
            if (currentColor == RED) {
                currentColor = GREEN;
            } else if (currentColor == GREEN) {
                currentColor = YELLOW;
            } else if (currentColor == YELLOW) {
                currentColor = RED;
            }
        }

        if (currentColor == GREEN) {
            printf("Green Light\n");
        } else if (currentColor == YELLOW) {
            printf("Yellow Light\n");
        } else if (currentColor == RED) {
            printf("Red Light\n");
        }

        if (timeLeft <= 10) {
            printf("Time Left: %d seconds\n", timeLeft);
        }

        sleep(1);
    }
    
    return 0;
}