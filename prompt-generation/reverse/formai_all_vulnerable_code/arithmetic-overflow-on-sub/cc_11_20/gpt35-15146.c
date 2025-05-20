//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

int main()
{
    int green = TRUE, red = FALSE, yellow = FALSE;
    int timeCounter = 0;
    srand(time(NULL));
    printf("Welcome to our Crazy Traffic Light Controller!\n\n");

    while(TRUE)
    {
        timeCounter++;
        if(green)
        {
            printf("Green Light On!\n");
            if(timeCounter == 20)
            {
                printf("Yellow Light On!\n");
                green = FALSE;
                yellow = TRUE;
                timeCounter = 0;
            }
        }
        else if(yellow)
        {
            printf("Yellow Light On!\n");
            if(timeCounter == 5)
            {
                printf("Red Light On!\n");
                yellow = FALSE;
                red = TRUE;
                timeCounter = 0;
            }
        }
        else if(red)
        {
            printf("Red Light On!\n");
            if(timeCounter == 15)
            {
                printf("Green Light On!\n");
                red = FALSE;
                green = TRUE;
                timeCounter = 0;
            }
        }

        // Let's add some randomness to keep things interesting
        if(rand() % 100 > 90)
        {
            printf("\nOh no! There's a chicken crossing the road!\n");
            printf("Stopping traffic immediately!\n");
            green = FALSE;
            yellow = TRUE;
            timeCounter = 0;

            // Let's wait for a bit to give the chicken some time to cross
            int waitingTime = rand() % 3 + 1; // Random number between 1 and 3 seconds
            printf("Waiting for chicken to cross for %d seconds...\n\n", waitingTime);

            // Wait for the specified number of seconds
            int startTime = time(NULL);
            while(time(NULL) - startTime < waitingTime) {}

            // Back to normal traffic
            yellow = FALSE;
            red = TRUE;
        }

        // Wait for 1 second before proceeding to the next iteration
        int startTime = time(NULL);
        while(time(NULL) - startTime < 1) {}
    }

    return 0;
}