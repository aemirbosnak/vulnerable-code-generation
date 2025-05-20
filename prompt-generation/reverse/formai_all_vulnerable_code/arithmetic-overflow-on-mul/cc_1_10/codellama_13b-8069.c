//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: protected
// Fitness Tracker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 100
#define MAX_USERS 100

// Exercise struct
typedef struct {
    char name[30];
    int calories;
    int duration;
} Exercise;

// User struct
typedef struct {
    char name[30];
    int age;
    int weight;
    int height;
    int gender;
    int calories;
    int exercises;
    Exercise exercises_done[MAX_EXERCISES];
} User;

// Function to get user input
void get_user_input(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight: ");
    scanf("%d", &user->weight);
    printf("Enter your height: ");
    scanf("%d", &user->height);
    printf("Enter your gender (0 for male, 1 for female): ");
    scanf("%d", &user->gender);
    printf("Enter your goal: ");
    scanf("%d", &user->calories);
}

// Function to calculate calories burned
int calculate_calories(User *user, Exercise *exercise) {
    int calories = 0;
    // Calculate calories based on exercise type
    if (strcmp(exercise->name, "running") == 0) {
        calories = user->weight * exercise->duration * 0.033;
    } else if (strcmp(exercise->name, "cycling") == 0) {
        calories = user->weight * exercise->duration * 0.025;
    } else if (strcmp(exercise->name, "swimming") == 0) {
        calories = user->weight * exercise->duration * 0.15;
    } else if (strcmp(exercise->name, "yoga") == 0) {
        calories = user->weight * exercise->duration * 0.005;
    } else {
        calories = user->weight * exercise->duration * 0.01;
    }
    return calories;
}

// Function to add exercise
void add_exercise(User *user, Exercise *exercise) {
    if (user->exercises < MAX_EXERCISES) {
        strcpy(user->exercises_done[user->exercises].name, exercise->name);
        user->exercises_done[user->exercises].calories = calculate_calories(user, exercise);
        user->exercises_done[user->exercises].duration = exercise->duration;
        user->exercises++;
    } else {
        printf("Exercise limit reached\n");
    }
}

// Function to print user data
void print_user_data(User *user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d\n", user->weight);
    printf("Height: %d\n", user->height);
    printf("Gender: %d\n", user->gender);
    printf("Goal: %d\n", user->calories);
    printf("Exercises done: %d\n", user->exercises);
    printf("Calories burned: %d\n", user->calories);
    for (int i = 0; i < user->exercises; i++) {
        printf("%s: %d calories, %d minutes\n", user->exercises_done[i].name, user->exercises_done[i].calories, user->exercises_done[i].duration);
    }
}

// Main function
int main() {
    User user;
    Exercise exercise;
    int option = 0;
    get_user_input(&user);
    while (option != 4) {
        printf("Menu:\n");
        printf("1. Add exercise\n");
        printf("2. Print user data\n");
        printf("3. Quit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter exercise name: ");
                scanf("%s", exercise.name);
                printf("Enter duration (in minutes): ");
                scanf("%d", &exercise.duration);
                add_exercise(&user, &exercise);
                break;
            case 2:
                print_user_data(&user);
                break;
            case 3:
                break;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}