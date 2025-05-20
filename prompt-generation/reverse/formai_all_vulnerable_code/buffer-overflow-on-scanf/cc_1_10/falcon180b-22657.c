//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for fitness data
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    float distance;
    float calories;
} fitness_data;

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    return (weight / (height * height));
}

// Function to calculate distance and calories burned based on steps
void calculate_distance_and_calories(int steps, float distance, float *calories) {
    *calories = (0.0175 * steps) - (0.056 * distance);
    printf("Calories burned: %.2f\n", *calories);
}

int main() {
    fitness_data user_data;
    float bmi;
    int choice, i;
    char input[50];

    // Initialize user data
    strcpy(user_data.name, "John Doe");
    user_data.age = 30;
    user_data.weight = 80.0;
    user_data.height = 1.8;
    user_data.bmi = calculate_bmi(user_data.weight, user_data.height);
    user_data.steps = 0;
    user_data.distance = 0.0;
    user_data.calories = 0.0;

    // Display initial fitness data
    printf("\nWelcome, %s! Your initial fitness data is:\n", user_data.name);
    printf("Age: %d\n", user_data.age);
    printf("Weight: %0.2f kg\n", user_data.weight);
    printf("Height: %0.2f m\n", user_data.height);
    printf("BMI: %0.2f\n", user_data.bmi);

    // Main menu loop
    do {
        printf("\nSelect an option:\n");
        printf("1. Enter steps\n");
        printf("2. Enter distance\n");
        printf("3. View summary\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number of steps: ");
                scanf("%d", &user_data.steps);
                calculate_distance_and_calories(user_data.steps, user_data.distance, &user_data.calories);
                break;
            case 2:
                printf("Enter distance (in meters): ");
                scanf("%f", &user_data.distance);
                calculate_distance_and_calories(user_data.steps, user_data.distance, &user_data.calories);
                break;
            case 3:
                printf("\nSummary:\n");
                printf("Name: %s\n", user_data.name);
                printf("Age: %d\n", user_data.age);
                printf("Weight: %0.2f kg\n", user_data.weight);
                printf("Height: %0.2f m\n", user_data.height);
                printf("BMI: %0.2f\n", user_data.bmi);
                printf("Steps: %d\n", user_data.steps);
                printf("Distance: %.2f m\n", user_data.distance);
                printf("Calories burned: %.2f\n", user_data.calories);
                break;
            case 4:
                printf("\nGoodbye, %s!\n", user_data.name);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}