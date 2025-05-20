//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>

int main()
{
    printf("Welcome to our Smart Home Light Control System!\n\n");

    int lights = 0; // Number of lights in the house
    printf("How many lights do you want to control? ");
    scanf("%d", &lights);

    int lightStatus[lights]; // An array to hold the status of each light
    for (int i = 0; i < lights; i++)
    {
        lightStatus[i] = 0; // Initialize all lights to be off
    }

    printf("\n");

    int option = 0; // The option chosen by the user
    while (option != 3)
    {
        printf("Select an option:\n");
        printf("1. Turn a light on\n");
        printf("2. Turn a light off\n");
        printf("3. Exit\n\n");

        scanf("%d", &option);

        if (option == 1)
        {
            int lightNum = 0; // The light number chosen by the user
            printf("Which light do you want to turn on? ");
            scanf("%d", &lightNum);

            if (lightNum > 0 && lightNum <= lights)
            {
                lightStatus[lightNum - 1] = 1; // Turn on the selected light
                printf("Light %d turned on.\n\n", lightNum);
            }
            else
            {
                printf("Invalid light number.\n\n");
            }
        }
        else if (option == 2)
        {
            int lightNum = 0; // The light number chosen by the user
            printf("Which light do you want to turn off? ");
            scanf("%d", &lightNum);

            if (lightNum > 0 && lightNum <= lights)
            {
                lightStatus[lightNum - 1] = 0; // Turn off the selected light
                printf("Light %d turned off.\n\n", lightNum);
            }
            else
            {
                printf("Invalid light number.\n\n");
            }
        }
        else if (option == 3)
        {
            printf("Exiting Smart Home Light Control System...\n");
            break;
        }
        else
        {
            printf("Invalid option.\n\n");
        }
    }

    return 0;
}