//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXERCISES 50
#define MAX_EXERCISE_NAME_LENGTH 50
#define MAX_EXERCISE_DURATION_LENGTH 10
#define MAX_EXERCISE_CALORIES_LENGTH 10

typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int duration;
    int calories;
} Exercise;

int main() {
    int numExercises = 0;
    Exercise exercises[MAX_EXERCISES];

    while (numExercises < MAX_EXERCISES) {
        printf("Enter the name of an exercise (or 'q' to quit): ");
        scanf("%s", exercises[numExercises].name);

        if (strcmp(exercises[numExercises].name, "q") == 0) {
            break;
        }

        printf("Enter the duration of %s in minutes: ", exercises[numExercises].name);
        scanf("%d", &exercises[numExercises].duration);

        printf("Enter the number of calories burned during %s: ", exercises[numExercises].name);
        scanf("%d", &exercises[numExercises].calories);

        numExercises++;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    char date[10];
    scanf("%s", date);

    FILE *fp = fopen("fitness_log.txt", "a");

    fprintf(fp, "Fitness Log for %s:\n", date);

    for (int i = 0; i < numExercises; i++) {
        fprintf(fp, "%s - Duration: %d minutes, Calories burned: %d\n", exercises[i].name, exercises[i].duration, exercises[i].calories);
    }

    fclose(fp);

    return 0;
}