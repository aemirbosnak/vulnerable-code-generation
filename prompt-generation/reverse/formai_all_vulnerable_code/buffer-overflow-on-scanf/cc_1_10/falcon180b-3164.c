//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time intervals for each light
#define RED_LIGHT_TIME 10
#define YELLOW_LIGHT_TIME 5
#define GREEN_LIGHT_TIME 15

// Define the light colors
#define RED 1
#define YELLOW 2
#define GREEN 3

// Function to display the current light color
void display_light(int light) {
    switch (light) {
        case RED:
            printf("The light is red.\n");
            break;
        case YELLOW:
            printf("The light is yellow.\n");
            break;
        case GREEN:
            printf("The light is green.\n");
            break;
    }
}

// Function to change the light color
void change_light(int *current_light) {
    int next_light;

    if (*current_light == RED) {
        next_light = YELLOW;
    } else if (*current_light == YELLOW) {
        next_light = GREEN;
    } else if (*current_light == GREEN) {
        next_light = RED;
    } else {
        printf("Invalid light color.\n");
        exit(1);
    }

    *current_light = next_light;
}

// Function to control the traffic lights
void traffic_lights(int duration) {
    int current_light = RED;

    printf("The traffic lights are starting...\n");

    while (duration > 0) {
        display_light(current_light);
        sleep(1);

        if (duration > RED_LIGHT_TIME) {
            change_light(&current_light);
        }

        duration--;
    }

    printf("The traffic lights are ending...\n");
}

int main() {
    int duration;

    printf("Welcome to the traffic light controller!\n");
    printf("Please enter the duration of the traffic lights in seconds: ");
    scanf("%d", &duration);

    printf("The traffic lights are starting...\n");
    traffic_lights(duration);

    printf("The traffic lights are ending...\n");

    return 0;
}