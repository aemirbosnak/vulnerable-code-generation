//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 1024

typedef struct User {
    char name[MAX_CHAR];
    int age;
    double height;
    double weight;
    double heartRate;
    double targetHeartRate;
    int stepsTaken;
    int caloriesBurnt;
} User;

int main() {
    User user;
    char input[MAX_CHAR];

    // Get the user's name, age, height, and weight
    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your height (in inches): ");
    scanf("%lf", &user.height);

    printf("Enter your weight (in pounds): ");
    scanf("%lf", &user.weight);

    // Calculate the user's target heart rate
    user.targetHeartRate = 220 - (user.age * 2);

    // Get the user's heart rate, steps taken, and calories burned
    printf("Enter your heart rate: ");
    scanf("%lf", &user.heartRate);

    printf("Enter the number of steps you took: ");
    scanf("%d", &user.stepsTaken);

    printf("Enter the number of calories you burned: ");
    scanf("%d", &user.caloriesBurnt);

    // Display the user's information
    printf("\n**User Information:**\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2lf inches\n", user.height);
    printf("Weight: %.2lf pounds\n", user.weight);
    printf("Target Heart Rate: %.2lf beats per minute\n", user.targetHeartRate);
    printf("Heart Rate: %.2lf beats per minute\n", user.heartRate);
    printf("Steps Taken: %d\n", user.stepsTaken);
    printf("Calories Burned: %d\n", user.caloriesBurnt);

    return 0;
}