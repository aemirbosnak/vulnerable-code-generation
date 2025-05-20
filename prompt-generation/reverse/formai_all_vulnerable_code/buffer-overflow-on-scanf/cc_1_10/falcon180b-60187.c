//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXERCISES 50
#define MAX_USER_NAME 50
#define MAX_WORKOUT_NAME 100
#define MAX_WORKOUT_DURATION 100
#define MAX_WORKOUT_DETAILS 500

typedef struct {
    char name[MAX_USER_NAME];
    int age;
    char gender;
} User;

typedef struct {
    char name[MAX_WORKOUT_NAME];
    int duration;
    char details[MAX_WORKOUT_DETAILS];
} Workout;

typedef struct {
    User user;
    Workout workout;
} Exercise;

void addUser(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &user->gender);
}

void addWorkout(Workout *workout) {
    printf("Enter workout name: ");
    scanf("%s", workout->name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workout->duration);
    printf("Enter workout details: ");
    scanf("%s", workout->details);
}

void addExercise(Exercise *exercise) {
    addUser(&exercise->user);
    addWorkout(&exercise->workout);
}

void printExercise(Exercise exercise) {
    printf("User: %s\n", exercise.user.name);
    printf("Age: %d\n", exercise.user.age);
    printf("Gender: %c\n", exercise.user.gender);
    printf("Workout name: %s\n", exercise.workout.name);
    printf("Workout duration (in minutes): %d\n", exercise.workout.duration);
    printf("Workout details: %s\n", exercise.workout.details);
}

int main() {
    User user;
    Workout workout;
    Exercise exercise;

    addUser(&user);
    addWorkout(&workout);
    addExercise(&exercise);

    printExercise(exercise);

    return 0;
}