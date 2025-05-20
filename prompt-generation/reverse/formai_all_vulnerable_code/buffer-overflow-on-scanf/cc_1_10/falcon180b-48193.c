//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 7

void traffic_light_controller(int duration_red, int duration_yellow, int duration_green) {
    int current_light = RED_LIGHT;
    int time_left = duration_red;

    printf("Starting traffic light controller...\n");

    while (time_left > 0) {
        switch (current_light) {
            case RED_LIGHT:
                printf("Red light is on.\n");
                break;
            case YELLOW_LIGHT:
                printf("Yellow light is on.\n");
                break;
            case GREEN_LIGHT:
                printf("Green light is on.\n");
                break;
        }

        time_left--;

        if (time_left == 0) {
            current_light = (current_light + 1) % 3;
            time_left = duration_red;
        }
    }

    printf("Traffic light controller finished.\n");
}

int main() {
    int duration_red, duration_yellow, duration_green;

    printf("Welcome to the happy traffic light controller!\n");
    printf("Please enter the duration (in seconds) for each light:\n");
    printf("Red light: ");
    scanf("%d", &duration_red);
    printf("Yellow light: ");
    scanf("%d", &duration_yellow);
    printf("Green light: ");
    scanf("%d", &duration_green);

    traffic_light_controller(duration_red, duration_yellow, duration_green);

    return 0;
}