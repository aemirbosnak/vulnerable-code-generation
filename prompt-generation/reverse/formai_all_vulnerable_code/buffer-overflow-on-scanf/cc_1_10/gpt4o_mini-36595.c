//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define TIP_COUNT 5

typedef struct {
    char date[11];
    char activity[30];
    int duration; // in minutes
    int caloriesBurned;
    int steps;
} WorkoutEntry;

void displayTips();
void addWorkoutEntry(WorkoutEntry entries[], int *count);
void viewWorkoutEntries(const WorkoutEntry entries[], int count);
void calculateStats(const WorkoutEntry entries[], int count);

int main() {
    WorkoutEntry workoutEntries[MAX_ENTRIES];
    int entryCount = 0;
    int choice;

    printf("Welcome to the Surprise Fitness Tracker!\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Add Workout Entry\n");
        printf("2. View Workout Entries\n");
        printf("3. Calculate Statistics\n");
        printf("4. Surprise Fitness Tips\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkoutEntry(workoutEntries, &entryCount);
                break;
            case 2:
                viewWorkoutEntries(workoutEntries, entryCount);
                break;
            case 3:
                calculateStats(workoutEntries, entryCount);
                break;
            case 4:
                displayTips();
                break;
            case 5:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayTips() {
    const char *tips[TIP_COUNT] = {
        "Drink more water! Hydration is the key to fitness.",
        "Remember to stretch before and after exercises.",
        "A balanced diet supplements your workouts!",
        "Mix cardio with weight training for best results.",
        "Set realistic goals and track your progress!"
    };

    srand(time(0)); // Seed the random number generator
    int randomIndex = rand() % TIP_COUNT;

    printf("Surprise Fitness Tip: %s\n", tips[randomIndex]);
}

void addWorkoutEntry(WorkoutEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Workout entry limit reached! Cannot add more.\n");
        return;
    }

    WorkoutEntry newEntry;
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", newEntry.date);
    printf("Enter the activity (e.g., Running, Cycling): ");
    scanf("%s", newEntry.activity);
    printf("Enter the duration (in minutes): ");
    scanf("%d", &newEntry.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newEntry.caloriesBurned);
    printf("Enter steps taken: ");
    scanf("%d", &newEntry.steps);

    entries[*count] = newEntry;
    (*count)++;
    printf("Workout entry added successfully!\n");
}

void viewWorkoutEntries(const WorkoutEntry entries[], int count) {
    if (count == 0) {
        printf("No workout entries to display.\n");
        return;
    }

    printf("\nWorkout Entries:\n");
    printf("--------------------------------------------------------\n");
    printf("| Date       | Activity       | Duration | Calories | Steps |\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-10s | %-14s | %-8d | %-8d | %-5d |\n",
               entries[i].date, entries[i].activity, 
               entries[i].duration, entries[i].caloriesBurned, 
               entries[i].steps);
    }
    printf("--------------------------------------------------------\n");
}

void calculateStats(const WorkoutEntry entries[], int count) {
    if (count == 0) {
        printf("No workout entries to calculate statistics.\n");
        return;
    }

    int totalDuration = 0;
    int totalCalories = 0;
    int totalSteps = 0;

    for (int i = 0; i < count; i++) {
        totalDuration += entries[i].duration;
        totalCalories += entries[i].caloriesBurned;
        totalSteps += entries[i].steps;
    }

    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %d calories\n", totalCalories);
    printf("Total Steps Taken: %d steps\n", totalSteps);
}