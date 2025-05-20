//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1024

typedef struct {
    time_t timestamp;
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void parse_log_line(const char *line, LogEntry *entry) {
    char time_str[20];
    sscanf(line, "%s %s %[^\n]", time_str, entry->level, entry->message);
    
    struct tm tm;
    strptime(time_str, "%Y-%m-%d %H:%M:%S", &tm);
    entry->timestamp = mktime(&tm);
}

void display_log_entries(LogEntry *entries, int count) {
    printf("---------- Log Entries ----------\n");
    for (int i = 0; i < count; i++) {
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&entries[i].timestamp));
        printf("%s [%s]: %s\n", buffer, entries[i].level, entries[i].message);
    }
    printf("-------------------------------\n");
}

void filter_log_by_level(LogEntry *entries, int count, const char *level) {
    printf("Filtering log entries with level: %s\n", level);
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].level, level) == 0) {
            char buffer[20];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&entries[i].timestamp));
            printf("%s [%s]: %s\n", buffer, entries[i].level, entries[i].message);
        }
    }
}

void count_log_levels(LogEntry *entries, int count) {
    int info_count = 0, error_count = 0, warn_count = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(entries[i].level, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(entries[i].level, "WARN") == 0) {
            warn_count++;
        }
    }

    printf("Log Level Counts:\n");
    printf("INFO: %d\n", info_count);
    printf("ERROR: %d\n", error_count);
    printf("WARN: %d\n", warn_count);
}

int main() {
    FILE *log_file = fopen("application.log", "r");
    if (!log_file) {
        perror("Unable to open log file");
        return EXIT_FAILURE;
    }

    LogEntry log_entries[MAX_LOG_ENTRIES];
    char line[MAX_LINE_LENGTH];
    int count = 0;

    while (fgets(line, sizeof(line), log_file) && count < MAX_LOG_ENTRIES) {
        parse_log_line(line, &log_entries[count]);
        count++;
    }
    fclose(log_file);
    
    display_log_entries(log_entries, count);
    printf("\n");
    
    filter_log_by_level(log_entries, count, "ERROR");
    printf("\n");

    count_log_levels(log_entries, count);
    
    return EXIT_SUCCESS;
}