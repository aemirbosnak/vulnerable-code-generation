//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_AGE 100
#define MAX_WEIGHT 100
#define MAX_HEIGHT 100
#define MAX_BMI 30
#define MAX_FITNESS_LEVEL 3

int main() {
    srand(time(NULL)); // Initialize random number generator
    int age;
    int weight;
    int height;
    int gender;
    int fitnessLevel;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
    if (age < 0 || age > MAX_AGE) {
        printf("Invalid age entered. Exiting program...\n");
        return 0;
    }

    printf("Please enter your weight (in kilograms): ");
    scanf("%d", &weight);
    if (weight < 0 || weight > MAX_WEIGHT) {
        printf("Invalid weight entered. Exiting program...\n");
        return 0;
    }

    printf("Please enter your height (in meters): ");
    scanf("%d", &height);
    if (height < 0 || height > MAX_HEIGHT) {
        printf("Invalid height entered. Exiting program...\n");
        return 0;
    }

    printf("Please enter your gender (0 for male, 1 for female): ");
    scanf("%d", &gender);

    if (gender < 0 || gender > 1) {
        printf("Invalid gender entered. Exiting program...\n");
        return 0;
    }

    if (gender == 0) {
        weight = weight / 2.2;
    }

    double bmi = (double) weight / ((double) height * (double) height);
    if (bmi < 18.5) {
        fitnessLevel = 0;
    }
    else if (bmi >= 18.5 && bmi < 24.9) {
        fitnessLevel = 1;
    }
    else if (bmi >= 25 && bmi < 29.9) {
        fitnessLevel = 2;
    }
    else if (bmi >= 30) {
        fitnessLevel = 3;
    }
    else {
        fitnessLevel = -1;
    }

    printf("Your BMI is %.2f\n", bmi);
    printf("Your fitness level is: %d\n", fitnessLevel);

    return 0;
}