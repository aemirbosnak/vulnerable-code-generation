//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the fitness tracker.
#define MAX_STEPS 10000

// Define the structure of a fitness tracker entry.
typedef struct {
    time_t timestamp;
    uint16_t steps;
} fitness_tracker_entry_t;

// Create a new fitness tracker.
fitness_tracker_entry_t* create_fitness_tracker() {
    fitness_tracker_entry_t* fitness_tracker = malloc(sizeof(fitness_tracker_entry_t) * MAX_STEPS);
    if (fitness_tracker == NULL) {
        return NULL;
    }

    // Initialize the fitness tracker with zero steps.
    for (int i = 0; i < MAX_STEPS; i++) {
        fitness_tracker[i].timestamp = 0;
        fitness_tracker[i].steps = 0;
    }

    return fitness_tracker;
}

// Add a new entry to the fitness tracker.
void add_fitness_tracker_entry(fitness_tracker_entry_t* fitness_tracker, time_t timestamp, uint16_t steps) {
    // Find the first empty entry in the fitness tracker.
    int i = 0;
    while (fitness_tracker[i].timestamp != 0) {
        i++;
    }

    // If the fitness tracker is full, then overwrite the oldest entry.
    if (i == MAX_STEPS) {
        i = 0;
    }

    // Add the new entry to the fitness tracker.
    fitness_tracker[i].timestamp = timestamp;
    fitness_tracker[i].steps = steps;
}

// Get the total number of steps in the fitness tracker.
uint16_t get_total_steps(fitness_tracker_entry_t* fitness_tracker) {
    uint16_t total_steps = 0;

    // Iterate over all of the entries in the fitness tracker.
    for (int i = 0; i < MAX_STEPS; i++) {
        // Add the steps from each entry to the total.
        total_steps += fitness_tracker[i].steps;
    }

    return total_steps;
}

// Print the fitness tracker to the console.
void print_fitness_tracker(fitness_tracker_entry_t* fitness_tracker) {
    // Iterate over all of the entries in the fitness tracker.
    for (int i = 0; i < MAX_STEPS; i++) {
        // Print the timestamp and steps for each entry.
        printf("%s: %d steps\n", ctime(&fitness_tracker[i].timestamp), fitness_tracker[i].steps);
    }
}

// Free the memory allocated for the fitness tracker.
void free_fitness_tracker(fitness_tracker_entry_t* fitness_tracker) {
    free(fitness_tracker);
}

int main() {
    // Create a new fitness tracker.
    fitness_tracker_entry_t* fitness_tracker = create_fitness_tracker();

    // Add some sample entries to the fitness tracker.
    time_t timestamp = time(NULL);
    add_fitness_tracker_entry(fitness_tracker, timestamp, 1000);
    add_fitness_tracker_entry(fitness_tracker, timestamp + 3600, 2000);
    add_fitness_tracker_entry(fitness_tracker, timestamp + 7200, 3000);

    // Get the total number of steps in the fitness tracker.
    uint16_t total_steps = get_total_steps(fitness_tracker);

    // Print the fitness tracker to the console.
    print_fitness_tracker(fitness_tracker);

    // Free the memory allocated for the fitness tracker.
    free_fitness_tracker(fitness_tracker);

    return 0;
}