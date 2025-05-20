//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    float bmi = (weight / (height * height)) * 703;
    return bmi;
}

// Function to calculate body fat percentage
float calculate_body_fat(float bmi, float age, char gender[]) {
    float body_fat;
    if (strcmp(gender, "male") == 0) {
        body_fat = (1.20 * bmi) + (0.23 * age) - 16.2;
    }
    else {
        body_fat = (1.20 * bmi) + (0.23 * age) - 5.4;
    }
    return body_fat;
}

// Function to display menu
void display_menu() {
    printf("\n--- Fitness Tracker ---\n");
    printf("1. Calculate BMI\n");
    printf("2. Calculate Body Fat Percentage\n");
    printf("3. Exit\n");
    printf("Enter your option: ");
}

int main() {
    int option;
    float weight, height, bmi, age, body_fat;
    char gender[10];

    do {
        display_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter your weight (in pounds): ");
                scanf("%f", &weight);
                printf("Enter your height (in inches): ");
                scanf("%f", &height);
                bmi = calculate_bmi(weight, height);
                printf("Your BMI is %.2f\n", bmi);
                break;
            case 2:
                printf("\nEnter your weight (in pounds): ");
                scanf("%f", &weight);
                printf("Enter your height (in inches): ");
                scanf("%f", &height);
                printf("Enter your age: ");
                scanf("%f", &age);
                printf("Enter your gender (male/female): ");
                scanf("%s", gender);
                bmi = calculate_bmi(weight, height);
                body_fat = calculate_body_fat(bmi, age, gender);
                printf("Your body fat percentage is %.2f%%\n", body_fat);
                break;
            case 3:
                printf("Exiting the program!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(option != 3);

    return 0;
}