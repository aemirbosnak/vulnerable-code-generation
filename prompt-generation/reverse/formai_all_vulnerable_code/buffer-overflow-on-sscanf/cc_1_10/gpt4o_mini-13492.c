//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char log_level[10];
    char message[MAX_LOG_LINE_LENGTH];
} LogEntry;

void parseLogLine(const char *line, LogEntry *entry) {
    sscanf(line, "%s %s %[^\n]s", entry->timestamp, entry->log_level, entry->message);
}

void displayLogEntry(const LogEntry *entry) {
    printf("[%s] [%s]: %s\n", entry->timestamp, entry->log_level, entry->message);
}

int readLogFile(const char *filename, LogEntry logEntries[], int maxEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open log file");
        return -1;
    }
    
    char line[MAX_LOG_LINE_LENGTH];
    int entryCount = 0;
    
    while (fgets(line, sizeof(line), file) && entryCount < maxEntries) {
        parseLogLine(line, &logEntries[entryCount]);
        entryCount++;
    }

    fclose(file);
    return entryCount;
}

void filterLogByLevel(const LogEntry logEntries[], int entryCount, const char *level) {
    printf("Log entries of level: %s\n", level);
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(logEntries[i].log_level, level) == 0) {
            displayLogEntry(&logEntries[i]);
        }
    }
}

void sortLogEntriesByTime(LogEntry logEntries[], int entryCount) {
    for (int i = 0; i < entryCount - 1; i++) {
        for (int j = i + 1; j < entryCount; j++) {
            if (strcmp(logEntries[i].timestamp, logEntries[j].timestamp) > 0) {
                LogEntry temp = logEntries[i];
                logEntries[i] = logEntries[j];
                logEntries[j] = temp;
            }
        }
    }
}

void countLogLevels(const LogEntry logEntries[], int entryCount) {
    int infoCount = 0, warningCount = 0, errorCount = 0;

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(logEntries[i].log_level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(logEntries[i].log_level, "WARNING") == 0) {
            warningCount++;
        } else if (strcmp(logEntries[i].log_level, "ERROR") == 0) {
            errorCount++;
        }
    }

    printf("Log Level Counts:\n");
    printf("INFO: %d\n", infoCount);
    printf("WARNING: %d\n", warningCount);
    printf("ERROR: %d\n", errorCount);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *logFile = argv[1];
    LogEntry logEntries[MAX_LOG_ENTRIES];

    int entryCount = readLogFile(logFile, logEntries, MAX_LOG_ENTRIES);
    if (entryCount < 0) {
        return EXIT_FAILURE;
    }

    // Display all log entries
    printf("All log entries:\n");
    for (int i = 0; i < entryCount; i++) {
        displayLogEntry(&logEntries[i]);
    }

    // Filter logs by level
    filterLogByLevel(logEntries, entryCount, "ERROR");

    // Sort log entries by timestamp
    sortLogEntriesByTime(logEntries, entryCount);
    printf("\nSorted log entries by timestamp:\n");
    for (int i = 0; i < entryCount; i++) {
        displayLogEntry(&logEntries[i]);
    }

    // Count occurrence of log levels
    countLogLevels(logEntries, entryCount);

    return EXIT_SUCCESS;
}