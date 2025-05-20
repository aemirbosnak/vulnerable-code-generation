//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_HISTORY 100

typedef struct {
    char name[30];
    int duration;  // duration in minutes
    int calories;  // calories burned
} Exercise;

typedef struct {
    char date[11];
    int total_duration;
    int total_calories;
    Exercise exercises[MAX_EXERCISES];
    int exercise_count;
} WorkoutHistory;

WorkoutHistory history[MAX_HISTORY];
int history_count = 0;

void display_menu() {
    printf("\n==============================\n");
    printf("       Fitness Tracker        \n");
    printf("==============================\n");
    printf("1. Log Workout\n");
    printf("2. View History\n");
    printf("3. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

void log_workout() {
    if (history_count >= MAX_HISTORY) {
        printf("Workout history is full!\n");
        return;
    }

    WorkoutHistory new_entry;
    new_entry.exercise_count = 0;
    new_entry.total_duration = 0;
    new_entry.total_calories = 0;

    // Get today's date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(new_entry.date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    printf("Logging workout for date: %s\n", new_entry.date);

    while (new_entry.exercise_count < MAX_EXERCISES) {
        Exercise exercise;
        printf("Enter exercise name (or 'stop' to finish): ");
        scanf(" %[^\n]s", exercise.name);
        if (strcmp(exercise.name, "stop") == 0) {
            break;
        }

        printf("Enter duration in minutes: ");
        scanf("%d", &exercise.duration);
        printf("Enter calories burned: ");
        scanf("%d", &exercise.calories);

        new_entry.exercises[new_entry.exercise_count] = exercise;
        new_entry.total_duration += exercise.duration;
        new_entry.total_calories += exercise.calories;
        new_entry.exercise_count++;
    }

    history[history_count++] = new_entry;
    printf("Workout logged successfully!\n");
}

void view_history() {
    if (history_count == 0) {
        printf("No workout history available.\n");
        return;
    }

    printf("\nWorkout History:\n");
    for (int i = 0; i < history_count; i++) {
        printf("Date: %s\n", history[i].date);
        printf("Total Duration: %d minutes\n", history[i].total_duration);
        printf("Total Calories: %d kcal\n", history[i].total_calories);
        printf("Exercises Done:\n");
        for (int j = 0; j < history[i].exercise_count; j++) {
            printf("  - %s: %d minutes, %d kcal\n", history[i].exercises[j].name, 
                    history[i].exercises[j].duration, history[i].exercises[j].calories);
        }
        printf("----------------------------\n");
    }
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                log_workout();
                break;
            case 2:
                view_history();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}