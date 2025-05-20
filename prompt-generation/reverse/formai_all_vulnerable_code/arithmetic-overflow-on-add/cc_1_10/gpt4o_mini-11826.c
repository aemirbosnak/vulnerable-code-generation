//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "app_log.txt"
#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct LogEntry {
    char timestamp[20];
    char logLevel[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logEntryCount = 0;

void log_event(const char* level, const char* message) {
    if (logEntryCount >= MAX_LOG_ENTRIES) {
        printf("Log entry limit reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    snprintf(logEntries[logEntryCount].timestamp, sizeof(logEntries[logEntryCount].timestamp), "%02d-%02d-%04d %02d:%02d:%02d",
             t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
    strncpy(logEntries[logEntryCount].logLevel, level, sizeof(logEntries[logEntryCount].logLevel) - 1);
    strncpy(logEntries[logEntryCount].message, message, sizeof(logEntries[logEntryCount].message) - 1);
    
    logEntryCount++;
}

void write_logs_to_file() {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    
    for (int i = 0; i < logEntryCount; i++) {
        fprintf(file, "[%s] %s: %s\n", logEntries[i].timestamp, logEntries[i].logLevel, logEntries[i].message);
    }

    fclose(file);
    logEntryCount = 0; // Clear the log entries after writing to file
}

void display_logs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file for reading");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void filter_logs(const char *level) {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file for reading");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Filtered Logs with level: %s\n", level);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, level)) {
            printf("%s", line);
        }
    }

    fclose(file);
}

int main() {
    log_event("INFO", "Application started");
    log_event("WARNING", "Low memory warning");
    log_event("ERROR", "File not found");
    
    write_logs_to_file();
    
    printf("All logs:\n");
    display_logs();
    
    printf("\nFiltered logs:\n");
    filter_logs("WARNING");
    
    return 0;
}