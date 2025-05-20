//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    float weight, height, bmi;
    int age;
    char gender;

    // Get user input
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    printf("Please enter your age in years: ");
    scanf("%d", &age);

    printf("Please enter your gender (m/f): ");
    scanf(" %c", &gender);

    // Calculate BMI
    bmi = weight / (height * height);

    // Print results
    printf("\n");
    printf("Your BMI is %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("You are underweight\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are in the normal weight range\n");
    } else {
        printf("You are overweight\n");
    }

    // Calculate target weight
    if (gender == 'm') {
        printf("Your target weight range is %.2fkg to %.2fkg\n", 20 * (height * height), 25 * (height * height));
    } else if (gender == 'f') {
        printf("Your target weight range is %.2fkg to %.2fkg\n", 19 * (height * height), 24 * (height * height));
    }

    // Generate workout plan
    srand(time(NULL));  // Seed random number generator based on current time
    printf("Your personalized workout plan:\n");
    for (int i = 1; i <= 5; i++) {
        int minutes = rand() % 31 + 30;  // Generate random number between 30-60
        printf("Day %d: %d minutes of cardio\n", i, minutes);
    }

    return 0;
}