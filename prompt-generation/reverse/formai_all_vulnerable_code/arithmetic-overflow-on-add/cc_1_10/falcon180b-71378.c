//Falcon-180B DATASET v1.0 Category: System event logger ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000
#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char type[20];
    char message[200];
    struct tm timestamp;
} Event;

FILE *eventLogFile;
pthread_mutex_t eventLogMutex;
int eventCount = 0;

void writeEventToFile(Event *event) {
    pthread_mutex_lock(&eventLogMutex);
    fprintf(eventLogFile, "%s - %s\n", event->type, event->message);
    fprintf(eventLogFile, "Timestamp: %d-%02d-%02d %02d:%02d:%02d\n\n",
            event->timestamp.tm_year + 1900, event->timestamp.tm_mon + 1,
            event->timestamp.tm_mday, event->timestamp.tm_hour,
            event->timestamp.tm_min, event->timestamp.tm_sec);
    fflush(eventLogFile);
    pthread_mutex_unlock(&eventLogMutex);
}

void *eventLoggerThread(void *arg) {
    while (1) {
        pthread_mutex_lock(&eventLogMutex);
        if (eventCount >= MAX_EVENTS) {
            fprintf(stderr, "Event log is full. Discarding new events.\n");
            pthread_mutex_unlock(&eventLogMutex);
            break;
        }
        pthread_mutex_unlock(&eventLogMutex);

        sleep(1);
    }

    return NULL;
}

int main() {
    eventLogFile = fopen(EVENT_LOG_FILE, "w");
    if (eventLogFile == NULL) {
        fprintf(stderr, "Failed to open event log file.\n");
        return 1;
    }

    pthread_t eventLoggerThreadId;
    pthread_create(&eventLoggerThreadId, NULL, eventLoggerThread, NULL);

    while (1) {
        Event event;
        memset(&event, 0, sizeof(Event));

        printf("Enter event type (max 20 characters): ");
        scanf("%s", event.type);

        printf("Enter event message (max 200 characters): ");
        scanf("%[^\n]", event.message);

        gettimeofday(&event.timestamp, NULL);

        writeEventToFile(&event);

        eventCount++;
    }

    return 0;
}