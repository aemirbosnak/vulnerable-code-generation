//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool isLightsOn = false; //Variable to check whether the lights are on or not
    int brightnessLevel = 0; //Variable to store the brightness level of the lights

    printf("Welcome to Smart Home Light Control\n");

    while(true)
    {
        int option;

        printf("\nPlease select an option:\n");
        printf("1. Turn Lights On\n");
        printf("2. Turn Lights Off\n");
        printf("3. Increase Brightness\n");
        printf("4. Decrease Brightness\n");
        printf("5. Exit\n");

        scanf("%d", &option); //Getting user input

        switch (option)
        {
            case 1:
                if(!isLightsOn) //Checking if lights are already on or not
                {
                    printf("\nTurning Lights On...\n");
                    isLightsOn = true;
                    brightnessLevel = 50; //Setting default brightness level
                    printf("Lights are now ON with brightness level %d%%\n", brightnessLevel);
                }
                else
                {
                    printf("\nLights are already ON\n");
                }
                break;

            case 2:
                if(isLightsOn) //Checking if lights are already off or not
                {
                    printf("\nTurning Lights Off...\n");
                    isLightsOn = false;
                    brightnessLevel = 0; //Resetting brightness level
                    printf("Lights are now OFF\n");
                }
                else
                {
                    printf("\nLights are already OFF\n");
                }
                break;

            case 3:
                if(isLightsOn && brightnessLevel<100) //Increasing brightness level if lights are on and limit not reached
                {
                    printf("\nIncreasing Brightness...\n");
                    brightnessLevel += 10;
                    printf("Brightness level increased to %d%%\n", brightnessLevel);
                }
                else if(!isLightsOn)
                {
                    printf("\nLights are OFF\n");
                }
                else
                {
                    printf("\nBrightness level cannot be increased further\n");
                }
                break;

            case 4:
                if(isLightsOn && brightnessLevel>10) //Decreasing brightness level if lights are on and limit not reached
                {
                    printf("\nDecreasing Brightness...\n");
                    brightnessLevel -= 10;
                    printf("Brightness level decreased to %d%%\n", brightnessLevel);
                }
                else if(!isLightsOn)
                {
                    printf("\nLights are OFF\n");
                }
                else
                {
                    printf("\nBrightness level cannot be decreased further\n");
                }
                break;

            case 5:
                printf("\nExiting Smart Home Light Control...\n");
                exit(0); //Exiting program
                break;

            default:
                printf("\nInvalid Option. Try Again!\n");
                break;
        }
    }

    return 0;
}