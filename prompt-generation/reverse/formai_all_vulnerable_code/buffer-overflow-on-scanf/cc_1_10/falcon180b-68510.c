//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

// Struct to hold event information
typedef struct {
    time_t timestamp;
    char *description;
} Event;

// Function prototypes
void addEvent(Event *events, int *numEvents);
void printEvents(Event *events, int numEvents);
void timeTravel(Event *events, int numEvents, time_t targetTime);

int main() {
    Event events[MAX_EVENTS];
    int numEvents = 0;

    // Add some sample events
    addEvent(events, &numEvents);
    addEvent(events, &numEvents);
    addEvent(events, &numEvents);

    // Print the initial timeline
    printf("Initial timeline:\n");
    printEvents(events, numEvents);

    // Time travel to a specific event
    time_t targetTime = 946684800; // January 1, 2000
    timeTravel(events, numEvents, targetTime);

    // Print the updated timeline
    printf("\nTimeline after time travel:\n");
    printEvents(events, numEvents);

    return 0;
}

// Function to add an event to the timeline
void addEvent(Event *events, int *numEvents) {
    char input[100];

    printf("Enter a description of the event: ");
    scanf("%s", input);

    events[*numEvents].timestamp = time(NULL);
    events[*numEvents].description = strdup(input);

    (*numEvents)++;
}

// Function to print the timeline
void printEvents(Event *events, int numEvents) {
    for (int i = 0; i < numEvents; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

// Function to time travel to a specific event
void timeTravel(Event *events, int numEvents, time_t targetTime) {
    for (int i = 0; i < numEvents; i++) {
        if (events[i].timestamp == targetTime) {
            printf("\nYou have arrived at the event:\n");
            printf("%s\n", events[i].description);
            return;
        }
    }

    printf("\nSorry, the event you are looking for does not exist.\n");
}