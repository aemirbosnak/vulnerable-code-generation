//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to toggle the light on and off
void toggleLight() {
    printf("Light toggled!\n");
}

// Function to turn off the light
void turnOffLight() {
    printf("Light turned off!\n");
}

// Function to turn on the light
void turnOnLight() {
    printf("Light turned on!\n");
}

// Function to set the brightness of the light
void setLightBrightness(int brightness) {
    printf("Light brightness set to %d!\n", brightness);
}

// Function to get the current brightness of the light
int getLightBrightness() {
    return 5;
}

// Function to set the color of the light
void setLightColor(char* color) {
    printf("Light color set to %s!\n", color);
}

// Function to get the current color of the light
char* getLightColor() {
    return "white";
}

// Function to handle user input
void handleInput(char* input) {
    char* command = strtok(input, " ");
    if (strcmp(command, "toggle") == 0) {
        toggleLight();
    } else if (strcmp(command, "on") == 0) {
        turnOnLight();
    } else if (strcmp(command, "off") == 0) {
        turnOffLight();
    } else if (strcmp(command, "brightness") == 0) {
        char* brightnessString = strtok(NULL, " ");
        int brightness = atoi(brightnessString);
        setLightBrightness(brightness);
    } else if (strcmp(command, "color") == 0) {
        char* color = strtok(NULL, " ");
        setLightColor(color);
    } else {
        printf("Invalid command!\n");
    }
}

// Main function
int main() {
    char input[100];
    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);
        handleInput(input);
    }
    return 0;
}