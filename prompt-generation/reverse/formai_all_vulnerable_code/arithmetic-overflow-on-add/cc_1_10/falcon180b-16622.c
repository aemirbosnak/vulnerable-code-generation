//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 100

typedef struct {
    char description[MAX_EVENT_LENGTH];
    time_t time;
} Event;

int main() {
    int numEvents = 0;
    Event events[MAX_EVENTS];
    char input[MAX_EVENT_LENGTH];

    // Set the initial time
    time_t startTime = time(NULL);

    // Get the user's first event
    printf("Enter your first event:\n");
    fgets(input, MAX_EVENT_LENGTH, stdin);
    strcpy(events[numEvents].description, input);
    events[numEvents].time = startTime;
    numEvents++;

    // Simulate time travel
    while (1) {
        time_t currentTime = startTime;

        // Display the timeline
        for (int i = 0; i < numEvents; i++) {
            if (events[i].time > currentTime) {
                printf("%s (in the future)\n", events[i].description);
            } else {
                printf("%s\n", events[i].description);
            }
        }

        // Get the user's next event
        printf("\nEnter your next event:\n");
        fgets(input, MAX_EVENT_LENGTH, stdin);
        strcpy(events[numEvents].description, input);
        events[numEvents].time = currentTime + 60; // Assume each event takes 1 minute
        numEvents++;

        // Check if we've reached the end of the timeline
        if (numEvents == MAX_EVENTS) {
            printf("\nYou've reached the end of the timeline!\n");
            break;
        }

        // Update the current time
        currentTime = events[numEvents - 1].time;
    }

    return 0;
}