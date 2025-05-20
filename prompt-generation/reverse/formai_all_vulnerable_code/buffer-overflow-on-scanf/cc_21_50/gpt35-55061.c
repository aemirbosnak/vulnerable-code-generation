//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Medieval drone remote control program

    printf("Welcome to the Medieval Drone Remote Control Program!\n");

    // Initialize random seed for the random actions
    srand(time(NULL));

    int isFlying = 0;
    int batteryLevel = 100;

    while (batteryLevel > 0)
    {
        printf("\nWhat would you like to do? (Enter the corresponding number)\n");
        printf("1. Take off\n");
        printf("2. Land\n");
        printf("3. Move forward\n");
        printf("4. Move backward\n");
        printf("5. Rotate left\n");
        printf("6. Rotate right\n");
        printf("7. Attack\n");
        printf("8. Defend\n");
        printf("9. Check battery level\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (isFlying)
                {
                    printf("The drone is already flying.\n");
                }
                else
                {
                    printf("The drone takes off!\n");
                    isFlying = 1;
                }
                break;

            case 2:
                if (!isFlying)
                {
                    printf("The drone is already on the ground.\n");
                }
                else
                {
                    printf("The drone lands safely.\n");
                    isFlying = 0;
                }
                break;

            case 3:
                if (!isFlying)
                {
                    printf("The drone must be in the air to move.\n");
                }
                else
                {
                    printf("The drone moves forward.\n");
                }
                break;

            case 4:
                if (!isFlying)
                {
                    printf("The drone must be in the air to move.\n");
                }
                else
                {
                    printf("The drone moves backward.\n");
                }
                break;

            case 5:
                if (!isFlying)
                {
                    printf("The drone must be in the air to rotate.\n");
                }
                else
                {
                    printf("The drone rotates left.\n");
                }
                break;

            case 6:
                if (!isFlying)
                {
                    printf("The drone must be in the air to rotate.\n");
                }
                else
                {
                    printf("The drone rotates right.\n");
                }
                break;

            case 7:
                if (!isFlying)
                {
                    printf("The drone must be in the air to attack.\n");
                }
                else
                {
                    printf("The drone attacks with its fiery breath!\n");
                }
                break;

            case 8:
                if (!isFlying)
                {
                    printf("The drone must be in the air to defend.\n");
                }
                else
                {
                    printf("The drone shields itself with its strong dragon scales!\n");
                }
                break;

            case 9:
                printf("The battery level is %d percent.\n", batteryLevel);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Randomly drain the battery
        int randNum = rand() % 10;
        if (randNum % 2 == 0)
        {
            batteryLevel -= 10;
        }

        if (batteryLevel <= 0)
        {
            printf("\nThe battery has run out! The drone crash-lands and is no more.\n");
        }
    }

    return 0;
}