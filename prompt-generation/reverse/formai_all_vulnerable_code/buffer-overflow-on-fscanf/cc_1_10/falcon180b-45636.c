//Falcon-180B DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT_LENGTH 256
#define MAX_EVENTS 1000

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

int main() {
    FILE* logFile;
    Event events[MAX_EVENTS];
    int eventCount = 0;

    // Open the log file for appending
    logFile = fopen("event_log.txt", "a");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read in the existing events from the log file
    while (fscanf(logFile, "%s %ld\n", events[eventCount].event, &events[eventCount].timestamp)!= EOF) {
        eventCount++;
    }
    fclose(logFile);

    // Main event logging loop
    while (1) {
        // Wait for an event to occur
        printf("Waiting for event...\n");
        fflush(stdout);
        char event[MAX_EVENT_LENGTH];
        fgets(event, MAX_EVENT_LENGTH, stdin);

        // Log the event
        strncpy(events[eventCount].event, event, MAX_EVENT_LENGTH - 1);
        events[eventCount].event[MAX_EVENT_LENGTH - 1] = '\0';
        time_t currentTime = time(NULL);
        events[eventCount].timestamp = currentTime;
        eventCount++;

        // Write the event to the log file
        logFile = fopen("event_log.txt", "a");
        if (logFile == NULL) {
            printf("Error opening log file.\n");
            exit(1);
        }
        for (int i = 0; i < eventCount; i++) {
            fprintf(logFile, "%s %ld\n", events[i].event, events[i].timestamp);
        }
        fclose(logFile);

        // Print the event to the console
        printf("Event logged: %s\n", event);
        fflush(stdout);
    }

    return 0;
}