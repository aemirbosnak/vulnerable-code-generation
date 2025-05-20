//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains a specific word
int contains_word(char* string, char* word) {
    char* token;
    char* rest = string;
    while ((token = strtok_r(rest, " ", &rest))) {
        if (strcmp(token, word) == 0)
            return 1;
    }
    return 0;
}

// Struct to hold log entry information
typedef struct {
    char timestamp[24];
    char level[10];
    char message[100];
} LogEntry;

// Function to parse a log entry from a string and store in a LogEntry struct
LogEntry parse_log_entry(char* line) {
    char timestamp[24];
    char level[10];
    char message[100];
    sscanf(line, "%[^ ] %[^ ] %[^\n]", timestamp, level, message);
    LogEntry entry = {timestamp, level, message};
    return entry;
}

int main() {
    // Read log file
    FILE* log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file\n");
        return 1;
    }

    // Initialize variables to hold log analysis information
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;
    int debug_count = 0;
    int total_count = 0;

    // Parse each log entry and update analysis information
    char line[150];
    while (fgets(line, 150, log_file) != NULL) {
        LogEntry entry = parse_log_entry(line);
        if (contains_word(entry.level, "ERROR")) {
            error_count++;
        } else if (contains_word(entry.level, "WARNING")) {
            warning_count++;
        } else if (contains_word(entry.level, "INFO")) {
            info_count++;
        } else if (contains_word(entry.level, "DEBUG")) {
            debug_count++;
        }
        total_count++;
    }

    // Print log analysis results
    printf("Log Analysis Results:\n");
    printf("Total log entries: %d\n", total_count);
    printf("ERROR count: %d\n", error_count);
    printf("WARNING count: %d\n", warning_count);
    printf("INFO count: %d\n", info_count);
    printf("DEBUG count: %d\n", debug_count);

    // Close log file
    fclose(log_file);

    return 0;
}