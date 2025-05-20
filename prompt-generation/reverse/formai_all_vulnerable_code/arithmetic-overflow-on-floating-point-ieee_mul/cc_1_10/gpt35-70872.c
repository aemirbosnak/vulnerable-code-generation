//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate BMI
float calculateBMI(float height, float weight) {
    float height_m = height / 100;
    return weight / (height_m * height_m);
}

// Function to print the current stats
void printStats(float height, float weight, float bmi) {
    printf("Your current stats are:\n");
    printf("Height: %.2f cm\n", height);
    printf("Weight: %.2f kg\n", weight);
    printf("BMI: %.2f kg/m2\n\n", bmi);
}

// Main function
int main() {
    float height, weight, bmi = 0;
    int choice = 0;
    
    printf("Welcome to the Fitness Tracker!\n\n");
    
    // Get initial stats
    printf("Please enter your height in cm: ");
    scanf("%f", &height);
    
    printf("Please enter your weight in kg: ");
    scanf("%f", &weight);
    
    // Calculate initial BMI
    bmi = calculateBMI(height, weight);
    printStats(height, weight, bmi);
    
    // Menu loop
    while (choice != 4) {
        printf("Please select an option:\n");
        printf("1. Log a Workout\n");
        printf("2. Add Food Intake\n");
        printf("3. Print Current Stats\n");
        printf("4. Exit Program\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            // Log a Workout
            case 1: {
                int duration;
                
                printf("Please enter the duration of your workout in minutes: ");
                scanf("%d", &duration);
                
                bmi -= duration / 60.0;
                
                printStats(height, weight, bmi);
                break;
            }
            // Add Food Intake
            case 2: {
                int calories;
                
                printf("Please enter the number of calories consumed: ");
                scanf("%d", &calories);
                
                bmi += calories / 3500.0;
                
                printStats(height, weight, bmi);
                break;
            }
            // Print Current Stats
            case 3: {
                printStats(height, weight, bmi);
                break;
            }
            // Exit Program
            case 4: {
                printf("Goodbye!\n");
                break;
            }
            // Handle Invalid Choice
            default: {
                printf("Invalid choice. Please try again.\n\n");
                break;
            }
        }
    }
    
    return 0;
}