//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: excited
// Excited Fitness Tracker in C

#include <stdio.h>

int main() {
    // Variables
    int weight, height, age, goal;
    float bmi;
    char gender;

    // Input
    printf("Enter your weight in pounds: ");
    scanf("%d", &weight);
    printf("Enter your height in inches: ");
    scanf("%d", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);
    printf("Enter your fitness goal (1-5): ");
    scanf("%d", &goal);

    // Calculations
    bmi = (weight * 703) / (height * height);

    // Output
    printf("Your BMI is: %f\n", bmi);
    printf("Your fitness goal is: ");
    switch (goal) {
        case 1:
            printf("Lose weight\n");
            break;
        case 2:
            printf("Maintain weight\n");
            break;
        case 3:
            printf("Gain muscle\n");
            break;
        case 4:
            printf("Increase endurance\n");
            break;
        case 5:
            printf("Improve overall health\n");
            break;
        default:
            printf("Invalid input\n");
            break;
    }

    // Determine if user is at risk
    if (gender == 'F' && bmi < 18.5) {
        printf("You are at risk for underweight.\n");
    } else if (gender == 'F' && bmi >= 18.5 && bmi < 24.9) {
        printf("You are at a healthy weight.\n");
    } else if (gender == 'F' && bmi >= 25 && bmi < 29.9) {
        printf("You are at risk for overweight.\n");
    } else if (gender == 'F' && bmi >= 30) {
        printf("You are obese.\n");
    } else if (gender == 'M' && bmi < 18.5) {
        printf("You are at risk for underweight.\n");
    } else if (gender == 'M' && bmi >= 18.5 && bmi < 24.9) {
        printf("You are at a healthy weight.\n");
    } else if (gender == 'M' && bmi >= 25 && bmi < 29.9) {
        printf("You are at risk for overweight.\n");
    } else if (gender == 'M' && bmi >= 30) {
        printf("You are obese.\n");
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}