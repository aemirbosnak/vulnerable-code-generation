//FormAI DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_LENGTH 256

typedef struct {
    char time[MAX_LOG_LENGTH];
    char level[MAX_LOG_LENGTH];
    char message[MAX_LOG_LENGTH];
} LogEntry;

void readLogFile(FILE* logFile, LogEntry* logs, int* numLogs) {
    char buffer[MAX_LINE_LENGTH];
    *numLogs = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, logFile)) {
        sscanf(buffer, "%s %s %[^\n]", logs[*numLogs].time, logs[*numLogs].level, logs[*numLogs].message);
        (*numLogs)++;
    }
}

void printLogs(LogEntry* logs, int numLogs) {
    for (int i = 0; i < numLogs; ++i) {
        printf("[%s] %s: %s\n", logs[i].time, logs[i].level, logs[i].message);
    }
}

void filterLogsByLevel(LogEntry* logs, int numLogs, char* level, LogEntry* filteredLogs, int* numFilteredLogs) {
    *numFilteredLogs = 0;

    for (int i = 0; i < numLogs; ++i) {
        if (strcmp(logs[i].level, level) == 0) {
            memcpy(&filteredLogs[*numFilteredLogs], &logs[i], sizeof(LogEntry));
            (*numFilteredLogs)++;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <log file> <log level>\n", argv[0]);
        return 1;
    }

    FILE* logFile = fopen(argv[1], "r");
    if (!logFile) {
        printf("Unable to open log file %s\n", argv[1]);
        return 1;
    }

    LogEntry* logs = (LogEntry*)malloc(MAX_LINE_LENGTH * sizeof(LogEntry));
    if (!logs) {
        printf("Unable to allocate memory for logs\n");
        fclose(logFile);
        return 1;
    }

    int numLogs;
    readLogFile(logFile, logs, &numLogs);

    char* level = argv[2];
    LogEntry* filteredLogs = (LogEntry*)malloc(MAX_LOG_LENGTH * sizeof(LogEntry));
    if (!filteredLogs) {
        printf("Unable to allocate memory for filtered logs\n");
        free(logs);
        fclose(logFile);
        return 1;
    }

    int numFilteredLogs;
    filterLogsByLevel(logs, numLogs, level, filteredLogs, &numFilteredLogs);

    printf("Original logs:\n");
    printLogs(logs, numLogs);

    printf("\nFiltered logs (level=%s):\n", level);
    printLogs(filteredLogs, numFilteredLogs);

    free(logs);
    free(filteredLogs);
    fclose(logFile);

    return 0;
}