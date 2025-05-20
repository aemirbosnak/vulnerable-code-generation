//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_LENGTH 50

typedef struct {
    char type[MAX_LENGTH];
    int duration; // in minutes
    int calories_burned;
    time_t date; // timestamp to track when the workout was done
} Workout;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    int count;
} FitnessTracker;

FitnessTracker tracker;

void initializeTracker() {
    tracker.count = 0;
}

void paranoidUserPrompt(const char* message) {
    printf("%s\n", message);
    printf("Press Enter to continue... ");
    while(getchar() != '\n'); // wait for Enter
}

void addWorkout() {
    if (tracker.count >= MAX_WORKOUTS) {
        printf("Error: Maximum workouts reached!\n");
        return;
    }
    
    Workout newWorkout;
    printf("Enter workout type (e.g., running, cycling): ");
    fgets(newWorkout.type, MAX_LENGTH, stdin);
    newWorkout.type[strcspn(newWorkout.type, "\n")] = 0; // remove newline

    printf("Enter duration in minutes: ");
    scanf("%d", &newWorkout.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.calories_burned);
    newWorkout.date = time(NULL); // current time

    tracker.workouts[tracker.count++] = newWorkout;
    paranoidUserPrompt("Workout added successfully!");
}

void viewWorkouts() {
    if (tracker.count == 0) {
        printf("No workouts recorded yet. Are you even exercising?!\n");
        return;
    }
    
    printf("\nYour Workouts:\n");
    for (int i = 0; i < tracker.count; i++) {
        struct tm * workout_time = localtime(&tracker.workouts[i].date);
        printf("Workout %d: %s, Duration: %d minutes, Calories burned: %d, Date: %s",
               i + 1, tracker.workouts[i].type,
               tracker.workouts[i].duration, tracker.workouts[i].calories_burned,
               asctime(workout_time));
    }
    paranoidUserPrompt("End of workout list. Are you sure you’ve recorded them all?");
}

void totalCalories() {
    int total = 0;
    for (int i = 0; i < tracker.count; i++) {
        total += tracker.workouts[i].calories_burned;
    }
    printf("Total calories burned: %d\n", total);
    paranoidUserPrompt("Keep burning those calories! The world is watching!");
}

void clearWorkouts() {
    if (tracker.count == 0) {
        printf("Nothing to clear, or are you just pretending to exercise?\n");
        return;
    }
    
    tracker.count = 0;
    paranoidUserPrompt("All workouts cleared. Did you even record any?");
}

void menu() {
    int choice;
    do {
        printf("\nFitness Tracker Menu\n");
        printf("1. Add Workout\n");
        printf("2. View Workouts\n");
        printf("3. Total Calories\n");
        printf("4. Clear Workouts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // consume newline character

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                viewWorkouts();
                break;
            case 3:
                totalCalories();
                break;
            case 4:
                clearWorkouts();
                break;
            case 5:
                printf("Exiting... Or am I just hiding? Beware!\n");
                break;
            default:
                printf("Invalid choice! Are you trying to fool me?\n");
        }
    } while (choice != 5);
}

int main() {
    initializeTracker();
    paranoidUserPrompt("Welcome to Your Paranoid Fitness Tracker! Let’s begin...");
    menu();
    return 0;
}