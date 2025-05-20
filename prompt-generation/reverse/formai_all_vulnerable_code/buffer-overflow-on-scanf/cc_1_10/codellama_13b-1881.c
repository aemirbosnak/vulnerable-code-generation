//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
// Fitness Tracker
#include <stdio.h>
#include <stdlib.h>

// Structure for storing fitness data
struct fitness_data {
    char name[30];
    int age;
    float weight;
    float height;
    float bmi;
    float daily_calories;
    float daily_steps;
    float daily_distance;
};

// Function for calculating BMI
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}

// Function for calculating daily calories
float calculate_daily_calories(float weight, float daily_distance) {
    return weight * 3600 * daily_distance;
}

// Function for calculating daily steps
float calculate_daily_steps(float daily_distance) {
    return daily_distance * 1000;
}

// Function for storing fitness data
void store_fitness_data(struct fitness_data *data) {
    printf("Enter name: ");
    scanf("%s", data->name);
    printf("Enter age: ");
    scanf("%d", &data->age);
    printf("Enter weight: ");
    scanf("%f", &data->weight);
    printf("Enter height: ");
    scanf("%f", &data->height);
    data->bmi = calculate_bmi(data->weight, data->height);
    data->daily_calories = calculate_daily_calories(data->weight, data->daily_distance);
    data->daily_steps = calculate_daily_steps(data->daily_distance);
}

// Function for displaying fitness data
void display_fitness_data(struct fitness_data data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Weight: %f kg\n", data.weight);
    printf("Height: %f m\n", data.height);
    printf("BMI: %f\n", data.bmi);
    printf("Daily calories: %f\n", data.daily_calories);
    printf("Daily steps: %f\n", data.daily_steps);
    printf("Daily distance: %f km\n", data.daily_distance);
}

int main() {
    struct fitness_data data;
    store_fitness_data(&data);
    display_fitness_data(data);
    return 0;
}