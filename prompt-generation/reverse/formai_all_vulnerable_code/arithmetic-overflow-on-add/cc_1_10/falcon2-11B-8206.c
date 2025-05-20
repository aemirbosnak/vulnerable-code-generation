//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define traffic light states
    int green = 1;
    int yellow = 2;
    int red = 3;

    // Initialize time variables
    int current_time = time(NULL);
    int next_change = current_time + 3; // Change after 3 seconds

    // Set initial state
    printf("Green light is on.\n");

    // Loop until exit
    while(1)
    {
        // Check if time to change light
        if (time(NULL) > next_change)
        {
            // Change light state
            if (green == 1)
            {
                green = 2;
                yellow = 1;
                printf("Yellow light is on.\n");
            }
            else if (yellow == 1)
            {
                yellow = 2;
                red = 1;
                printf("Red light is on.\n");
            }
            else if (red == 1)
            {
                red = 2;
                green = 1;
                printf("Green light is on.\n");
            }

            // Set next change time
            next_change += 3;
        }

        // Sleep for a second
        sleep(1);
    }

    return 0;
}