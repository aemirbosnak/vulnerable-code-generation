//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps and heart rate values
#define MAX_STEPS 10000
#define MAX_HEART_RATE 255

// Define the data structure for a fitness tracker entry
typedef struct fitness_tracker_entry {
    time_t timestamp;
    unsigned int steps;
    unsigned char heart_rate;
} fitness_tracker_entry_t;

// Define the data structure for a fitness tracker
typedef struct fitness_tracker {
    unsigned int num_entries;
    fitness_tracker_entry_t entries[MAX_STEPS];
} fitness_tracker_t;

// Create a new fitness tracker
fitness_tracker_t* create_fitness_tracker() {
    fitness_tracker_t* tracker = malloc(sizeof(fitness_tracker_t));
    tracker->num_entries = 0;
    return tracker;
}

// Add an entry to a fitness tracker
void add_entry_to_fitness_tracker(fitness_tracker_t* tracker, time_t timestamp, unsigned int steps, unsigned char heart_rate) {
    // Check if the tracker is full
    if (tracker->num_entries == MAX_STEPS) {
        printf("Warning: Fitness tracker is full!\n");
        return;
    }

    // Add the new entry to the tracker
    tracker->entries[tracker->num_entries].timestamp = timestamp;
    tracker->entries[tracker->num_entries].steps = steps;
    tracker->entries[tracker->num_entries].heart_rate = heart_rate;
    tracker->num_entries++;
}

// Get the total number of steps recorded by a fitness tracker
unsigned int get_total_steps(fitness_tracker_t* tracker) {
    unsigned int total_steps = 0;
    for (unsigned int i = 0; i < tracker->num_entries; i++) {
        total_steps += tracker->entries[i].steps;
    }
    return total_steps;
}

// Get the average heart rate recorded by a fitness tracker
unsigned char get_average_heart_rate(fitness_tracker_t* tracker) {
    unsigned int total_heart_rate = 0;
    for (unsigned int i = 0; i < tracker->num_entries; i++) {
        total_heart_rate += tracker->entries[i].heart_rate;
    }
    return total_heart_rate / tracker->num_entries;
}

// Get the maximum heart rate recorded by a fitness tracker
unsigned char get_maximum_heart_rate(fitness_tracker_t* tracker) {
    unsigned char max_heart_rate = 0;
    for (unsigned int i = 0; i < tracker->num_entries; i++) {
        if (tracker->entries[i].heart_rate > max_heart_rate) {
            max_heart_rate = tracker->entries[i].heart_rate;
        }
    }
    return max_heart_rate;
}

// Get the minimum heart rate recorded by a fitness tracker
unsigned char get_minimum_heart_rate(fitness_tracker_t* tracker) {
    unsigned char min_heart_rate = MAX_HEART_RATE;
    for (unsigned int i = 0; i < tracker->num_entries; i++) {
        if (tracker->entries[i].heart_rate < min_heart_rate) {
            min_heart_rate = tracker->entries[i].heart_rate;
        }
    }
    return min_heart_rate;
}

// Print the entries of a fitness tracker
void print_fitness_tracker(fitness_tracker_t* tracker) {
    for (unsigned int i = 0; i < tracker->num_entries; i++) {
        printf("%ld: %u steps, %u bpm\n", tracker->entries[i].timestamp, tracker->entries[i].steps, tracker->entries[i].heart_rate);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker_t* tracker) {
    free(tracker);
}

// Main function
int main() {
    // Create a new fitness tracker
    fitness_tracker_t* tracker = create_fitness_tracker();

    // Add some entries to the fitness tracker
    add_entry_to_fitness_tracker(tracker, time(NULL), 1000, 120);
    add_entry_to_fitness_tracker(tracker, time(NULL) + 3600, 2000, 130);
    add_entry_to_fitness_tracker(tracker, time(NULL) + 7200, 3000, 140);

    // Get some statistics from the fitness tracker
    printf("Total steps: %u\n", get_total_steps(tracker));
    printf("Average heart rate: %u bpm\n", get_average_heart_rate(tracker));
    printf("Maximum heart rate: %u bpm\n", get_maximum_heart_rate(tracker));
    printf("Minimum heart rate: %u bpm\n", get_minimum_heart_rate(tracker));

    // Print the entries of the fitness tracker
    print_fitness_tracker(tracker);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}