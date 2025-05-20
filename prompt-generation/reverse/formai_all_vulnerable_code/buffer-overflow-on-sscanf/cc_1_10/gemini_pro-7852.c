//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Structure to store log entry data
typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function to read log entries from a file
int read_log_entries(FILE *fp, LogEntry *entries) {
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (line_count >= MAX_LINES) {
            fprintf(stderr, "Error: Maximum number of log entries exceeded\n");
            return -1;
        }

        LogEntry *entry = &entries[line_count];
        sscanf(line, "%s %s %[^\n]", entry->timestamp, entry->level, entry->message);
        line_count++;
    }

    return line_count;
}

// Function to print log entries
void print_log_entries(LogEntry *entries, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
    }
}

// Function to filter log entries by level
void filter_log_entries_by_level(LogEntry *entries, int count, char *level) {
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].level, level) == 0) {
            printf("%s %s %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
        }
    }
}

// Function to main
int main() {
    // Open log file
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open log file\n");
        return -1;
    }

    // Read log entries from file
    LogEntry entries[MAX_LINES];
    int count = read_log_entries(fp, entries);
    if (count < 0) {
        return -1;
    }

    // Close log file
    fclose(fp);

    // Print log entries
    printf("All log entries:\n");
    print_log_entries(entries, count);

    // Filter log entries by level
    printf("Log entries with level ERROR:\n");
    filter_log_entries_by_level(entries, count, "ERROR");

    return 0;
}