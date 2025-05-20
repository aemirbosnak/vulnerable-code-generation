//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[20];
    float weight, height;
    int age, goal, calories;
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);
    printf("Enter your height (in cm): ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("\nWelcome %s, let's get started with your fitness tracker!\n\n", username);
    printf("What is your fitness goal?\n1. Lose weight\n2. Gain weight\n3. Maintain weight\nEnter your choice: ");
    scanf("%d", &goal);
    switch(goal) {
        case 1:
            calories = weight * 25;
            printf("You need to consume %d calories to achieve your goal of losing weight.\n", calories);
            break;
        case 2:
            calories = weight * 28;
            printf("You need to consume %d calories to achieve your goal of gaining weight.\n", calories);
            break;
        case 3:
            calories = weight * 24;
            printf("You need to consume %d calories to achieve your goal of maintaining weight.\n", calories);
            break;
        default:
            printf("Invalid choice.\n");
            exit(0);
    }
    printf("\nLet's start tracking your daily progress!\n\n");
    while(1) {
        int choice;
        printf("What would you like to do?\n1. Log meals\n2. Log exercise\n3. View progress\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the details of the meal you had:\n");
                char meal[10];
                float calories_consumed;
                printf("Enter the name of the meal: ");
                scanf("%s", meal);
                printf("Enter the number of calories consumed: ");
                scanf("%f", &calories_consumed);
                calories -= calories_consumed;
                printf("Remaining calories for the day: %d\n", calories);
                break;
            case 2:
                printf("\nEnter the details of the exercise you did:\n");
                char exercise[10];
                float calories_burned;
                printf("Enter the name of the exercise: ");
                scanf("%s", exercise);
                printf("Enter the number of calories burned: ");
                scanf("%f", &calories_burned);
                calories += calories_burned;
                printf("Remaining calories for the day: %d\n", calories);
                break;
            case 3:
                printf("\nYour current progress:\n");
                printf("Weight: %0.2f kg\n", weight);
                printf("Height: %0.2f cm\n", height);
                printf("Age: %d\n", age);
                if(goal == 1) {
                    printf("Goal: Lose weight\n");
                } else if(goal == 2) {
                    printf("Goal: Gain weight\n");
                } else {
                    printf("Goal: Maintain weight\n");
                }
                printf("Calories remaining: %d\n", calories);
                break;
            case 4:
                printf("Thanks for using the fitness tracker!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}