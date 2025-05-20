//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 20
#define MAX_REPS 100
#define MAX_SETS 10
#define MAX_DURATION 3600

typedef struct {
    char name[50];
    int calories;
} Workout;

typedef struct {
    char name[50];
    int reps;
    int sets;
    int duration;
    int calories;
} Exercise;

Workout workouts[MAX_WORKOUTS];
Exercise exercises[MAX_EXERCISES];
int num_workouts = 0;
int num_exercises = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);
    num_workouts++;
}

void add_exercise() {
    printf("Enter exercise name: ");
    scanf("%s", exercises[num_exercises].name);
    printf("Enter reps: ");
    scanf("%d", &exercises[num_exercises].reps);
    printf("Enter sets: ");
    scanf("%d", &exercises[num_exercises].sets);
    printf("Enter duration (in seconds): ");
    scanf("%d", &exercises[num_exercises].duration);
    exercises[num_exercises].calories = (int) ((double) exercises[num_exercises].reps * exercises[num_exercises].sets * exercises[num_exercises].duration / (60 * 3600)) * 8;
    num_exercises++;
}

void display_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s: %d calories\n", workouts[i].name, workouts[i].calories);
    }
}

void display_exercises() {
    printf("Exercises:\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s: %d calories\n", exercises[i].name, exercises[i].calories);
    }
}

int main() {
    srand(time(NULL));
    add_workout();
    add_exercise();
    display_workouts();
    display_exercises();
    return 0;
}