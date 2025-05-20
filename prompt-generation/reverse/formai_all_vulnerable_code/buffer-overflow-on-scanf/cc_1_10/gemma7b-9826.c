//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Declare variables
    char name[20];
    int age, height, weight, heartRate, stepsTaken;
    float BMI, averageHeartRate, totalDistanceTraveled;

    // Get user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (in inches): ");
    scanf("%d", &height);

    printf("Enter your weight (in pounds): ");
    scanf("%d", &weight);

    // Calculate BMI
    BMI = (weight * 703) / (height * height);

    // Calculate average heart rate
    averageHeartRate = 220 - (age * 2);

    // Calculate total distance traveled
    totalDistanceTraveled = stepsTaken * 0.025;

    // Display results
    printf("\nHi, %s! Here's your fitness report:**\n", name);

    printf("Age: %d\n", age);

    printf("Height: %d inches\n", height);

    printf("Weight: %d pounds\n", weight);

    printf("BMI: %.2f\n", BMI);

    printf("Average Heart Rate: %.2f beats per minute\n", averageHeartRate);

    printf("Total Distance Traveled: %.2f miles\n", totalDistanceTraveled);

    return 0;
}