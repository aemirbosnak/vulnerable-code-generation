//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants for the various devices
#define LIGHT 0
#define FAN 1
#define AC 2
#define DOOR 3

// Define states for the various devices
#define OFF 0
#define ON 1
#define OPEN 2
#define CLOSED 3

int main() {
    int lightState = OFF;
    int fanState = OFF;
    int acState = OFF;
    int doorState = CLOSED;

    // Set up the random number generator for the temperature
    srand(time(NULL));

    // Loop infinitely until user chooses to exit
    while (true) {
        printf("Choose an option:\n");
        printf("[1] Turn the light %s\n", (lightState == OFF) ? "on" : "off");
        printf("[2] Turn the fan %s\n", (fanState == OFF) ? "on" : "off");
        printf("[3] Turn the AC %s\n", (acState == OFF) ? "on" : "off");
        printf("[4] %s the door\n", (doorState == CLOSED) ? "Open" : "Close");
        printf("[5] Check the temperature\n");
        printf("[6] Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lightState = (lightState == OFF) ? ON : OFF;
                printf("The light is now %s.\n", (lightState == OFF) ? "off" : "on");
                break;
            case 2:
                fanState = (fanState == OFF) ? ON : OFF;
                printf("The fan is now %s.\n", (fanState == OFF) ? "off" : "on");
                break;
            case 3:
                acState = (acState == OFF) ? ON : OFF;
                printf("The AC is now %s.\n", (acState == OFF) ? "off" : "on");
                break;
            case 4:
                doorState = (doorState == CLOSED) ? OPEN : CLOSED;
                printf("The door is now %s.\n", (doorState == CLOSED) ? "closed" : "open");
                break;
            case 5:
                printf("The temperature is %d degrees Celsius.\n", (rand() % 20) + 10);
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}