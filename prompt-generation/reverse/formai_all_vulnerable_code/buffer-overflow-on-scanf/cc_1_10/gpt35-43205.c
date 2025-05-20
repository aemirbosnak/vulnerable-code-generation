//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int redTime, yellowTime, greenTime, currentTime;
    char choice;

    printf("*****Welcome to Traffic Light Controller*****\n\n");

    do
    {
        printf("Enter the time for red light in seconds: ");
        scanf("%d", &redTime);

        printf("Enter the time for yellow light in seconds: ");
        scanf("%d", &yellowTime);

        printf("Enter the time for green light in seconds: ");
        scanf("%d", &greenTime);

        printf("\nTraffic Light Program started...\n");

        while (1)
        {
            printf("\n===RED LIGHT===\n");

            for (currentTime = redTime; currentTime >= 0; currentTime--)
            {
                printf("%d\n", currentTime);
                sleep(1);
            }

            printf("\n===YELLOW LIGHT===\n");

            for (currentTime = yellowTime; currentTime >= 0; currentTime--)
            {
                printf("%d\n", currentTime);
                sleep(1);
            }

            printf("\n===GREEN LIGHT===\n");

            for (currentTime = greenTime; currentTime >= 0; currentTime--)
            {
                printf("%d\n", currentTime);
                sleep(1);
            }
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\nExiting program...\n");

    return 0;
}