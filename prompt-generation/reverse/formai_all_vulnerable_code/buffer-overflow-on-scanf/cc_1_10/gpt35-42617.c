//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Initializing variables
    char* destination;
    int num_waypoints;
    char** waypoints;
    int num_turns = 0;
    int num_mistakes = 0;
    time_t start_time, end_time;
    double elapsed_time;

    // Getting user input
    printf("Enter your destination: ");
    scanf("%m[^\n]", &destination);

    printf("Enter the number of waypoints: ");
    scanf("%d", &num_waypoints);

    waypoints = malloc(num_waypoints * sizeof(char*));
    for(int i = 0; i < num_waypoints; i++) {
        printf("Enter waypoint #%d: ", i+1);
        scanf("%m[^\n]", &waypoints[i]);
    }

    // Starting the simulation
    printf("Starting GPS navigation to %s...\n\n", destination);
    start_time = time(NULL);

    for(int i = 0; i < num_waypoints; i++) {
        printf("Distance to %s: %.2f km\n", waypoints[i], (double)rand()/RAND_MAX*50);

        char next_turn[10];
        printf("Next turn: ");
        scanf("%s", next_turn);

        if(strcmp(next_turn, "left") == 0) {
            printf("Turning left...\n");
            num_turns++;
        }
        else if(strcmp(next_turn, "right") == 0) {
            printf("Turning right...\n");
            num_turns++;
        }
        else {
            printf("Invalid turn! You must be lost...\n");
            num_mistakes++;
        }
    }

    // End of simulation
    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\nCongratulations, you have reached %s in %.2f minutes!\n", destination, elapsed_time/60);
    printf("You made %d turns and %d mistakes during your paranoid journey.\n", num_turns, num_mistakes);

    // Freeing memory
    free(destination);
    for(int i = 0; i < num_waypoints; i++) {
        free(waypoints[i]);
    }
    free(waypoints);

    return 0;
}