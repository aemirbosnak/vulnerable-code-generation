//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int steps = 0, calories = 0, distance = 0;
    float heart_rate = 0.0, sleep = 0.0;
    char exercise[20], goal[50], answer;

    printf("Welcome to Shape Shifter Fitness Tracker!\n\n");

    printf("Enter your exercise for the day: ");
    scanf("%s", exercise);

    printf("How many steps did you take today? ");
    scanf("%d", &steps);

    calories = steps * 0.04; // assume 1 step burns 0.04 calories
    distance = steps / 1320; // assume 1320 steps equal 1 km

    printf("Enter your heart rate for the day: ");
    scanf("%f", &heart_rate);

    printf("How many hours did you sleep last night? ");
    scanf("%f", &sleep);

    srand(time(NULL)); // for random motivation quotes

    printf("\nGreat job on your workout today!\n\n");

    switch (rand() % 5)
    {
        case 0:
            printf("You're a star! Keep up the good work!\n");
            break;
        case 1:
            printf("You're doing amazing! Stay motivated!\n");
            break;
        case 2:
            printf("Your commitment is inspiring! Don't give up!\n");
            break;
        case 3:
            printf("You're making progress! Keep pushing yourself!\n");
            break;
        case 4:
            printf("You're killing it! Keep up the awesome work!\n");
            break;
    }

    printf("\nWould you like to set a fitness goal for yourself? (y/n) ");
    scanf(" %c", &answer);

    if (answer == 'y' || answer == 'Y')
    {
        printf("\nWhat is your fitness goal? ");
        scanf(" %[^\n]s", goal);

        printf("Okay, your goal is to %s. Let's do this!\n\n", goal);
    }
    else
    {
        printf("\nOkay, we will check in later to set a goal. Keep pushing yourself!\n\n");
    }

    printf("Here are your fitness stats for today:\n\n");
    printf("Exercise: %s\n", exercise);
    printf("Steps taken: %d\n", steps);
    printf("Calories burned: %d\n", calories);
    printf("Distance traveled: %d km\n", distance);
    printf("Heart rate: %.1f bpm\n", heart_rate);
    printf("Sleep: %.1f hours\n\n", sleep);

    return 0;
}