//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored
#define MAX_STEPS 1000

// Define the structure of a step
typedef struct {
    int timestamp;
    int count;
} step_t;

// Define the structure of a fitness tracker
typedef struct {
    int num_steps;
    step_t steps[MAX_STEPS];
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t *fitness_tracker_new() {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    tracker->num_steps = 0;
    return tracker;
}

// Add a new step to the fitness tracker
void fitness_tracker_add_step(fitness_tracker_t *tracker, int timestamp, int count) {
    tracker->steps[tracker->num_steps].timestamp = timestamp;
    tracker->steps[tracker->num_steps].count = count;
    tracker->num_steps++;
}

// Get the total number of steps in the fitness tracker
int fitness_tracker_get_total_steps(fitness_tracker_t *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_steps; i++) {
        total_steps += tracker->steps[i].count;
    }
    return total_steps;
}

// Get the average number of steps per day in the fitness tracker
float fitness_tracker_get_average_steps_per_day(fitness_tracker_t *tracker) {
    // Get the current time
    time_t current_time = time(NULL);
    struct tm *current_time_tm = localtime(&current_time);

    // Get the start of the day
    time_t start_of_day = mktime(current_time_tm);

    // Get the number of steps taken since the start of the day
    int steps_since_start_of_day = 0;
    for (int i = 0; i < tracker->num_steps; i++) {
        if (tracker->steps[i].timestamp >= start_of_day) {
            steps_since_start_of_day += tracker->steps[i].count;
        }
    }

    // Calculate the average number of steps per day
    float average_steps_per_day = (float)steps_since_start_of_day / (float)(current_time_tm->tm_hour * 60 * 60 + current_time_tm->tm_min * 60 + current_time_tm->tm_sec);

    return average_steps_per_day;
}

// Print the fitness tracker data
void fitness_tracker_print(fitness_tracker_t *tracker) {
    printf("Fitness Tracker Data:\n");
    printf("---------------------\n");
    printf("Total Steps: %d\n", fitness_tracker_get_total_steps(tracker));
    printf("Average Steps Per Day: %.2f\n", fitness_tracker_get_average_steps_per_day(tracker));
    printf("Steps:\n");
    for (int i = 0; i < tracker->num_steps; i++) {
        printf("  - Timestamp: %d, Count: %d\n", tracker->steps[i].timestamp, tracker->steps[i].count);
    }
}

// Free the memory allocated to the fitness tracker
void fitness_tracker_free(fitness_tracker_t *tracker) {
    free(tracker);
}


int main() {
    // Create a new fitness tracker
    fitness_tracker_t *tracker = fitness_tracker_new();

    // Add some steps to the fitness tracker
    fitness_tracker_add_step(tracker, time(NULL), 1000);
    fitness_tracker_add_step(tracker, time(NULL) + 60 * 60, 2000);
    fitness_tracker_add_step(tracker, time(NULL) + 12 * 60 * 60, 3000);

    // Print the fitness tracker data
    fitness_tracker_print(tracker);

    // Free the memory allocated to the fitness tracker
    fitness_tracker_free(tracker);

    return 0;
}