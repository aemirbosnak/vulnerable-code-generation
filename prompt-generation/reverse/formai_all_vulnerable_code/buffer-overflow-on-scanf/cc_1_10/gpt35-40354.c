//FormAI DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdbool.h>

// Declare Boolean Variables
bool isLightOn = false;
bool isFanOn = false;
bool isTVOn = false;

// Function to turn on the Lights
void turnOnLights()
{
    isLightOn = true;
    printf("Lights turned on!\n");
}

// Function to turn off the Lights
void turnOffLights()
{
    isLightOn = false;
    printf("Lights turned off!\n");
}

// Function to turn on the Fan
void turnOnFan()
{
    isFanOn = true;
    printf("Fan turned on!\n");
}

// Function to turn off the Fan
void turnOffFan()
{
    isFanOn = false;
    printf("Fan turned off!\n");
}

// Function to turn on the TV
void turnOnTV()
{
    isTVOn = true;
    printf("TV turned on!\n");
}

// Function to turn off the TV
void turnOffTV()
{
    isTVOn = false;
    printf("TV turned off!\n");
}

int main()
{
    int userInput;

    // Welcome Message
    printf("Welcome to Smart Home Automation!\n");

    // Main Menu
    printf("Press 1 to Turn on Lights.\n");
    printf("Press 2 to Turn off Lights.\n");
    printf("Press 3 to Turn on Fan.\n");
    printf("Press 4 to Turn off Fan.\n");
    printf("Press 5 to Turn on TV.\n");
    printf("Press 6 to Turn off TV.\n");
    printf("Press 0 to Quit.\n");

    // User Input
    while (true)
    {
        printf("Enter your choice: ");
        scanf("%d", &userInput);

        // Input Validation
        if (userInput < 0 || userInput > 6)
        {
            printf("Invalid input! Try Again\n");
            continue;
        }

        switch (userInput)
        {
            // Case to Turn on the Lights
            case 1:
                if (!isLightOn)
                {
                    turnOnLights();
                }
                else
                {
                    printf("Lights already turned on!\n");
                }
                break;

            // Case to Turn off the Lights
            case 2:
                if (isLightOn)
                {
                    turnOffLights();
                }
                else
                {
                    printf("Lights already turned off!\n");
                }
                break;

            // Case to Turn on the Fan
            case 3:
                if (!isFanOn)
                {
                    turnOnFan();
                }
                else
                {
                    printf("Fan already turned on!\n");
                }
                break;

            // Case to Turn off the Fan
            case 4:
                if (isFanOn)
                {
                    turnOffFan();
                }
                else
                {
                    printf("Fan already turned off!\n");
                }
                break;

            // Case to Turn on the TV
            case 5:
                if (!isTVOn)
                {
                    turnOnTV();
                }
                else
                {
                    printf("TV already turned on!\n");
                }
                break;

            // Case to Turn off the TV
            case 6:
                if (isTVOn)
                {
                    turnOffTV();
                }
                else
                {
                    printf("TV already turned off!\n");
                }
                break;

            // Case to Quit
            case 0:
                printf("Thank you for using Smart Home Automation!");
                return 0;
        }
    }
    return 0;
}