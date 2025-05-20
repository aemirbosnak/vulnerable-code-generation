//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int light = 0;
    char response;
    time_t t;

    // Get current time
    time(&t);

    // Generate a random seed based on current time
    srand((unsigned)t);

    // Turn off lights by default
    printf("Lights are currently off.\n");

    // Loop until user decides to turn off lights
    do
    {
        // Prompt user for input
        printf("Would you like to turn the lights on? (y/n) ");
        scanf(" %c", &response);

        if (response == 'y')
        {
            // Generate a random number from 1-100
            int random_num = rand() % 100 + 1;

            // Determine if the lights should turn on
            if (random_num <= 50)
            {
                // Turn on lights
                printf("Turning on lights.\n");
                light = 1;
            }
            else
            {
                // Lights don't turn on
                printf("Lights did not turn on.\n");
            }
        }
    } while (response != 'n');

    // Turn off lights
    if (light == 1)
    {
        printf("Turning off lights.\n");
    }

    return 0;
}