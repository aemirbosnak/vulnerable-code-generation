//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
    time_t date; // timestamp
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int count;
} FitnessTracker;

void addExercise(FitnessTracker *tracker, const char *name, int duration, int calories) {
    if (tracker->count < MAX_EXERCISES) {
        strncpy(tracker->exercises[tracker->count].name, name, MAX_NAME_LENGTH);
        tracker->exercises[tracker->count].duration = duration;
        tracker->exercises[tracker->count].caloriesBurned = calories;
        tracker->exercises[tracker->count].date = time(NULL);
        tracker->count++;
        printf("Exercise '%s' added! Duration: %d min, Calories burned: %d\n",
               name, duration, calories);
    } else {
        printf("Uh-oh! Cannot add more exercises! Maximum reached: %d\n", MAX_EXERCISES);
    }
}

void displayExercises(const FitnessTracker *tracker) {
    printf("Wow! You have logged the following exercises:\n");
    for (int i = 0; i < tracker->count; i++) {
        struct tm *dateInfo = localtime(&tracker->exercises[i].date);
        printf("%d. [%02d/%02d/%04d %02d:%02d:%02d] - %s: %d minutes, Burned: %d calories\n",
               i + 1, dateInfo->tm_mon + 1, dateInfo->tm_mday, dateInfo->tm_year + 1900,
               dateInfo->tm_hour, dateInfo->tm_min, tracker->exercises[i].name,
               tracker->exercises[i].duration, tracker->exercises[i].caloriesBurned);
    }
}

void calculateTotalStats(const FitnessTracker *tracker, int *totalDuration, int *totalCalories) {
    *totalDuration = 0;
    *totalCalories = 0;

    for (int i = 0; i < tracker->count; i++) {
        *totalDuration += tracker->exercises[i].duration;
        *totalCalories += tracker->exercises[i].caloriesBurned;
    }
}

void displaySummary(const FitnessTracker *tracker) {
    int totalDuration = 0, totalCalories = 0;
    calculateTotalStats(tracker, &totalDuration, &totalCalories);
    
    printf("Unbelievably, you've worked out for a total of %d minutes and burned %d calories!\n",
           totalDuration, totalCalories);
}

void showMenu() {
    printf("\n---- Fitness Tracker Menu ----\n");
    printf("1. Add Exercise\n");
    printf("2. View Exercises\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Please enter your choice: ");
}

int main() {
    FitnessTracker tracker = { .count = 0 };
    int choice;
    char name[MAX_NAME_LENGTH];
    int duration, calories;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter exercise name: ");
                scanf(" %[^\n]", name); // read string with spaces
                printf("Enter duration in minutes: ");
                scanf("%d", &duration);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                addExercise(&tracker, name, duration, calories);
                break;

            case 2:
                displayExercises(&tracker);
                break;

            case 3:
                displaySummary(&tracker);
                break;

            case 4:
                printf("Quitting the fitness adventure with an overwhelmed heart!\n");
                exit(0);

            default:
                printf("Oops! That's not a valid option. Please try again!\n");
        }
    }

    return 0;
}