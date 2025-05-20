//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int calBurnt = 0; // initialize the burnt calories as 0
    int userChoice;

    srand(time(0));  // set the seed for randomizing the calorie burn

    printf("Welcome to C Fitness Tracker!\n");

    // start a loop to keep prompting the user with options
    while(1)
    {
        printf("\nChoose an option:\n");
        printf("1) Log a workout\n");
        printf("2) View total calories burnt\n");
        printf("3) Exit\n");

        scanf("%d", &userChoice);

        if(userChoice == 1)
        {
            // generate a random value between 50 and 500 to represent calorie burn
            int burn = rand() % 451 + 50; 

            // add the generated value to the total calories burnt
            calBurnt += burn; 

            printf("\nCalories burnt: %d\n", burn);
            printf("Workout logged successfully!\n");
        }
        else if(userChoice == 2)
        {
            printf("\nTotal calories burnt: %d\n", calBurnt);
        }
        else if(userChoice == 3)
        {
            printf("\nThank you for using C Fitness Tracker!\n");
            break; // exit the loop
        }
        else
        {
            printf("\nInvalid choice! Please choose again.\n");
        }
    }

    return 0;
}