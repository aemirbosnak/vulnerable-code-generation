//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define NSEC_PER_SEC 1000000000L

void traffic_light_controller(int duration_sec)
{
    int current_light = RED_LIGHT;
    int light_duration_ns = duration_sec * NSEC_PER_SEC;
    int wait_ns = light_duration_ns / 3;

    printf("Traffic light controller started with duration %d seconds\n", duration_sec);

    while (light_duration_ns > 0)
    {
        switch (current_light)
        {
            case RED_LIGHT:
                printf("Red light on\n");
                fflush(stdout);
                break;
            case YELLOW_LIGHT:
                printf("Yellow light on\n");
                fflush(stdout);
                break;
            case GREEN_LIGHT:
                printf("Green light on\n");
                fflush(stdout);
                break;
        }

        nanosleep(&(struct timespec){0, wait_ns}, NULL);

        light_duration_ns -= wait_ns;

        switch (current_light)
        {
            case RED_LIGHT:
                current_light = YELLOW_LIGHT;
                break;
            case YELLOW_LIGHT:
                current_light = GREEN_LIGHT;
                break;
            case GREEN_LIGHT:
                current_light = RED_LIGHT;
                break;
        }
    }

    printf("Traffic light controller stopped\n");
}

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <duration_sec>\n", argv[0]);
        return 1;
    }

    int duration_sec = atoi(argv[1]);

    if (duration_sec <= 0)
    {
        printf("Invalid duration\n");
        return 1;
    }

    traffic_light_controller(duration_sec);

    return 0;
}