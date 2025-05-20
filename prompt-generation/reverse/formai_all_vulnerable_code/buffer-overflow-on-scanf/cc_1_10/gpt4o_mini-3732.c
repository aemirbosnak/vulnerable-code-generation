//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int duration;  // in minutes
    int calories;  // calories burned
} Exercise;

void addExercise(Exercise exercises[], int *count) {
    if (*count >= MAX_EXERCISES) {
        printf("Cannot add more exercises, limit reached.\n");
        return;
    }
    printf("Enter exercise name: ");
    scanf("%s", exercises[*count].name);
    printf("Enter duration in minutes: ");
    scanf("%d", &exercises[*count].duration);
    printf("Enter calories burned: ");
    scanf("%d", &exercises[*count].calories);
    (*count)++;
}

void viewExercises(const Exercise exercises[], int count) {
    if (count == 0) {
        printf("No exercises recorded.\n");
        return;
    }

    printf("Your Exercises:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Duration: %d mins, Calories burned: %d\n", i + 1, exercises[i].name, exercises[i].duration, exercises[i].calories);
    }
}

void dailySummary(const Exercise exercises[], int count) {
    if (count == 0) {
        printf("No exercises recorded for today's summary.\n");
        return;
    }

    int totalCalories = 0;
    int totalTime = 0;
    for (int i = 0; i < count; i++) {
        totalCalories += exercises[i].calories;
        totalTime += exercises[i].duration;
    }

    printf("Daily Summary:\n");
    printf("Total Time Exercised: %d minutes\n", totalTime);
    printf("Total Calories Burned: %d calories\n", totalCalories);
}

int main() {
    Exercise exercises[MAX_EXERCISES];
    int exerciseCount = 0;
    int choice;

    while (1) {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Add New Exercise\n");
        printf("2. View Exercises\n");
        printf("3. Daily Summary\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addExercise(exercises, &exerciseCount);
                break;
            case 2:
                viewExercises(exercises, exerciseCount);
                break;
            case 3:
                dailySummary(exercises, exerciseCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}