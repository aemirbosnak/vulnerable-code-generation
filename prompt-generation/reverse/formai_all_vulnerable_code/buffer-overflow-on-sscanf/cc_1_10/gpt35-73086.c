//FormAI DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum buffer size for each line in the log file
#define LINE_BUFFER_SIZE 256

// Define struct to hold relevant information from each log line
typedef struct {
    char date[11];
    char time[9];
    char type[8];
    char message[LINE_BUFFER_SIZE - 20];
} LogLine;

int main(int argc, char *argv[]) {
    // Check if log file argument was provided
    if (argc < 2) {
        printf("Please specify a log file to analyze.\n");
        return 1;
    }

    // Open log file for reading
    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Could not open log file %s.\n", argv[1]);
        return 1;
    }

    // Initialize variables for log analysis
    int numFatalErrors = 0;
    int numWarnings = 0;
    int numInfoMessages = 0;
    int numDebugMessages = 0;
    LogLine currentLine;
    char currentBuffer[LINE_BUFFER_SIZE];

    // Loop through log file line by line and analyze each one
    while (fgets(currentBuffer, LINE_BUFFER_SIZE, logFile) != NULL) {
        // Skip empty lines and comments
        if (strlen(currentBuffer) < 2 || currentBuffer[0] == '#') {
            continue;
        }

        // Parse relevant information from current log line
        sscanf(currentBuffer, "%s %s %s %[^\n]s", currentLine.date, currentLine.time, currentLine.type, currentLine.message);

        // Determine type of log message and increment relevant counter
        if (strcmp(currentLine.type, "FATAL") == 0) {
            numFatalErrors++;
        } else if (strcmp(currentLine.type, "WARNING") == 0) {
            numWarnings++;
        } else if (strcmp(currentLine.type, "INFO") == 0) {
            numInfoMessages++;
        } else if (strcmp(currentLine.type, "DEBUG") == 0) {
            numDebugMessages++;
        } else {
            printf("Unrecognized log type on line: %s", currentBuffer);
        }
    }

    // Print summary of log analysis
    printf("Log analysis of file '%s':\n", argv[1]);
    printf("  %d fatal errors\n", numFatalErrors);
    printf("  %d warnings\n", numWarnings);
    printf("  %d info messages\n", numInfoMessages);
    printf("  %d debug messages\n", numDebugMessages);

    // Clean up resources and exit
    fclose(logFile);
    return 0;
}