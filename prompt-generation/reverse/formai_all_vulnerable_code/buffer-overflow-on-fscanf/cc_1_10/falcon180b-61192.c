//Falcon-180B DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define EVENT_NAME_MAX_LENGTH 50
#define EVENT_DESCRIPTION_MAX_LENGTH 200

typedef struct {
    char name[EVENT_NAME_MAX_LENGTH];
    char description[EVENT_DESCRIPTION_MAX_LENGTH];
    time_t timestamp;
} Event;

int main() {
    FILE *logFile;
    Event events[MAX_EVENTS];
    int numEvents = 0;

    logFile = fopen("event_log.txt", "a");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    // Read existing events from the log file
    while (numEvents < MAX_EVENTS && fscanf(logFile, "%s %s %ld\n", events[numEvents].name, events[numEvents].description, &events[numEvents].timestamp)!= EOF) {
        numEvents++;
    }

    while (1) {
        printf("Enter event name (up to %d characters):\n", EVENT_NAME_MAX_LENGTH - 1);
        scanf("%s", events[numEvents].name);

        printf("Enter event description (up to %d characters):\n", EVENT_DESCRIPTION_MAX_LENGTH - 1);
        scanf("%s", events[numEvents].description);

        time(&events[numEvents].timestamp);

        fprintf(logFile, "%s %s %ld\n", events[numEvents].name, events[numEvents].description, events[numEvents].timestamp);
        printf("Event logged:\n");
        printf("  Name: %s\n", events[numEvents].name);
        printf("  Description: %s\n", events[numEvents].description);
        printf("  Timestamp: %s\n\n", ctime(&events[numEvents].timestamp));

        numEvents++;

        if (numEvents == MAX_EVENTS) {
            break;
        }
    }

    fclose(logFile);

    return 0;
}