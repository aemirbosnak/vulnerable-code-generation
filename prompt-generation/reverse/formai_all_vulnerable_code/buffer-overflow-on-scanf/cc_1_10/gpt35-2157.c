//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// function to control the lights in the room
void controlLights(bool isOn)
{
    if(isOn)
    {
        printf("Lights are on.\n");
    }
    else
    {
        printf("Lights are off.\n");
    }
}

// function to control the brightness of the lights
void controlBrightness(int brightness)
{
    printf("Brightness level is %d.\n", brightness);
}

// function to control the color of the lights
void controlColor(int color)
{
    printf("Color is %d.\n", color);
}

// main function to run the program
int main()
{
    int choice = 1, brightness = 0, color = 0;
    bool isOn = false;

    // loop to continuously display options until user chooses to exit
    while(choice != 0)
    {
        printf("Choose an option:\n");
        printf("1. Turn lights on/off\n");
        printf("2. Control brightness\n");
        printf("3. Control color\n");
        printf("0. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // toggle the lights on/off
                isOn = !isOn;
                controlLights(isOn);
                break;
            case 2:
                // control brightness of the lights
                printf("Enter brightness value (0-100): ");
                scanf("%d", &brightness);
                controlBrightness(brightness);
                break;
            case 3:
                // control color of the lights
                printf("Enter color value (1-5): ");
                scanf("%d", &color);
                controlColor(color);
                break;
            case 0:
                // exit the program
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}