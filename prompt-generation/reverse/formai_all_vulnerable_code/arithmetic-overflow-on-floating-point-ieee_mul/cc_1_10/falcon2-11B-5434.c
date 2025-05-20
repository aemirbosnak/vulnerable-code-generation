//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate BMI (Body Mass Index)
double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

// Function to calculate BMR (Basal Metabolic Rate)
double calculateBMR(double weight, double height, double age, double gender) {
    double bmr = (10 * weight) + (6.25 * height) - (5 * age) + 5;
    if (gender == 'M') {
        bmr += 5;
    } else if (gender == 'F') {
        bmr -= 161;
    }
    return bmr;
}

// Function to calculate VO2 max
double calculateVO2max(double weight, double height, double age, double gender) {
    double v02max = (0.1807 * weight) + (0.2017 * height) - (0.2012 * age) - (0.0209 * gender);
    return v02max;
}

// Function to calculate TDEE (Total Daily Energy Expenditure)
double calculateTDEE(double weight, double height, double age, double gender, double activityLevel) {
    double tdee = (weight * 0.0001) + (height * 0.00009) - (age * 0.0012) + (gender * 0.0125) + (activityLevel * 0.0017);
    return tdee;
}

int main() {
    double weight, height, age, gender, activityLevel;
    double bmi, bmr, v02max, tdee;

    printf("Enter your weight in kg: ");
    scanf("%lf", &weight);
    printf("Enter your height in meters: ");
    scanf("%lf", &height);
    printf("Enter your age: ");
    scanf("%lf", &age);
    printf("Enter your gender (M/F): ");
    scanf("%s", &gender);
    printf("Enter your activity level (1-5): ");
    scanf("%lf", &activityLevel);

    bmi = calculateBMI(weight, height);
    bmr = calculateBMR(weight, height, age, gender);
    v02max = calculateVO2max(weight, height, age, gender);
    tdee = calculateTDEE(weight, height, age, gender, activityLevel);

    printf("BMI: %.2f\n", bmi);
    printf("BMR: %.2f\n", bmr);
    printf("VO2 max: %.2f\n", v02max);
    printf("TDEE: %.2f\n", tdee);

    return 0;
}