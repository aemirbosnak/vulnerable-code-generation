//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome message
    printf("Welcome to Retro Fitness Tracker!\n\n");

    // Set random seed
    srand(time(0));

    // Declare variables
    float weight = 0.0, height = 0.0;
    int age = 0, target_durations[3] = {0};
    const float jogging_speed = 5.0, cycling_speed = 8.0, weight_lifting_speed = 3.0;
    const float jogging_calories = 10.0, cycling_calories = 15.0, weight_lifting_calories = 5.0;
    float total_calories = 0.0, total_time = 0.0;

    // Get user information
    printf("Enter your weight (in kgs): ");
    scanf("%f", &weight);
    printf("Enter your height (in meters): ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%d", &age);

    // Calculate BMI
    float bmi = weight / (height * height);

    // Display user information
    printf("\nYour BMI is: %.2f\n", bmi);
    printf("Your target durations for today: \n\n");

    // Generate target durations for each exercise
    for (int i = 0; i < 3; i++) {
        target_durations[i] = rand() % 30 + 10;
        switch (i) {
            case 0:
                printf("- Jogging: %d minutes\n", target_durations[i]);
                break;
            case 1:
                printf("- Cycling: %d minutes\n", target_durations[i]);
                break;
            case 2:
                printf("- Weight Lifting: %d minutes\n", target_durations[i]);
                break;
        }
    }

    // Start tracking workout
    printf("\nStart your workout!\n");

    while (total_time < 90.0) {
        int choice = 0;
        printf("\nChoose an exercise: \n");
        printf("1. Jogging\n");
        printf("2. Cycling\n");
        printf("3. Weight Lifting\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        float speed = 0.0, duration = 0.0, calories_per_minute = 0.0;
        switch (choice) {
            case 1:
                speed = jogging_speed;
                calories_per_minute = jogging_calories;
                break;
            case 2:
                speed = cycling_speed;
                calories_per_minute = cycling_calories;
                break;
            case 3:
                speed = weight_lifting_speed;
                calories_per_minute = weight_lifting_calories;
                break;
            default:
                printf("Invalid option!\n");
                continue;
        }

        printf("Enter duration (in minutes): ");
        scanf("%f", &duration);

        total_calories += calories_per_minute * duration;
        total_time += duration;

        printf("Total time: %.2f / 90 minutes\n", total_time);
        printf("Calories burnt: %.2f / %.2f calories\n", total_calories, target_durations[0] * jogging_calories + target_durations[1] * cycling_calories + target_durations[2] * weight_lifting_calories);

        if (total_time >= 90.0) {
            printf("\nGood job on completing your workout!\n");
            float recommended_calories = (66 + (13.7 * weight) + (5 * height * 100) - (6.8 * age)) * 1.5;
            printf("Recommended daily calorie intake for you: %.2f calories\n", recommended_calories);
            break;
        }
    }

    return 0;
}