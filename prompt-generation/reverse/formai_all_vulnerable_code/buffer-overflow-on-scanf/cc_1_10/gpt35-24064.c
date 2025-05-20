//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    int age;
    float height;
    float weight;
};

struct Exercise {
    char name[20];
    int caloriesBurned;
};

int main() {
    struct User user;
    struct Exercise exercises[3];
    int exerciseCount = 0;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("---------------------------------\n");

    // prompt user for personal information
    printf("Please enter your name: ");
    scanf("%s", user.name);

    printf("Please enter your age: ");
    scanf("%d", &user.age);

    printf("Please enter your height (in meters): ");
    scanf("%f", &user.height);

    printf("Please enter your weight (in kg): ");
    scanf("%f", &user.weight);

    printf("\nThank you! Here is your personal information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f meters\n", user.height);
    printf("Weight: %.2f kg\n", user.weight);

    // prompt user for exercises
    printf("\nNow let's track your exercises. Enter up to 3 exercises.\n");
    while (exerciseCount < 3) {
        struct Exercise exercise;

        printf("\nEnter exercise name (type 'stop' to finish): ");
        scanf("%19s", exercise.name);

        if (strcmp(exercise.name, "stop") == 0) {
            break;
        }

        printf("Enter calories burned: ");
        scanf("%d", &exercise.caloriesBurned);

        exercises[exerciseCount++] = exercise;
    }

    // print exercise summary
    printf("\nExercise Summary:\n");
    int totalCalories = 0;
    for (int i = 0; i < exerciseCount; i++) {
        printf("%s: %d calories burned\n", exercises[i].name, exercises[i].caloriesBurned);
        totalCalories += exercises[i].caloriesBurned;
    }
    printf("Total calories burned: %d\n", totalCalories);

    return 0;
}