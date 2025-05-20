//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_TYPE 50
#define MAX_LOG_COUNT 1000

typedef struct {
    char type[MAX_LOG_TYPE];
    int count;
} LogEntry;

LogEntry logEntries[MAX_LOG_COUNT];
int logEntryCount = 0;

void initializeLogEntries() {
    for(int i = 0; i < MAX_LOG_COUNT; i++) {
        logEntries[i].count = 0;
        strcpy(logEntries[i].type, "");
    }
}

void addLogEntry(char *logType) {
    for(int i = 0; i < logEntryCount; i++) {
        if(strcmp(logEntries[i].type, logType) == 0) {
            logEntries[i].count++;
            return;
        }
    }
    // New log entry
    strcpy(logEntries[logEntryCount].type, logType);
    logEntries[logEntryCount].count = 1;
    logEntryCount++;
}

void printLogSummary() {
    printf("\n--- Log Summary ---\n");
    for(int i = 0; i < logEntryCount; i++) {
        printf("Log Type: %s | Count: %d\n", logEntries[i].type, logEntries[i].count);
    }
}

void analyzeLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open log file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    initializeLogEntries();
    
    while (fgets(line, sizeof(line), file)) {
        char *timestamp = strtok(line, " ");
        char *logType = strtok(NULL, " ");
        if (logType) {
            logType[strcspn(logType, "\n")] = 0; // Remove newline character
            addLogEntry(logType);
        }
    }
    
    fclose(file);
    printLogSummary();
}

void menu() {
    printf("Welcome to Mind-Bending Log Analyzer!\n");
    printf("======================================\n");
    printf("1. Analyze new log file\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char filename[MAX_LINE_LENGTH];
    
    do {
        menu();
        scanf("%d", &choice);
        getchar(); // consume newline
        
        switch(choice) {
            case 1:
                printf("Enter the log filename to analyze: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                analyzeLogFile(filename);
                break;
            case 2:
                printf("Exiting, may your logs be always clear!\n");
                break;
            default:
                printf("Please select a valid option.\n");
                break;
        }
    } while (choice != 2);
    
    return 0;
}