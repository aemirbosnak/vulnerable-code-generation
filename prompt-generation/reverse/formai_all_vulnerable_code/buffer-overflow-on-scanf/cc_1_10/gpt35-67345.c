//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>

//This program is called MyFitnessTracker, an example program for tracking exercise and diet

int main()
{
    printf("Welcome to MyFitnessTracker!\n");
    
    //Setting up variables for tracking data
    int calories_goal = 2000;
    int calories_consumed = 0;
    int calories_burned = 0;
    int calories_remaining = 0;
    float weight = 150.0; //In pounds
    
    //Logging data for the day
    printf("Enter the number of calories you consumed today: ");
    scanf("%d", &calories_consumed);
    
    printf("Enter the number of calories you burned during exercise: ");
    scanf("%d", &calories_burned);
    
    //Calculating remaining calories and weight loss
    calories_remaining = calories_goal - calories_consumed + calories_burned;
    float weight_loss = calories_remaining / 3500.0; //3500 calories burned = 1 pound lost
    
    //Displaying results
    printf("\n-----------------------\n");
    printf("Today's Results\n");
    printf("-----------------------\n");
    printf("Calories consumed: %d\n", calories_consumed);
    printf("Calories burned: %d\n", calories_burned);
    printf("Calories remaining: %d\n", calories_remaining);
    printf("Approximate weight loss: %.2f pounds\n", weight_loss);
    
    //Prompting for next steps
    printf("-----------------------\n");
    printf("What would you like to do next?\n");
    printf("1. Log another day\n");
    printf("2. Update weight\n");
    printf("3. Exit program\n");
    
    //Handling user selection
    int selection = 0;
    scanf("%d", &selection);
    
    switch(selection)
    {
        case 1:
            printf("Logging another day...\n");
            //TODO: Code for logging another day
            break;
        case 2:
            printf("Updating weight...\n");
            printf("Enter your weight in pounds: ");
            scanf("%f", &weight);
            printf("Weight updated!\n");
            break;
        case 3:
            printf("Exiting program... Goodbye!");
            return 0;
        default:
            printf("Invalid selection. Exiting program... Goodbye!");
            return 0;
    }
    
    return 0;
}