//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the maximum number of workouts that can be tracked
#define MAX_WORKOUTS 100

// Define the structure for a single workout
typedef struct {
    char name[50];
    int duration;
    double distance;
    double calories;
    time_t timestamp;
} Workout;

// Define the main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize an array to store workouts
    Workout workouts[MAX_WORKOUTS];

    // Initialize the number of workouts
    int numWorkouts = 0;

    // Main loop
    while (1) {
        // Print the menu
        printf("Fitness Tracker\n");
        printf("1. Add a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Perform the chosen action
        switch (choice) {
            case 1:
                // Add a workout
                if (numWorkouts >= MAX_WORKOUTS) {
                    printf("Cannot add more workouts.\n");
                } else {
                    printf("Enter the name of the workout: ");
                    scanf("%s", workouts[numWorkouts].name);

                    printf("Enter the duration of the workout (in seconds): ");
                    scanf("%d", &workouts[numWorkouts].duration);

                    printf("Enter the distance covered (in meters): ");
                    scanf("%lf", &workouts[numWorkouts].distance);

                    workouts[numWorkouts].calories = (double)workouts[numWorkouts].duration * (double)workouts[numWorkouts].distance / 3600.0;

                    workouts[numWorkouts].timestamp = time(NULL);

                    numWorkouts++;

                    printf("Workout added successfully.\n");
                }
                break;

            case 2:
                // View workout history
                if (numWorkouts == 0) {
                    printf("No workouts found.\n");
                } else {
                    printf("Workout history:\n");
                    for (int i = 0; i < numWorkouts; i++) {
                        printf("%s: %.2lf minutes, %.2lf meters, %.2lf calories\n", workouts[i].name, workouts[i].duration / 60.0, workouts[i].distance, workouts[i].calories);
                    }
                }
                break;

            case 3:
                // Exit
                exit(0);

            default:
                // Invalid choice
                printf("Invalid choice.\n");
        }
    }

    return 0;
}