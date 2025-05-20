//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_EXERCISES 10

typedef struct {
    char name[32];
    int age;
    float weight;
    float height;
} user_t;

typedef struct {
    char name[32];
    int calories;
} exercise_t;

typedef struct {
    user_t users[MAX_USERS];
    exercise_t exercises[MAX_EXERCISES];
    int num_users;
    int num_exercises;
} fitness_tracker_t;

int main() {
    fitness_tracker_t tracker;
    tracker.num_users = 0;
    tracker.num_exercises = 0;

    // Add users
    for (int i = 0; i < MAX_USERS; i++) {
        user_t user;
        scanf("%s", user.name);
        scanf("%d", &user.age);
        scanf("%f", &user.weight);
        scanf("%f", &user.height);
        tracker.users[i] = user;
        tracker.num_users++;
    }

    // Add exercises
    for (int i = 0; i < MAX_EXERCISES; i++) {
        exercise_t exercise;
        scanf("%s", exercise.name);
        scanf("%d", &exercise.calories);
        tracker.exercises[i] = exercise;
        tracker.num_exercises++;
    }

    // Display users
    printf("Users:\n");
    for (int i = 0; i < tracker.num_users; i++) {
        user_t user = tracker.users[i];
        printf("Name: %s, Age: %d, Weight: %f, Height: %f\n", user.name, user.age, user.weight, user.height);
    }

    // Display exercises
    printf("Exercises:\n");
    for (int i = 0; i < tracker.num_exercises; i++) {
        exercise_t exercise = tracker.exercises[i];
        printf("Name: %s, Calories: %d\n", exercise.name, exercise.calories);
    }

    return 0;
}