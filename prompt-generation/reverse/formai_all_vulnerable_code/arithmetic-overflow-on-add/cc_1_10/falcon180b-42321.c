//Falcon-180B DATASET v1.0 Category: System event logger ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char event_type[50];
    char event_description[200];
    time_t event_timestamp;
} EventLogEntry;

void log_event(const char* event_type, const char* event_description) {
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);

    EventLogEntry entry = {
       .event_type = event_type,
       .event_description = event_description,
       .event_timestamp = now
    };

    FILE* log_file = fopen(EVENT_LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: could not open event log file.\n");
        return;
    }

    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d - %s - %s\n",
            current_time->tm_year + 1900,
            current_time->tm_mon + 1,
            current_time->tm_mday,
            current_time->tm_hour,
            current_time->tm_min,
            current_time->tm_sec,
            event_type,
            event_description);

    fclose(log_file);
}

int main() {
    log_event("System Start", "The system has started up.");

    // Simulate some events happening in the system
    for (int i = 0; i < 10; i++) {
        char event_description[100];
        sprintf(event_description, "Event %d happened.", i);
        log_event("Event", event_description);
        sleep(1);
    }

    log_event("System Shutdown", "The system is shutting down.");

    return 0;
}