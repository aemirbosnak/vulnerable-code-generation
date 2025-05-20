//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function prototype for calculating daily caloric intake
int calculate_calories(int age, float weight, float height, float activity_level);

// Function prototype for calculating daily water intake
int calculate_water(float weight);

int main() {
    int age;
    float weight, height, caloric_intake, water_intake;
    float activity_level = 1.375; // Sedentary lifestyle

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Please enter your height in centimeters: ");
    scanf("%f", &height);

    caloric_intake = calculate_calories(age, weight, height, activity_level);
    water_intake = calculate_water(weight);

    printf("Based on the information you provided, here are your daily recommendations:\n");
    printf("Caloric Intake: %d calories\n", caloric_intake);
    printf("Water Intake: %d milliliters\n", water_intake * 1000);

    return 0;
}

int calculate_calories(int age, float weight, float height, float activity_level) {
    float basal_metabolic_rate, total_calories;

    basal_metabolic_rate = 88.362 + (13.4 * weight) + (4.8 * height) - (5.7 * age);
    total_calories = basal_metabolic_rate * activity_level;

    return (int) total_calories;
}

int calculate_water(float weight) {
    float water_needs;

    water_needs = (weight * 0.03) * 3300;

    return (int) water_needs;
}