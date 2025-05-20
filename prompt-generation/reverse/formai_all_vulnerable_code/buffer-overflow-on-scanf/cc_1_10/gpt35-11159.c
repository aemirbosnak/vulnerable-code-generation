//FormAI DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variable declaration
int isWindowOpen = 0;
int isLightOn = 0;
int isACOn = 0;

// Function to open/close window
void toggleWindow() {
    if(isWindowOpen == 0) {
        printf("Window is opening...\n");
        isWindowOpen = 1;
    } else {
        printf("Window is closing...\n");
        isWindowOpen = 0;
    }
}

// Function to turn on/off light
void toggleLight() {
    if(isLightOn == 0) {
        printf("Light is turning on...\n");
        isLightOn = 1;
    } else {
        printf("Light is turning off...\n");
        isLightOn = 0;
    }
}

// Function to turn on/off AC
void toggleAC() {
    if(isACOn == 0) {
        printf("AC is turning on...\n");
        isACOn = 1;
    } else {
        printf("AC is turning off...\n");
        isACOn = 0;
    }
}

int main() {
    char command[20];
    int roomTemp;
    
    // Setting up random seed for room temperature
    srand(time(NULL));
    roomTemp = rand() % 10 + 20; // Generating random temperature between 20 to 30 degrees
    
    printf("Welcome to Smart Home Automation!\n");
    printf("Room temperature currently is %d degrees Celsius.\n", roomTemp);
    
    while(1) {
        printf("Please enter a command (window/light/AC or exit): ");
        scanf("%s", command);
        
        if(strcmp(command, "window") == 0) {
            toggleWindow();
        } else if(strcmp(command, "light") == 0) {
            toggleLight();
        } else if(strcmp(command, "AC") == 0) {
            toggleAC();
        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting from Smart Home Automation...\n");
            break;
        } else {
            printf("Invalid command! Please try again...\n");
        }
    }
    
    return 0;
}