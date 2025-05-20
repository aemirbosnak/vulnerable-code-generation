//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUT_TYPES 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_USER_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 1000

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
} Workout;

typedef struct {
    char name[MAX_USER_NAME_LENGTH];
    int age;
    int weight;
    int height;
    int gender;
    int daily_steps_goal;
    int daily_calories_goal;
    Workout workouts[MAX_WORKOUT_TYPES];
    int num_workouts;
} User;

int main() {
    User user;
    int choice;

    do {
        printf("CyberFitness Tracker 3000\n");
        printf("1. Create new user\n");
        printf("2. Log in\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter your name: ");
            scanf("%s", user.name);
            printf("Enter your age: ");
            scanf("%d", &user.age);
            printf("Enter your weight (in kg): ");
            scanf("%d", &user.weight);
            printf("Enter your height (in cm): ");
            scanf("%d", &user.height);
            printf("Enter your gender (0 for male, 1 for female): ");
            scanf("%d", &user.gender);
            printf("Enter your daily steps goal: ");
            scanf("%d", &user.daily_steps_goal);
            printf("Enter your daily calories goal: ");
            scanf("%d", &user.daily_calories_goal);
        } else if (choice == 2) {
            printf("Enter your name: ");
            scanf("%s", user.name);
            printf("Enter your password: ");
            scanf("%s", user.name); // just for demo purposes, replace with proper authentication
        } else if (choice == 3) {
            exit(0);
        }
    } while (1);

    return 0;
}