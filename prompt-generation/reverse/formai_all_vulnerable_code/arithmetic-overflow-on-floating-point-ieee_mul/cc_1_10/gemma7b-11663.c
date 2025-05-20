//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Sherlock Holmes Fitness Tracker structure
typedef struct SherlockHolmesFitnessTracker {
    char name[20];
    int age;
    float height;
    float weight;
    int stepsTaken;
    int caloriesBurned;
} SherlockHolmesFitnessTracker;

// Function to calculate the number of calories burned
int calculateCaloriesBurned(SherlockHolmesFitnessTracker *shft) {
    int age = shft->age;
    float height = shft->height;
    float weight = shft->weight;
    int stepsTaken = shft->stepsTaken;

    // Formula to calculate the number of calories burned
    int caloriesBurned = (10 * weight) + (6.25 * height) - (5 * age) + stepsTaken * 1.0;

    return caloriesBurned;
}

int main() {
    // Create a Sherlock Holmes Fitness Tracker structure
    SherlockHolmesFitnessTracker shft;

    // Get the user's name, age, height, and weight
    printf("Enter your name: ");
    scanf("%s", shft.name);

    printf("Enter your age: ");
    scanf("%d", &shft.age);

    printf("Enter your height (in inches): ");
    scanf("%f", &shft.height);

    printf("Enter your weight (in pounds): ");
    scanf("%f", &shft.weight);

    // Get the user's number of steps taken
    printf("Enter the number of steps you took today: ");
    scanf("%d", &shft.stepsTaken);

    // Calculate the number of calories burned
    int caloriesBurned = calculateCaloriesBurned(&shft);

    // Display the number of calories burned
    printf("The number of calories you burned today is: %d", caloriesBurned);

    return 0;
}