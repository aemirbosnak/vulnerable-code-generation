//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct FitnessTracker {
    char name[MAX_SIZE];
    int age;
    float height;
    float weight;
    int stepsTaken;
    int caloriesBurned;
} FitnessTracker;

int main() {
    FitnessTracker tracker;

    // Initialize the fitness tracker
    tracker.name[0] = '\0';
    tracker.age = 0;
    tracker.height = 0.0f;
    tracker.weight = 0.0f;
    tracker.stepsTaken = 0;
    tracker.caloriesBurned = 0;

    // Get the user's name, age, height, and weight
    printf("Enter your name: ");
    scanf("%s", tracker.name);

    printf("Enter your age: ");
    scanf("%d", &tracker.age);

    printf("Enter your height (in meters): ");
    scanf("%f", &tracker.height);

    printf("Enter your weight (in kilograms): ");
    scanf("%f", &tracker.weight);

    // Calculate the user's BMI
    float bmi = tracker.weight * 70.0f / (tracker.height * tracker.height);

    // Display the user's BMI
    printf("Your BMI is: %.2f", bmi);

    // Get the user's number of steps taken
    printf("Enter the number of steps you took today: ");
    scanf("%d", &tracker.stepsTaken);

    // Calculate the number of calories burned
    int caloriesBurned = tracker.stepsTaken * 10;

    // Display the number of calories burned
    printf("You burned a total of %d calories today.", caloriesBurned);

    // Update the fitness tracker's information
    tracker.caloriesBurned = caloriesBurned;

    // Print the fitness tracker's information
    printf("Name: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Height: %.2f meters\n", tracker.height);
    printf("Weight: %.2f kilograms\n", tracker.weight);
    printf("Steps Taken: %d\n", tracker.stepsTaken);
    printf("Calories Burned: %d\n", tracker.caloriesBurned);

    return 0;
}