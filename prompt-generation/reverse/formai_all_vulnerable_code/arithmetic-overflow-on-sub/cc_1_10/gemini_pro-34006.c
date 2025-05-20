//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define some constants
#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 20

// Define a struct to represent an event
typedef struct event {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t timestamp;
} event_t;

// Define a struct to represent the time travel simulator
typedef struct time_travel_simulator {
    event_t events[MAX_EVENTS];
    int num_events;
    time_t current_time;
} time_travel_simulator_t;

// Create a new time travel simulator
time_travel_simulator_t* create_time_travel_simulator() {
    time_travel_simulator_t* simulator = malloc(sizeof(time_travel_simulator_t));
    simulator->num_events = 0;
    simulator->current_time = time(NULL);
    return simulator;
}

// Add an event to the time travel simulator
void add_event(time_travel_simulator_t* simulator, char* name, time_t timestamp) {
    if (simulator->num_events >= MAX_EVENTS) {
        printf("Error: cannot add more events to the simulator");
        return;
    }
    strcpy(simulator->events[simulator->num_events].name, name);
    simulator->events[simulator->num_events].timestamp = timestamp;
    simulator->num_events++;
}

// Travel to a specific time
void travel_to_time(time_travel_simulator_t* simulator, time_t timestamp) {
    simulator->current_time = timestamp;
}

// Get the current time
time_t get_current_time(time_travel_simulator_t* simulator) {
    return simulator->current_time;
}

// Get the next event
event_t* get_next_event(time_travel_simulator_t* simulator) {
    for (int i = 0; i < simulator->num_events; i++) {
        if (simulator->events[i].timestamp > simulator->current_time) {
            return &simulator->events[i];
        }
    }
    return NULL;
}

// Print the current state of the time travel simulator
void print_time_travel_simulator(time_travel_simulator_t* simulator) {
    printf("Current time: %s", ctime(&simulator->current_time));
    printf("Events:\n");
    for (int i = 0; i < simulator->num_events; i++) {
        printf("  - %s: %s", simulator->events[i].name, ctime(&simulator->events[i].timestamp));
    }
}

// Free the memory allocated for the time travel simulator
void free_time_travel_simulator(time_travel_simulator_t* simulator) {
    free(simulator);
}

// Main function
int main() {
    // Create a new time travel simulator
    time_travel_simulator_t* simulator = create_time_travel_simulator();

    // Add some events to the simulator
    add_event(simulator, "Birth", time(NULL) - (60 * 60 * 24 * 365 * 25));
    add_event(simulator, "First day of school", time(NULL) - (60 * 60 * 24 * 365 * 18));
    add_event(simulator, "Graduation", time(NULL) - (60 * 60 * 24 * 365 * 12));
    add_event(simulator, "First job", time(NULL) - (60 * 60 * 24 * 365 * 5));
    add_event(simulator, "Marriage", time(NULL) + (60 * 60 * 24 * 365 * 5));

    // Print the current state of the simulator
    print_time_travel_simulator(simulator);

    // Travel to a specific time
    travel_to_time(simulator, time(NULL) - (60 * 60 * 24 * 365 * 18));

    // Print the current state of the simulator
    print_time_travel_simulator(simulator);

    // Get the next event
    event_t* next_event = get_next_event(simulator);

    // Print the next event
    printf("Next event: %s: %s", next_event->name, ctime(&next_event->timestamp));

    // Free the memory allocated for the simulator
    free_time_travel_simulator(simulator);

    return 0;
}