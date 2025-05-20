//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 2147483647
#define MIN_STEPS 0

typedef struct {
    int steps;
    time_t timestamp;
} StepData;

int main(void) {
    int total_steps = 0;
    int steps_per_minute = 0;
    int num_entries = 0;
    StepData step_data[1000];

    printf("\n--------------------------------------------\n");
    printf("| Welcome to the Surprise C Fitness Tracker! |\n");
    printf("--------------------------------------------|\n\n");

    time_t current_time;
    time(&current_time);

    while (total_steps < MAX_STEPS && num_entries < 1000) {
        printf("\nEnter the number of steps you've taken since the last entry (0 to quit): ");
        scanf("%d", &step_data[num_entries].steps);

        if (step_data[num_entries].steps == 0) {
            printf("Exiting the program...\n");
            break;
        }

        if (step_data[num_entries].steps > MAX_STEPS) {
            printf("Error: The number of steps entered is too large. Please enter a valid number.\n");
            continue;
        }

        time(&step_data[num_entries].timestamp);
        total_steps += step_data[num_entries].steps;
        num_entries++;

        steps_per_minute = (total_steps / num_entries) * 60;
        printf("\nCurrent average steps per minute: %d", steps_per_minute);
        printf("\n----------------------------------------\n");
    }

    if (num_entries == 1000) {
        printf("\nReached the maximum number of entries. Calculating average steps per minute...\n");
        steps_per_minute = total_steps / (num_entries * 60);
        printf("\nAverage steps per minute: %d", steps_per_minute);
        printf("\n----------------------------------------\n");
    }

    printf("\nThank you for using the Surprise C Fitness Tracker! Have a great day!\n");

    return 0;
}