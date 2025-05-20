//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return (weight / (height * height));
}

int main() {
    float weight, height, bmi;
    int age, heart_rate, goal;
    time_t current_time;
    char* c_time_string;

    // Get user data
    printf("Enter your weight in kg: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your resting heart rate: ");
    scanf("%d", &heart_rate);
    printf("Enter your fitness goal (1 for weight loss, 2 for muscle gain, 3 for maintenance): ");
    scanf("%d", &goal);

    // Calculate BMI
    bmi = calculateBMI(weight, height);

    // Get current time
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    // Determine daily calories and macronutrient requirements based on user goal
    int calories, protein, carbs, fat;
    if (goal == 1) {
        calories = 0.8 * (24 * weight) + 200;
        protein = 1.5 * weight;
        carbs = 2 * weight;
        fat = 0.2 * (calories / 9);
    } else if (goal == 2) {
        calories = 17.5 * weight + 400;
        protein = 1.2 * weight;
        carbs = 2.5 * weight;
        fat = 0.3 * (calories / 9);
    } else {
        calories = 15 * weight + 400;
        protein = 1.0 * weight;
        carbs = 2.0 * weight;
        fat = 0.25 * (calories / 9);
    }

    // Print user data and recommendations
    printf("\n--- Your Fitness Tracker ---\n");
    printf("Date and Time: %s\n", c_time_string);
    printf("Weight: %.2f kg\n", weight);
    printf("Height: %.2f meters\n", height);
    printf("BMI: %.2f\n", bmi);
    printf("Age: %d\n", age);
    printf("Resting Heart Rate: %d\n", heart_rate);
    printf("Fitness Goal: ");
    switch (goal) {
        case 1:
            printf("Weight Loss\n");
            break;
        case 2:
            printf("Muscle Gain\n");
            break;
        case 3:
            printf("Maintenance\n");
            break;
        default:
            printf("Not Set\n");
            break;
    }
    printf("Calories per day: %d\n", calories);
    printf("Protein per day: %d g\n", protein);
    printf("Carbs per day: %d g\n", carbs);
    printf("Fat per day: %d g\n", fat);

    return 0;
}