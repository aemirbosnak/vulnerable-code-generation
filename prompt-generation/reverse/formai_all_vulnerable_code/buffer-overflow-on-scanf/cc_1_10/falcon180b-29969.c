//Falcon-180B DATASET v1.0 Category: System event logger ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    time_t timestamp;
    char message[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

int main() {
    FILE *logFile;
    char logFilePath[MAX_LOG_ENTRY_LENGTH];
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numLogEntries = 0;
    time_t lastLogEntryTime = 0;

    printf("Enter log file path: ");
    scanf("%s", logFilePath);

    logFile = fopen(logFilePath, "a");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (1) {
        printf("Enter message: ");
        scanf("%s", logEntries[numLogEntries].message);

        if (numLogEntries == MAX_LOG_ENTRIES - 1) {
            printf("Log file is full.\n");
            break;
        }

        time(&logEntries[numLogEntries].timestamp);
        if (lastLogEntryTime == 0) {
            strcpy(logEntries[numLogEntries].message, "Program started");
        } else {
            sprintf(logEntries[numLogEntries].message, "%.24s: %s", ctime(&logEntries[numLogEntries].timestamp), logEntries[numLogEntries].message);
        }

        fprintf(logFile, "%s\n", logEntries[numLogEntries].message);
        fflush(logFile);

        numLogEntries++;
        lastLogEntryTime = logEntries[numLogEntries - 1].timestamp;
    }

    fclose(logFile);

    return 0;
}