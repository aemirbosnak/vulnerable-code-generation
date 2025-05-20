//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ERROR_MESSAGE_SIZE 256

// Define error codes
#define SUCCESS 0
#define INVALID_INPUT 1
#define OUT_OF_BOUNDS 2
#define DIVIDE_BY_ZERO 3

// Define error messages
#define INVALID_INPUT_MSG "Invalid input detected! Please try again."
#define OUT_OF_BOUNDS_MSG "Input out of bounds. Please enter a valid value."
#define DIVIDE_BY_ZERO_MSG "Cannot divide by zero. Please check your calculation."

int main() {
    // Define variables
    int age, height, weight, i;
    char name[MAX_INPUT_SIZE];

    // Initialize variables
    age = 0;
    height = 0;
    weight = 0;
    i = 0;

    // Get user input
    printf("Welcome to the health checker!\n");
    printf("Please enter your name: ");
    fgets(name, MAX_INPUT_SIZE, stdin);

    // Check for invalid input
    if (strlen(name) > MAX_INPUT_SIZE - 1) {
        printf(INVALID_INPUT_MSG);
        return INVALID_INPUT;
    }

    // Get age, height, and weight
    printf("Please enter your age: ");
    scanf("%d", &age);

    if (age < 0 || age > 100) {
        printf(OUT_OF_BOUNDS_MSG);
        return OUT_OF_BOUNDS;
    }

    printf("Please enter your height: ");
    scanf("%d", &height);

    if (height < 0 || height > 200) {
        printf(OUT_OF_BOUNDS_MSG);
        return OUT_OF_BOUNDS;
    }

    printf("Please enter your weight: ");
    scanf("%d", &weight);

    // Check for divide by zero
    if (weight == 0) {
        printf(DIVIDE_BY_ZERO_MSG);
        return DIVIDE_BY_ZERO;
    }

    // Calculate BMI
    double bmi = (double)weight / (double)height;

    // Check for BMI range
    if (bmi < 18.5) {
        printf("You are underweight. Please consult a doctor.");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("Your weight is normal.");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight. Please consider a healthy diet and exercise.");
    } else {
        printf("You are obese. Please consult a doctor immediately.");
    }

    return SUCCESS;
}