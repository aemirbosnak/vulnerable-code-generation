//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 30
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration;
    time_t start_time;
    time_t end_time;
    char date[MAX_DATE_LENGTH];
} Exercise;

void add_exercise(Exercise *exercises, int num_exercises) {
    printf("Enter the name of the exercise: ");
    scanf("%s", exercises[num_exercises].name);
    printf("Enter the duration of the exercise in seconds: ");
    scanf("%d", &exercises[num_exercises].duration);
    exercises[num_exercises].start_time = time(NULL);
    strftime(exercises[num_exercises].date, MAX_DATE_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&exercises[num_exercises].start_time));
}

void display_exercises(Exercise *exercises, int num_exercises) {
    printf("\nExercise Log\n");
    printf("--------------------\n");
    printf("Name\tDuration\tStart Time\tEnd Time\tDate\n");
    for (int i = 0; i < num_exercises; i++) {
        printf("%s\t%d\t%s\t%s\t%s\n", exercises[i].name, exercises[i].duration, ctime(&exercises[i].start_time), ctime(&exercises[i].end_time), exercises[i].date);
    }
}

int main() {
    Exercise exercises[MAX_EXERCISES];
    int num_exercises = 0;

    while (num_exercises < MAX_EXERCISES) {
        int choice;
        printf("\nChoose an option:\n");
        printf("1. Add exercise\n2. Display exercise log\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_exercise(exercises, num_exercises);
                num_exercises++;
                break;
            case 2:
                display_exercises(exercises, num_exercises);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}