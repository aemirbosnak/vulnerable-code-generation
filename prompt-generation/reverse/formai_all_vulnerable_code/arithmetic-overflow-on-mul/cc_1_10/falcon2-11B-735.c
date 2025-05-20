//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Initialize variables
    int num_of_days = 0;
    int num_of_steps = 0;
    int calories_burned = 0;
    int weight_loss = 0;
    int total_calories_consumed = 0;
    int total_calories_burned = 0;
    int total_water_intake = 0;

    // User inputs
    printf("How many days do you want to track? ");
    scanf("%d", &num_of_days);
    printf("How many steps do you want to track per day? ");
    scanf("%d", &num_of_steps);
    printf("How many calories do you want to burn per day? ");
    scanf("%d", &calories_burned);
    printf("How much weight loss do you want to track per day? ");
    scanf("%d", &weight_loss);
    printf("How many calories do you want to consume per day? ");
    scanf("%d", &total_calories_consumed);
    printf("How much water do you want to intake per day? ");
    scanf("%d", &total_water_intake);

    // Calculate daily totals
    for (int i = 0; i < num_of_days; i++) {
        num_of_steps += num_of_steps;
        calories_burned += calories_burned;
        weight_loss += weight_loss;
        total_calories_consumed += total_calories_consumed;
        total_water_intake += total_water_intake;
    }

    // Calculate total values
    total_calories_burned = calories_burned * num_of_days;
    total_water_intake = total_water_intake * num_of_days;
    weight_loss = weight_loss * num_of_days;

    // Print results
    printf("Total number of days: %d\n", num_of_days);
    printf("Total number of steps: %d\n", num_of_steps);
    printf("Total calories burned: %d\n", total_calories_burned);
    printf("Total weight loss: %d\n", weight_loss);
    printf("Total calories consumed: %d\n", total_calories_consumed);
    printf("Total water intake: %d\n", total_water_intake);

    return 0;
}