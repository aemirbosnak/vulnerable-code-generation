//FormAI DATASET v1.0 Category: Smart home light control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on/off light
void toggleLight(int* lightStatus) {
    *lightStatus = (*lightStatus == 0) ? 1 : 0;
}

// Function to set brightness level of light
void setBrightness(int* brightnessLevel, int newLevel) {
    *brightnessLevel = newLevel;
}

// Function to print light status
void printLightStatus(int lightStatus, int brightnessLevel) {
    printf("Light is currently %s and brightness level is %d\n",
           lightStatus == 1 ? "ON" : "OFF", brightnessLevel);
}

int main() {
    int lightStatus = 0; // 0 is off, 1 is on
    int brightnessLevel = 50; // default brightness level is 50
    
    // Print current status of light
    printLightStatus(lightStatus, brightnessLevel);
    
    // Let user interact with the light
    bool exitProgram = false;
    do {
        printf("\nWhat would you like to do?\n");
        printf("\t1. Turn light on/off (Press 1)\n");
        printf("\t2. Set brightness level (Press 2)\n");
        printf("\t3. Exit program (Press 3)\n");
        
        // Get user's choice
        int userChoice;
        scanf("%d", &userChoice);
        
        switch (userChoice) {
            case 1: // Toggle light
                toggleLight(&lightStatus);
                printLightStatus(lightStatus, brightnessLevel);
                break;
            case 2: // Set brightness level
                printf("Enter new brightness level (0-100): ");
                int newLevel;
                scanf("%d", &newLevel);
                if (newLevel < 0 || newLevel > 100) {
                    printf("Error: Invalid brightness level!\n");
                } else {
                    setBrightness(&brightnessLevel, newLevel);
                    printLightStatus(lightStatus, brightnessLevel);
                }
                break;
            case 3: // Exit program
                printf("Exiting program...\n");
                exitProgram = true;
                break;
            default:
                printf("Error: Invalid input!\n");
        }
    } while (!exitProgram);
    
    return 0;
}