//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Traffic Light States
#define RED 0
#define GREEN 1
#define YELLOW 2

// Traffic Light Timings
#define RED_TIME 10
#define GREEN_TIME 15
#define YELLOW_TIME 3

// Function to simulate a 1-second delay
void delay(int seconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main()
{
    int state = RED; // Initial Traffic Light State
    int time_remaining = RED_TIME; // Time left in current state

    printf("##### TRAFFIC LIGHT CONTROLLER #####\n\n");

    while(1)
    {
        // Show the current state of the traffic light
        if(state == RED)
            printf("RED LIGHT\n");
        else if(state == GREEN)
            printf("GREEN LIGHT\n");
        else if(state == YELLOW)
            printf("YELLOW LIGHT\n");

        //Countdown for time remaining in current state
        printf("Time Remaining: %d seconds\n\n", time_remaining);

        // Update the traffic light state and reset timer
        if(state == RED && time_remaining == 0)
        {
            state = GREEN;
            time_remaining = GREEN_TIME;
        }
        else if(state == GREEN && time_remaining == 0)
        {
            state = YELLOW;
            time_remaining = YELLOW_TIME;
        }
        else if(state == YELLOW && time_remaining == 0)
        {
            state = RED;
            time_remaining = RED_TIME;
        }

        // Decrement the time remaining for each second
        delay(1);
        time_remaining--;
    }

    return 0;
}