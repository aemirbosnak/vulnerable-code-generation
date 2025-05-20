//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for log levels
#define BUFFER_SIZE 256
#define LOG_FILE "app.log"

// Enum to represent log levels
typedef enum {
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_UNKNOWN
} LogLevel;

// Function to get the log level from the string
LogLevel getLogLevel(const char *level) {
    if (strcmp(level, "INFO") == 0) {
        return LOG_INFO;
    } else if (strcmp(level, "WARN") == 0) {
        return LOG_WARN;
    } else if (strcmp(level, "ERROR") == 0) {
        return LOG_ERROR;
    } else {
        return LOG_UNKNOWN;
    }
}

// Function to print colored log level
void printColoredLogLevel(LogLevel level) {
    switch (level) {
        case LOG_INFO:
            printf("\033[0;32mINFO\033[0m"); // Green
            break;
        case LOG_WARN:
            printf("\033[1;33mWARN\033[0m"); // Yellow
            break;
        case LOG_ERROR:
            printf("\033[1;31mERROR\033[0m"); // Red
            break;
        default:
            printf("UNKNOWN");
            break;
    }
}

// Main function to analyze logs
int main() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        printf("Could not open the log file: %s\n", LOG_FILE);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int logCount[3] = {0}; // Index 0 for INFO, 1 for WARN, 2 for ERROR

    printf("🎉 Welcome to the Log Analyzer! 🎉\n");
    printf("Analyzing the log file: %s\n", LOG_FILE);
    printf("===========================================\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char level[10];
        // Assuming log entries are in the format: "LEVEL: message"
        sscanf(buffer, "%[^:]:", level);
        LogLevel logLevel = getLogLevel(level);

        switch (logLevel) {
            case LOG_INFO:
                logCount[0]++;
                break;
            case LOG_WARN:
                logCount[1]++;
                break;
            case LOG_ERROR:
                logCount[2]++;
                break;
            default:
                break;
        }
    }

    fclose(file);

    printf("📊 Analysis Summary:\n");
    printf("===========================================\n");
    printf("Total INFO logs:    ");
    printColoredLogLevel(LOG_INFO);
    printf(": %d\n", logCount[0]);

    printf("Total WARN logs:    ");
    printColoredLogLevel(LOG_WARN);
    printf(": %d\n", logCount[1]);

    printf("Total ERROR logs:   ");
    printColoredLogLevel(LOG_ERROR);
    printf(": %d\n", logCount[2]);

    printf("===========================================\n");
    printf("🧹 Log analysis complete! Have a great day! 🎈\n");

    return 0;
}