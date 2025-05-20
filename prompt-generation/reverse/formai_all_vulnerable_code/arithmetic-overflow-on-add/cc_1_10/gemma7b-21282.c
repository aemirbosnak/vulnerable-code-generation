//Gemma-7B DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i = 0;
    int t = 0;
    int r = 0;
    int g = 0;
    time_t timer;

    // Seed the random number generator
    srand(time(NULL));

    // Set the initial traffic light status
    r = 1;
    g = 0;

    // Start the timer
    timer = time(NULL) + 5;

    // Loop until the timer times out
    while (time(NULL) < timer)
    {
        // Flash the red light
        if (r && i % 2 == 0)
        {
            printf("Red light is flashing.\n");
        }

        // Turn on the green light
        if (g && i % 2 == 0)
        {
            printf("Green light is on.\n");
        }

        // Increment the timer
        t++;

        // Randomly change the traffic light status
        if (rand() % 5 == 0)
        {
            r = 0;
            g = 1;
        }

        // Increment the loop counter
        i++;

        // Sleep for a while
        sleep(1);
    }

    // End the timer
    printf("Traffic light controller is stopping.\n");

    return 0;
}