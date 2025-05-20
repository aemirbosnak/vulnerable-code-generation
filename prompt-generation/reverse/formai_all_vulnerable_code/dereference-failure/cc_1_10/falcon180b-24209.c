//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 1000

typedef struct {
    char ip[MAX_LOG_ENTRY_LENGTH];
    char url[MAX_LOG_ENTRY_LENGTH];
    char method[MAX_LOG_ENTRY_LENGTH];
    char status[MAX_LOG_ENTRY_LENGTH];
    char timestamp[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

int main() {
    FILE *logFile;
    char logLine[MAX_LOG_ENTRY_LENGTH];
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    // Open the log file
    logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    // Read each line from the log file
    while (fgets(logLine, MAX_LOG_ENTRY_LENGTH, logFile)!= NULL) {
        // Extract the fields from the log line
        char *ip = strtok(logLine, " ");
        char *url = strtok(NULL, " ");
        char *method = strtok(NULL, " ");
        char *status = strtok(NULL, " ");
        char *timestamp = strtok(NULL, " ");

        // Store the fields in a LogEntry struct
        strcpy(logEntries[numEntries].ip, ip);
        strcpy(logEntries[numEntries].url, url);
        strcpy(logEntries[numEntries].method, method);
        strcpy(logEntries[numEntries].status, status);
        strcpy(logEntries[numEntries].timestamp, timestamp);

        // Increment the number of entries
        numEntries++;
    }

    // Close the log file
    fclose(logFile);

    // Print the log entries
    printf("Log Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("IP: %s\nURL: %s\nMethod: %s\nStatus: %s\nTimestamp: %s\n\n",
               logEntries[i].ip, logEntries[i].url, logEntries[i].method, logEntries[i].status, logEntries[i].timestamp);
    }

    return 0;
}