//Falcon-180B DATASET v1.0 Category: System event logger ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_LOG_ENTRIES 100
#define MAX_EVENT_LENGTH 256

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} LogEntry;

typedef struct {
    LogEntry entries[MAX_LOG_ENTRIES];
    int numEntries;
} EventLog;

void initEventLog(EventLog* log) {
    memset(log, 0, sizeof(EventLog));
}

int addEvent(EventLog* log, const char* event) {
    if (log->numEntries >= MAX_LOG_ENTRIES) {
        return -1;
    }

    LogEntry entry;
    strncpy(entry.event, event, MAX_EVENT_LENGTH);
    entry.timestamp = time(NULL);

    log->entries[log->numEntries++] = entry;

    return 0;
}

int printEventLog(const EventLog* log) {
    if (log->numEntries == 0) {
        printf("No events logged.\n");
        return 0;
    }

    printf("Event log:\n");
    for (int i = 0; i < log->numEntries; ++i) {
        printf("%s (%ld)\n", log->entries[i].event, log->entries[i].timestamp);
    }

    return 0;
}

int main() {
    EventLog log;
    initEventLog(&log);

    int choice;
    do {
        printf("Choose an option:\n"
               "1. Log an event\n"
               "2. Print event log\n"
               "3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char event[MAX_EVENT_LENGTH];
                printf("Enter event to log (max %d characters):\n", MAX_EVENT_LENGTH - 1);
                scanf("%s", event);
                addEvent(&log, event);
                break;
            }
        case 2:
            printEventLog(&log);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}