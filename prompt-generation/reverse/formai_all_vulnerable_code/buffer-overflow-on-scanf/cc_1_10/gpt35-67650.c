//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 50

// Define structures
struct exercise {
    char name[MAX_NAME_LENGTH];
    int sets;
    int reps;
    int weight;
};

struct workout {
    int day;
    int month;
    int year;
    int num_exercises;
    struct exercise exercises[MAX_EXERCISES];
};

// Function prototypes
void add_workout(struct workout *workouts, int *num_workouts);
void view_workouts(struct workout *workouts, int num_workouts);
void view_exercises(struct workout *workouts, int num_workouts);
void view_stats(struct workout *workouts, int num_workouts);

// Global variables
struct workout workouts[MAX_EXERCISES];
int num_workouts = 0;

int main() {
    int choice;
    do {
        printf("\n\n");
        printf("------------------------------------------------\n");
        printf(" Fitness Tracker\n");
        printf("------------------------------------------------\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. View exercises\n");
        printf("4. View statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_workout(workouts, &num_workouts);
                break;
            case 2:
                view_workouts(workouts, num_workouts);
                break;
            case 3:
                view_exercises(workouts, num_workouts);
                break;
            case 4:
                view_stats(workouts, num_workouts);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void add_workout(struct workout *workouts, int *num_workouts) {
    int i, j;
    struct workout w;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &w.day, &w.month, &w.year);
    printf("Enter number of exercises: ");
    scanf("%d", &w.num_exercises);
    for (i = 0; i < w.num_exercises; i++) {
        printf("Enter exercise name: ");
        scanf("%s", w.exercises[i].name);
        printf("Enter number of sets: ");
        scanf("%d", &w.exercises[i].sets);
        printf("Enter number of reps: ");
        scanf("%d", &w.exercises[i].reps);
        printf("Enter weight: ");
        scanf("%d", &w.exercises[i].weight);
    }
    workouts[*num_workouts] = w;
    (*num_workouts)++;
}

void view_workouts(struct workout *workouts, int num_workouts) {
    int i, j;
    printf("Workouts\n");
    printf("------------------------------------\n");
    for (i = 0; i < num_workouts; i++) {
        printf("%d/%d/%d\n", workouts[i].day, workouts[i].month, workouts[i].year);
        printf("Exercises\n");
        printf("------------------------------------\n");
        for (j = 0; j < workouts[i].num_exercises; j++) {
            printf("%s:\t%d sets x %d reps x %d kg\n", workouts[i].exercises[j].name, workouts[i].exercises[j].sets, workouts[i].exercises[j].reps, workouts[i].exercises[j].weight);
        }
        printf("\n");
    }
}

void view_exercises(struct workout *workouts, int num_workouts) {
    int i, j, k;
    struct exercise *exercises;
    int num_exercises = 0;
    printf("Exercises\n");
    printf("------------------------------------\n");
    for (i = 0; i < num_workouts; i++) {
        for (j = 0; j < workouts[i].num_exercises; j++) {
            int exists = 0;
            for (k = 0; k < num_exercises; k++) {
                if (strcmp(workouts[i].exercises[j].name, exercises[k].name) == 0) {
                    exercises[k].sets += workouts[i].exercises[j].sets;
                    exercises[k].reps += workouts[i].exercises[j].reps;
                    exercises[k].weight += workouts[i].exercises[j].weight;
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                struct exercise e;
                strcpy(e.name, workouts[i].exercises[j].name);
                e.sets = workouts[i].exercises[j].sets;
                e.reps = workouts[i].exercises[j].reps;
                e.weight = workouts[i].exercises[j].weight;
                exercises[num_exercises] = e;
                num_exercises++;
            }
        }
    }

    // Display exercises
    for (i = 0; i < num_exercises; i++) {
        printf("%s:\t%d sets x %d reps x %d kg\n", exercises[i].name, exercises[i].sets, exercises[i].reps, exercises[i].weight);
    }
}

void view_stats(struct workout *workouts, int num_workouts) {
    int i, j;
    int sets = 0, reps = 0, weight = 0;
    for (i = 0; i < num_workouts; i++) {
        for (j = 0; j < workouts[i].num_exercises; j++) {
            sets += workouts[i].exercises[j].sets;
            reps += workouts[i].exercises[j].reps;
            weight += workouts[i].exercises[j].weight;
        }
    }

    printf("Total workouts: %d\n", num_workouts);
    printf("Total exercises: %d\n", sets);
    printf("Total reps: %d\n", reps);
    printf("Total weight: %d kg\n", weight);
}