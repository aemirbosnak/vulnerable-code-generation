//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

bool isHome = false;

void turnOnLights() {
    printf("Turning on lights\n");
}

void turnOffLights() {
    printf("Turning off lights\n");
}

void openDoor() {
    printf("Opening door\n");
}

void closeDoor() {
    printf("Closing door\n");
}

int main() {
    printf("Welcome to Smart Home Automation\n");
    
    while (true) {
        printf("Enter a command (enter 'help' for options): ");
        char command[20];
        scanf("%s", command);
        
        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("'lights on' - turn on the lights\n");
            printf("'lights off' - turn off the lights\n");
            printf("'open door' - open the door\n");
            printf("'close door' - close the door\n");
            printf("'status' - check if someone is home\n");
            printf("'exit' - exit the program\n");
        } else if (strcmp(command, "lights on") == 0) {
            if (isHome) {
                turnOnLights();
            } else {
                printf("Cannot turn on lights, no one is home\n");
            }
        } else if (strcmp(command, "lights off") == 0) {
            if (isHome) {
                turnOffLights();
            } else {
                printf("Cannot turn off lights, no one is home\n");
            }
        } else if (strcmp(command, "open door") == 0) {
            openDoor();
            isHome = true;
        } else if (strcmp(command, "close door") == 0) {
            closeDoor();
            isHome = false;
        } else if (strcmp(command, "status") == 0) {
            if (isHome) {
                printf("Someone is home\n");
            } else {
                printf("No one is home\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command, enter 'help' for options\n");
        }
    }
    
    return 0;
}