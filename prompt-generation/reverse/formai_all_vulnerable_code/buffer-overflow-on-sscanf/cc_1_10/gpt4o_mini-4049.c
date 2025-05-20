//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct LogEntry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_LINES];
int logCount = 0;

void parseLogLine(const char *line) {
    if (logCount >= MAX_LOG_LINES) {
        fprintf(stderr, "Log capacity reached.\n");
        return;
    }
    
    sscanf(line, "%19s %9s %[^\n]", logEntries[logCount].timestamp, logEntries[logCount].level, logEntries[logCount].message);
    logCount++;
}

void loadLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLogLine(line);
    }
    fclose(file);
}

void filterByLevel(const char *level) {
    printf("Log entries with level '%s':\n", level);
    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].level, level) == 0) {
            printf("%s - %s: %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
        }
    }
}

void countLevels() {
    int infoCount = 0, warnCount = 0, errorCount = 0;
    
    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(logEntries[i].level, "WARNING") == 0) {
            warnCount++;
        } else if (strcmp(logEntries[i].level, "ERROR") == 0) {
            errorCount++;
        }
    }
    
    printf("Log Level Counts:\n");
    printf("INFO: %d\n", infoCount);
    printf("WARNING: %d\n", warnCount);
    printf("ERROR: %d\n", errorCount);
}

void displayAllLogs() {
    printf("All Log Entries:\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s - %s: %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
    }
}

void saveFilteredLog(const char *level, const char *outputFile) {
    FILE *file = fopen(outputFile, "w");
    if (!file) {
        perror("Unable to open output file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].level, level) == 0) {
            fprintf(file, "%s - %s: %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
        }
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    loadLogFile(argv[1]);
    displayAllLogs();
    countLevels();
    
    // Example of filtering logs
    filterByLevel("ERROR");
    
    // Save filtered logs to a new file
    saveFilteredLog("INFO", "info_logs.txt");
    
    return EXIT_SUCCESS;
}