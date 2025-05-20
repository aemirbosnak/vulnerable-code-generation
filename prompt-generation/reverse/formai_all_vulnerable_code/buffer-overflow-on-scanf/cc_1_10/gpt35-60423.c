//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    bool isGreen = false;
    bool isYellow = false;
    bool isRed = true;
    char input;

    printf("Welcome to the Traffic Light Controller!\n");

    while (true)
    {
        printf("Enter 'g' to turn on the green light,\n");
        printf("'y' to turn on the yellow light,\n");
        printf("'r' to turn on the red light,\n");
        printf("'q' to quit the program.\n");
        printf(">> ");

        scanf(" %c", &input);

        switch (input)
        {
            case 'g':
                if (isGreen)
                {
                    printf("The green light is already on!\n");
                }
                else
                {
                    printf("Turning on the green light...\n");
                    isGreen = true;
                    isYellow = false;
                    isRed = false;
                }
                break;
            case 'y':
                if (isYellow)
                {
                    printf("The yellow light is already on!\n");
                }
                else
                {
                    printf("Turning on the yellow light...\n");
                    isGreen = false;
                    isYellow = true;
                    isRed = false;
                }
                break;
            case 'r':
                if (isRed)
                {
                    printf("The red light is already on!\n");
                }
                else
                {
                    printf("Turning on the red light...\n");
                    isGreen = false;
                    isYellow = false;
                    isRed = true;
                }
                break;
            case 'q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input! Please try again.\n");
                break;
        }

        // Simulating traffic flow
        int delayTime = rand() % 7 + 3; // Random delay between 3 and 9 seconds
        printf("Simulating traffic flow for %d seconds...\n", delayTime);
        for (int i = delayTime; i > 0; i--)
        {
            printf("Time left: %d seconds\n", i);
            sleep(1); // Sleeping for 1 second
        }
        printf("\n");
    }

    return 0;
}