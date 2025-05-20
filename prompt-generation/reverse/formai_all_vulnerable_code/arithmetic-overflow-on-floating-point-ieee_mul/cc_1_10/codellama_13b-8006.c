//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: grateful
// C Fitness Tracker Example Program
#include <stdio.h>
#include <stdlib.h>

// Structure to hold fitness tracker data
struct fitness_data {
    int age;
    float weight;
    float height;
    float bmi;
    float steps;
    float distance;
    float calories;
};

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate daily calories
float calculate_calories(int age, float weight, float height, float steps, float distance) {
    return weight * 24 * 60 * 60 / 7000 + steps * 100 + distance * 60 * 60 / 1609;
}

// Function to display fitness tracker data
void display_data(struct fitness_data data) {
    printf("Age: %d\n", data.age);
    printf("Weight: %.2f kg\n", data.weight);
    printf("Height: %.2f m\n", data.height);
    printf("BMI: %.2f\n", data.bmi);
    printf("Steps: %d\n", data.steps);
    printf("Distance: %.2f km\n", data.distance);
    printf("Calories: %.2f\n", data.calories);
}

int main() {
    struct fitness_data data;

    // Ask for user input
    printf("Enter your age: ");
    scanf("%d", &data.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &data.weight);
    printf("Enter your height (in m): ");
    scanf("%f", &data.height);
    printf("Enter your daily steps: ");
    scanf("%f", &data.steps);
    printf("Enter your daily distance (in km): ");
    scanf("%f", &data.distance);

    // Calculate BMI and daily calories
    data.bmi = calculate_bmi(data.weight, data.height);
    data.calories = calculate_calories(data.age, data.weight, data.height, data.steps, data.distance);

    // Display fitness tracker data
    display_data(data);

    return 0;
}