//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int weight;
    int stepCount = 0;
    int heartRate;

    srand(time(NULL));
    heartRate = rand() % 80 + 100;

    printf("Welcome to your Cyberpunk Fitness Tracker!\n");
    printf("Please enter your weight in pounds: ");
    scanf("%d", &weight);

    printf("Press 'Enter' to begin tracking your steps.\n");

    while (getchar() != '\n'); //flush standard input

    while (1)
    {
        printf("Press 'Enter' after each step.\n");

        getchar(); // Wait for Enter key press
        stepCount++;

        if (stepCount % 100 == 0)
        {
            heartRate += rand() % 10 - 5; // simulate a change in heart rate
            printf("Your heart rate is now %d bpm.\n", heartRate);
        }

        printf("You have taken %d steps.\n", stepCount);

        // Calculate calories burned
        int caloriesBurned = ((float) weight / 2.2) * 0.57 * stepCount / 1000;
        printf("You have burned %d calories.\n\n", caloriesBurned);

        // Check if user wants to quit
        printf("Would you like to quit? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y')
        {
            break;
        }

        while (getchar() != '\n'); //flush standard input
    }

    printf("\nThank you for using your Cyberpunk Fitness Tracker.\n");
    return 0;
}