//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int age;
    float height, weight, bmi, target_weight;
    char gender, activity_level;
    time_t current_time;
    struct tm *local_time;

    // Get user inputs
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);
    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Please enter your activity level (sedentary/moderate/active): ");
    scanf(" %c", &activity_level);

    // Calculate BMI
    bmi = weight / (height * height);
    printf("Your BMI is: %.2f\n", bmi);

    // Calculate target weight
    if (bmi < 18.5) {
        target_weight = 18.5 * height * height;
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        target_weight = weight;
    } else {
        target_weight = 24.9 * height * height;
    }

    // Print out target weight and recommended daily calorie intake based on activity level
    printf("Your target weight is: %.2fkg.\n", target_weight);
    switch(activity_level){
        case 's':
            printf("Based on your activity level, your recommended daily calorie intake is: %d calories.\n", (int)(target_weight * 25));
            break;
        case 'm':
            printf("Based on your activity level, your recommended daily calorie intake is: %d calories.\n", (int)(target_weight * 30));
            break;
        case 'a':
            printf("Based on your activity level, your recommended daily calorie intake is: %d calories.\n", (int)(target_weight * 35));
            break;
        default:
            printf("Invalid activity level.");
            exit(0);
    }

    // Record current time to track progress
    current_time = time(NULL);
    local_time = localtime(&current_time);
    printf("---------------------------\n");
    printf("Today's date: %d/%d/%d\n", local_time->tm_mon + 1, local_time->tm_mday, local_time->tm_year + 1900);
    printf("Starting weight: %.2fkg\n", weight);

    // Simulate 7 days of progress tracking
    for (int i = 0; i < 7; i++) {
        int random_weight_change = (int)(((double)rand() / RAND_MAX) * 1.5 - 0.75); // Random weight change between -0.75kg to +0.75kg
        weight += random_weight_change;
        printf("---------------------------\n");
        printf("Date: %d/%d/%d\n", local_time->tm_mon + 1, local_time->tm_mday + i + 1, local_time->tm_year + 1900);
        printf("Current weight: %.2fkg\n", weight);
        if (weight < target_weight) {
            printf("You need to gain %.2fkg to reach your target weight.\n", target_weight - weight);
        } else {
            printf("You have reached your target weight!\n");
        }
    }

    printf("---------------------------\n");
    printf("Thank you for using the Fitness Tracker! Good luck with your fitness journey!\n");

    return 0;
}