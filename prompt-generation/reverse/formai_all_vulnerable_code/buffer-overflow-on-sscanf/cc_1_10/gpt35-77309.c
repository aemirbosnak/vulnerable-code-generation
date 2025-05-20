//FormAI DATASET v1.0 Category: Log analysis ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 1000

typedef struct {
    char date[20];
    char time[20];
    char level[10];
    char message[100];
} LogEntry;

int readLogFile(char* fileName, LogEntry logList[]);
void printLogList(LogEntry logList[], int logCount);
void printLogLevelCount(LogEntry logList[], int logCount);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [log file name]\n", argv[0]);
        exit(1);
    }

    LogEntry logList[MAX_LOGS];
    int logCount = readLogFile(argv[1], logList);

    printf("Log file: %s\n", argv[1]);
    printf("Total log entries: %d\n\n", logCount);

    printf("===== Log entries =====\n");
    printLogList(logList, logCount);

    printf("\n===== Log level counts =====\n");
    printLogLevelCount(logList, logCount);

    return 0;
}

// Read the log file and store each entry in logList
// Returns the number of log entries read
int readLogFile(char* fileName, LogEntry logList[]) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    int logCount = 0;
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        LogEntry logEntry;
        sscanf(line, "%s %s %s %s", logEntry.date, logEntry.time, logEntry.level, logEntry.message);
        memcpy(&logList[logCount], &logEntry, sizeof(LogEntry));
        logCount++;
    }

    fclose(fp);
    return logCount;
}

// Print all log entries in logList
void printLogList(LogEntry logList[], int logCount) {
    for (int i = 0; i < logCount; i++) {
        LogEntry logEntry = logList[i];
        printf("[%s %s] %s: %s\n", logEntry.date, logEntry.time, logEntry.level, logEntry.message);
    }
}

// Print the count of each log level in logList
void printLogLevelCount(LogEntry logList[], int logCount) {
    int debugCount = 0;
    int infoCount = 0;
    int warnCount = 0;
    int errorCount = 0;

    for (int i = 0; i < logCount; i++) {
        LogEntry logEntry = logList[i];
        if (strcmp(logEntry.level, "DEBUG") == 0) {
            debugCount++;
        } else if (strcmp(logEntry.level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(logEntry.level, "WARN") == 0) {
            warnCount++;
        } else if (strcmp(logEntry.level, "ERROR") == 0) {
            errorCount++;
        }
    }

    printf("DEBUG: %d\n", debugCount);
    printf("INFO: %d\n", infoCount);
    printf("WARN: %d\n", warnCount);
    printf("ERROR: %d\n", errorCount);
}