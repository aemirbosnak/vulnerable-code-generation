//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

struct log_entry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [log_filename]\n", argv[0]);
        return 1;
    }

    char* log_filename = argv[1];
    FILE* log_file = fopen(log_filename, "r");

    if (log_file == NULL) {
        printf("Error: Unable to read file '%s'\n", log_filename);
        return 1;
    }

    int line_count = 0;
    struct log_entry log_entries[MAX_LINES];
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL && line_count < MAX_LINES) {
        char* token;
        struct log_entry entry;

        // Extract timestamp
        token = strtok(line, " ");
        strcpy(entry.timestamp, token);

        // Extract log level
        token = strtok(NULL, " ");
        strcpy(entry.level, token);

        // Extract log message
        token = strtok(NULL, "\n");
        strcpy(entry.message, token);

        log_entries[line_count] = entry;
        line_count++;
    }

    fclose(log_file);

    // Print log entries
    for (int i = 0; i < line_count; i++) {
        printf("[%s] %s: %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
    }

    // Count log entries by level
    int debug_count = 0;
    int info_count = 0;
    int warn_count = 0;
    int error_count = 0;

    for (int i = 0; i < line_count; i++) {
        if (strcmp(log_entries[i].level, "DEBUG") == 0) {
            debug_count++;
        } else if (strcmp(log_entries[i].level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(log_entries[i].level, "WARN") == 0) {
            warn_count++;
        } else if (strcmp(log_entries[i].level, "ERROR") == 0) {
            error_count++;
        }
    }

    printf("\nDEBUG count: %d\n", debug_count);
    printf("INFO count: %d\n", info_count);
    printf("WARN count: %d\n", warn_count);
    printf("ERROR count: %d\n", error_count);

    return 0;
}