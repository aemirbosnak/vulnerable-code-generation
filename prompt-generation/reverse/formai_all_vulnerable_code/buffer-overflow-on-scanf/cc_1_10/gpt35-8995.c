//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
} User;

typedef struct {
    char date[11];
    int steps;
    float distance;
    float calories;
} Workout;

int main() {
    User user;
    Workout workouts[7];
    float total_distance = 0.0;
    float total_calories = 0.0;
    int total_steps = 0;

    // Getting user information
    printf("Welcome to the C Fitness Tracker!\n");
    printf("What is your name? ");
    scanf("%s", user.name);
    printf("What is your age? ");
    scanf("%d", &user.age);
    printf("What is your height (in meters)? ");
    scanf("%f", &user.height);
    printf("What is your weight (in kilograms)? ");
    scanf("%f", &user.weight);

    // Getting workout information for last week
    printf("\nEnter your workout information for the last 7 days:\n");
    for (int i = 0; i < 7; i++) {
        printf("\nWorkout %d:\n", i+1);
        printf("Date (mm/dd/yyyy): ");
        scanf("%s", workouts[i].date);
        printf("Number of steps: ");
        scanf("%d", &workouts[i].steps);
        printf("Distance (in kilometers): ");
        scanf("%f", &workouts[i].distance);
        printf("Calories burned: ");
        scanf("%f", &workouts[i].calories);

        total_distance += workouts[i].distance;
        total_calories += workouts[i].calories;
        total_steps += workouts[i].steps;
    }

    // Displaying summary of user information and workout data
    printf("\n");
    printf("=== USER INFORMATION ===\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f meters\n", user.height);
    printf("Weight: %.2f kilograms\n", user.weight);
    printf("\n");
    printf("=== WEEKLY WORKOUT SUMMARY ===\n");
    printf("Total number of steps: %d\n", total_steps);
    printf("Total distance covered: %.2f kilometers\n", total_distance);
    printf("Total calories burned: %.2f\n", total_calories);
    printf("\n");
    printf("Workout Details by Day:\n");
    printf("-----------------------------------------------\n");
    printf("| Date     | Steps Taken | Distance (km) | Calories |\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < 7; i++) {
        printf("| %s | %10d | %12.2f | %8.2f |\n", workouts[i].date, workouts[i].steps, workouts[i].distance, workouts[i].calories);
    }
    printf("-----------------------------------------------\n");

    return 0;
}