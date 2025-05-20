//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "logfile.log"
#define BUFFER_SIZE 256

// Struct to hold each log entry
typedef struct {
    time_t timestamp;
    char level[16];
    char message[BUFFER_SIZE];
} LogEntry;

// Function to parse a single line of the log file
LogEntry parseLogLine(const char *line) {
    LogEntry entry;
    char timeStr[20];

    sscanf(line, "%19s %15s %[^\n]", timeStr, entry.level, entry.message);
    struct tm tm;
    strptime(timeStr, "%Y-%m-%d %H:%M:%S", &tm);
    entry.timestamp = mktime(&tm);

    return entry;
}

// Function to print the log entries
void printLogEntry(LogEntry entry) {
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&entry.timestamp));
    printf("[%s] [%s] %s\n", timeString, entry.level, entry.message);
}

// Function to analyze the log entries
void analyzeLogs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    char line[BUFFER_SIZE];
    int errorCount = 0;
    int warningCount = 0;
    int infoCount = 0;
    LogEntry entries[100];
    int entryCount = 0;

    while (fgets(line, sizeof(line), file)) {
        LogEntry entry = parseLogLine(line);
        entries[entryCount++] = entry;

        if (strcasecmp(entry.level, "ERROR") == 0) {
            errorCount++;
        } else if (strcasecmp(entry.level, "WARNING") == 0) {
            warningCount++;
        } else if (strcasecmp(entry.level, "INFO") == 0) {
            infoCount++;
        }
    }

    fclose(file);

    printf("Log Analysis Results:\n");
    printf("Total Errors: %d\n", errorCount);
    printf("Total Warnings: %d\n", warningCount);
    printf("Total Info: %d\n", infoCount);
    printf("\nDetails of last 5 log entries:\n");

    int start = (entryCount < 5) ? 0 : entryCount - 5;
    for (int i = start; i < entryCount; i++) {
        printLogEntry(entries[i]);
    }
}

// Function to add a new log entry
void addLogEntry(const char *level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    struct tm *lt = localtime(&now);
    fprintf(file, "%04d-%02d-%02d %02d:%02d:%02d %s %s\n",
            lt->tm_year + 1900,
            lt->tm_mon + 1,
            lt->tm_mday,
            lt->tm_hour,
            lt->tm_min,
            lt->tm_sec,
            level,
            message);

    fclose(file);
}

int main() {
    int choice;
    char message[BUFFER_SIZE], level[16];

    while (1) {
        printf("\nLog Analyzer Menu:\n");
        printf("1. Add log entry\n");
        printf("2. Analyze logs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
        case 1:
            printf("Enter log level (INFO, WARNING, ERROR): ");
            fgets(level, sizeof(level), stdin);
            strtok(level, "\n"); // remove newline
            
            printf("Enter log message: ");
            fgets(message, sizeof(message), stdin);
            strtok(message, "\n"); // remove newline
            
            addLogEntry(level, message);
            printf("Log entry added successfully.\n");
            break;

        case 2:
            analyzeLogs(LOG_FILE);
            break;

        case 3:
            printf("Exiting.\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}