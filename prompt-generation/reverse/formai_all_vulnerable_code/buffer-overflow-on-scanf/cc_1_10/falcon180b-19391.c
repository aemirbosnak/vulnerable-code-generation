//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_DESCRIPTION 100

// Event structure
struct Event {
    time_t time;
    char description[MAX_EVENT_DESCRIPTION];
};

// Function prototypes
void addEvent(struct Event *events, int *eventCount);
void printEvents(struct Event events[], int eventCount);
void timeTravel(struct Event events[], int eventCount, time_t targetTime);

int main() {
    // Initialize event list
    struct Event events[MAX_EVENTS];
    int eventCount = 0;

    // Add some events
    addEvent(events, &eventCount);
    addEvent(events, &eventCount);
    addEvent(events, &eventCount);

    // Print initial event list
    printf("Initial event list:\n");
    printEvents(events, eventCount);

    // Time travel to a specific time
    time_t targetTime = 1582016000; // January 18, 2020
    timeTravel(events, eventCount, targetTime);

    // Print final event list
    printf("\nFinal event list:\n");
    printEvents(events, eventCount);

    return 0;
}

// Function to add an event to the list
void addEvent(struct Event *events, int *eventCount) {
    printf("Enter the date and time of the event (YYYY-MM-DD HH:MM:SS): ");
    struct tm eventTime;
    scanf("%d-%d-%d %d:%d:%d", &eventTime.tm_year, &eventTime.tm_mon, &eventTime.tm_mday, &eventTime.tm_hour, &eventTime.tm_min, &eventTime.tm_sec);
    events[*eventCount].time = mktime(&eventTime);

    printf("Enter a description of the event: ");
    scanf("%[^\n]", events[*eventCount].description);

    (*eventCount)++;
}

// Function to print the event list
void printEvents(struct Event events[], int eventCount) {
    for (int i = 0; i < eventCount; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

// Function to time travel to a specific time
void timeTravel(struct Event events[], int eventCount, time_t targetTime) {
    printf("Entering time machine...\n");
    for (int i = 0; i < eventCount; i++) {
        if (events[i].time > targetTime) {
            events[i].time -= targetTime - events[i].time;
        }
    }
    printf("Exiting time machine.\n");
}