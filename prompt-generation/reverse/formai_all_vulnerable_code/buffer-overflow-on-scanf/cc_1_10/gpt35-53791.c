//FormAI DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_LIGHTS 4

// Function to turn on the given light
void turnOnLight(int light_num, bool* lights_state) {
    if (!lights_state[light_num]) {
        lights_state[light_num] = true;
        printf("Turning on light %d\n", light_num);
    }
}

// Function to turn off the given light
void turnOffLight(int light_num, bool* lights_state) {
    if (lights_state[light_num]) {
        lights_state[light_num] = false;
        printf("Turning off light %d\n", light_num);
    }
}

int main() {
    bool lights_state[NUM_LIGHTS] = {false};

    // Display the available commands
    printf("Enter a command:\n");
    printf("1 - Turn on a light\n");
    printf("2 - Turn off a light\n");
    printf("3 - Quit\n");

    int command;
    int light_num;
    while (command != 3) {
        printf("Enter a command: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                printf("Enter the light number to turn on: ");
                scanf("%d", &light_num);
                if (light_num < 1 || light_num > NUM_LIGHTS) {
                    printf("Invalid light number\n");
                } else {
                    turnOnLight(light_num - 1, lights_state);
                }
                break;
            case 2:
                printf("Enter the light number to turn off: ");
                scanf("%d", &light_num);
                if (light_num < 1 || light_num > NUM_LIGHTS) {
                    printf("Invalid light number\n");
                } else {
                    turnOffLight(light_num - 1, lights_state);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}