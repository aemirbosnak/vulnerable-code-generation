//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: complex
// Complex C Fitness Tracker Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for tracking fitness data
struct FitnessData {
    char name[20];
    int age;
    float height;
    float weight;
    float bmi;
    char gender;
    char activity[10];
    float distance;
    float duration;
    int calories;
};

// Function for calculating BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function for printing fitness data
void printFitnessData(struct FitnessData data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Height: %.2f\n", data.height);
    printf("Weight: %.2f\n", data.weight);
    printf("BMI: %.2f\n", data.bmi);
    printf("Gender: %c\n", data.gender);
    printf("Activity: %s\n", data.activity);
    printf("Distance: %.2f\n", data.distance);
    printf("Duration: %.2f\n", data.duration);
    printf("Calories: %d\n", data.calories);
}

// Function for calculating daily calories burned
int calculateDailyCalories(int activityLevel) {
    if (activityLevel == 1) {
        return 1000;
    } else if (activityLevel == 2) {
        return 1500;
    } else if (activityLevel == 3) {
        return 2000;
    } else {
        return 2500;
    }
}

// Function for tracking fitness data
void trackFitnessData(struct FitnessData *data) {
    // Get user input for fitness data
    printf("Enter name: ");
    scanf("%s", data->name);
    printf("Enter age: ");
    scanf("%d", &data->age);
    printf("Enter height (in inches): ");
    scanf("%f", &data->height);
    printf("Enter weight (in pounds): ");
    scanf("%f", &data->weight);
    printf("Enter gender (M/F): ");
    scanf("%c", &data->gender);
    printf("Enter activity level (1-4): ");
    scanf("%d", &data->activity);
    printf("Enter distance (in miles): ");
    scanf("%f", &data->distance);
    printf("Enter duration (in hours): ");
    scanf("%f", &data->duration);

    // Calculate BMI and daily calories burned
    data->bmi = calculateBMI(data->weight, data->height);
    data->calories = calculateDailyCalories(data->activity);

    // Print fitness data
    printFitnessData(*data);
}

int main() {
    // Declare struct for fitness data
    struct FitnessData data;

    // Track fitness data
    trackFitnessData(&data);

    return 0;
}