//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_EXERCISE_NAME_LENGTH 50
#define MAX_EXERCISE_DURATION_MINUTES 120

typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int duration_minutes;
} Exercise;

Exercise exercises[MAX_EXERCISES];
int num_exercises;

void add_exercise(char* name, int duration_minutes) {
    if (num_exercises >= MAX_EXERCISES) {
        printf("Error: Maximum number of exercises reached.\n");
        return;
    }
    strcpy(exercises[num_exercises].name, name);
    exercises[num_exercises].duration_minutes = duration_minutes;
    num_exercises++;
}

void start_exercise(int exercise_index) {
    if (exercise_index < 0 || exercise_index >= num_exercises) {
        printf("Error: Invalid exercise index.\n");
        return;
    }
    printf("Starting exercise: %s\n", exercises[exercise_index].name);
    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < exercises[exercise_index].duration_minutes * 60) {
        // Do nothing, just wait for the exercise to finish
    }
    printf("Finished exercise: %s\n", exercises[exercise_index].name);
}

int main() {
    num_exercises = 0;
    add_exercise("Running", 30);
    add_exercise("Swimming", 45);
    add_exercise("Cycling", 60);

    int choice;
    while (1) {
        printf("1. Start exercise\n");
        printf("2. Add exercise\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter exercise index (0-2): ");
                scanf("%d", &choice);
                start_exercise(choice);
                break;
            case 2:
                printf("Enter exercise name: ");
                scanf("%s", exercises[num_exercises].name);
                printf("Enter exercise duration in minutes: ");
                scanf("%d", &exercises[num_exercises].duration_minutes);
                num_exercises++;
                break;
            case 3:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }
    return 0;
}