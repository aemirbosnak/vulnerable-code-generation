//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: calm
/* A Traffic Light Controller program in C */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for generating random delays

#define RED 1
#define YELLOW 2
#define GREEN 3

void delay(int seconds)
{
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main()
{
    int state = RED;  // start with red light on
    int count = 0;
    printf("Traffic Light Controller\n\n");

    while (1)
    {
        if (state == RED)
        {
            printf("Red light on for 10 seconds\n");
            delay(10);
            state = GREEN;  // switch to green light
        }
        else if (state == YELLOW)
        {
            printf("Yellow light on for 3 seconds\n");
            delay(3);
            state = RED;  // switch to red light
        }
        else if (state == GREEN)
        {
            printf("Green light on for 20 seconds\n");
            delay(20);
            state = YELLOW;  // switch to yellow light
        }

        count++;  // increment cycle count

        // display cycle count and current light state
        printf("\nCycle %d: ", count);
        if (state == RED)
            printf("RED\n");
        else if (state == YELLOW)
            printf("YELLOW\n");
        else if (state == GREEN)
            printf("GREEN\n");

        // add some randomness to delay between cycles
        int random_delay = rand() % 10 + 1;  // random delay between 1 and 10 seconds
        printf("Delaying next cycle for %d seconds...\n", random_delay);
        delay(random_delay);
    }

    return 0;
}