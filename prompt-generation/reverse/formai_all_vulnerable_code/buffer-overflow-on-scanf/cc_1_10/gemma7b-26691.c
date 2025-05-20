//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the Temple of Fitness.\n");

    int steps_taken = 0;
    char username[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Greetings, %s! Prepare to embark on your fitness journey.\n", username);

    while (1)
    {
        printf("Choose your destiny:\n");
        printf("1. Treadmill Trail\n");
        printf("2. Stairway Ascent\n");
        printf("3. Plank Power\n");
        printf("Enter your choice: ");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                steps_taken += 200;
                printf("You've taken 200 steps on the treadmill! Keep going, %s!\n", username);
                break;
            case 2:
                steps_taken += 150;
                printf("You've climbed 150 stairs, %s! You're a mountain climber!\n", username);
                break;
            case 3:
                steps_taken += 100;
                printf("You've held a plank for 100 seconds, %s! You're a master of endurance!\n", username);
                break;
            default:
                printf("Invalid choice, %s. Please try again.\n", username);
                break;
        }

        printf("Your total number of steps taken is: %d\n", steps_taken);
        printf("Thank you for visiting the Temple of Fitness, %s. Come back soon!\n", username);

        if (steps_taken >= 1000)
        {
            printf("Congratulations, %s! You've reached the goal of 1000 steps! You're a fitness legend!\n", username);
            break;
        }
    }

    return 0;
}