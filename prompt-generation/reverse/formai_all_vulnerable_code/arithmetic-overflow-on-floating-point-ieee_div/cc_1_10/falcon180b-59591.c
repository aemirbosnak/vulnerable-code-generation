//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define structure for fitness data
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} fitness_data;

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    return (weight / (height * height));
}

// Function to display fitness data
void display_fitness_data(fitness_data data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Weight: %f\n", data.weight);
    printf("Height: %f\n", data.height);
    printf("BMI: %f\n", data.bmi);
}

// Main function to take input and calculate BMI
int main() {
    fitness_data user_data;

    // Take user input for name, age, weight and height
    printf("Enter your name: ");
    scanf("%s", user_data.name);

    printf("Enter your age: ");
    scanf("%d", &user_data.age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &user_data.weight);

    printf("Enter your height (in meters): ");
    scanf("%f", &user_data.height);

    // Calculate BMI using the calculate_bmi function
    user_data.bmi = calculate_bmi(user_data.weight, user_data.height);

    // Display the fitness data
    printf("Your fitness data:\n");
    display_fitness_data(user_data);

    return 0;
}