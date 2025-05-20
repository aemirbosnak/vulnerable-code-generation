//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel simulator
typedef struct {
    time_t time;
    char *location;
} TimeTravelSimulator;

// Initialize the time travel simulator
TimeTravelSimulator *init_time_travel_simulator(time_t time, char *location) {
    TimeTravelSimulator *tts = malloc(sizeof(TimeTravelSimulator));
    tts->time = time;
    tts->location = location;
    return tts;
}

// Travel through time
void travel_through_time(TimeTravelSimulator *tts, time_t time, char *location) {
    tts->time = time;
    tts->location = location;
}

// Get the current time and location
void get_current_time_and_location(TimeTravelSimulator *tts, time_t *time, char **location) {
    *time = tts->time;
    *location = tts->location;
}

// Print the current time and location
void print_current_time_and_location(TimeTravelSimulator *tts) {
    printf("Current time: %s\n", ctime(&tts->time));
    printf("Current location: %s\n", tts->location);
}

// Main function
int main() {
    // Initialize the time travel simulator
    TimeTravelSimulator *tts = init_time_travel_simulator(time(NULL), "Earth");

    // Travel through time
    travel_through_time(tts, time(NULL) - 1000000, "Mars");

    // Get the current time and location
    time_t time;
    char *location;
    get_current_time_and_location(tts, &time, &location);

    // Print the current time and location
    print_current_time_and_location(tts);

    // Free the time travel simulator
    free(tts);

    return 0;
}