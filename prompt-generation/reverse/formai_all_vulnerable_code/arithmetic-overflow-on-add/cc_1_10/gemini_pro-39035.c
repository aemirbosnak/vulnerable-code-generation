//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be stored in the fitness tracker.
#define MAX_STEPS 1000

// Define the structure of a fitness tracker entry.
typedef struct {
    time_t timestamp;
    int steps;
} fitness_tracker_entry;

// Define the fitness tracker structure.
typedef struct {
    fitness_tracker_entry entries[MAX_STEPS];
    int num_entries;
} fitness_tracker;

// Initialize a fitness tracker.
void fitness_tracker_init(fitness_tracker *tracker) {
    tracker->num_entries = 0;
}

// Add an entry to the fitness tracker.
void fitness_tracker_add_entry(fitness_tracker *tracker, time_t timestamp, int steps) {
    if (tracker->num_entries < MAX_STEPS) {
        tracker->entries[tracker->num_entries].timestamp = timestamp;
        tracker->entries[tracker->num_entries].steps = steps;
        tracker->num_entries++;
    }
}

// Get the total number of steps recorded by the fitness tracker.
int fitness_tracker_get_total_steps(fitness_tracker *tracker) {
    int total_steps = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        total_steps += tracker->entries[i].steps;
    }
    return total_steps;
}

// Get the average number of steps per day recorded by the fitness tracker.
double fitness_tracker_get_average_steps_per_day(fitness_tracker *tracker) {
    if (tracker->num_entries == 0) {
        return 0.0;
    }
    time_t start_timestamp = tracker->entries[0].timestamp;
    time_t end_timestamp = tracker->entries[tracker->num_entries - 1].timestamp;
    double days_elapsed = difftime(end_timestamp, start_timestamp) / (60 * 60 * 24);
    double average_steps_per_day = fitness_tracker_get_total_steps(tracker) / days_elapsed;
    return average_steps_per_day;
}

// Get the maximum number of steps recorded by the fitness tracker in a single day.
int fitness_tracker_get_max_steps_in_a_day(fitness_tracker *tracker) {
    int max_steps_in_a_day = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        time_t timestamp = tracker->entries[i].timestamp;
        struct tm *time_info = localtime(&timestamp);
        int day_of_year = time_info->tm_yday;
        int steps_on_day = 0;
        for (int j = i; j < tracker->num_entries; j++) {
            time_t next_timestamp = tracker->entries[j].timestamp;
            struct tm *next_time_info = localtime(&next_timestamp);
            int next_day_of_year = next_time_info->tm_yday;
            if (next_day_of_year != day_of_year) {
                break;
            }
            steps_on_day += tracker->entries[j].steps;
        }
        if (steps_on_day > max_steps_in_a_day) {
            max_steps_in_a_day = steps_on_day;
        }
    }
    return max_steps_in_a_day;
}

// Print the fitness tracker data to the console.
void fitness_tracker_print(fitness_tracker *tracker) {
    printf("Fitness Tracker Data:\n");
    printf("---------------------\n");
    printf("Total Steps: %d\n", fitness_tracker_get_total_steps(tracker));
    printf("Average Steps Per Day: %.2f\n", fitness_tracker_get_average_steps_per_day(tracker));
    printf("Max Steps In A Day: %d\n", fitness_tracker_get_max_steps_in_a_day(tracker));
    printf("Entries:\n");
    for (int i = 0; i < tracker->num_entries; i++) {
        time_t timestamp = tracker->entries[i].timestamp;
        struct tm *time_info = localtime(&timestamp);
        char time_string[26];
        strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
        printf("  %s: %d steps\n", time_string, tracker->entries[i].steps);
    }
}

// Main function.
int main() {
    // Initialize the fitness tracker.
    fitness_tracker tracker;
    fitness_tracker_init(&tracker);

    // Add some sample data to the fitness tracker.
    fitness_tracker_add_entry(&tracker, time(NULL), 1000);
    fitness_tracker_add_entry(&tracker, time(NULL) + (60 * 60 * 24), 1500);
    fitness_tracker_add_entry(&tracker, time(NULL) + (60 * 60 * 48), 2000);

    // Print the fitness tracker data to the console.
    fitness_tracker_print(&tracker);

    return 0;
}