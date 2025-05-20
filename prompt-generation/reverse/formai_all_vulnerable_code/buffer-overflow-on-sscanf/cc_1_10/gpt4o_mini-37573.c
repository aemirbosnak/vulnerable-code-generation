//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    time_t timestamp;
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void parseLogLine(const char *line) {
    if (logCount >= MAX_LOG_ENTRIES) {
        fprintf(stderr, "Error: Maximum log entries reached.\n");
        return;
    }

    char timeBuffer[20];
    sscanf(line, "%s %s %[^'\n']", timeBuffer, logEntries[logCount].level, logEntries[logCount].message);
    
    struct tm tm_time;
    strptime(timeBuffer, "%Y-%m-%d %H:%M:%S", &tm_time);
    logEntries[logCount].timestamp = mktime(&tm_time);
    
    logCount++;
}

void displayLogEntries() {
    printf("\nLog Entries:\n");
    for (int i = 0; i < logCount; i++) {
        char timeString[20];
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&logEntries[i].timestamp));
        printf("[%s] [%s] %s\n", timeString, logEntries[i].level, logEntries[i].message);
    }
}

void filterLogsByLevel(const char *level) {
    printf("\nFiltered Log Entries (Level: %s):\n", level);
    for (int i = 0; i < logCount; i++) {
        if (strcmp(logEntries[i].level, level) == 0) {
            char timeString[20];
            strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&logEntries[i].timestamp));
            printf("[%s] [%s] %s\n", timeString, logEntries[i].level, logEntries[i].message);
        }
    }
}

int readLogsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open log file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLogLine(line);
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (readLogsFromFile(argv[1]) != 0) {
        return EXIT_FAILURE;
    }

    displayLogEntries();

    char levelToFilter[10];
    printf("\nEnter log level to filter (INFO, ERROR, DEBUG): ");
    if (scanf("%9s", levelToFilter) == 1) {
        filterLogsByLevel(levelToFilter);
    }

    return EXIT_SUCCESS;
}