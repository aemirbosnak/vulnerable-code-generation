//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the log entry details
typedef struct {
    char timestamp[50];
    char logLevel[10];
    char message[100];
} LogEntry;

// Function prototypes
void readLogFile(const char* filename, LogEntry* logEntries, int* count);
void displayLogs(const LogEntry* logEntries, int count);
void filterLogsByLevel(const LogEntry* logEntries, int count, const char* level);

int main() {
    // Declare an array of LogEntry to store log entries
    LogEntry logEntries[100];
    int count = 0;

    // Gratefully read the log file
    readLogFile("application.log", logEntries, &count);

    // Display all logs
    printf("All Logs:\n");
    displayLogs(logEntries, count);

    // Gratefully filter logs by level
    char logLevel[10];
    printf("Enter log level to filter (INFO, ERROR, DEBUG): ");
    scanf("%s", logLevel);
    printf("\nLogs with level '%s':\n", logLevel);
    filterLogsByLevel(logEntries, count, logLevel);

    return 0;
}

// Function to read log entries from a file
void readLogFile(const char* filename, LogEntry* logEntries, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open log file.\n");
        return;
    }

    while (fgets(logEntries[*count].timestamp, sizeof(logEntries[*count].timestamp), file) != NULL) {
        // Clean up newline characters and read log level and message
        strtok(logEntries[*count].timestamp, "\n");
        fgets(logEntries[*count].logLevel, sizeof(logEntries[*count].logLevel), file);
        strtok(logEntries[*count].logLevel, "\n");
        fgets(logEntries[*count].message, sizeof(logEntries[*count].message), file);
        strtok(logEntries[*count].message, "\n");
        
        (*count)++;
    }

    fclose(file);
    printf("Successfully read %d log entries from '%s'.\n", *count, filename);
}

// Function to display logs
void displayLogs(const LogEntry* logEntries, int count) {
    for (int i = 0; i < count; i++) {
        printf("[%s] %s: %s\n", logEntries[i].timestamp, logEntries[i].logLevel, logEntries[i].message);
    }
}

// Function to filter logs by log level
void filterLogsByLevel(const LogEntry* logEntries, int count, const char* level) {
    for (int i = 0; i < count; i++) {
        if (strcmp(logEntries[i].logLevel, level) == 0) {
            printf("[%s] %s: %s\n", logEntries[i].timestamp, logEntries[i].logLevel, logEntries[i].message);
        }
    }
}