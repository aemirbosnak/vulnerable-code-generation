//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char log_level[10];
    char message[200];
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

void parse_log_entry(const char *line) {
    if (log_count >= MAX_LOG_ENTRIES) {
        fprintf(stderr, "Maximum log entry limit reached!\n");
        return;
    }

    // Simulated parsing of log entry; expects "TIMESTAMP LOG_LEVEL MESSAGE"
    sscanf(line, "%19s %9s %[^\n]", log_entries[log_count].timestamp, log_entries[log_count].log_level, log_entries[log_count].message);
    log_count++;
}

void display_summary() {
    int error_count = 0, warning_count = 0;

    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(log_entries[i].log_level, "WARNING") == 0) {
            warning_count++;
        }
    }

    printf("\nLog Summary:\n");
    printf("Total entries: %d\n", log_count);
    printf("Total errors: %d\n", error_count);
    printf("Total warnings: %d\n", warning_count);
}

void display_errors() {
    printf("\nError Entries:\n");
    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, "ERROR") == 0) {
            printf("%s %s: %s\n", log_entries[i].timestamp, log_entries[i].log_level, log_entries[i].message);
        }
    }
}

void display_warnings() {
    printf("\nWarning Entries:\n");
    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, "WARNING") == 0) {
            printf("%s %s: %s\n", log_entries[i].timestamp, log_entries[i].log_level, log_entries[i].message);
        }
    }
}

void read_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open log file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parse_log_entry(line);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_log_file(argv[1]);
    display_summary();
    display_errors();
    display_warnings();

    return EXIT_SUCCESS;
}