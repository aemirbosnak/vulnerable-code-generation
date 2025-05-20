//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

bool isLightOn = false;

void cyber_punk_display()
{
    printf("╔══════════════════════════════════════════╗\n");
    printf("║     _ _______  _____          __   _      ║\n");
    printf("║    (_)___ ___|/ ___/   _____ / /_ (_)____ ║\n");
    printf("║   / / __ `__ \\\\__ \\   / ___// __// // __ \\\║\n");
    printf("║  / / / / / / /__/ /  (__  )/ /_ / // /_/ /║\n");
    printf("║ /_/_/ /_/ /_/____/  /____/ \\__//_/ \\____/ ║\n");
    printf("╚══════════════════════════════════════════╝\n");
}

void printInstructions()
{
    printf("Available commands:\n");
    printf("1. Turn light on\n");
    printf("2. Turn light off\n");
    printf("3. Exit\n");
}

void toggleLight()
{
    if(isLightOn) {
        printf("Turning light off...\n");
        isLightOn = false;
    } else {
        printf("Turning light on...\n");
        isLightOn = true;
    }
}

int main()
{
    int choice;

    cyber_punk_display();

    while (true)
    {
        printInstructions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if(!isLightOn) {
                    printf("Light is already off\n");
                } else {
                    toggleLight();
                }
                break;

            case 2:
                if(isLightOn) {
                    printf("Light is already on\n");
                } else {
                    toggleLight();
                }
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again\n");
        }
    }
    return 0;
}