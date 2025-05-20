//Falcon-180B DATASET v1.0 Category: System event logger ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char event_type[20];
    char event_description[100];
    time_t event_timestamp;
} LogEntry;

int main() {
    FILE *log_file;
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    // Open log file for appending
    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read existing log entries from file
    while (fscanf(log_file, "%s %s %ld\n", log_entries[num_entries].event_type, log_entries[num_entries].event_description, &log_entries[num_entries].event_timestamp)!= EOF) {
        num_entries++;
    }

    // Add new log entries
    while (1) {
        char event_type[20];
        char event_description[100];
        time_t event_timestamp;

        printf("Enter event type (up to 20 characters): ");
        scanf("%s", event_type);

        printf("Enter event description (up to 100 characters): ");
        scanf("%s", event_description);

        event_timestamp = time(NULL);

        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Log is full.\n");
            break;
        }

        log_entries[num_entries].event_type[0] = '\0';
        strncat(log_entries[num_entries].event_type, event_type, 20);

        log_entries[num_entries].event_description[0] = '\0';
        strncat(log_entries[num_entries].event_description, event_description, 100);

        log_entries[num_entries].event_timestamp = event_timestamp;
        num_entries++;

        fprintf(log_file, "%s %s %ld\n", log_entries[num_entries - 1].event_type, log_entries[num_entries - 1].event_description, log_entries[num_entries - 1].event_timestamp);
    }

    // Close log file
    fclose(log_file);

    return 0;
}