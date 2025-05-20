//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of log entries to analyze
#define MAX_LOG_ENTRIES 1000

// Define the maximum length of a log entry
#define MAX_LOG_ENTRY_LENGTH 100

// Define the structure for a log entry
typedef struct {
    char ip[16];
    char date[20];
    char time[20];
    char request[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

// Function to compare two log entries based on their IP addresses
int compareLogEntries(const void* a, const void* b) {
    const LogEntry* entryA = (const LogEntry*)a;
    const LogEntry* entryB = (const LogEntry*)b;
    return strcmp(entryA->ip, entryB->ip);
}

// Function to analyze the log file and count the number of requests per IP address
void analyzeLogFile(const char* logFilePath) {
    FILE* logFile = fopen(logFilePath, "r");
    if (logFile == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numLogEntries = 0;

    // Read the log file and store the entries in the array
    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, logFile)!= NULL) {
        if (numLogEntries >= MAX_LOG_ENTRIES) {
            printf("Warning: maximum number of log entries reached.\n");
            break;
        }

        LogEntry* entry = &logEntries[numLogEntries];
        sscanf(line, "%15s %19s %19s \"%[^\"]\"", entry->ip, entry->date, entry->time, entry->request);
        numLogEntries++;
    }

    fclose(logFile);

    // Sort the log entries by IP address
    qsort(logEntries, numLogEntries, sizeof(LogEntry), compareLogEntries);

    // Print the results
    printf("Number of requests per IP address:\n");
    for (int i = 0; i < numLogEntries; i++) {
        LogEntry* entry = &logEntries[i];
        printf("%s - %d requests\n", entry->ip, i+1);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        exit(1);
    }

    analyzeLogFile(argv[1]);

    return 0;
}