//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
} LogLevel;

char* log_level_names[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
    "CRITICAL"
};

typedef struct {
    LogLevel level;
    char message[MAX_LINE_LENGTH];
} LogEntry;

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_filename>\n", argv[0]);
        exit(1);
    }

    char* log_filename = argv[1];
    FILE* log_file = fopen(log_filename, "r");

    if (log_file == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", log_filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    LogEntry entries[MAX_LINE_LENGTH];
    int num_entries = 0;

    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        char* level_name = strtok(line, ":");
        LogLevel level;

        if (strcmp(level_name, "DEBUG") == 0) {
            level = DEBUG;
        } else if (strcmp(level_name, "INFO") == 0) {
            level = INFO;
        } else if (strcmp(level_name, "WARNING") == 0) {
            level = WARNING;
        } else if (strcmp(level_name, "ERROR") == 0) {
            level = ERROR;
        } else if (strcmp(level_name, "CRITICAL") == 0) {
            level = CRITICAL;
        } else {
            fprintf(stderr, "Unknown log level: %s\n", level_name);
            exit(1);
        }

        char* message = strtok(NULL, "");
        LogEntry entry = { level, "" };
        strncpy(entry.message, message, strlen(message) - 1);
        entries[num_entries++] = entry;
    }

    int debug_count = 0;
    int info_count = 0;
    int warning_count = 0;
    int error_count = 0;
    int critical_count = 0;

    for (int i = 0; i < num_entries; ++i) {
        LogEntry entry = entries[i];

        switch (entry.level) {
            case DEBUG: ++debug_count; break;
            case INFO: ++info_count; break;
            case WARNING: ++warning_count; break;
            case ERROR: ++error_count; break;
            case CRITICAL: ++critical_count; break;
            default:
                fprintf(stderr, "Unknown log level: %d\n", entry.level);
                exit(1);
        }
    }

    printf("Log analysis for file: %s\n", log_filename);
    printf("DEBUG: %d\n", debug_count);
    printf("INFO: %d\n", info_count);
    printf("WARNING: %d\n", warning_count);
    printf("ERROR: %d\n", error_count);
    printf("CRITICAL: %d\n", critical_count);

    return 0;
}