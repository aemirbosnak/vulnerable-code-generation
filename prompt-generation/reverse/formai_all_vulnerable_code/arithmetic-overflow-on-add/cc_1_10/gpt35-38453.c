//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialise the variables
    int timeElapsed = 0;
    int greenLight = 0;
    int yellowLight = 0;
    int redLight = 0;

    // prompt the user for input
    printf("Enter the duration for Green Light (in seconds): ");
    scanf("%d", &greenLight);

    printf("Enter the duration for Yellow Light (in seconds): ");
    scanf("%d", &yellowLight);

    printf("Enter the duration for Red Light (in seconds): ");
    scanf("%d", &redLight);

    // calculate the total cycle time
    int totalTime = greenLight + yellowLight + redLight;

    // loop through the traffic light cycle
    while (timeElapsed <= totalTime)
    {
        // check which light to display
        if (timeElapsed >= 0 && timeElapsed < greenLight)
        {
            printf("Green Light!\n");
        }
        else if (timeElapsed >= greenLight && timeElapsed < greenLight + yellowLight)
        {
            printf("Yellow Light!\n");
        }
        else if (timeElapsed >= greenLight + yellowLight && timeElapsed < totalTime)
        {
            printf("Red Light!\n");
        }

        // increment the timer by 1 second
        timeElapsed++;

        // wait for 1 second before displaying the next light
        sleep(1);
    }

    return 0;
}