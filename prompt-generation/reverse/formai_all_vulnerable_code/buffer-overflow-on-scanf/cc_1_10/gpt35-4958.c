//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

//Function to turn on the light
void turnOnLight(bool *lightState) {
    *lightState = true;
    printf("Light is now on.\n");
}

//Function to turn off the light
void turnOffLight(bool *lightState) {
    *lightState = false;
    printf("Light is now off.\n");
}

//Function to toggle the light
void toggleLight(bool *lightState) {
    if(*lightState) {
        turnOffLight(lightState);
    } else {
        turnOnLight(lightState);
    }
}

int main()
{
    bool lightState = false; //initialize the light state to false, meaning the light is initially off
    int choice;

    while(true) {
        printf("What would you like to do?\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Toggle the light\n");
        scanf("%d", &choice); //get user input for what they want to do

        switch(choice) {
            case 1:
                turnOnLight(&lightState); //call the turnOnLight function
                break;
            case 2:
                turnOffLight(&lightState); //call the turnOffLight function
                break;
            case 3:
                toggleLight(&lightState); //call the toggleLight function
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}