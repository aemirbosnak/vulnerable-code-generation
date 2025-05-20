//FormAI DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char message[100];
} LogEntry;

int main() {
    int numEntries = 0;
    LogEntry entries[MAX_LOG_ENTRIES];

    // read log file
    FILE *logFile = fopen("example.log", "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (numEntries < MAX_LOG_ENTRIES && !feof(logFile)) {
        LogEntry newEntry;

        int year, month, day, hour, minute, second;
        fscanf(logFile, "%d-%d-%d %d:%d:%d %s",
            &year, &month, &day, &hour, &minute, &second, newEntry.message);

        newEntry.year = year;
        newEntry.month = month;
        newEntry.day = day;
        newEntry.hour = hour;
        newEntry.minute = minute;
        newEntry.second = second;

        entries[numEntries] = newEntry;
        numEntries++;
    }

    fclose(logFile);

    // analyze log data
    int errorCount = 0;
    int warningCount = 0;
    int infoCount = 0;

    for (int i = 0; i < numEntries; i++) {
        char* message = entries[i].message;

        if (strstr(message, "ERROR") != NULL) {
            errorCount++;
        } else if (strstr(message, "WARNING") != NULL) {
            warningCount++;
        } else {
            infoCount++;
        }
    }

    // print log analysis results
    printf("Log Analysis Results:\n");
    printf("Number of Errors: %d\n", errorCount);
    printf("Number of Warnings: %d\n", warningCount);
    printf("Number of Info Messages: %d\n", infoCount);

    return 0;
}