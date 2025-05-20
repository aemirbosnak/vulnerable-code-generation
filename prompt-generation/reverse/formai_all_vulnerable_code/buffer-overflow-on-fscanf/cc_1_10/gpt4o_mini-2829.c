//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

// Enum for log level
typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG
} LogLevel;

typedef struct {
    time_t timestamp;
    LogLevel level;
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function to return string representation of log level
const char* level_to_string(LogLevel level) {
    switch(level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case DEBUG: return "DEBUG";
        default: return "UNKNOWN";
    }
}

// Function to read log entries from a file
int read_logs(const char* filename, LogEntry logs[], int max_entries) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open log file");
        return -1;
    }

    int count = 0;
    while (count < max_entries && fscanf(file, "%ld %d %[^\n]\n", 
        &logs[count].timestamp, (int*)&logs[count].level, logs[count].message) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to filter logs by level
void filter_logs_by_level(LogEntry logs[], int count, LogLevel level) {
    printf("\nFiltered Logs with Level %s:\n", level_to_string(level));
    for (int i = 0; i < count; i++) {
        if (logs[i].level == level) {
            printf("[%s] %s\n", ctime(&logs[i].timestamp), logs[i].message);
        }
    }
}

// Function to display all logs
void display_all_logs(LogEntry logs[], int count) {
    printf("\nAll Log Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("[%s] %s: %s\n", ctime(&logs[i].timestamp), level_to_string(logs[i].level), logs[i].message);
    }
}

// Function to count log levels
void count_log_levels(LogEntry logs[], int count) {
    int level_count[4] = {0}; // Array for counting log levels

    for (int i = 0; i < count; i++) {
        level_count[logs[i].level]++;
    }

    printf("\nCount of each Log Level:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", level_to_string(i), level_count[i]);
    }
}

// Function to write a summary to a file
void write_summary(const char* filename, LogEntry logs[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Could not open summary file");
        return;
    }

    fprintf(file, "Log Summary:\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "[%s] %s: %s\n", ctime(&logs[i].timestamp), level_to_string(logs[i].level), logs[i].message);
    }

    fclose(file);
}

// Main function
int main() {
    LogEntry logs[MAX_LOG_LINES];
    const char* log_filename = "logs.txt";  // Input log file
    const char* summary_filename = "summary.txt";  // Output summary file
    int log_count = read_logs(log_filename, logs, MAX_LOG_LINES);

    if (log_count < 0) {
        return EXIT_FAILURE;  // Exit if there's an error reading logs
    }

    display_all_logs(logs, log_count);
    filter_logs_by_level(logs, log_count, ERROR);
    count_log_levels(logs, log_count);
    write_summary(summary_filename, logs, log_count);

    printf("\nSummary written to %s\n", summary_filename);
    return EXIT_SUCCESS;
}