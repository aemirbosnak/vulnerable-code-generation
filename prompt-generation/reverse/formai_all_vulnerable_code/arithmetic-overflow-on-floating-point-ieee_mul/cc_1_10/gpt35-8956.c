//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{

    printf("######################\n");
    printf("#  C Fitness Tracker  #\n");
    printf("######################\n\n");

    printf("Welcome to the C Fitness Tracker!\n");

    int age, weight, caloriesBurned, minutesWorkout;
    float height, BMI;

    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("\nPlease enter your weight(in kg): ");
    scanf("%d", &weight);
    printf("\nPlease enter your height(in meters): ");
    scanf("%f", &height);

    BMI = weight / (height * height);

    if(BMI < 18.5)
    {
        printf("You are underweight\n");
    }

    else if(BMI >= 18.5 && BMI <= 24.9)
    {
        printf("You have a normal weight\n");
    }

    else if(BMI >= 25 && BMI <= 29.9)
    {
        printf("You are overweight\n");
    }

    else if(BMI >= 30)
    {
        printf("You are obese\n");
    }

    printf("\nSherlock: Mr.X, let's focus on your fitness regime. How many minutes did you workout today?\n");
    scanf("%d", &minutesWorkout);
    printf("\nSherlock: And how many calories do you think you burned during the workout session?\n");
    scanf("%d", &caloriesBurned);

    srand(time(0)); //to generate random numbers
    int goalCalories = rand()%600 + 300;

    printf("\nSherlock: Based on your age, weight, height, and workout routine, you should burn approximately %d calories per day.\n", goalCalories);

    if(caloriesBurned > goalCalories)
    {
        printf("\nSherlock: Well done, Mr.X! Your hard work is paying off!\n");
    }

    else
    {
        printf("\nSherlock: Hmm, it looks like you have some more work to do in order to meet your daily calorie-burning goal.\n");
    }

    return 0;
}