//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

void delay(int n)
{
    int ms = 1000 * n;
    clock_t start_time = clock();
    while(clock() < start_time + ms);
}

int main()
{
    int state = RED;
    int time_elapsed = 0;
    int previous_state = RED;
    int previous_time_elasped = 0;

    while(1)
    {
        switch(state)
        {
            case RED:
            printf("RED light is ON\n");
            delay(10);
            state = GREEN;
            time_elapsed = 0;
            break;

            case YELLOW:
            printf("YELLOW light is ON\n");
            delay(5);
            state = RED;
            time_elapsed = 0;
            break;

            case GREEN:
            printf("GREEN light is ON\n");
            delay(15);
            state = YELLOW;
            time_elapsed = 0;
            break;
        }

        if(previous_state == state && previous_time_elasped == time_elapsed)
        {
            printf("Traffic light state is stuck at %d\n", state);
            break;
        }

        previous_state = state;
        previous_time_elasped = time_elapsed;
        time_elapsed++;
    }

    return 0;
}