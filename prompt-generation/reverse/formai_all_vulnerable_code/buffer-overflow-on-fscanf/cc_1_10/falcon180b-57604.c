//Falcon-180B DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE_NAME "system_log.txt"

typedef struct {
    char event_type[20];
    char message[100];
    time_t timestamp;
} LogEntry;

int main() {
    FILE *log_file;
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    char event_type[20];
    char message[100];
    time_t current_time;

    // Open the log file for appending
    log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    // Read in any existing log entries
    rewind(log_file);
    while (fscanf(log_file, "%s %s %ld\n", log_entries[num_entries].event_type, log_entries[num_entries].message, &log_entries[num_entries].timestamp)!= EOF) {
        num_entries++;
    }

    // Prompt the user for the event type and message
    printf("Enter the event type (up to 20 characters): ");
    scanf("%s", event_type);
    printf("Enter the message (up to 100 characters): ");
    scanf("%s", message);

    // Get the current time
    time(&current_time);

    // Write the new log entry to the file
    if (num_entries >= MAX_LOG_ENTRIES) {
        printf("Error: log is full, cannot add new entry.\n");
        fclose(log_file);
        return 1;
    }
    strncpy(log_entries[num_entries].event_type, event_type, 20);
    strncpy(log_entries[num_entries].message, message, 100);
    log_entries[num_entries].timestamp = current_time;
    fwrite(&log_entries[num_entries], sizeof(LogEntry), 1, log_file);
    printf("Log entry added.\n");

    fclose(log_file);
    return 0;
}