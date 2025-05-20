//Falcon-180B DATASET v1.0 Category: System event logger ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define MAX_ENTRY_LENGTH 512

// Log entry structure
typedef struct {
    time_t timestamp;
    char message[MAX_ENTRY_LENGTH];
} LogEntry;

// Function to format a timestamp as a string
char* format_timestamp(time_t timestamp) {
    struct tm* tm = localtime(&timestamp);
    char buffer[32];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);
    return strdup(buffer);
}

// Function to log an entry
void log_entry(LogEntry* entry) {
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    fprintf(log_file, "%s - %s\n", format_timestamp(entry->timestamp), entry->message);
    fclose(log_file);
}

// Function to read the log and print entries
void print_log() {
    FILE* log_file = fopen("event_log.txt", "r");
    if (log_file == NULL) {
        printf("No log entries found.\n");
        return;
    }

    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, sizeof(line), log_file)!= NULL) {
        printf("%s", line);
    }

    fclose(log_file);
}

int main() {
    // Initialize log entries
    LogEntry log_entries[MAX_LOG_ENTRIES];
    memset(log_entries, 0, sizeof(log_entries));

    // Log some entries
    log_entry(&(log_entries[0]));
    log_entry(&(log_entries[1]));

    // Print the log
    print_log();

    return 0;
}