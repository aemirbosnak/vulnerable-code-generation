//Falcon-180B DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "event_log.txt"

typedef struct {
    char event_type[20];
    char event_message[100];
    time_t event_time;
} log_entry;

FILE *log_file;
int num_entries = 0;

void initialize_log() {
    log_file = fopen(LOG_FILE, "w");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
}

void write_log_entry(log_entry entry) {
    fprintf(log_file, "Event Type: %s\nMessage: %s\nTimestamp: %s\n",
            entry.event_type, entry.event_message, ctime(&entry.event_time));
}

void close_log() {
    fclose(log_file);
}

int main() {
    initialize_log();

    while (1) {
        log_entry entry;
        printf("Enter event type (up to 20 characters): ");
        scanf("%s", entry.event_type);

        printf("Enter event message (up to 100 characters): ");
        scanf("%[^\n]", entry.event_message);

        entry.event_time = time(NULL);
        write_log_entry(entry);

        if (++num_entries >= MAX_LOG_ENTRIES) {
            printf("Log file limit reached. Exiting...\n");
            close_log();
            exit(0);
        }
    }

    return 0;
}