//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORKOUTS 5
#define NUM_EXERCISES 10
#define NUM_WEEKS 12

typedef struct {
    char name[50];
    int reps;
    int sets;
} Exercise;

typedef struct {
    char name[50];
    Exercise exercises[NUM_EXERCISES];
} Workout;

typedef struct {
    char name[50];
    Workout workouts[NUM_WORKOUTS];
} Program;

int main() {
    Program program;
    int i, j, k;
    char input[100];

    // Initialize program name
    printf("Enter program name: ");
    scanf("%s", program.name);

    // Initialize workouts
    for (i = 0; i < NUM_WORKOUTS; i++) {
        printf("Enter workout %d name: ", i+1);
        scanf("%s", program.workouts[i].name);
        for (j = 0; j < NUM_EXERCISES; j++) {
            printf("Enter exercise %d name: ", j+1);
            scanf("%s", program.workouts[i].exercises[j].name);
            printf("Enter reps: ");
            scanf("%d", &program.workouts[i].exercises[j].reps);
            printf("Enter sets: ");
            scanf("%d", &program.workouts[i].exercises[j].sets);
        }
    }

    // Initialize weeks
    for (i = 0; i < NUM_WEEKS; i++) {
        printf("Week %d:\n", i+1);
        for (j = 0; j < NUM_WORKOUTS; j++) {
            printf("Workout %d:\n", j+1);
            for (k = 0; k < NUM_EXERCISES; k++) {
                printf("%s - %d reps x %d sets\n", program.workouts[j].exercises[k].name, program.workouts[j].exercises[k].reps, program.workouts[j].exercises[k].sets);
            }
        }
    }

    return 0;
}