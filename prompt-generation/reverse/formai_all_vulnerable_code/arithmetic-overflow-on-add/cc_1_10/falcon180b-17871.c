//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIMESTAMPS 1000

// Event structure
typedef struct {
    char *description;
    time_t timestamp;
} Event;

// Function prototypes
void addEvent(Event *events, int *numEvents, char *description, time_t timestamp);
void printEvents(Event *events, int numEvents);
void timeTravel(Event *events, int numEvents, time_t targetTimestamp);

int main() {
    Event events[MAX_EVENTS];
    int numEvents = 0;
    time_t currentTimestamp = time(NULL);

    // Add some initial events
    addEvent(events, &numEvents, "Program started", currentTimestamp);
    addEvent(events, &numEvents, "First event", currentTimestamp + 60);
    addEvent(events, &numEvents, "Second event", currentTimestamp + 120);

    // Print the initial timeline
    printf("Initial timeline:\n");
    printEvents(events, numEvents);

    // Time travel to the future
    timeTravel(events, numEvents, currentTimestamp + 300);

    // Print the updated timeline
    printf("\nTimeline after time travel:\n");
    printEvents(events, numEvents);

    return 0;
}

void addEvent(Event *events, int *numEvents, char *description, time_t timestamp) {
    if (*numEvents >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    events[*numEvents].description = description;
    events[*numEvents].timestamp = timestamp;
    (*numEvents)++;
}

void printEvents(Event *events, int numEvents) {
    for (int i = 0; i < numEvents; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

void timeTravel(Event *events, int numEvents, time_t targetTimestamp) {
    for (int i = 0; i < numEvents; i++) {
        if (events[i].timestamp > targetTimestamp) {
            events[i].timestamp -= targetTimestamp - events[i].timestamp;
        }
    }
}