//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

typedef struct {
    char name[50];
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
} Workout;

void add_exercise(Workout* workout) {
    printf("Enter exercise name: ");
    scanf("%s", workout->exercises[workout->num_exercises].name);
    printf("Enter exercise duration (in seconds): ");
    scanf("%d", &workout->exercises[workout->num_exercises].duration);
    printf("Enter exercise calories burned: ");
    scanf("%d", &workout->exercises[workout->num_exercises].calories);
    workout->num_exercises++;
}

void display_workout(Workout* workout) {
    printf("Workout name: %s\n", workout->name);
    printf("Number of exercises: %d\n", workout->num_exercises);
    for (int i = 0; i < workout->num_exercises; i++) {
        printf("Exercise %d:\n", i+1);
        printf("Name: %s\n", workout->exercises[i].name);
        printf("Duration: %d seconds\n", workout->exercises[i].duration);
        printf("Calories burned: %d\n\n", workout->exercises[i].calories);
    }
}

void start_workout(Workout* workout) {
    time_t start_time;
    time(&start_time);
    for (int i = 0; i < workout->num_exercises; i++) {
        printf("Starting exercise %s...\n", workout->exercises[i].name);
        sleep(workout->exercises[i].duration);
        printf("Finished exercise %s.\n", workout->exercises[i].name);
    }
    time_t end_time;
    time(&end_time);
    int workout_duration = difftime(end_time, start_time);
    printf("Total workout duration: %d seconds\n", workout_duration);
}

int main() {
    Workout workout;
    printf("Enter workout name: ");
    scanf("%s", workout.name);
    int num_exercises = 0;
    while (num_exercises < MAX_EXERCISES && num_exercises < workout.num_exercises) {
        add_exercise(&workout);
        num_exercises = workout.num_exercises;
    }
    display_workout(&workout);
    start_workout(&workout);
    return 0;
}