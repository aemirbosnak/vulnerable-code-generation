//FormAI DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void turnOnLights();
void turnOffLights();
void dimLights(int brightness);

// main function
int main()
{
    int choice, brightness;
    printf("Welcome to Smart Home Light Control\n");

    // keep running the program until the user chooses to exit
    while (1)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on the lights\n");
        printf("2. Turn off the lights\n");
        printf("3. Dim the lights\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                turnOnLights();
                break;
            case 2:
                turnOffLights();
                break;
            case 3:
                printf("Enter the brightness level (0-100): ");
                scanf("%d", &brightness);
                dimLights(brightness);
                break;
            case 4:
                printf("Exiting Smart Home Light Control\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to turn on the lights
void turnOnLights()
{
    printf("Lights turned on\n");
}

// Function to turn off the lights
void turnOffLights()
{
    printf("Lights turned off\n");
}

// Function to dim the lights
void dimLights(int brightness)
{
    if (brightness < 0 || brightness > 100)
    {
        printf("Invalid brightness level\n");
    }
    else
    {
        printf("Lights dimmed to %d%%\n", brightness);
    }
}