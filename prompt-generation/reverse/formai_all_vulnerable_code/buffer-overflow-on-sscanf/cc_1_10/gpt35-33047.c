//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Define a struct to hold each log entry
typedef struct {
    char date[11];
    char time[9];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Define a struct to hold the log data
typedef struct {
    LogEntry* entries;
    int numEntries;
} LogData;

// Function to parse a log file
LogData parseLogFile(char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening log file: %s\n", filename);
        exit(1);
    }

    // Create the log data struct
    LogData logData;
    logData.numEntries = 0;
    logData.entries = NULL;

    // Read each line of the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Parse the log entry
        LogEntry entry;
        sscanf(line, "%10s %8s %9s %[^\n]", entry.date, entry.time, entry.level, entry.message);

        // Add the entry to the log data struct
        logData.numEntries++;
        logData.entries = realloc(logData.entries, logData.numEntries * sizeof(LogEntry));
        logData.entries[logData.numEntries-1] = entry;
    }

    // Close the file
    fclose(file);

    return logData;
}

// Function to print a log entry
void printLogEntry(LogEntry entry) {
    printf("%s %s %s %s\n", entry.date, entry.time, entry.level, entry.message);
}

int main() {
    // Parse the log file
    LogData logData = parseLogFile("example.log");

    // Print the log entries
    for (int i = 0; i < logData.numEntries; i++) {
        printLogEntry(logData.entries[i]);
    }

    // Free the log data memory
    free(logData.entries);

    return 0;
}