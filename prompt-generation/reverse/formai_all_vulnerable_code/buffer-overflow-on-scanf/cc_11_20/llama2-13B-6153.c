//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    int age, weight, height;
    double bmi;
    char gender[5];

    // Ask for user input
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your weight in kg: ");
    scanf("%d", &weight);
    printf("Please enter your height in cm: ");
    scanf("%d", &height);

    // Check for invalid input
    if (age < MIN_VALUE || age > MAX_VALUE) {
        printf("Error: Age must be between %d and %d\n", MIN_VALUE, MAX_VALUE);
        return 1;
    }

    if (weight < MIN_VALUE || weight > MAX_VALUE) {
        printf("Error: Weight must be between %d and %d\n", MIN_VALUE, MAX_VALUE);
        return 1;
    }

    if (height < MIN_VALUE || height > MAX_VALUE) {
        printf("Error: Height must be between %d and %d\n", MIN_VALUE, MAX_VALUE);
        return 1;
    }

    // Calculate BMI
    bmi = (weight / (height * height)) * 10000;

    // Check for underweight, normal weight, overweight, and obese
    if (bmi < 18.5) {
        printf("Error: You are underweight with a BMI of %f\n", bmi);
        return 1;
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("Your weight is normal with a BMI of %f\n", bmi);
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight with a BMI of %f\n", bmi);
    } else {
        printf("You are obese with a BMI of %f\n", bmi);
    }

    // Ask for gender
    printf("What is your gender? (M/F): ");
    fgets(gender, 5, stdin);

    // Check for invalid gender input
    if (strcmp(gender, "M") != 0 && strcmp(gender, "F") != 0) {
        printf("Error: Gender must be either M or F\n");
        return 1;
    }

    // Print the results
    printf("Your BMI is %f\n", bmi);
    printf("You are %s\n", (bmi < 18.5) ? "underweight" : (bmi < 25) ? "normal weight" : (bmi < 30) ? "overweight" : "obese");

    return 0;
}