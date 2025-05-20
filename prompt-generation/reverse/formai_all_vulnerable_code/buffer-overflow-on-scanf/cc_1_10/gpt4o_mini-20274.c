//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

void displayLights(TrafficLightState state) {
    printf("\nTraffic Light State: ");
    switch (state) {
        case RED:
            printf("Red\n");
            break;
        case GREEN:
            printf("Green\n");
            break;
        case YELLOW:
            printf("Yellow\n");
            break;
    }
    fflush(stdout);
}

void operateTrafficLight() {
    TrafficLightState currentState = GREEN;

    while(1) {
        // Green Light
        currentState = GREEN;
        displayLights(currentState);
        sleep(5); // Green light for 5 seconds

        // Yellow Light
        currentState = YELLOW;
        displayLights(currentState);
        sleep(2); // Yellow light for 2 seconds

        // Red Light
        currentState = RED;
        displayLights(currentState);
        sleep(5); // Red light for 5 seconds
        printf("\n-----\n");
    }
}

int main() {
    char command[10];

    printf("Traffic Light Controller\n");
    printf("Commands: start, stop, reset, exit\n");

    while(1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "start") == 0) {
            printf("Traffic light started!\n");
            operateTrafficLight();
        } else if (strcmp(command, "stop") == 0) {
            printf("Traffic light stopped!\n");
            break; // Stop the operation
        } else if (strcmp(command, "reset") == 0) {
            printf("Traffic light reset!\n");
            // In this simple example, we just display an additional message
            // Reset logic can be expanded as required.
            continue;
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}