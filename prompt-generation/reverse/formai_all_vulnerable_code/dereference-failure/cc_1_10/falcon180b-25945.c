//Falcon-180B DATASET v1.0 Category: System event logger ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 256

typedef struct {
    char message[MAX_LOG_ENTRY_LENGTH];
    time_t timestamp;
} LogEntry;

FILE *logFile;
int numEntries = 0;

void initLog() {
    logFile = fopen("event_log.txt", "w");
    if (logFile == NULL) {
        printf("Error: Failed to open event log file.\n");
        exit(1);
    }
}

void logEvent(const char *message) {
    if (numEntries >= MAX_LOG_ENTRIES) {
        printf("Warning: Event log is full. Discarding new entry.\n");
        return;
    }

    time_t currentTime = time(NULL);
    struct tm *timeInfo = localtime(&currentTime);

    strftime(message, MAX_LOG_ENTRY_LENGTH, "%Y-%m-%d %H:%M:%S", timeInfo);
    strcat(message, ": ");
    strcat(message, message);

    fprintf(logFile, "%s\n", message);
    numEntries++;
}

void closeLog() {
    fclose(logFile);
}

int main() {
    initLog();

    logEvent("Program started");

    // Example events
    logEvent("Button clicked");
    logEvent("File saved");
    logEvent("Network connection established");

    closeLog();

    return 0;
}