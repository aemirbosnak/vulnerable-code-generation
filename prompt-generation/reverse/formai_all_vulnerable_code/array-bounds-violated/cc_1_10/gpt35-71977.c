//FormAI DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to turn on/off the lights based on the user's input.
void controlLight(char command[]) {
    if (strcmp(command,"turn on lights") == 0) {
        printf("Turning on lights...\n");
    } else if (strcmp(command,"turn off lights") == 0) {
        printf("Turning off lights...\n");
    } else {
        printf("Invalid input, please try again.\n");
    }
}

// Function to adjust the thermostat temperature based on the user's input.
void controlTemperature(char command[]) {
    if (strcmp(command,"increase temperature") == 0) {
        printf("Increasing temperature...\n");
    } else if (strcmp(command,"decrease temperature") == 0) {
        printf("Decreasing temperature...\n");
    } else {
        printf("Invalid input, please try again.\n");
    }
}

// Function to lock/unlock the front door based on the user's input.
void controlFrontDoor(char command[]) {
    if (strcmp(command,"lock front door") == 0) {
        printf("Locking front door...\n");
    } else if (strcmp(command,"unlock front door") == 0) {
        printf("Unlocking front door...\n");
    } else {
        printf("Invalid input, please try again.\n");
    }
}

// Main function to simulate a smart home automation system.
int main() {
    char input[50];

    printf("Welcome to Smart Home Automation!\n");

    while (1) {
        printf("\nPlease enter a command:\n");
        fgets(input, 50, stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input,"exit") == 0) {
            break;
        } else if (strstr(input,"lights") != NULL) {
            controlLight(input);
        } else if (strstr(input,"temperature") != NULL) {
            controlTemperature(input);
        } else if (strstr(input,"front door") != NULL) {
            controlFrontDoor(input);
        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    printf("Goodbye!\n");

    return 0;
}