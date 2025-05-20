//FormAI DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int lightStatus = 0;
    int userChoice = 0;

    printf("Welcome to Smart Home Light Control\n");
    printf("Please select an option:\n");
    printf("1. Turn on the light\n");
    printf("2. Turn off the light\n");
    printf("3. Toggle the light\n");
    printf("4. Exit\n");

    while (true)
    {
        scanf("%d", &userChoice);

        if (userChoice == 1)
        {
            if (lightStatus == 1)
            {
                printf("Light is already on.\n");
            }
            else
            {
                lightStatus = 1;
                printf("Light turned on.\n");
            }
        }
        else if (userChoice == 2)
        {
            if (lightStatus == 0)
            {
                printf("Light is already off.\n");
            }
            else
            {
                lightStatus = 0;
                printf("Light turned off.\n");
            }
        }
        else if (userChoice == 3)
        {
            if (lightStatus == 1)
            {
                lightStatus = 0;
                printf("Light toggled off.\n");
            }
            else
            {
                lightStatus = 1;
                printf("Light toggled on.\n");
            }
        }
        else if (userChoice == 4)
        {
            printf("Exiting Smart Home Light Control.\n");
            break;
        }
        else
        {
            printf("Invalid option selected. Please try again.\n");
        }

        printf("Please select an option:\n");
        printf("1. Turn on the light\n");
        printf("2. Turn off the light\n");
        printf("3. Toggle the light\n");
        printf("4. Exit\n");
    }

    return 0;
}