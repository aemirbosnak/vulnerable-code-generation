//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
// Embark on a fitness odyssey with this C Fitness Tracker!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold the fitness data
typedef struct FitnessData {
    char name[50];       // User's name
    int age;             // User's age
    int height;          // User's height in cm
    int weight;          // User's weight in kg
    double bmi;          // Body Mass Index
    int steps;           // Daily step count
    int caloriesBurned;  // Daily calories burned
    int distanceWalked;  // Daily distance walked in km
} FitnessData;

// Function to calculate BMI
double calculateBMI(int weight, int height) {
    return (double)weight / (height * height / 10000);
}

// Function to generate a daily fitness report
void generateDailyReport(FitnessData *data) {
    printf("**Fitness Report for %s**\n", data->name);
    printf("Age: %d\n", data->age);
    printf("Height: %dcm\n", data->height);
    printf("Weight: %dkg\n", data->weight);
    printf("BMI: %.2f\n", data->bmi);
    printf("Steps Taken: %d\n", data->steps);
    printf("Calories Burned: %d\n", data->caloriesBurned);
    printf("Distance Walked: %.2fkm\n", data->distanceWalked);
}

// Function to update fitness data
void updateFitnessData(FitnessData *data) {
    printf("Enter your name: ");
    scanf("%s", data->name);
    printf("Enter your age: ");
    scanf("%d", &data->age);
    printf("Enter your height in cm: ");
    scanf("%d", &data->height);
    printf("Enter your weight in kg: ");
    scanf("%d", &data->weight);
    data->bmi = calculateBMI(data->weight, data->height);
    printf("Your BMI is: %.2f\n", data->bmi);
}

// Main function to interact with the user
int main() {
    FitnessData data; // Create a fitness data instance
    int choice; // User's choice

    // Seed the random number generator
    srand(time(NULL));

    // Welcome the user
    printf("Welcome to the Fitness Tracker!\n");

    // Loop until the user exits
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Update fitness data\n");
        printf("2. Generate daily report\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateFitnessData(&data);
                break;
            case 2:
                generateDailyReport(&data);
                break;
            case 3:
                printf("Goodbye! Stay fit!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}