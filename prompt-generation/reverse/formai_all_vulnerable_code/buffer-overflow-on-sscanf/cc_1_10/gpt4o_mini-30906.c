//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char severity[10];
    char message[100];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

// Function to load logs from a file
void loadLogs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening log file: %s\n", filename);
        exit(1);
    }

    char buffer[MAX_LOG_SIZE];
    while (fgets(buffer, MAX_LOG_SIZE, file) && logCount < MAX_LOG_ENTRIES) {
        sscanf(buffer, "%19s %9s %[^\n]", logEntries[logCount].timestamp, logEntries[logCount].severity, logEntries[logCount].message);
        logCount++;
    }
    fclose(file);
}

// Function to categorize logs
void categorizeLogs(int *infoCount, int *warningCount, int *errorCount) {
    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].severity, "INFO") == 0) {
            (*infoCount)++;
        } else if (strcmp(logEntries[i].severity, "WARNING") == 0) {
            (*warningCount)++;
        } else if (strcmp(logEntries[i].severity, "ERROR") == 0) {
            (*errorCount)++;
        }
    }
}

// Function to print the summary of log entries
void printLogSummary(int infoCount, int warningCount, int errorCount) {
    printf("\n--- Log Summary ---\n");
    printf("Total INFO logs: %d\n", infoCount);
    printf("Total WARNING logs: %d\n", warningCount);
    printf("Total ERROR logs: %d\n", errorCount);
    printf("--------------------\n");
}

// Function to display log entries
void displayLogs() {
    printf("\n--- Log Entries ---\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s %s: %s\n", logEntries[i].timestamp, logEntries[i].severity, logEntries[i].message);
    }
    printf("--------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    loadLogs(argv[1]);

    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;
    
    categorizeLogs(&infoCount, &warningCount, &errorCount);
    
    displayLogs();
    printLogSummary(infoCount, warningCount, errorCount);

    return 0;
}