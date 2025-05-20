//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a fitness tracker
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    int calories;
} FitnessTracker;

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate calories burned based on steps taken
int calculateCalories(int steps) {
    return steps * 0.1;
}

// Function to display the fitness tracker data
void displayFitnessTracker(FitnessTracker ft) {
    printf("Name: %s\n", ft.name);
    printf("Age: %d\n", ft.age);
    printf("Weight: %f\n", ft.weight);
    printf("Height: %f\n", ft.height);
    printf("BMI: %f\n", ft.bmi);
    printf("Steps taken: %d\n", ft.steps);
    printf("Calories burned: %d\n", ft.calories);
}

// Function to get user input for fitness tracker data
void getFitnessTrackerData(FitnessTracker *ft) {
    printf("Enter your name: ");
    scanf("%s", ft->name);

    printf("Enter your age: ");
    scanf("%d", &ft->age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &ft->weight);

    printf("Enter your height (in cm): ");
    scanf("%f", &ft->height);

    ft->bmi = calculateBMI(ft->weight, ft->height);

    printf("Enter the number of steps taken today: ");
    scanf("%d", &ft->steps);

    ft->calories = calculateCalories(ft->steps);
}

// Main function
int main() {
    FitnessTracker ft;

    // Get user input for fitness tracker data
    getFitnessTrackerData(&ft);

    // Display the fitness tracker data
    displayFitnessTracker(ft);

    return 0;
}