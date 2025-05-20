//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // duration in minutes
    int calorieBurn; // calories burned
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int exerciseCount;
} FitnessTracker;

void addExercise(FitnessTracker *tracker) {
    if (tracker->exerciseCount >= MAX_EXERCISES) {
        printf("Can't add more exercises. Limit reached!\n");
        return;
    }

    Exercise newExercise;
    printf("Enter exercise name: ");
    scanf("%s", newExercise.name);
    printf("Enter duration in minutes: ");
    scanf("%d", &newExercise.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newExercise.calorieBurn);

    tracker->exercises[tracker->exerciseCount++] = newExercise;
    printf("Exercise added: %s | Duration: %d minutes | Calories: %d\n",
           newExercise.name,
           newExercise.duration,
           newExercise.calorieBurn);
}

void viewExercises(const FitnessTracker *tracker) {
    if (tracker->exerciseCount == 0) {
        printf("No exercises recorded yet.\n");
        return;
    }

    printf("Recorded Exercises:\n");
    for (int i = 0; i < tracker->exerciseCount; i++) {
        printf("%d. %s | Duration: %d minutes | Calories: %d\n",
               i + 1,
               tracker->exercises[i].name,
               tracker->exercises[i].duration,
               tracker->exercises[i].calorieBurn);
    }
}

void calculateCalories(const FitnessTracker *tracker) {
    int totalCalories = 0;
    for (int i = 0; i < tracker->exerciseCount; i++) {
        totalCalories += tracker->exercises[i].calorieBurn;
    }
    printf("Total calories burned: %d\n", totalCalories);
}

void deleteExercise(FitnessTracker *tracker) {
    if (tracker->exerciseCount == 0) {
        printf("No exercises to delete.\n");
        return;
    }

    viewExercises(tracker);
    printf("Enter the number of the exercise to delete: ");
    int number;
    scanf("%d", &number);

    if (number < 1 || number > tracker->exerciseCount) {
        printf("Invalid exercise number.\n");
        return;
    }

    for (int i = number - 1; i < tracker->exerciseCount - 1; i++) {
        tracker->exercises[i] = tracker->exercises[i + 1];
    }
    tracker->exerciseCount--;
    printf("Exercise deleted successfully!\n");
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Exercise\n");
    printf("2. View Exercises\n");
    printf("3. Calculate Calories Burned\n");
    printf("4. Delete Exercise\n");
    printf("5. Exit\n");
}

int main() {
    FitnessTracker tracker;
    tracker.exerciseCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                viewExercises(&tracker);
                break;
            case 3:
                calculateCalories(&tracker);
                break;
            case 4:
                deleteExercise(&tracker);
                break;
            case 5:
                printf("Exiting Fitness Tracker. Stay fit!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}