//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function prototypes
void turnOnLights();
void turnOffLights();
void changeBrightness();
void displayMenu();

// variables
bool isLightsOn = false;
int brightness = 0;


int main() {

    printf("*** Welcome to Smart Home Light Control ***\n");
    while(true) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                turnOnLights();
                break;
            case 2:
                turnOffLights();
                break;
            case 3:
                changeBrightness();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\nPlease choose an option:\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Change brightness\n");
    printf("4. Exit\n");
}

void turnOnLights() {
    if(isLightsOn) {
        printf("Lights are already on.\n");
    } else {
        isLightsOn = true;
        printf("Lights are now on.\n");
    }
}

void turnOffLights() {
    if(!isLightsOn) {
        printf("Lights are already off.\n");
    } else {
        isLightsOn = false;
        printf("Lights are now off.\n");
    }
}

void changeBrightness() {
    printf("Enter brightness level (0-100): ");
    int newBrightness;
    scanf("%d", &newBrightness);
    
    if(newBrightness < 0 || newBrightness > 100) {
        printf("Invalid brightness level, please enter a value between 0-100.\n");
    } else {
        brightness = newBrightness;
        printf("Brightness level set to %d.\n", brightness);
    }
}