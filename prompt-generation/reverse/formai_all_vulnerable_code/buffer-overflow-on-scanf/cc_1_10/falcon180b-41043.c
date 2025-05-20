//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 10

typedef struct {
    char name[50];
    int duration;
    int calories_burned;
    int heart_rate;
} Workout;

typedef struct {
    char name[50];
    int duration;
    int calories_burned;
    int heart_rate;
} Exercise;

void add_workout(Workout *workout) {
    FILE *fp = fopen("workouts.txt", "a");
    fprintf(fp, "Workout Name: %s\n", workout->name);
    fprintf(fp, "Duration: %d minutes\n", workout->duration);
    fprintf(fp, "Calories Burned: %d\n", workout->calories_burned);
    fprintf(fp, "Heart Rate: %d bpm\n\n", workout->heart_rate);
    fclose(fp);
}

void add_exercise(Exercise *exercise) {
    FILE *fp = fopen("exercises.txt", "a");
    fprintf(fp, "Exercise Name: %s\n", exercise->name);
    fprintf(fp, "Duration: %d minutes\n", exercise->duration);
    fprintf(fp, "Calories Burned: %d\n", exercise->calories_burned);
    fprintf(fp, "Heart Rate: %d bpm\n\n", exercise->heart_rate);
    fclose(fp);
}

int main() {
    int choice = 0;
    while (choice!= 4) {
        printf("1. Start Workout\n");
        printf("2. End Workout\n");
        printf("3. Add Exercise\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Start Workout
                break;
            case 2:
                // End Workout
                break;
            case 3:
                // Add Exercise
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}