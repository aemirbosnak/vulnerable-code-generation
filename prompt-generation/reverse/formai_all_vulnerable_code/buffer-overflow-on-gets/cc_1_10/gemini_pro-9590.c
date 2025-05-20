//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STEPS 10000
#define MAX_HEART_RATE 220

typedef struct {
    int steps;
    int heart_rate;
    char *date;
} fitness_data_t;

void print_fitness_data(fitness_data_t *data) {
    printf("Steps: %d\n", data->steps);
    printf("Heart rate: %d\n", data->heart_rate);
    printf("Date: %s\n", data->date);
}

int main() {
    // Create a fitness tracker
    fitness_data_t fitness_tracker;

    // Set the initial values
    fitness_tracker.steps = 0;
    fitness_tracker.heart_rate = 0;
    fitness_tracker.date = "2023-01-01";

    // Get the user's input
    char input[100];
    while (1) {
        printf("Enter a command (steps, heart rate, date, print, quit): ");
        gets(input);

        // Parse the command
        if (strcmp(input, "steps") == 0) {
            // Get the number of steps
            int steps;
            printf("Enter the number of steps: ");
            scanf("%d", &steps);

            // Update the fitness tracker
            fitness_tracker.steps += steps;
        } else if (strcmp(input, "heart rate") == 0) {
            // Get the heart rate
            int heart_rate;
            printf("Enter the heart rate: ");
            scanf("%d", &heart_rate);

            // Update the fitness tracker
            fitness_tracker.heart_rate = heart_rate;
        } else if (strcmp(input, "date") == 0) {
            // Get the date
            char date[100];
            printf("Enter the date: ");
            gets(date);

            // Update the fitness tracker
            fitness_tracker.date = date;
        } else if (strcmp(input, "print") == 0) {
            // Print the fitness data
            print_fitness_data(&fitness_tracker);
        } else if (strcmp(input, "quit") == 0) {
            // Quit the program
            break;
        } else {
            // Invalid command
            printf("Invalid command\n");
        }
    }

    return 0;
}