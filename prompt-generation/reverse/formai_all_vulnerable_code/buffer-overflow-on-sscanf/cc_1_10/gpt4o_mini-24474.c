//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LINE_LENGTH 256

typedef struct {
    time_t timestamp;
    char level[10];
    char message[LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void addLogEntry(const char* level, const char* message) {
    if (logCount >= MAX_LOG_ENTRIES) {
        printf("Log limit reached. Cannot add more entries.\n");
        return;
    }
    logEntries[logCount].timestamp = time(NULL);
    strncpy(logEntries[logCount].level, level, sizeof(logEntries[logCount].level) - 1);
    strncpy(logEntries[logCount].message, message, sizeof(logEntries[logCount].message) - 1);
    logCount++;
}

void parseLogFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        printf("Failed to open log file: %s\n", fileName);
        return;
    }

    char line[LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && logCount < MAX_LOG_ENTRIES) {
        char level[10];
        char message[LINE_LENGTH];
        time_t timestamp;
        if (sscanf(line, "%ld %9s %[^\n]", &timestamp, level, message) == 3) {
            logEntries[logCount].timestamp = timestamp;
            strncpy(logEntries[logCount].level, level, sizeof(logEntries[logCount].level) - 1);
            strncpy(logEntries[logCount].message, message, sizeof(logEntries[logCount].message) - 1);
            logCount++;
        } else {
            printf("Failed to parse line: %s\n", line);
        }
    }

    fclose(file);
}

void analyzeLogs() {
    int infoCount = 0, errorCount = 0, warningCount = 0;

    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(logEntries[i].level, "ERROR") == 0) {
            errorCount++;
        } else if (strcmp(logEntries[i].level, "WARNING") == 0) {
            warningCount++;
        }
    }

    printf("\n--- LOG ANALYSIS ---\n");
    printf("Total INFO logs: %d\n", infoCount);
    printf("Total ERROR logs: %d\n", errorCount);
    printf("Total WARNING logs: %d\n", warningCount);

    double errorPercentage = ((double)errorCount / logCount) * 100.0;
    printf("Percentage of ERROR logs: %.2f%%\n", errorPercentage);
}

void printLogs() {
    printf("\n--- LOG ENTRIES ---\n");
    for (int i = 0; i < logCount; i++) {
        char timeString[20];
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&logEntries[i].timestamp));
        printf("[%s] [%s] %s\n", timeString, logEntries[i].level, logEntries[i].message);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseLogFile(argv[1]);
    analyzeLogs();
    printLogs();

    return EXIT_SUCCESS;
}