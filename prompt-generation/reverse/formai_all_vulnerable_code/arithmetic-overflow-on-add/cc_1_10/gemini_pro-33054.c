//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the time travel simulator struct
typedef struct {
    time_t start_time;
    time_t end_time;
    int num_jumps;
    int current_jump;
} time_travel_simulator;

// Create a new time travel simulator
time_travel_simulator* create_time_travel_simulator(time_t start_time, time_t end_time, int num_jumps) {
    time_travel_simulator* simulator = malloc(sizeof(time_travel_simulator));
    simulator->start_time = start_time;
    simulator->end_time = end_time;
    simulator->num_jumps = num_jumps;
    simulator->current_jump = 0;
    return simulator;
}

// Destroy a time travel simulator
void destroy_time_travel_simulator(time_travel_simulator* simulator) {
    free(simulator);
}

// Jump to a specific time
void jump_to_time(time_travel_simulator* simulator, time_t time) {
    if (time < simulator->start_time || time > simulator->end_time) {
        printf("Invalid time: %ld\n", time);
        return;
    }
    simulator->current_jump++;
    simulator->start_time = time;
}

// Get the current time
time_t get_current_time(time_travel_simulator* simulator) {
    return simulator->start_time;
}

// Get the number of jumps made
int get_num_jumps(time_travel_simulator* simulator) {
    return simulator->current_jump;
}

// Print the time travel simulator
void print_time_travel_simulator(time_travel_simulator* simulator) {
    printf("Time travel simulator:\n");
    printf("  Start time: %ld\n", simulator->start_time);
    printf("  End time: %ld\n", simulator->end_time);
    printf("  Number of jumps: %d\n", simulator->num_jumps);
    printf("  Current jump: %d\n", simulator->current_jump);
}

// Main function
int main() {
    // Create a new time travel simulator
    time_travel_simulator* simulator = create_time_travel_simulator(time(NULL), time(NULL) + 60 * 60 * 24, 3);

    // Jump to a specific time
    jump_to_time(simulator, time(NULL) + 60 * 60);

    // Get the current time
    time_t current_time = get_current_time(simulator);

    // Get the number of jumps made
    int num_jumps = get_num_jumps(simulator);

    // Print the time travel simulator
    print_time_travel_simulator(simulator);

    // Destroy the time travel simulator
    destroy_time_travel_simulator(simulator);

    return 0;
}