//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* User-defined structure to hold fitness data */
struct FitnessData {
    float weight;
    int steps;
    int caloriesBurned;
};

/* Function to calculate BMI */
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

/* Main function */
int main() {
    printf("*** C Fitness Tracker ***\n");
    printf("Enter your weight (in kg): ");
    
    /* Reading user input */
    float weight;
    scanf("%f", &weight);

    printf("Enter your height (in meters): ");
    float height;
    scanf("%f", &height);
    
    /* Calculating BMI */
    float bmi = calculateBMI(weight, height);
    
    printf("Your Body Mass Index (BMI) is: %.2f\n", bmi);
    
    /* Creating an instance of FitnessData structure */
    struct FitnessData fitnessData;
    fitnessData.weight = weight;
   
    /* Initializing other variables */
    fitnessData.steps = 0;
    fitnessData.caloriesBurned = 0;
    
    /* User Menu */
    while (1) {
        printf("\n1. Add steps\n");
        printf("2. View fitness data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            /* Adding steps */
            case 1: {
                printf("\nEnter number of steps: ");
                int steps;
                scanf("%d", &steps);
                
                /* Updating steps and calories burned */
                fitnessData.steps += steps;
                fitnessData.caloriesBurned += steps / 20;
                
                printf("Steps added successfully!\n");
                break;
            }
            
            /* Viewing fitness data */
            case 2: {
                printf("\nWeight: %.2f kg\n", fitnessData.weight);
                printf("Steps: %d\n", fitnessData.steps);
                printf("Calories Burned: %d cal\n", fitnessData.caloriesBurned);
                break;
            }
            
            /* Exiting the program */
            case 3: {
                printf("\nThank you for using C Fitness Tracker!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice! Try again.\n");
            }
        }
    }
    
    return 0;
}