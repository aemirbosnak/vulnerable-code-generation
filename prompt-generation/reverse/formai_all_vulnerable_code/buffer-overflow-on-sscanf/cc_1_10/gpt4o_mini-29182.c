//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

// Structure to hold the log entry details
typedef struct {
    char timestamp[20];
    char logLevel[10];
    char message[100];
} LogEntry;

// Function to parse a single log entry
void parseLogEntry(char *line, LogEntry *entry) {
    sscanf(line, "%s %s %[^\n]", entry->timestamp, entry->logLevel, entry->message);
}

// Function to analyze log entries and count occurrences of log levels
void analyzeLogs(LogEntry *logs, int count, int *levelCount) {
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].logLevel, "INFO") == 0) {
            levelCount[0]++;
        } else if (strcmp(logs[i].logLevel, "WARNING") == 0) {
            levelCount[1]++;
        } else if (strcmp(logs[i].logLevel, "ERROR") == 0) {
            levelCount[2]++;
        } else if (strcmp(logs[i].logLevel, "DEBUG") == 0) {
            levelCount[3]++;
        }
    }
}

// Function to print the analysis result
void printAnalysis(int *levelCount) {
    printf("Log Level Analysis:\n");
    printf("INFO: %d\n", levelCount[0]);
    printf("WARNING: %d\n", levelCount[1]);
    printf("ERROR: %d\n", levelCount[2]);
    printf("DEBUG: %d\n", levelCount[3]);
}

int main(int argc, char *argv[]) {
    // Check if a log file is provided
    if (argc < 2) {
        printf("Surprise! You didn't provide a log file!\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Whoa! Could not open file %s\n", argv[1]);
        return 1;
    }

    LogEntry logs[MAX_LOG_ENTRIES];
    int logCount = 0;
    char line[MAX_LINE_LENGTH];

    // Read the log entries from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        if (logCount < MAX_LOG_ENTRIES) {
            parseLogEntry(line, &logs[logCount]);
            logCount++;
        } else {
            printf("Whoa! Reached the maximum log entry limit!\n");
            break;
        }
    }
    fclose(file);

    // Surprise analysis starts here
    int levelCount[4] = {0};  // INFO, WARNING, ERROR, DEBUG
    analyzeLogs(logs, logCount, levelCount);

    // Print the results
    printAnalysis(levelCount);

    // Finding the craziest log message
    int crazyLogIndex = 0;

    for (int i = 1; i < logCount; i++) {
        if (strlen(logs[i].message) > strlen(logs[crazyLogIndex].message)) {
            crazyLogIndex = i;
        }
    }

    printf("The craziest log message was:\n%s [%s] %s\n", logs[crazyLogIndex].timestamp, logs[crazyLogIndex].logLevel, logs[crazyLogIndex].message);

    // Count unique log messages
    char uniqueMessages[MAX_LOG_ENTRIES][100];
    int uniqueCount = 0;

    for (int i = 0; i < logCount; i++) {
        int isUnique = 1;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(logs[i].message, uniqueMessages[j]) == 0) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            strcpy(uniqueMessages[uniqueCount], logs[i].message);
            uniqueCount++;
        }
    }

    printf("Surprise! There are %d unique log messages!\n", uniqueCount);
    
    // Generating a fun report
    FILE *report = fopen("log_analysis_report.txt", "w");
    if (report == NULL) {
        printf("Oops! Could not create report file!\n");
        return 1;
    }

    fprintf(report, "Log Analysis Report:\n");
    fprintf(report, "====================\n");
    fprintf(report, "Total Entries: %d\n", logCount);
    fprintf(report, "INFO: %d\n", levelCount[0]);
    fprintf(report, "WARNING: %d\n", levelCount[1]);
    fprintf(report, "ERROR: %d\n", levelCount[2]);
    fprintf(report, "DEBUG: %d\n", levelCount[3]);
    fprintf(report, "The craziest log message:\n%s [%s] %s\n", 
            logs[crazyLogIndex].timestamp, logs[crazyLogIndex].logLevel, logs[crazyLogIndex].message);
    fprintf(report, "Unique Messages Count: %d\n", uniqueCount);

    fclose(report);
    printf("Surprise! Log analysis report generated as 'log_analysis_report.txt'\n");
    return 0;
}