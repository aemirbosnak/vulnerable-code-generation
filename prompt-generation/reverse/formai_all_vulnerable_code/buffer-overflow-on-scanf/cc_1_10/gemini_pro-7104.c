//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Elementary, my dear Watson!
int main() {
    // Fetch the current system time for our deductions.
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    // Initialize our fitness tracker data.
    int steps_taken = 0;
    int calories_burned = 0;
    int distance_traveled = 0;

    // Begin our investigation.
    while (1) {
        // Retrieve the user's input.
        printf("Enter a command, my dear Watson:");
        char command[100];
        scanf("%s", command);

        // Watson, parse the user's command.
        if (strcmp(command, "walk") == 0) {
            // The user has decided to embark on a stroll.
            printf("How many steps did you take, Watson?");
            int steps;
            scanf("%d", &steps);

            // Update our fitness tracker data.
            steps_taken += steps;
            calories_burned += steps * 0.05;
            distance_traveled += steps * 0.0005;
        } else if (strcmp(command, "run") == 0) {
            // Watson, it appears the user has engaged in some jogging.
            printf("How long did you run for, my dear fellow?");
            int minutes;
            scanf("%d", &minutes);

            // Calculate the distance covered and calories burned.
            distance_traveled += minutes * 0.1;
            calories_burned += minutes * 10;
        } else if (strcmp(command, "cycle") == 0) {
            // Watson, the user has taken to cycling.
            printf("How many kilometers did you cycle, Watson?");
            int kilometers;
            scanf("%d", &kilometers);

            // Update our fitness tracker data.
            distance_traveled += kilometers;
            calories_burned += kilometers * 15;
        } else if (strcmp(command, "quit") == 0) {
            // Watson, it appears our investigation has reached its conclusion.
            printf("Excellent work, Watson! Here is a summary of your fitness data:\n");
            printf("Steps Taken: %d\n", steps_taken);
            printf("Calories Burned: %d\n", calories_burned);
            printf("Distance Traveled: %d kilometers\n", distance_traveled);

            return 0;
        } else {
            // Watson, it seems the user has entered an invalid command.
            printf("Invalid command, my dear Watson. Please try again.");
        }
    }

    return 0;
}