//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef struct {
    time_t timestamp;
    char log_level[16];
    char message[MAX_LOG_LINE_LENGTH];
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

void parse_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && log_count < MAX_LOG_ENTRIES) {
        LogEntry entry;
        struct tm time_info;
        
        // Assuming log format: YYYY-MM-DD HH:MM:SS LOG_LEVEL Message
        sscanf(line, "%d-%d-%d %d:%d:%d %s %[^\n]", 
               &time_info.tm_year, &time_info.tm_mon, &time_info.tm_mday,
               &time_info.tm_hour, &time_info.tm_min, &time_info.tm_sec,
               entry.log_level, entry.message);
        
        // Adjust year and month for struct tm
        time_info.tm_year -= 1900; // Year since 1900
        time_info.tm_mon -= 1;      // Months since January [0-11]
        
        entry.timestamp = mktime(&time_info);
        log_entries[log_count++] = entry;
    }
    
    fclose(file);
}

void display_log_entries() {
    for (int i = 0; i < log_count; i++) {
        struct tm *time_info = localtime(&log_entries[i].timestamp);
        char time_buffer[20];
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
        
        printf("[%s] [%s] %s\n", time_buffer, log_entries[i].log_level, log_entries[i].message);
    }
}

void filter_log_entries(const char *level) {
    printf("Filtered logs with level '%s':\n", level);
    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, level) == 0) {
            char time_buffer[20];
            struct tm *time_info = localtime(&log_entries[i].timestamp);
            strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", time_info);
            printf("[%s] [%s] %s\n", time_buffer, log_entries[i].log_level, log_entries[i].message);
        }
    }
}

void count_log_levels() {
    int info_count = 0, error_count = 0, warning_count = 0;

    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(log_entries[i].log_level, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(log_entries[i].log_level, "WARNING") == 0) {
            warning_count++;
        }
    }

    printf("Log Level Counts:\n");
    printf("INFO: %d\n", info_count);
    printf("ERROR: %d\n", error_count);
    printf("WARNING: %d\n", warning_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_log_file(argv[1]);

    printf("Log Entries:\n");
    display_log_entries();

    // Example filtering by log level
    filter_log_entries("ERROR");

    // Example counting log levels
    count_log_levels();

    return EXIT_SUCCESS;
}