//FormAI DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NUM_LIGHTS 10

// Initialize an array of bools to represent the lights state
bool lights[NUM_LIGHTS] = {false};

// Function to print the current state of all the lights
void printLights() {
    printf("Current light state:\n");
    for(int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d: %s\n", i+1, lights[i] ? "On" : "Off");
    }
    printf("\n");
}

// Function to toggle the state of a specific light
void toggleLight(int lightNum) {
    lights[lightNum-1] = !lights[lightNum-1];
    printf("Toggled light %d. New state: %s\n", lightNum, lights[lightNum-1] ? "On" : "Off");
}

int main() {
    // Display welcome message and instructions
    printf("Welcome to smart home light control!\n");
    printf("Enter \"help\" for a list of commands.\n\n");

    char command[100];
    bool running = true;

    // Loop to get user input and execute commands
    while(running) {
        printf("Enter command: ");
        scanf("%s", command);
        
        if(strcmp(command, "help") == 0) {
            printf("Commands:\n");
            printf("toggle <light number>\n");
            printf("all-on\n");
            printf("all-off\n");
            printf("exit\n\n");
        }
        else if(strcmp(command, "toggle") == 0) {
            int lightNum;
            scanf("%d", &lightNum);
            if(lightNum < 1 || lightNum > NUM_LIGHTS) {
                printf("Invalid light number. Choose a number between 1 and %d.\n", NUM_LIGHTS);
            }
            else {
                toggleLight(lightNum);
            }
        }
        else if(strcmp(command, "all-on") == 0) {
            for(int i = 0; i < NUM_LIGHTS; i++) {
                lights[i] = true;
            }
            printf("Turned all lights on.\n");
        }
        else if(strcmp(command, "all-off") == 0) {
            for(int i = 0; i < NUM_LIGHTS; i++) {
                lights[i] = false;
            }
            printf("Turned all lights off.\n");
        }
        else if(strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            running = false;
        }
        else {
            printf("Invalid command. Enter \"help\" for a list of commands.\n");
        }

        printLights();
    }

    return 0;
}