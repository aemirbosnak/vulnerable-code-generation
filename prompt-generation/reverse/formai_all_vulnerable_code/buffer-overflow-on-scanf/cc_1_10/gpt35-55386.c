//FormAI DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>

int main()
{
    int lightsOn = 0; // variable to keep track of lights being on or off
    int brightness = 0; // variable to adjust brightness level

    printf("Welcome to Retro Smart Home Light Control System\n");
    printf("Enter 1 to turn on lights or 0 to turn them off: ");

    scanf("%d", &lightsOn); // taking input from user

    if (lightsOn == 1)
    {
        printf("Great! Lights are now turned on.\n");
        printf("Enter brightness level (0-10): ");

        scanf("%d", &brightness);

        if (brightness >= 0 && brightness <= 10)
        {
            printf("Brightness level set to %d\n", brightness);
        }
        else
        {
            printf("Invalid brightness level. Setting to default (5).\n");
            brightness = 5;
        }

        printf("Press 1 to increase brightness and 0 to decrease brightness: ");
        int choice = 0;

        while (1)
        {
            scanf("%d", &choice);

            if (choice == 1)
            {
                if (brightness < 10)
                {
                    brightness++;
                    printf("Brightness level increased to %d\n", brightness);
                }
                else
                {
                    printf("Maximum brightness level reached.\n");
                }
            }
            else if (choice == 0)
            {
                if (brightness > 0)
                {
                    brightness--;
                    printf("Brightness level decreased to %d\n", brightness);
                }
                else
                {
                    printf("Minimum brightness level reached.\n");
                }
            }
            else
            {
                printf("Invalid choice. Please press 1 or 0.\n");
            }
        }
    }
    else if (lightsOn == 0)
    {
        printf("Okay! Lights are now turned off.\n");
    }
    else
    {
        printf("Invalid input. Please enter either 1 or 0.\n");
    }

    return 0;
}