//Falcon-180B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_SIZE 100

typedef struct {
    char eventType[EVENT_SIZE];
    char eventMessage[EVENT_SIZE];
    time_t eventTime;
} Event;

void logEvent(Event* event) {
    FILE* logFile = fopen("event_log.txt", "a");
    if (logFile == NULL) {
        printf("Error opening log file\n");
        return;
    }
    fprintf(logFile, "Event Type: %s\n", event->eventType);
    fprintf(logFile, "Event Message: %s\n", event->eventMessage);
    fprintf(logFile, "Event Time: %s", ctime(&event->eventTime));
    fprintf(logFile, "\n");
    fclose(logFile);
}

int main() {
    Event events[MAX_EVENTS];
    int numEvents = 0;

    while (1) {
        printf("Enter event type (up to %d characters): ", EVENT_SIZE - 1);
        scanf("%s", events[numEvents].eventType);

        printf("Enter event message (up to %d characters): ", EVENT_SIZE - 1);
        scanf("%s", events[numEvents].eventMessage);

        time_t currentTime;
        time(&currentTime);
        events[numEvents].eventTime = currentTime;

        logEvent(&events[numEvents]);
        numEvents++;

        if (numEvents >= MAX_EVENTS) {
            printf("Maximum number of events reached. Exiting...\n");
            break;
        }
    }

    return 0;
}