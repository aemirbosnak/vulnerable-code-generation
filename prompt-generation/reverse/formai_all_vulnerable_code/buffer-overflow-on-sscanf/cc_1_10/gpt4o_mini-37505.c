//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOGS 1000

typedef struct {
    char timestamp[30];
    char logLevel[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logs[MAX_LOGS];
int logCount = 0;

void parseLogLine(const char *line) {
    if (logCount >= MAX_LOGS) {
        printf("Log limit reached, cannot parse more logs.\n");
        return;
    }

    sscanf(line, "%29s %9s %[^\n]", logs[logCount].timestamp, logs[logCount].logLevel, logs[logCount].message);
    logCount++;
}

void loadLogs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open log file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLogLine(line);
    }

    fclose(file);
}

void printLogsByLevel(const char *logLevel) {
    printf("Logs with level: %s\n", logLevel);
    printf("----------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        if (strcmp(logs[i].logLevel, logLevel) == 0) {
            printf("[%s] %s: %s\n", logs[i].timestamp, logs[i].logLevel, logs[i].message);
        }
    }
}

void printAllLogs() {
    printf("All Logs:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        printf("[%s] %s: %s\n", logs[i].timestamp, logs[i].logLevel, logs[i].message);
    }
}

void countLogLevels() {
    int infoCount = 0, warningCount = 0, errorCount = 0;

    for (int i = 0; i < logCount; i++) {
        if (strcmp(logs[i].logLevel, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(logs[i].logLevel, "WARNING") == 0) {
            warningCount++;
        } else if (strcmp(logs[i].logLevel, "ERROR") == 0) {
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

    loadLogs(argv[1]);

    printAllLogs();

    countLogLevels();

    printf("\n");
    printLogsByLevel("ERROR");
    printf("\n");
    printLogsByLevel("WARNING");

    return EXIT_SUCCESS;
}