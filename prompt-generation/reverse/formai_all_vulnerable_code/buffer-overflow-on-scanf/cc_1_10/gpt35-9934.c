//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Hardware setup
    bool isLightsOn = false;
    bool isACOn = false;
    bool isFanOn = false;
    bool isSecurityOn = false;

    // User input
    char choice;
    printf("\nWelcome to the Smart Home Automation System. Please enter your choice:\n");
    printf("1. Turn Lights On/Off\n");
    printf("2. Turn AC On/Off\n");
    printf("3. Turn Fan On/Off\n");
    printf("4. Turn Security On/Off\n");
    scanf("%c", &choice);

    // Process user input
    switch (choice)
    {
        case '1':
            if (isLightsOn)
            {
                printf("Turning off the lights.\n");
                isLightsOn = false;
            }
            else
            {
                printf("Turning on the lights.\n");
                isLightsOn = true;
            }
            break;

        case '2':
            if (isACOn)
            {
                printf("Turning off the AC.\n");
                isACOn = false;
            }
            else
            {
                printf("Turning on the AC.\n");
                isACOn = true;
            }
            break;

        case '3':
            if (isFanOn)
            {
                printf("Turning off the fan.\n");
                isFanOn = false;
            }
            else
            {
                printf("Turning on the fan.\n");
                isFanOn = true;
            }
            break;

        case '4':
            if (isSecurityOn)
            {
                printf("Turning off the security system.\n");
                isSecurityOn = false;
            }
            else
            {
                printf("Turning on the security system.\n");
                isSecurityOn = true;
            }
            break;

        default:
            printf("Invalid Choice.\n");
            break;
    }

    return 0;
}