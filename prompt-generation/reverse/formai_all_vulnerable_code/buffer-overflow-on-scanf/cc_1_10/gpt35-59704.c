//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 50
#define MAX_NAME_LEN 20

// Struct to represent a workout
typedef struct {
    char name[MAX_NAME_LEN];
    int calories_burned;
    int duration_min;
    struct tm date; // from time.h
} Workout;

// Function to add a new workout to the tracker
void add_workout(Workout *workouts, int *num_workouts) {
    // Check if max number of workouts already reached
    if (*num_workouts == MAX_WORKOUTS) {
        printf("Error: max number of workouts reached\n");
        return;
    }

    // Prompt user for workout details
    printf("Enter workout name: ");
    scanf("%s", workouts[*num_workouts].name);
    printf("Enter calories burned: ");
    scanf("%d", &workouts[*num_workouts].calories_burned);
    printf("Enter duration (min): ");
    scanf("%d", &workouts[*num_workouts].duration_min);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &workouts[*num_workouts].date.tm_mon, &workouts[*num_workouts].date.tm_mday, &workouts[*num_workouts].date.tm_year);

    // Increment number of workouts
    *num_workouts += 1;

    printf("Workout added!\n");
}

// Function to print all the workouts in the tracker
void print_workouts(Workout *workouts, int num_workouts) {
    printf("Workouts:\n");

    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d calories burned, %d min duration, %d/%d/%d\n", workouts[i].name, workouts[i].calories_burned,
               workouts[i].duration_min, workouts[i].date.tm_mon, workouts[i].date.tm_mday, workouts[i].date.tm_year);
    }
}

// Function to calculate total calories burned from all workouts
int total_calories_burned(Workout *workouts, int num_workouts) {
    int total = 0;

    for (int i = 0; i < num_workouts; i++) {
        total += workouts[i].calories_burned;
    }

    return total;
}

// Function to calculate average workout duration
float avg_workout_duration(Workout *workouts, int num_workouts) {
    int total = 0;

    for (int i = 0; i < num_workouts; i++) {
        total += workouts[i].duration_min;
    }

    return (float) total / num_workouts;
}

int main() {
    // Initialize workouts array and number of workouts
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    // Main program loop
    while (true) {
        // Prompt user for action
        printf("Choose action:\n");
        printf("1. Add a workout\n");
        printf("2. View all workouts\n");
        printf("3. Calculate total calories burned\n");
        printf("4. Calculate average workout duration\n");
        printf("5. Quit\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout(workouts, &num_workouts);
                break;
            case 2:
                print_workouts(workouts, num_workouts);
                break;
            case 3:
                printf("Total calories burned: %d\n", total_calories_burned(workouts, num_workouts));
                break;
            case 4:
                printf("Average workout duration: %.1f min\n", avg_workout_duration(workouts, num_workouts));
                break;
            case 5:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}