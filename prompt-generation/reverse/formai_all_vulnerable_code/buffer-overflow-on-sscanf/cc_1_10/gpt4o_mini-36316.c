//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINES 1000  // Maximum log lines to process
#define LOG_FILE "system.log" // Log file to read

typedef struct {
    time_t timestamp; // Log entry timestamp
    char log_level[10]; // Level of the log: INFO, ERROR, etc.
    char message[256]; // Log message
} LogEntry;

// Array to store log entries
LogEntry log_entries[MAX_LOG_LINES];
int log_count = 0;

// Function to parse a single log line into a LogEntry structure
int parse_log_line(const char *line, LogEntry *entry) {
    struct tm tm;
    char level[10];

    // Format: [YYYY-MM-DD HH:MM:SS] LEVEL: Message
    int matched = sscanf(line, "[%4d-%2d-%2d %2d:%2d:%2d] %9s: %[^\n]",
                         &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
                         &tm.tm_hour, &tm.tm_min, &tm.tm_sec,
                         level, entry->message);

    if (matched == 8) {
        // Adjust year and month for proper time conversion
        tm.tm_year -= 1900; // Years since 1900
        tm.tm_mon -= 1; // Months are zero indexed
        tm.tm_isdst = -1; // Not considering daylight saving time for simplicity
        entry->timestamp = mktime(&tm);
        strcpy(entry->log_level, level);
        return 1; // Successfully parsed
    }
    return 0; // Parsing failed
}

// Function to read log entries from a log file
void read_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }

    char line[512];
    while (fgets(line, sizeof(line), file) && log_count < MAX_LOG_LINES) {
        if (parse_log_line(line, &log_entries[log_count])) {
            log_count++;
        }
    }

    fclose(file);
}

// Function to display all log entries
void display_logs() {
    for (int i = 0; i < log_count; i++) {
        char time_buffer[20];
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", localtime(&log_entries[i].timestamp));
        printf("[%s] %s: %s\n", time_buffer, log_entries[i].log_level, log_entries[i].message);
    }
}

// Function to count logs by level
void count_logs_by_level() {
    int info_count = 0;
    int error_count = 0;
    
    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(log_entries[i].log_level, "ERROR") == 0) {
            error_count++;
        }
        // Add more levels if needed
    }
    printf("Log Counts:\n");
    printf("INFO: %d\n", info_count);
    printf("ERROR: %d\n", error_count);
}

// Main function to run the log analysis program
int main() {
    printf("Welcome to the Log Analysis Tool!\n");
    read_log_file(LOG_FILE);
    
    printf("\nAll Log Entries:\n");
    display_logs();

    printf("\nCounting Log Levels:\n");
    count_logs_by_level();

    return 0;
}