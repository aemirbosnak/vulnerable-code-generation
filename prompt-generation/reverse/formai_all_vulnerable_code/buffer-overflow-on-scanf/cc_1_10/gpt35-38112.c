//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

// define the function to turn the light on
void turnOnLight() {
    printf("The light is now turned on.\n");
}

// define the function to turn the light off
void turnOffLight() {
    printf("The light is now turned off.\n");
}

int main() {
    //initialize a boolean variable to keep track of the light status
    bool isLightOn = false;
    
    // print instructions for the user
    printf("Welcome to the Smart Home Light Control.\n");
    printf("Enter '1' to turn the light on.\n");
    printf("Enter '0' to turn the light off.\n");
    printf("Enter '2' to exit the program.\n");

    // create an infinite loop, user must input 2 to exit
    while (true) {
        int userChoice;
        scanf("%d", &userChoice);
        if (userChoice == 1) {
            if (!isLightOn) {
                isLightOn = true;
                turnOnLight();
            } else {
                printf("The light is already on.\n");
            }
        } else if (userChoice == 0) {
            if (isLightOn) {
                isLightOn = false;
                turnOffLight();
            } else {
                printf("The light is already off.\n");
            }
        } else if (userChoice == 2) {
            printf("Program is exiting.\n");
            break;
        } else {
            printf("Invalid input. Please enter 1, 0, or 2.\n");
        }
    }
    return 0;
}