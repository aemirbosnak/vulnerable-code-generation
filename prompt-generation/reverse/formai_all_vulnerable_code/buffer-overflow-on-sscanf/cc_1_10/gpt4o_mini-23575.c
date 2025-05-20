//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1024

typedef struct {
    char timestamp[20];
    char logLevel[10];
    char message[200];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

// Function to parse a single log line
int parseLogLine(const char* line) {
    if (sscanf(line, "%19s %9s %[^\n]", logEntries[logCount].timestamp,
               logEntries[logCount].logLevel, logEntries[logCount].message) != 3) {
        return -1; // Parsing failed
    }
    logCount++;
    return 0; // Successfully parsed
}

// Function to display all log entries
void displayLogs() {
    printf("Timestamp\t\tLogLevel\tMessage\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s\t%s\t%s\n", logEntries[i].timestamp,
               logEntries[i].logLevel, logEntries[i].message);
    }
}

// Function to filter logs by log level
void filterLogs(const char* level) {
    printf("Filtered Logs (Level: %s):\n", level);
    printf("Timestamp\t\tMessage\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].logLevel, level) == 0) {
            printf("%s\t%s\n", logEntries[i].timestamp, logEntries[i].message);
        }
    }
}

// Function to load logs from a file
int loadLogs(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1; // Fail to open file
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (logCount >= MAX_LOG_ENTRIES) {
            fprintf(stderr, "Log limit reached, unable to load more logs!\n");
            break;
        }
        if (parseLogLine(line) != 0) {
            fprintf(stderr, "Failed to parse line: %s", line);
        }
    }
    fclose(file);
    return 0; // Loading successful
}

// Function to save logs to a file
int saveLogs(const char* filepath) {
    FILE* file = fopen(filepath, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    for (int i = 0; i < logCount; i++) {
        fprintf(file, "%s %s %s\n", logEntries[i].timestamp,
                logEntries[i].logLevel, logEntries[i].message);
    }
    fclose(file);
    return 0; // Saving successful
}

// Main function to demonstrate log analysis capabilities
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1; // Exit with error
    }

    if (loadLogs(argv[1]) != 0) {
        return 1; // Exit if loading logs fails
    }

    // Display all logs
    displayLogs();

    // Example filtering
    filterLogs("ERROR");

    // Save the logs to a new file
    if (saveLogs("output_logs.txt") != 0) {
        return 1; // Exit if saving logs fails
    }

    printf("Logs saved successfully to output_logs.txt\n");
    return 0; // Exit successfully
}