//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PEDESTRIAN_RED 4
#define PEDESTRIAN_GREEN 5

// Define the duration of each light in seconds
#define LIGHT_DURATION 10
#define PEDESTRIAN_LIGHT_DURATION 20

// Define the number of lights
#define NUM_LIGHTS 4

int main() {
    int light_state[NUM_LIGHTS];
    int pedestrian_light_state = PEDESTRIAN_RED;
    int current_light = 0;
    int num_pedestrians = 0;
    int light_duration_countdown = LIGHT_DURATION;
    int pedestrian_light_duration_countdown = PEDESTRIAN_LIGHT_DURATION;

    // Initialize the lights to red
    for (int i = 0; i < NUM_LIGHTS; i++) {
        light_state[i] = RED;
    }

    // Loop until the user decides to quit
    while (1) {
        // Print the current state of the lights
        printf("Current light state:\n");
        for (int i = 0; i < NUM_LIGHTS; i++) {
            switch (light_state[i]) {
                case RED:
                    printf("Light %d is red\n", i + 1);
                    break;
                case YELLOW:
                    printf("Light %d is yellow\n", i + 1);
                    break;
                case GREEN:
                    printf("Light %d is green\n", i + 1);
                    break;
            }
        }

        // Check for pedestrians
        if (num_pedestrians > 0 && pedestrian_light_state == PEDESTRIAN_RED) {
            printf("Pedestrians are waiting to cross\n");
        }

        // Update the light states
        for (int i = 0; i < NUM_LIGHTS; i++) {
            if (light_state[i] == RED) {
                light_state[i] = GREEN;
            } else if (light_state[i] == GREEN) {
                light_state[i] = YELLOW;
            } else if (light_state[i] == YELLOW) {
                light_state[i] = RED;
            }
        }

        current_light++;
        if (current_light >= NUM_LIGHTS) {
            current_light = 0;
        }

        light_duration_countdown--;
        if (light_duration_countdown == 0) {
            light_duration_countdown = LIGHT_DURATION;
        }

        pedestrian_light_duration_countdown--;
        if (pedestrian_light_duration_countdown == 0) {
            pedestrian_light_duration_countdown = PEDESTRIAN_LIGHT_DURATION;
            pedestrian_light_state = (pedestrian_light_state == PEDESTRIAN_RED)? PEDESTRIAN_GREEN : PEDESTRIAN_RED;
        }

        // Check for user input to quit
        char input;
        scanf("%c", &input);
        if (input == 'q') {
            break;
        }
    }

    return 0;
}