//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float duration; // duration in hours
    float caloriesBurned; // calories burned
    float distance; // distance covered in km
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int count; // number of exercises recorded
} FitnessTracker;

// Function prototypes
void addExercise(FitnessTracker *tracker);
void viewExercises(const FitnessTracker *tracker);
void calculateTotalCalories(const FitnessTracker *tracker);
void calculateTotalDistance(const FitnessTracker *tracker);
void clearInputs();

int main() {
    FitnessTracker tracker = {.count = 0};
    int choice;

    do {
        printf("\n--- Fitness Tracker ---\n");
        printf("1. Add Exercise\n");
        printf("2. View Exercises\n");
        printf("3. Calculate Total Calories Burned\n");
        printf("4. Calculate Total Distance Covered\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputs(); // Clear the input buffer

        switch (choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                viewExercises(&tracker);
                break;
            case 3:
                calculateTotalCalories(&tracker);
                break;
            case 4:
                calculateTotalDistance(&tracker);
                break;
            case 5:
                printf("Exiting... Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void addExercise(FitnessTracker *tracker) {
    if (tracker->count >= MAX_EXERCISES) {
        printf("Cannot add more exercises. Max limit reached.\n");
        return;
    }

    Exercise newExercise;
    printf("Enter exercise name: ");
    fgets(newExercise.name, MAX_NAME_LENGTH, stdin);
    newExercise.name[strcspn(newExercise.name, "\n")] = '\0'; // Remove newline

    printf("Enter duration (in hours): ");
    scanf("%f", &newExercise.duration);

    printf("Enter calories burned: ");
    scanf("%f", &newExercise.caloriesBurned);

    printf("Enter distance covered (in km): ");
    scanf("%f", &newExercise.distance);
    clearInputs(); // Clear the input buffer

    tracker->exercises[tracker->count] = newExercise;
    tracker->count++;
    printf("Exercise added successfully!\n");
}

void viewExercises(const FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No exercises recorded yet.\n");
        return;
    }

    printf("\n--- Recorded Exercises ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Exercise %d:\n", i + 1);
        printf("  Name: %s\n", tracker->exercises[i].name);
        printf("  Duration: %.2f hours\n", tracker->exercises[i].duration);
        printf("  Calories Burned: %.2f\n", tracker->exercises[i].caloriesBurned);
        printf("  Distance: %.2f km\n", tracker->exercises[i].distance);
    }
}

void calculateTotalCalories(const FitnessTracker *tracker) {
    float totalCalories = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalCalories += tracker->exercises[i].caloriesBurned;
    }
    printf("Total Calories Burned: %.2f\n", totalCalories);
}

void calculateTotalDistance(const FitnessTracker *tracker) {
    float totalDistance = 0;
    for (int i = 0; i < tracker->count; i++) {
        totalDistance += tracker->exercises[i].distance;
    }
    printf("Total Distance Covered: %.2f km\n", totalDistance);
}

void clearInputs() {
    while (getchar() != '\n'); // Clear input buffer
}