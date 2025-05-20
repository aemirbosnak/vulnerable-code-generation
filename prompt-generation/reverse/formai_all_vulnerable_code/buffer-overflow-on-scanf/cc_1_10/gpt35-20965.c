//FormAI DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void turnOnLights(int lights[]) {
    for (int i = 0; i < 5; i++) {
        lights[i] = 1; // Set light state to on
    }
    printf("All lights are turned on!\n");
}

void turnOffLights(int lights[]) {
    for (int i = 0; i < 5; i++) {
        lights[i] = 0; // Set light state to off
    }
    printf("All lights are turned off!\n");
}

int main() {
    int lights[5] = {0, 0, 0, 0, 0}; // Represents the state of each light (0 - off, 1 - on)
    int input, timeNow;

    printf("Welcome to the smart home light control system!\n\n");
    printf("Enter 1 to turn on the lights\n");
    printf("Enter 2 to turn off the lights\n");
    printf("Enter 3 to check the current time\n\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                turnOnLights(lights);
                break;
            case 2:
                turnOffLights(lights);
                break;
            case 3:
                timeNow = time(NULL);
                printf("Current time: %s", asctime(localtime(&timeNow)));
                break;
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    }

    return 0;
}