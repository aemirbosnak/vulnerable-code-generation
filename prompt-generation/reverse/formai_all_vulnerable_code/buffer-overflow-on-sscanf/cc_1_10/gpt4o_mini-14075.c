//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function prototypes
void readLogFile(const char *filename, LogEntry *logs, int *logCount);
void analyzeLogs(LogEntry *logs, int logCount);
void printLogEntry(LogEntry entry);

int main() {
    LogEntry logs[MAX_LOG_ENTRIES];
    int logCount = 0;
    const char *filename = "mystical_forest.log";

    printf("Entering the digital forest of logs...\n");
    readLogFile(filename, logs, &logCount);
    analyzeLogs(logs, logCount);
    
    printf("Exiting the digital forest, until next time!\n");
    return 0;
}

void readLogFile(const char *filename, LogEntry *logs, int *logCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open the log file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && *logCount < MAX_LOG_ENTRIES) {
        sscanf(line, "%s %s %[^\n]", logs[*logCount].timestamp, logs[*logCount].level, logs[*logCount].message);
        (*logCount)++;
    }

    fclose(file);
    printf("Gathered %d mystical log entries from the forest.\n", *logCount);
}

void analyzeLogs(LogEntry *logs, int logCount) {
    int errorCount = 0, warningCount = 0, infoCount = 0;
    for (int i = 0; i < logCount; i++) {
        if (strcasecmp(logs[i].level, "ERROR") == 0) {
            errorCount++;
            printLogEntry(logs[i]);
        } else if (strcasecmp(logs[i].level, "WARNING") == 0) {
            warningCount++;
        } else if (strcasecmp(logs[i].level, "INFO") == 0) {
            infoCount++;
        }
    }
    
    printf("\nLog Analysis Summary:\n");
    printf("Total Error Messages: %d\n", errorCount);
    printf("Total Warning Messages: %d\n", warningCount);
    printf("Total Info Messages: %d\n", infoCount);
    
    if (errorCount == 0) {
        printf("The forest is calm, no errors to report!\n");
    } else {
        printf("Beware! The forest holds %d errors, tread carefully!\n", errorCount);
    }
}

void printLogEntry(LogEntry entry) {
    printf("[%s] %s: %s\n", entry.timestamp, entry.level, entry.message);
}