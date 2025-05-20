//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate BMI
float calculate_bmi(float height, float weight) {
    return weight/(height*height);
}

// function to calculate body fat percentage
float calculate_body_fat(float bmi, int age, char gender) {
    float factor;
    if (gender == 'm') {
        factor = 1.112 - (0.00043499 * bmi * 10000) + (0.00000055 * age * age);
    } else {
        factor = 1.097 - (0.00046971 * bmi * 10000) + (0.00000056 * age * age);
    }
    return (495/(factor * bmi)) - 450;
}

// function to display results
void display_results(float bmi, float body_fat) {
    printf("Your BMI is %.2f\n", bmi);
    printf("Your Body Fat Percentage is %.2f\n", body_fat);
}

int main() {
    // initialize variables
    float height, weight, bmi, body_fat;
    int age;
    char gender;

    // take user inputs
    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your weight (in kilograms): ");
    scanf("%f", &weight);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gender (m/f): ");
    scanf(" %c", &gender);

    // calculate BMI and body fat percentage
    bmi = calculate_bmi(height, weight);
    body_fat = calculate_body_fat(bmi, age, gender);

    // display results
    display_results(bmi, body_fat);

    return 0;
}