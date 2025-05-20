//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate the BMI of a person
double calculate_BMI(double weight, double height) {
    double bmi = weight / (height * height);
    return bmi;
}

// function to calculate the ideal body weight of a person
double calculate_ideal_weight(double height) {
    double ibw;
    const double female_base_height = 60;
    const double male_base_height = 64;
    
    if (height < 60) {
        ibw = 45;
    } else if (height >= 60 && height <= 64) {
        ibw = female_base_height + ((height - 60) * 2.3);
    } else if (height > 64) {
        ibw = male_base_height + ((height - 64) * 2.7);
    }
    
    return ibw;
}

// function to display the menu of options
void display_menu() {
    printf("\n--- C Fitness Tracker ---\n\n");
    printf("1. Record Weight\n");
    printf("2. Calculate BMI\n");
    printf("3. Calculate Ideal Body Weight\n");
    printf("4. Exit Program\n");
    printf("\nEnter option number: ");
}

// main function
int main() {
    double weight = 0.0;
    double height = 0.0;
    double bmi = 0.0;
    double ideal_weight = 0.0;
    int choice = 0;
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nEnter weight (in kg): ");
                scanf("%lf", &weight);
                printf("Weight recorded.");
                break;
            case 2:
                printf("\nEnter height (in meters): ");
                scanf("%lf", &height);
                bmi = calculate_BMI(weight, height);
                printf("BMI calculated: %.2lf", bmi);
                break;
            case 3:
                printf("\nEnter height (in inches): ");
                scanf("%lf", &height);
                ideal_weight = calculate_ideal_weight(height);
                printf("Ideal body weight calculated: %.1lf kg", ideal_weight);
                break;
            case 4:
                printf("\nExiting program. Goodbye!");
                break;
            default:
                printf("\nInvalid option. Please try again.");
        }
        
        printf("\n\n");
        
    } while (choice != 4);
    
    return 0;
}