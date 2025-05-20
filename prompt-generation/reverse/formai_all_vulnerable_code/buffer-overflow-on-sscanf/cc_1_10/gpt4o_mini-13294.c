//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

// Enum for log levels
typedef enum {
    INFO,
    WARNING,
    ERROR,
} LogLevel;

// Structure to hold log entry
typedef struct {
    LogLevel level;
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function prototypes
void analyzeLogs(LogEntry logs[], int count);
void printLogSummary(LogEntry logs[], int count);
LogLevel parseLogLevel(const char *levelStr);
void toLowerCase(char *str);

// Main function
int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    LogEntry logs[MAX_LOG_LINES];
    int logCount = 0;

    // Open log file
    file = fopen("logs.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open log file.\n");
        return EXIT_FAILURE;
    }

    // Read each line from the log file
    while (fgets(line, sizeof(line), file) && logCount < MAX_LOG_LINES) {
        char levelStr[10];

        // Expected line format: "[LOG_LEVEL] message"
        if (sscanf(line, "[%9[^]]] %[^\n]", levelStr, logs[logCount].message) == 2) {
            logs[logCount].level = parseLogLevel(levelStr);
            logCount++;
        } else {
            fprintf(stderr, "Invalid log format: %s\n", line);
        }
    }

    fclose(file);

    // Analyze and print log summary
    analyzeLogs(logs, logCount);

    return EXIT_SUCCESS;
}

// Function to analyze logs
void analyzeLogs(LogEntry logs[], int count) {
    printf("Analyzing Logs...\n");
    printLogSummary(logs, count);
}

// Function to print a summary of logs
void printLogSummary(LogEntry logs[], int count) {
    int infoCount = 0, warningCount = 0, errorCount = 0;

    for (int i = 0; i < count; i++) {
        switch (logs[i].level) {
            case INFO: infoCount++; break;
            case WARNING: warningCount++; break;
            case ERROR: errorCount++; break;
        }
    }

    printf("Log Summary:\n");
    printf("INFO: %d\n", infoCount);
    printf("WARNING: %d\n", warningCount);
    printf("ERROR: %d\n", errorCount);
}

// Function to parse log level
LogLevel parseLogLevel(const char *levelStr) {
    char lowerStr[10];
    strcpy(lowerStr, levelStr);
    toLowerCase(lowerStr);

    if (strcmp(lowerStr, "info") == 0) return INFO;
    else if (strcmp(lowerStr, "warning") == 0) return WARNING;
    else if (strcmp(lowerStr, "error") == 0) return ERROR;
    else {
        fprintf(stderr, "Unknown log level: %s\n", levelStr);
        return INFO;  // Default log level
    }
}

// Function to convert string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}