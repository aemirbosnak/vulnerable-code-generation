//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 10
#define MAX_REPS 100
#define MAX_SETS 10
#define MAX_DURATION 1000
#define MAX_DISTANCE 1000
#define MAX_CALORIES 10000
#define MAX_NOTES_LENGTH 100

typedef struct {
    char name[MAX_NOTES_LENGTH];
    time_t timestamp;
    int duration;
    int distance;
    int calories;
} Workout;

typedef struct {
    char name[MAX_NOTES_LENGTH];
    int reps;
    int sets;
} Exercise;

int main() {
    char username[MAX_NOTES_LENGTH];
    printf("Enter your name: ");
    scanf("%s", username);

    FILE *workout_file = fopen("workouts.txt", "a");
    if (workout_file == NULL) {
        printf("Error opening workouts file.\n");
        return 1;
    }

    fprintf(workout_file, "User: %s\n", username);

    int num_workouts = 0;
    while (num_workouts < MAX_WORKOUTS) {
        Workout workout;
        strcpy(workout.name, "");
        workout.timestamp = time(NULL);
        workout.duration = 0;
        workout.distance = 0;
        workout.calories = 0;

        int num_exercises = 0;
        while (num_exercises < MAX_EXERCISES) {
            Exercise exercise;
            strcpy(exercise.name, "");
            exercise.reps = 0;
            exercise.sets = 0;

            printf("Enter exercise name: ");
            scanf("%s", exercise.name);

            printf("Enter reps: ");
            scanf("%d", &exercise.reps);

            printf("Enter sets: ");
            scanf("%d", &exercise.sets);

            strcat(workout.name, exercise.name);
            strcat(workout.name, ", ");

            workout.duration += exercise.reps * exercise.sets;
            workout.distance += (int)(exercise.reps * exercise.sets * 50); // assuming each rep is 50 meters
            workout.calories += (int)(exercise.reps * exercise.sets * 5); // assuming each rep burns 5 calories

            num_exercises++;
        }

        fprintf(workout_file, "Workout: %s\n", workout.name);
        fprintf(workout_file, "Duration: %d seconds\n", workout.duration);
        fprintf(workout_file, "Distance: %d meters\n", workout.distance);
        fprintf(workout_file, "Calories burned: %d\n\n", workout.calories);

        num_workouts++;
    }

    fclose(workout_file);

    return 0;
}