//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
void get_user_info(char *name, int *age, float *height, float *weight);
void calculate_bmi(float height, float weight, float *bmi);
void print_results(char *name, int age, float height, float weight, float bmi);

// Main function
int main() {
    char name[50];
    int age;
    float height, weight, bmi;

    // Get user information
    get_user_info(name, &age, &height, &weight);

    // Calculate BMI
    calculate_bmi(height, weight, &bmi);

    // Print results
    print_results(name, age, height, weight, bmi);

    return 0;
}

// Function to get user information
void get_user_info(char *name, int *age, float *height, float *weight) {
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", age);

    printf("Enter your height in cm: ");
    scanf("%f", height);

    printf("Enter your weight in kg: ");
    scanf("%f", weight);
}

// Function to calculate BMI
void calculate_bmi(float height, float weight, float *bmi) {
    *bmi = weight / (height * height);
}

// Function to print results
void print_results(char *name, int age, float height, float weight, float bmi) {
    printf("\nResults for %s:\n", name);
    printf("Age: %d\n", age);
    printf("Height: %0.2f cm\n", height);
    printf("Weight: %0.2f kg\n", weight);
    printf("BMI: %0.2f\n", bmi);
}