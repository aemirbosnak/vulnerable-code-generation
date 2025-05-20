//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate BMI
float calculateBMI(float height, float weight){
    return weight/(height*height);
}

// Function to calculate Ideal Body Weight (IBW)
float calculateIBW(char gender, float height){
    if(gender=='m'){
        return 50 + 0.9 * (height - 152);
    }
    else{
        return 45.5 + 0.9 * (height - 152);
    }
}

// Function to calculate Body Fat Percentage (BFP)
float calculateBFP(char gender, float height, float neck, float waist, float hip){
    if(gender=='m'){
        return 495/ (1.0324 - 0.19077 * log10(waist-neck) + 0.15456 * log10(height)) - 450;
    }
    else{
        return 495/ (1.29579 - 0.35004 * log10(waist+hip-neck) + 0.22100 * log10(height)) - 450;
    }
}

int main(){
    // Introduction
    printf("Welcome to the Ada Fitness Tracker!\n");

    // User Input
    char gender;
    float height, weight, neck, waist, hip;
    printf("Please enter your gender (m/f): ");
    scanf("%c", &gender);
    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Please enter your neck circumference in centimeters: ");
    scanf("%f", &neck);
    printf("Please enter your waist circumference in centimeters: ");
    scanf("%f", &waist);
    printf("Please enter your hip circumference in centimeters: ");
    scanf("%f", &hip);

    // Calculations
    float bmi = calculateBMI(height, weight);
    float ibw = calculateIBW(gender, height);
    float bfp = calculateBFP(gender, height, neck, waist, hip);

    // Results
    printf("\nYour calculated BMI is: %.2f\n", bmi);
    printf("Your ideal body weight (IBW) is: %.2f kg\n", ibw);
    printf("Your calculated body fat percentage (BFP) is: %.2f\n", bfp);
    printf("\nThank you for using Ada Fitness Tracker! Stay Healthy and Stay Fit :)\n");

    return 0;
}