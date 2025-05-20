//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to set the temperature
void setTemperature(int temperature) {
    printf("Temperature set to %d degrees Celsius.\n", temperature);
}

// Function to turn on the lights
void turnOnLights() {
    printf("Lights turned on.\n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("Lights turned off.\n");
}

// Function to lock the door
void lockDoor() {
    printf("Door locked.\n");
}

// Function to unlock the door
void unlockDoor() {
    printf("Door unlocked.\n");
}

int main() {
    // Initial temperature
    int temperature = 20;

    // Initial lights state
    int lights = 0;

    // Initial door state
    int door = 0;

    while(1) {
        printf("Enter a command (set temperature, turn on lights, turn off lights, lock door, unlock door, quit): ");
        char command[20];
        scanf("%s", command);

        if(strcmp(command, "set") == 0) {
            printf("Enter a temperature: ");
            scanf("%d", &temperature);
            setTemperature(temperature);
        } else if(strcmp(command, "on") == 0) {
            turnOnLights();
            lights = 1;
        } else if(strcmp(command, "off") == 0) {
            turnOffLights();
            lights = 0;
        } else if(strcmp(command, "lock") == 0) {
            lockDoor();
            door = 1;
        } else if(strcmp(command, "unlock") == 0) {
            unlockDoor();
            door = 0;
        } else if(strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}