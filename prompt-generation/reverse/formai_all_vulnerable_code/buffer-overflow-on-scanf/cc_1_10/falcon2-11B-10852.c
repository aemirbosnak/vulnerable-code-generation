//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to calculate the BMI (Body Mass Index)
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate the BMR (Basal Metabolic Rate)
float calculate_bmr(float weight, float height, float age, float gender) {
    float bmr = 0.0;
    if (gender == 'M') {
        bmr = 66 + (13.75 * weight) + (5.003 * height) - (6.755 * age);
    } else if (gender == 'F') {
        bmr = 655 + (9.563 * weight) + (1.850 * height) - (4.676 * age);
    } else {
        bmr = 66 + (13.75 * weight) + (5.003 * height) - (6.755 * age);
    }
    return bmr;
}

// Function to calculate the RMR (Resting Metabolic Rate)
float calculate_rmr(float bmr, float gender) {
    if (gender == 'M') {
        return bmr * 1.2;
    } else if (gender == 'F') {
        return bmr * 1.375;
    } else {
        return bmr;
    }
}

// Function to calculate the AMR (Active Metabolic Rate)
float calculate_amr(float bmr, float weight, float height, float age, float gender, float activity_level) {
    float amr = bmr * (1 + (activity_level * 0.1));
    if (gender == 'M') {
        amr = amr * 1.2;
    } else if (gender == 'F') {
        amr = amr * 1.375;
    } else {
        amr = amr;
    }
    return amr;
}

// Function to calculate the TDEE (Total Daily Energy Expenditure)
float calculate_tdee(float rmr, float amr, float weight, float height, float age, float gender, float activity_level) {
    float tdee = rmr + amr;
    if (gender == 'M') {
        tdee = tdee * 1.2;
    } else if (gender == 'F') {
        tdee = tdee * 1.375;
    } else {
        tdee = tdee;
    }
    return tdee;
}

// Main function
int main() {
    // Get user input
    float weight, height, age, gender, activity_level;
    printf("Enter your weight (in kg): ");
    scanf("%f", &weight);
    printf("Enter your height (in cm): ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%f", &age);
    printf("Enter your gender (M/F): ");
    scanf("%c", &gender);
    printf("Enter your activity level (1-5): ");
    scanf("%f", &activity_level);

    // Calculate BMI
    float bmi = calculate_bmi(weight, height);
    printf("Your BMI is: %.2f\n", bmi);

    // Calculate BMR
    float bmr = calculate_bmr(weight, height, age, gender);
    printf("Your BMR is: %.2f\n", bmr);

    // Calculate RMR
    float rmr = calculate_rmr(bmr, gender);
    printf("Your RMR is: %.2f\n", rmr);

    // Calculate AMR
    float amr = calculate_amr(bmr, weight, height, age, gender, activity_level);
    printf("Your AMR is: %.2f\n", amr);

    // Calculate TDEE
    float tdee = calculate_tdee(rmr, amr, weight, height, age, gender, activity_level);
    printf("Your TDEE is: %.2f\n", tdee);

    return 0;
}