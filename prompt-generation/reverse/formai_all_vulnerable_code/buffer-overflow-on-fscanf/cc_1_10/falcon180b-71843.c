//Falcon-180B DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000 // Maximum number of log entries

// Struct to hold log entry data
typedef struct {
    char event[100];
    char description[200];
    time_t timestamp;
} LogEntry;

void log_event(char* event, char* description) {
    LogEntry entry;
    strcpy(entry.event, event);
    strcpy(entry.description, description);
    entry.timestamp = time(NULL);

    // Open log file for appending
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return;
    }

    // Write log entry to file
    fprintf(log_file, "Event: %s\nDescription: %s\nTimestamp: %s\n", entry.event, entry.description, ctime(&entry.timestamp));
    fclose(log_file);
}

void print_log(FILE* log_file) {
    LogEntry entry;
    char buffer[512];

    // Read log entries from file
    rewind(log_file);
    while (fscanf(log_file, "Event: %s\nDescription: %[^\n]\nTimestamp: %s\n", entry.event, entry.description, buffer) == 3) {
        // Print log entry to console
        printf("Event: %s\nDescription: %s\nTimestamp: %s\n", entry.event, entry.description, buffer);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Example usage of log_event() function
    int num_events = rand() % 10 + 1;
    for (int i = 0; i < num_events; i++) {
        char event[20];
        sprintf(event, "Event %d", i + 1);
        char description[50];
        sprintf(description, "This is a test event.");
        log_event(event, description);
    }

    // Print log to console
    FILE* log_file = fopen("event_log.txt", "r");
    if (log_file!= NULL) {
        print_log(log_file);
        fclose(log_file);
    }

    return 0;
}