//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of exercises to track
#define MAX_EXERCISES 10

// Define the structure for each exercise
typedef struct {
    char name[50];
    double distance;
    double time;
    double calories;
} Exercise;

// Define the main function
int main() {
    // Declare variables
    int numExercises;
    Exercise exercises[MAX_EXERCISES];

    // Prompt the user for the number of exercises
    printf("Enter the number of exercises (1-%d): ", MAX_EXERCISES);
    scanf("%d", &numExercises);

    // Loop through each exercise and get the details from the user
    for (int i = 0; i < numExercises; i++) {
        printf("Enter exercise %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", exercises[i].name);
        printf("Distance: ");
        scanf("%lf", &exercises[i].distance);
        printf("Time: ");
        scanf("%lf", &exercises[i].time);
        printf("Calories: ");
        scanf("%lf", &exercises[i].calories);
    }

    // Calculate the total distance, time, and calories for all exercises
    double totalDistance = 0;
    double totalTime = 0;
    double totalCalories = 0;

    for (int i = 0; i < numExercises; i++) {
        totalDistance += exercises[i].distance;
        totalTime += exercises[i].time;
        totalCalories += exercises[i].calories;
    }

    // Print the results
    printf("\nTotal distance: %.2lf km\n", totalDistance/1000);
    printf("Total time: %.2lf hours\n", totalTime/3600);
    printf("Total calories burned: %.2lf kcal\n", totalCalories);

    return 0;
}