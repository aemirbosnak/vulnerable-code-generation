//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORKOUTS 10

typedef struct {
    char name[50];
    int duration;
    int calories;
} workout;

typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
} user;

void addWorkout(workout* workouts, int size, char name[50], int duration, int calories) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(workouts[i].name, name) == 0) {
            workouts[i].duration += duration;
            workouts[i].calories += calories;
            return;
        }
    }
    strcpy(workouts[size].name, name);
    workouts[size].duration = duration;
    workouts[size].calories = calories;
    size++;
}

void printWorkouts(workout* workouts, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s: %d minutes, %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

int main() {
    workout workouts[MAX_WORKOUTS];
    user user;

    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your weight in pounds: ");
    scanf("%d", &user.weight);

    printf("Enter your height in inches: ");
    scanf("%d", &user.height);

    int i;
    for (i = 0; i < MAX_WORKOUTS; i++) {
        char name[50];
        printf("Enter workout %d name: ", i+1);
        scanf("%s", name);
        printf("Enter workout %d duration in minutes: ", i+1);
        scanf("%d", &workouts[i].duration);
        printf("Enter workout %d calories burned: ", i+1);
        scanf("%d", &workouts[i].calories);
        addWorkout(workouts, i, name, workouts[i].duration, workouts[i].calories);
    }

    int totalCalories = 0;
    int totalMinutes = 0;

    for (i = 0; i < MAX_WORKOUTS; i++) {
        totalCalories += workouts[i].calories;
        totalMinutes += workouts[i].duration;
    }

    printf("\nTotal calories burned: %d\n", totalCalories);
    printf("Total workout time: %d minutes\n", totalMinutes);

    return 0;
}