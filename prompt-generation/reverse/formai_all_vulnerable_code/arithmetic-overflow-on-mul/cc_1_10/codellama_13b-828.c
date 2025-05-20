//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
// C Fitness Tracker Example Program

#include <stdio.h>
#include <stdlib.h>

// Structure to store user data
struct user_data {
    int age;
    int height;
    int weight;
    int gender;
};

// Function to calculate BMI
float calculate_bmi(struct user_data data) {
    return (data.weight / (data.height * data.height)) * 703;
}

// Function to calculate daily calorie intake
int calculate_daily_calorie_intake(struct user_data data, float bmi) {
    if (data.gender == 0) { // male
        return 1.2 * data.weight + 6.25 * data.height - 5 * data.age + 5;
    } else { // female
        return 1.2 * data.weight + 6.25 * data.height - 5 * data.age - 161;
    }
}

// Function to calculate daily physical activity
int calculate_daily_physical_activity(struct user_data data) {
    if (data.age < 18) {
        return 1.2;
    } else if (data.age < 25) {
        return 1.375;
    } else if (data.age < 30) {
        return 1.55;
    } else if (data.age < 35) {
        return 1.725;
    } else if (data.age < 40) {
        return 1.9;
    } else if (data.age < 45) {
        return 2.075;
    } else if (data.age < 50) {
        return 2.25;
    } else if (data.age < 55) {
        return 2.425;
    } else if (data.age < 60) {
        return 2.6;
    } else {
        return 2.775;
    }
}

// Function to calculate total daily calorie intake
int calculate_total_daily_calorie_intake(struct user_data data, float bmi, int physical_activity) {
    return (int) (calculate_daily_calorie_intake(data, bmi) * physical_activity);
}

// Function to calculate weekly progress
void calculate_weekly_progress(struct user_data data, float bmi, int physical_activity, int total_calorie_intake) {
    printf("Weekly progress:\n");
    printf("BMI: %.2f\n", bmi);
    printf("Daily calorie intake: %d\n", total_calorie_intake);
    printf("Daily physical activity: %d\n", physical_activity);
    printf("Total calorie intake: %d\n", total_calorie_intake);
}

int main() {
    // Get user data
    struct user_data data;
    printf("Enter your age: ");
    scanf("%d", &data.age);
    printf("Enter your height (in inches): ");
    scanf("%d", &data.height);
    printf("Enter your weight (in pounds): ");
    scanf("%d", &data.weight);
    printf("Enter your gender (0 for male, 1 for female): ");
    scanf("%d", &data.gender);

    // Calculate BMI
    float bmi = calculate_bmi(data);

    // Calculate daily calorie intake
    int daily_calorie_intake = calculate_daily_calorie_intake(data, bmi);

    // Calculate daily physical activity
    int daily_physical_activity = calculate_daily_physical_activity(data);

    // Calculate total daily calorie intake
    int total_calorie_intake = calculate_total_daily_calorie_intake(data, bmi, daily_physical_activity);

    // Calculate weekly progress
    calculate_weekly_progress(data, bmi, daily_physical_activity, total_calorie_intake);

    return 0;
}