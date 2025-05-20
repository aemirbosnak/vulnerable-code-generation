//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int totalEntries = 0;

void parseLogLine(const char *line) {
    if (totalEntries >= MAX_LOG_ENTRIES) {
        return;
    }
    sscanf(line, "%19s %9s %[^\n]", logEntries[totalEntries].timestamp, 
            logEntries[totalEntries].level, 
            logEntries[totalEntries].message);
    totalEntries++;
}

void printLogSummary() {
    printf("Log Summary:\n");
    int errorCount = 0, warningCount = 0, infoCount = 0;

    for (int i = 0; i < totalEntries; i++) {
        if (strcmp(logEntries[i].level, "ERROR") == 0) {
            errorCount++;
        } else if (strcmp(logEntries[i].level, "WARNING") == 0) {
            warningCount++;
        } else if (strcmp(logEntries[i].level, "INFO") == 0) {
            infoCount++;
        }
    }

    printf("Total Entries: %d\n", totalEntries);
    printf("INFO: %d\n", infoCount);
    printf("WARNING: %d\n", warningCount);
    printf("ERROR: %d\n", errorCount);
}

void findLogByLevel(const char *level) {
    printf("Logs at level %s:\n", level);
    for (int i = 0; i < totalEntries; i++) {
        if (strcmp(logEntries[i].level, level) == 0) {
            printf("[%s] %s: %s\n", logEntries[i].timestamp, 
                   logEntries[i].level, logEntries[i].message);
        }
    }
}

void writeLogToFile(const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < totalEntries; i++) {
        fprintf(file, "%s %s %s\n", logEntries[i].timestamp, 
                logEntries[i].level, logEntries[i].message);
    }

    fclose(file);
    printf("Log written to %s successfully.\n", filename);
}

void readLogFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLogLine(line);
    }

    fclose(file);
    printf("Log file %s read successfully. Total entries: %d\n", 
            filename, totalEntries);
}

void showHelp() {
    printf("Usage: log_analyzer <logfile>\n");
    printf("Options:\n");
    printf("  -summary    Show a summary of the logs\n");
    printf("  -level <LEVEL>    Show logs of a specific level (INFO, WARNING, ERROR)\n");
    printf("  -write <FILENAME>    Write logs to a specified file\n");
    printf("  -help       Show this help message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        showHelp();
        return 1;
    }

    readLogFile(argv[1]);

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-summary") == 0) {
            printLogSummary();
        } else if (strcmp(argv[i], "-level") == 0 && i + 1 < argc) {
            findLogByLevel(argv[i + 1]);
            i++; // Skip the next argument
        } else if (strcmp(argv[i], "-write") == 0 && i + 1 < argc) {
            writeLogToFile(argv[i + 1]);
            i++; // Skip the next argument
        } else if (strcmp(argv[i], "-help") == 0) {
            showHelp();
        } else {
            printf("Unknown option: %s\n", argv[i]);
            showHelp();
            return 1;
        }
    }
    
    return 0;
}