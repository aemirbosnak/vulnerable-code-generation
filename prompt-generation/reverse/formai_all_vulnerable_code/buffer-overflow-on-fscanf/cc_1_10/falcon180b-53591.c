//Falcon-180B DATASET v1.0 Category: System event logger ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char event_type[20];
    char event_message[200];
    time_t timestamp;
} LogEntry;

void log_event(char* event_type, char* event_message) {
    FILE* log_file;
    log_file = fopen(LOG_FILE, "a");

    if (log_file == NULL) {
        printf("Error: Could not open log file\n");
        return;
    }

    LogEntry entry;
    strcpy(entry.event_type, event_type);
    strcpy(entry.event_message, event_message);
    entry.timestamp = time(NULL);

    fprintf(log_file, "%s, %s, %ld\n", entry.event_type, entry.event_message, entry.timestamp);

    fclose(log_file);
}

void display_log(void) {
    FILE* log_file;
    log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        printf("Error: Could not open log file\n");
        return;
    }

    LogEntry entry;
    while (fscanf(log_file, "%s, %s, %ld", entry.event_type, entry.event_message, &entry.timestamp) == 3) {
        printf("%s, %s, %ld\n", entry.event_type, entry.event_message, entry.timestamp);
    }

    fclose(log_file);
}

int main(void) {
    log_event("System Start", "Program started successfully");
    log_event("Error", "An error occurred");
    log_event("Warning", "A warning message");

    display_log();

    return 0;
}