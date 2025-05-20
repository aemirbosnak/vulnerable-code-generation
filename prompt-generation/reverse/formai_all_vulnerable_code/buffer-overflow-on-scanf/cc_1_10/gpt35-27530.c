//FormAI DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0
#define MAX_TEMP 80

bool isDoorOpen = false;
bool isLightOn = false;
int currentTemp = 70;

int main()
{
    while (true)
    {
        printf("Welcome to Smart Home Automation\n\n");
        printf("Menu:\n");
        printf("1. Open/Close Door\n");
        printf("2. Turn Light On/Off\n");
        printf("3. Adjust Temperature\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (!isDoorOpen)
                {
                    printf("Opening door...\n");
                    isDoorOpen = true;
                }
                else
                {
                    printf("Closing door...\n");
                    isDoorOpen = false;
                }
                break;
            case 2:
                if (!isLightOn)
                {
                    printf("Turning light on...\n");
                    isLightOn = true;
                }
                else
                {
                    printf("Turning light off...\n");
                    isLightOn = false;
                }
                break;
            case 3:
                printf("Current temperature: %d\n", currentTemp);
                printf("Enter new temperature: ");
                int newTemp;
                scanf("%d", &newTemp);
                if (newTemp > MAX_TEMP)
                {
                    printf("Temperature too high!\n");
                }
                else
                {
                    currentTemp = newTemp;
                    printf("Temperature set to %d\n", currentTemp);
                }
                break;
            case 4:
                printf("Quitting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    }

    return 0;
}