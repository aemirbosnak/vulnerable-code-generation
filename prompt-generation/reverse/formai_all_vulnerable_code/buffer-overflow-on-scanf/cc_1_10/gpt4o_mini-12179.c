//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISE_NAME 50

typedef struct {
    char name[MAX_EXERCISE_NAME];
    int duration; // in minutes
    float calories; // calories burned
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

void addWorkout(FitnessTracker *tracker) {
    if (tracker->count >= MAX_WORKOUTS) {
        printf("Workout limit reached, cannot add more!\n");
        return;
    }
    
    Workout newWorkout;
    printf("Enter Exercise Name: ");
    scanf(" %[^\n]", newWorkout.name);
    printf("Enter Duration (in minutes): ");
    scanf("%d", &newWorkout.duration);
    printf("Enter Calories Burned: ");
    scanf("%f", &newWorkout.calories);
    
    tracker->workouts[tracker->count] = newWorkout;
    tracker->count++;
    printf("Workout added successfully!\n");
}

void viewWorkouts(FitnessTracker *tracker) {
    if (tracker->count == 0) {
        printf("No workouts logged yet!\n");
        return;
    }

    printf("\n--- Workout Log ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Workout %d:\n", i + 1);
        printf("  Name: %s\n", tracker->workouts[i].name);
        printf("  Duration: %d minutes\n", tracker->workouts[i].duration);
        printf("  Calories Burned: %.2f kcal\n", tracker->workouts[i].calories);
        printf("\n");
    }
}

void calculateTotalStats(FitnessTracker *tracker) {
    int totalDuration = 0;
    float totalCalories = 0;
    
    for (int i = 0; i < tracker->count; i++) {
        totalDuration += tracker->workouts[i].duration;
        totalCalories += tracker->workouts[i].calories;
    }
    
    printf("\n--- Total Stats ---\n");
    printf("Total Duration: %d minutes\n", totalDuration);
    printf("Total Calories Burned: %.2f kcal\n", totalCalories);
}

void displayMenu() {
    printf("\n--- Fitness Tracker Menu ---\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Calculate Total Stats\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FitnessTracker tracker;
    tracker.count = 0; // Initializing the count of workouts

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                viewWorkouts(&tracker);
                break;
            case 3:
                calculateTotalStats(&tracker);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}