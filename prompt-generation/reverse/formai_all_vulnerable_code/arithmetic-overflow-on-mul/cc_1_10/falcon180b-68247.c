//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CYCLE_TIME 1000 // Time in milliseconds for one cycle
#define RED_LIGHT 1
#define GREEN_LIGHT 2
#define YELLOW_LIGHT 3

// Function to print the current state of the traffic light
void print_state(int state) {
    switch (state) {
        case RED_LIGHT:
            printf("Red light\n");
            break;
        case GREEN_LIGHT:
            printf("Green light\n");
            break;
        case YELLOW_LIGHT:
            printf("Yellow light\n");
            break;
        default:
            printf("Invalid state\n");
            break;
    }
}

// Function to change the state of the traffic light
void change_state(int *state) {
    int next_state;

    if (*state == RED_LIGHT) {
        next_state = GREEN_LIGHT;
    } else if (*state == GREEN_LIGHT) {
        next_state = YELLOW_LIGHT;
    } else if (*state == YELLOW_LIGHT) {
        next_state = RED_LIGHT;
    } else {
        next_state = RED_LIGHT;
    }

    *state = next_state;
}

// Function to simulate the traffic light
void traffic_light(int duration) {
    int state = RED_LIGHT;
    int elapsed_time = 0;

    while (elapsed_time < duration) {
        printf("Current state: ");
        print_state(state);
        printf("Elapsed time: %d ms\n", elapsed_time);

        change_state(&state);

        elapsed_time += CYCLE_TIME;
        usleep(CYCLE_TIME * 1000); // Sleep for one cycle
    }
}

int main() {
    int duration;

    printf("Enter the duration of the simulation in seconds: ");
    scanf("%d", &duration);

    traffic_light(duration * 1000); // Convert seconds to milliseconds

    return 0;
}