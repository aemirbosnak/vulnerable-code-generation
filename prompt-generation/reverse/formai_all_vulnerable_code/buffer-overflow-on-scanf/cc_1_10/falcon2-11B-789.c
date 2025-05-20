//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define structure for user data
typedef struct {
    char name[50];
    float weight;
    float height;
    int age;
    float steps;
} User;

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate BMR
float calculateBMR(float weight, float height, float age) {
    float bmr = 66 + (13.75 * weight) + (5 * height) - (6.75 * age);
    return bmr;
}

// Function to calculate calories burned
float calculateCalories(float bmr, float steps) {
    float calories = bmr * 0.1 * steps;
    return calories;
}

int main() {
    srand(time(NULL)); // Seed random number generator

    User user;
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    printf("Please enter your weight (in kg): ");
    scanf("%f", &user.weight);

    printf("Please enter your height (in cm): ");
    scanf("%f", &user.height);

    printf("Please enter your age: ");
    scanf("%d", &user.age);

    printf("Please enter the number of steps you took today: ");
    scanf("%f", &user.steps);

    printf("Calculating...\n");

    float bmi = calculateBMI(user.weight, user.height);
    float bmr = calculateBMR(user.weight, user.height, user.age);
    float calories = calculateCalories(bmr, user.steps);

    printf("Your BMI is: %.2f\n", bmi);
    printf("Your BMR is: %.2f\n", bmr);
    printf("You burned %.2f calories today.\n", calories);

    return 0;
}