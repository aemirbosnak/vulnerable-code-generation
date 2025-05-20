//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int redTime = 10;
    int yellowTime = 5;
    int greenTime = 30;

    int timeLeft = redTime;
    char light[10] = "red";

    time_t t;
    srand((unsigned) time(&t));

    printf("Traffic Light Controller\n");

    printf("\n\nInitializing lights...\n");

    // Main loop for the traffic lights
    while (1) {

        // Check if the light is still red
        if (timeLeft > 0 && strcmp(light, "red") == 0) {
            printf("\n\nRed Light\n");
            printf("Time remaining: %d\n", timeLeft);
            timeLeft--;

            // Wait for a second
            clock_t start_time = clock();
            while (clock() < start_time + CLOCKS_PER_SEC);
        }

        // Check if the light is still yellow
        else if (timeLeft > 1 && strcmp(light, "yellow") == 0) {
            printf("Yellow Light\n");
            printf("Time remaining: %d\n", timeLeft);
            timeLeft--;

            // Wait for a second
            clock_t start_time = clock();
            while (clock() < start_time + CLOCKS_PER_SEC);
        }

        // Check if the light is still green
        else if (timeLeft > 0 && strcmp(light, "green") == 0) {
            printf("Green Light\n");
            printf("Time remaining: %d\n", timeLeft);
            timeLeft--;

            // Wait for a second
            clock_t start_time = clock();
            while (clock() < start_time + CLOCKS_PER_SEC);
        }

        // If all lights have been cycled through, reset everything
        else {
            if (strcmp(light, "red") == 0) {
                light[10] = "green";
                timeLeft = greenTime;
            } else if (strcmp(light, "yellow") == 0) {
                light[10] = "red";
                timeLeft = redTime;
            } else if (strcmp(light, "green") == 0) {
                light[10] = "yellow";
                timeLeft = yellowTime;
            }
            printf("\n\nSwitching to %s Light\n", light);

            // Randomly introduce a delay between light switches
            int delay = rand() % 5;
            printf("Delay: %d seconds\n", delay);

            // Wait for the delay
            clock_t start_time = clock();
            while (clock() < start_time + delay * CLOCKS_PER_SEC);
        }
    }

    return 0;
}