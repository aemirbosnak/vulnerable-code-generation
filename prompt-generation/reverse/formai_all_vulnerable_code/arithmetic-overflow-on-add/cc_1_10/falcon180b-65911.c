//Falcon-180B DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_ENTRY_SIZE 256

typedef struct {
    char message[LOG_ENTRY_SIZE];
    time_t timestamp;
} LogEntry;

FILE *logFile;
char logFilePath[256];
int currentLogEntryIndex = 0;

void initLogger() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(logFilePath, "log_%04d%02d%02d_%02d%02d%02d.txt",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);

    logFile = fopen(logFilePath, "w");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
}

void logMessage(char *message) {
    if (currentLogEntryIndex >= MAX_LOG_ENTRIES) {
        fclose(logFile);
        initLogger();
    }

    LogEntry entry;
    strncpy(entry.message, message, LOG_ENTRY_SIZE - 1);
    entry.message[LOG_ENTRY_SIZE - 1] = '\0';
    entry.timestamp = time(NULL);

    fprintf(logFile, "%s (%ld)\n", entry.message, entry.timestamp);
    currentLogEntryIndex++;
}

int main() {
    initLogger();

    logMessage("Logger initialized");

    for (int i = 0; i < 10; i++) {
        logMessage("Logging message #" + i);
        sleep(1);
    }

    fclose(logFile);
    return 0;
}