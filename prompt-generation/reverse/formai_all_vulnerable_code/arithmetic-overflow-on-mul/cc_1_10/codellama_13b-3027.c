//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: retro
/*
 * C Fitness Tracker
 * A retro-style fitness tracker program
 */

#include <stdio.h>
#include <stdlib.h>

// Define the struct for the fitness data
struct fitness_data {
    int age;
    float height;
    float weight;
    int daily_steps;
};

// Define the function to calculate the BMI
float calculate_bmi(struct fitness_data *data) {
    return (data->weight / (data->height * data->height)) * 10000;
}

// Define the function to calculate the daily calorie burn
float calculate_daily_calories(struct fitness_data *data) {
    // Calculate the basal metabolic rate (BMR)
    float bmr = data->weight * 24;

    // Calculate the daily calorie burn
    float daily_calories = bmr + (data->daily_steps * 10);

    return daily_calories;
}

// Define the function to print the fitness data
void print_fitness_data(struct fitness_data *data) {
    printf("Fitness Data:\n");
    printf("Age: %d\n", data->age);
    printf("Height: %.2f\n", data->height);
    printf("Weight: %.2f\n", data->weight);
    printf("Daily Steps: %d\n", data->daily_steps);
    printf("BMI: %.2f\n", calculate_bmi(data));
    printf("Daily Calories: %.2f\n", calculate_daily_calories(data));
}

// Define the function to update the fitness data
void update_fitness_data(struct fitness_data *data) {
    // Ask the user for the updated data
    printf("Enter the updated age: ");
    scanf("%d", &data->age);

    printf("Enter the updated height: ");
    scanf("%f", &data->height);

    printf("Enter the updated weight: ");
    scanf("%f", &data->weight);

    printf("Enter the updated daily steps: ");
    scanf("%d", &data->daily_steps);
}

// Define the main function
int main() {
    // Create a struct to hold the fitness data
    struct fitness_data data = {
        25,
        175,
        70,
        10000
    };

    // Print the initial fitness data
    print_fitness_data(&data);

    // Update the fitness data
    update_fitness_data(&data);

    // Print the updated fitness data
    print_fitness_data(&data);

    return 0;
}