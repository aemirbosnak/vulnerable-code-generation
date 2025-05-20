//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to print the menu
void print_menu() {
    printf("\n\nFitness Tracker Menu:\n");
    printf("1. Start Workout\n");
    printf("2. Stop Workout\n");
    printf("3. View Workout History\n");
    printf("4. Exit\n");
}

// Function to start a workout
void start_workout() {
    time_t start_time;
    time(&start_time);
    srand(start_time);

    int duration = rand() % 60 + 1; // Random duration between 1 and 60 minutes
    printf("\nStarting workout for %d minutes...\n", duration);

    time_t end_time = start_time + duration * 60; // Calculate end time based on duration
    while (difftime(time(NULL), end_time) > 0) { // Continue until end time is reached
        printf("\r%d minutes remaining...", duration);
        fflush(stdout);
        sleep(1);
    }

    printf("\n\nWorkout complete!\n");
}

// Function to stop a workout
void stop_workout() {
    printf("\nWorkout stopped.\n");
}

// Function to view workout history
void view_history() {
    printf("\nWorkout History:\n");
}

// Main function
int main() {
    bool running = true;

    while (running) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_workout();
                break;
            case 2:
                stop_workout();
                break;
            case 3:
                view_history();
                break;
            case 4:
                running = false;
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}