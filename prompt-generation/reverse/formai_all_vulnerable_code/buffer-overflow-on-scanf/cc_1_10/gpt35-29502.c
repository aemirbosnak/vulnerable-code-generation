//FormAI DATASET v1.0 Category: Smart home automation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants
#define LIGHT_OFF 0
#define LIGHT_ON 1

// Function prototypes
void turnLightOn(bool *lightStatus);
void turnLightOff(bool *lightStatus);
void printCurrentLightStatus(bool lightStatus);
void displayMainMenu();

int main()
{
    bool lightStatus = LIGHT_OFF;

    printf("\nWelcome to the Smart Home Automation program!\n");

    while (true) {
        displayMainMenu();

        int userInput;
        printf("\nEnter the operation you want to perform: ");
        scanf("%d", &userInput);

        switch (userInput) {
            case 1:
                turnLightOn(&lightStatus);
                break;
            case 2:
                turnLightOff(&lightStatus);
                break;
            case 3:
                printCurrentLightStatus(lightStatus);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid input. Try again.\n");
                break;
        }

        // Pause the system for 1 second to simulate processing time
        printf("\nProcessing...\n\n");
        sleep(1);
    }

    return 0;
}

void turnLightOn(bool *lightStatus)
{
    if (*lightStatus == LIGHT_ON) {
        printf("\nThe light is already on.\n");
    } else {
        *lightStatus = LIGHT_ON;
        printf("\nThe light is now on.\n");
    }
}

void turnLightOff(bool *lightStatus)
{
    if (*lightStatus == LIGHT_OFF) {
        printf("\nThe light is already off.\n");
    } else {
        *lightStatus = LIGHT_OFF;
        printf("\nThe light is now off.\n");
    }
}

void printCurrentLightStatus(bool lightStatus)
{
    if (lightStatus == LIGHT_ON) {
        printf("\nThe light is currently on.\n");
    } else {
        printf("\nThe light is currently off.\n");
    }
}

void displayMainMenu()
{
    printf("\n*******************\n");
    printf("MAIN MENU\n");
    printf("*******************\n");
    printf("1. Turn the light on\n");
    printf("2. Turn the light off\n");
    printf("3. Check the current status of the light\n");
    printf("4. Exit the program\n");
    printf("\n");
}