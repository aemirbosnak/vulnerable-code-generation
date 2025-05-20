//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for tracking data
#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

// Define the workout data structure
typedef struct {
    char exerciseName[MAX_NAME_LENGTH];
    int sets;
    int reps;
} WorkoutData;

// Define the workout session data structure
typedef struct {
    time_t startTime;
    time_t endTime;
    int numWorkouts;
    WorkoutData workouts[MAX_ENTRIES]; // use a fixed size array to store workout data
} WorkoutSession;

// Function to display menu and get user input
int displayMenu() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Record a workout\n");
    printf("2. View workout history\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a workout to the session
void recordWorkout(WorkoutData *workoutData, int *numWorkouts) {
    if (*numWorkouts >= MAX_ENTRIES) {
        printf("Maximum number of workouts reached.\n");
        return;
    }
    printf("Enter exercise name: ");
    scanf("%s", workoutData[*numWorkouts].exerciseName);
    printf("Enter number of sets: ");
    scanf("%d", &workoutData[*numWorkouts].sets);
    printf("Enter number of reps: ");
    scanf("%d", &workoutData[*numWorkouts].reps);
    (*numWorkouts)++;
}

// Function to display the workout history
void viewWorkoutHistory(WorkoutSession *session) {
    if (session->numWorkouts == 0) {
        printf("No workouts recorded yet.\n");
        return;
    }
    printf("Workout history:\n");
    printf("| %-20s | %-10s | %-10s |\n", "Exercise", "Sets", "Reps");
    printf("----------------------------------------\n");
    for (int i = 0; i < session->numWorkouts; i++) {
        printf("| %-20s | %-10d | %-10d |\n", session->workouts[i].exerciseName, session->workouts[i].sets, session->workouts[i].reps);
    }
}

// Main function to start the workout tracker program
int main() {
    WorkoutSession session;
    int choice, numWorkouts = 0;

    // Initialize session start time
    session.startTime = time(NULL);

    while (1) {
        // Display menu and get user choice
        choice = displayMenu();

        switch (choice)
        {
        case 1:
            // Record a workout
            recordWorkout(session.workouts, &numWorkouts);
            break;
        case 2:
            // View workout history
            viewWorkoutHistory(&session);
            break;
        case 3:
            // Exit program
            // Set session end time and calculate session duration
            session.endTime = time(NULL);
            int duration = (int)difftime(session.endTime, session.startTime);
            printf("Session duration: %d seconds\n", duration);
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }
    return 0;
}