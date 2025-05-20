//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to turn on/off lights
void turnLights(char status[]) {
    if(strcmp(status, "on") == 0) {
        printf("Lights turned on.\n");
    } else if(strcmp(status, "off") == 0) {
        printf("Lights turned off.\n");
    } else {
        printf("Invalid status specified.\n");
    }
}

// function to adjust temperature
void adjustTemperature(int temperature) {
    printf("Temperature set to %d degrees Celsius.\n", temperature);
}

// function to lock/unlock doors
void lockDoors(char status[]) {
    if(strcmp(status, "lock") == 0) {
        printf("Doors locked.\n");
    } else if(strcmp(status, "unlock") == 0) {
        printf("Doors unlocked.\n");
    } else {
        printf("Invalid status specified.\n");
    }
}

int main() {
    // welcome message
    printf("Welcome to Smart Home Automation system.\n");
    
    // initialize commands
    char command[30];
    int temperature;
    
    while(1) {
        printf("\nPlease enter your command: ");
        scanf("%s", command);
        
        // check command and execute appropriate function
        if(strcmp(command, "light") == 0) {
            char status[10];
            printf("Turn lights on or off? ");
            scanf("%s", status);
            turnLights(status);
        } else if(strcmp(command, "temperature") == 0) {
            printf("Set temperature to: ");
            scanf("%d", &temperature);
            adjustTemperature(temperature);
        } else if(strcmp(command, "door") == 0) {
            char status[10];
            printf("Lock or unlock doors? ");
            scanf("%s", status);
            lockDoors(status);
        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Automation system.\n");
            break;
        } else {
            printf("Unknown command.\n");
        }
    }
    
    return 0;
}