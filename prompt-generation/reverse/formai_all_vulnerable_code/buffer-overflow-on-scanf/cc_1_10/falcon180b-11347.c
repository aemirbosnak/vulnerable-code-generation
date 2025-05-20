//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXERCISES 10
#define MAX_EXERCISE_NAME_LENGTH 50
#define MAX_EXERCISE_DURATION 24

typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int duration;
} Exercise;

int main() {
    int numExercises = 0;
    Exercise exercises[MAX_EXERCISES];
    char input[MAX_EXERCISE_NAME_LENGTH];
    int duration;
    int i;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Enter the number of exercises you want to track (up to %d): ", MAX_EXERCISES);
    scanf("%d", &numExercises);

    for (i = 0; i < numExercises; i++) {
        printf("Enter the name of exercise %d: ", i+1);
        scanf("%s", exercises[i].name);
        printf("Enter the duration of exercise %d (in minutes): ", i+1);
        scanf("%d", &exercises[i].duration);
    }

    printf("Enter the name of the exercise you want to track: ");
    scanf("%s", input);

    for (i = 0; i < numExercises; i++) {
        if (strcmp(input, exercises[i].name) == 0) {
            duration = exercises[i].duration;
            break;
        }
    }

    if (i == numExercises) {
        printf("Exercise not found.\n");
        return 0;
    }

    printf("You have tracked %d minutes of %s.\n", duration, input);
    return 0;
}