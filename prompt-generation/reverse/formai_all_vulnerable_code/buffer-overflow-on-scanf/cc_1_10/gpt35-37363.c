//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Struct for storing user information
typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
} UserInfo;

// Struct for storing fitness data
typedef struct {
    int steps;
    float distance;
    float calories;
    float heartRate;
} FitnessData;

int main() {
    UserInfo user;
    FitnessData data;

    // Get user information from input
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your height in meters: ");
    scanf("%f", &user.height);
    printf("Enter your weight in kilograms: ");
    scanf("%f", &user.weight);

    // Print user information
    printf("\nUser Information\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2fm\n", user.height);
    printf("Weight: %.2fkg\n", user.weight);

    // Ask user for fitness data
    printf("\nEnter number of steps taken: ");
    scanf("%d", &data.steps);
    printf("Enter distance traveled in kilometers: ");
    scanf("%f", &data.distance);
    printf("Enter calories burned: ");
    scanf("%f", &data.calories);
    printf("Enter heart rate in bpm: ");
    scanf("%f", &data.heartRate);

    // Print fitness data
    printf("\nFitness Data\n");
    printf("Steps taken: %d\n", data.steps);
    printf("Distance traveled: %.2fkm\n", data.distance);
    printf("Calories burned: %.2fkcal\n", data.calories);
    printf("Heart rate: %.2fbpm\n", data.heartRate);

    return 0;
}