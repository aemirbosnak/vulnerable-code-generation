//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int red = 1, yellow = 0, green = 0;
    clock_t start, end;
    double duration;

    start = clock(); // start the timer
    printf("Traffic Light Controller\n");

    while(1)
    {
        printf("\nRed Light\n");
        while(red == 1)
        {
            end = clock(); // end the timer for Red Light
            duration = (double)(end - start) / CLOCKS_PER_SEC;
            if(duration >= 5) // if the duration is more than or equal to 5 seconds, switch to yellow light
            {
                red = 0;
                yellow = 1;
                start = clock(); // reset the timer for Yellow Light
            }
        }

        printf("\nYellow Light\n");
        while(yellow == 1)
        {
            end = clock(); // end the timer for Yellow Light
            duration = (double)(end - start) / CLOCKS_PER_SEC;
            if(duration >= 2) // if the duration is more than or equal to 2 seconds, switch to green light
            {
                yellow = 0;
                green = 1;
                start = clock(); // reset the timer for Green Light
            }
        }

        printf("\nGreen Light\n");
        while(green == 1)
        {
            end = clock(); // end the timer for Green Light
            duration = (double)(end - start) / CLOCKS_PER_SEC;
            if(duration >= 5) // if the duration is more than or equal to 5 seconds, switch to red light
            {
                green = 0;
                red = 1;
                start = clock(); // reset the timer for Red Light
            }
        }
    }
    return 0;
}