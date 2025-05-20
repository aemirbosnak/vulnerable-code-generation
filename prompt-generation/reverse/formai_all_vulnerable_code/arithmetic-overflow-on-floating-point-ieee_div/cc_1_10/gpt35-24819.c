//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to calculate BMI
double calculateBMI(double weight, double height) {
    double bmi = weight / (height * height);
    return bmi;
}

// function to calculate calories burned based on activity time and MET value
double calculateCaloriesBurned(double met, double weight, double time) {
    double calories = (met * weight * 3.5 * time) / 200;
    return calories;
}

int main() {
    // variables
    double weight, height;
    int age, choice;
    char gender[10];
    double distance, pace, time, metValue;

    // user input
    printf("Enter your weight in kgs: ");
    scanf("%lf", &weight);
    printf("Enter your height in meters: ");
    scanf("%lf", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Are you male or female? (Enter 'male' or 'female'): ");
    scanf("%s", &gender);

    // calculate BMI
    double bmi = calculateBMI(weight, height);

    // print BMI and corresponding category
    printf("\nYour BMI is %.2f.\n", bmi);
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("You are normal weight.\n");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    // user input
    printf("\nWhat activity did you do?\n");
    printf("1. Walking\n2. Running\n");
    scanf("%d", &choice);
    printf("Enter the distance you covered in kms: ");
    scanf("%lf", &distance);
    printf("Enter the time taken in minutes: ");
    scanf("%lf", &time);

    // calculate pace and MET value
    pace = time / distance;
    if (choice == 1) {
        metValue = 3.5;
    } else if (choice == 2) {
        metValue = 7;
    }

    // calculate calories burned
    double caloriesBurned = calculateCaloriesBurned(metValue, weight, time);

    // print calories burned
    printf("\nYou burned %.2f calories.\n", caloriesBurned);

    return 0;
}