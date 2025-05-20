//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include<stdio.h>

//Function to get user input for daily activity
void get_activity(int* activity)
{
    printf("Enter the number of steps taken today: ");
    scanf("%d", &activity[0]);

    printf("Enter the number of minutes spent on cardio workout: ");
    scanf("%d", &activity[1]);

    printf("Enter the number of minutes spent on strength training: ");
    scanf("%d", &activity[2]);

    printf("Enter the number of minutes spent on yoga or stretching: ");
    scanf("%d", &activity[3]);
}

//Function to calculate total calories burned based on activity
int calculate_calories(int* activity)
{
    int steps = activity[0];
    int cardio_minutes = activity[1];
    int strength_minutes = activity[2];
    int yoga_minutes = activity[3];

    //Calculating calories burned per activity
    int steps_calories = steps * 0.045;
    int cardio_calories = cardio_minutes * 8;
    int strength_calories = strength_minutes * 6;
    int yoga_calories = yoga_minutes * 3;

    //Total calories burned for the day
    int total_calories = steps_calories + cardio_calories + strength_calories + yoga_calories;

    return total_calories;
}

int main()
{
    printf("Welcome to the Fitness Tracker!\n\n");

    int activity[4];
    get_activity(activity);

    //Calculating total calories burned
    int total_calories = calculate_calories(activity);

    printf("\nTotal calories burned today: %d\n", total_calories);

    return 0;
}