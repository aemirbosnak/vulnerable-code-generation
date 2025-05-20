//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include<stdio.h>
#include<string.h>

//Function to calculate calories based on workout type
int calculateCalories(char workoutType[20], int duration){
    int calories;
    if(strcmp(workoutType, "Running") == 0){
        calories = 10 * duration; // 10 calories burned per minute of running
    } else if(strcmp(workoutType, "Cycling") == 0){
        calories = 8 * duration; // 8 calories burned per minute of cycling
    } else if(strcmp(workoutType, "Swimming") == 0){
        calories = 12 * duration; // 12 calories burned per minute of swimming
    } else if(strcmp(workoutType, "Strength") == 0){
        calories = 5 * duration; // 5 calories burned per minute of strength training
    } else{
        printf("Invalid workout type.");
        calories = 0;
    }
    return calories;
}

//Main function to track fitness
int main(){
    char name[20];
    int age, weight, height;
    char workoutType[20];
    int duration, caloriesBurned;

    printf("Hello there! Welcome to your fitness tracker.\n");
    printf("Let's start by getting some basic information about you.\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("What is your age?\n");
    scanf("%d", &age);
    printf("What is your weight in kilograms?\n");
    scanf("%d", &weight);
    printf("What is your height in centimeters?\n");
    scanf("%d", &height);

    printf("\nGreat! Now let's get started with your workout.\n");
    printf("What type of workout did you do today?\n");
    scanf("%s", workoutType);
    printf("How long did you work out for (in minutes)?\n");
    scanf("%d", &duration);

    caloriesBurned = calculateCalories(workoutType, duration);

    printf("\nThank you for using your fitness tracker today, %s!\n", name);
    printf("You burned %d calories during your %d minute %s workout.\n", caloriesBurned, duration, workoutType);
    printf("Keep up the good work!");
    
    return 0;
}