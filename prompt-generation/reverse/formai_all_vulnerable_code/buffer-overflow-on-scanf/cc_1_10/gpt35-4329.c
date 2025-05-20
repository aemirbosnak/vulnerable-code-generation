//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_EXERCISES 50
#define MAX_WORKOUTS 1000

struct Exercise {
    char name[50];
    int caloriesBurnedPerMinute;
};

struct User {
    char name[50];
    int age;
    int weight;
    int height;
    struct Exercise exercises[MAX_EXERCISES];
    int numExercises;
};

struct Workout {
    char exerciseName[50];
    int durationInMinutes;
    int caloriesBurned;
};

struct User users[MAX_USERS];
int numUsers = 0;

struct Workout workouts[MAX_WORKOUTS];
int numWorkouts = 0;

void addUser() {
    printf("Enter user name: ");
    scanf("%s", users[numUsers].name);
    printf("Enter age: ");
    scanf("%d", &users[numUsers].age);
    printf("Enter weight in kilograms: ");
    scanf("%d", &users[numUsers].weight);
    printf("Enter height in centimeters: ");
    scanf("%d", &users[numUsers].height);
    users[numUsers].numExercises = 0;
    printf("User %s added successfully!\n", users[numUsers].name);
    numUsers++;
}

void addExercise() {
    printf("Enter user name: ");
    char username[50];
    scanf("%s", username);

    struct User *user = NULL;
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, username) == 0) {
            user = &users[i];
            break;
        }
    }

    if (user == NULL) {
        printf("User %s not found!\n", username);
        return;
    }

    printf("Enter exercise name: ");
    scanf("%s", user->exercises[user->numExercises].name);
    printf("Enter calories burned per minute: ");
    scanf("%d", &user->exercises[user->numExercises].caloriesBurnedPerMinute);
    user->numExercises++;

    printf("Exercise %s added for user %s!\n", user->exercises[user->numExercises-1].name, user->name);
}

struct Exercise *getExerciseByName(char *exerciseName, struct User *user) {
    int i;
    for (i = 0; i < user->numExercises; i++) {
        if (strcmp(user->exercises[i].name, exerciseName) == 0) {
            return &user->exercises[i];
        }
    }

    return NULL;
}

void addWorkout() {
    printf("Enter user name: ");
    char username[50];
    scanf("%s", username);

    struct User *user = NULL;
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, username) == 0) {
            user = &users[i];
            break;
        }
    }

    if (user == NULL) {
        printf("User %s not found!\n", username);
        return;
    }

    char exerciseName[50];
    int durationInMinutes;
    printf("Enter exercise name: ");
    scanf("%s", exerciseName);
    printf("Enter duration in minutes: ");
    scanf("%d", &durationInMinutes);

    struct Exercise *exercise = getExerciseByName(exerciseName, user);
    if (exercise == NULL) {
        printf("Exercise %s not found for user %s!\n", exerciseName, user->name);
        return;
    }

    int caloriesBurned = exercise->caloriesBurnedPerMinute * durationInMinutes;
    printf("%d calories burned during %d minutes of %s for user %s!\n", caloriesBurned, durationInMinutes, exerciseName, user->name);
    strcpy(workouts[numWorkouts].exerciseName, exerciseName);
    workouts[numWorkouts].durationInMinutes = durationInMinutes;
    workouts[numWorkouts].caloriesBurned = caloriesBurned;
    numWorkouts++;
}

void printAllWorkouts() {
    printf("All workouts:\n");
    int i;
    for (i = 0; i < numWorkouts; i++) {
        printf("%d. %s for %d minutes, %d calories burned\n", i+1, workouts[i].exerciseName, workouts[i].durationInMinutes, workouts[i].caloriesBurned);
    }
}

void printAllExercises() {
    printf("All exercises:\n");
    int i;
    for (i = 0; i < numUsers; i++) {
        printf("%s's exercises:\n", users[i].name);
        int j;
        for (j = 0; j < users[i].numExercises; j++) {
            printf("\t%s (%d cals/min)\n", users[i].exercises[j].name, users[i].exercises[j].caloriesBurnedPerMinute);
        }
    }
}

void printUserWorkouts() {
    printf("Enter user name: ");
    char username[50];
    scanf("%s", username);

    struct User *user = NULL;
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, username) == 0) {
            user = &users[i];
            break;
        }
    }

    if (user == NULL) {
        printf("User %s not found!\n", username);
        return;
    }

    printf("%s's workouts:\n", user->name);
    int numUserWorkouts = 0;
    for (i = 0; i < numWorkouts; i++) {
        if (strcmp(workouts[i].exerciseName, "") != 0 && strcmp(workouts[i].exerciseName, "") != NULL && strcmp(username, "") != 0 && strcmp(username, "") != NULL) {
            if (strcmp(workouts[i].exerciseName, "") != 0 && strcmp(workouts[i].exerciseName, "") != NULL && strcmp(users[i].name, "") != 0 && strcmp(users[i].name, "") != NULL && strcmp(workouts[i].exerciseName, "") != 0 && strcmp(workouts[i].exerciseName, "") != NULL) {
                if (strcmp(workouts[i].exerciseName, "") != 0 && strcmp(workouts[i].exerciseName, "") != NULL && strcmp(workouts[i].exerciseName, "") != 0 && strcmp(workouts[i].exerciseName, "") != NULL) {
                    if (strcmp(users[i].name, username) == 0) {
                        printf("- %s for %d minutes, %d calories burned\n", workouts[i].exerciseName, workouts[i].durationInMinutes, workouts[i].caloriesBurned);
                        numUserWorkouts++;
                    }
                }
            }
        }
    }
    if (numUserWorkouts == 0) {
        printf("No workouts found for user %s!\n", user->name);
    }
}

int main() {
    int command = -1;

    while (command != 0) {
        printf("\nCommand List:\n");
        printf("1. Add a user\n");
        printf("2. Add an exercise to a user\n");
        printf("3. Add a workout\n");
        printf("4. Print all workouts\n");
        printf("5. Print all exercises\n");
        printf("6. Print a user's workouts\n");
        printf("0. Exit\n");

        printf("Enter command: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                addUser();
                break;
            case 2:
                addExercise();
                break;
            case 3:
                addWorkout();
                break;
            case 4:
                printAllWorkouts();
                break;
            case 5:
                printAllExercises();
                break;
            case 6:
                printUserWorkouts();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}