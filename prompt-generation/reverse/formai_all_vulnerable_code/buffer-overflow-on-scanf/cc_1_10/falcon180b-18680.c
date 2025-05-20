//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 24*60*60 // 1 day in seconds

// Struct to store a workout
typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} Workout;

int main() {
    char input[100];
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    // Initialize random seed
    srand(time(NULL));

    // Main loop
    while(1) {
        // Print menu
        printf("Fitness Tracker\n");
        printf("1. Start a workout\n");
        printf("2. End a workout\n");
        printf("3. View workout history\n");
        printf("4. Exit\n");

        // Get user input
        scanf("%s", input);

        // Perform action based on user input
        switch(input[0]) {
            case '1':
                // Start a workout
                if(num_workouts >= MAX_WORKOUTS) {
                    printf("Cannot start more than %d workouts.\n", MAX_WORKOUTS);
                } else {
                    workouts[num_workouts].start_time = time(NULL);
                    strcpy(workouts[num_workouts].name, "Workout");
                    num_workouts++;
                    printf("Workout started.\n");
                }
                break;
            case '2':
                // End a workout
                if(num_workouts == 0) {
                    printf("No workout in progress.\n");
                } else {
                    workouts[num_workouts-1].end_time = time(NULL);
                    workouts[num_workouts-1].duration = difftime(workouts[num_workouts-1].end_time, workouts[num_workouts-1].start_time);
                    printf("Workout ended. Duration: %d seconds.\n", workouts[num_workouts-1].duration);
                    num_workouts--;
                }
                break;
            case '3':
                // View workout history
                if(num_workouts == 0) {
                    printf("No workout history.\n");
                } else {
                    printf("Workout history:\n");
                    for(int i=0; i<num_workouts; i++) {
                        printf("%s: %d seconds\n", workouts[i].name, workouts[i].duration);
                    }
                }
                break;
            case '4':
                // Exit
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}