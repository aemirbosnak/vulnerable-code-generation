//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define LOG_FILE "application.log"

// Log entry structure
typedef struct {
    time_t timestamp;
    char level[10];
    char message[200];
} LogEntry;

// Function to print a log entry
void print_log_entry(LogEntry *entry) {
    char time_str[20];
    struct tm *tm_info;

    tm_info = localtime(&entry->timestamp);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("[%s] [%s]: %s\n", time_str, entry->level, entry->message);
}

// Function to analyze log entries from a file
void analyze_logs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    LogEntry entry;
    char line[MAX_LINE_LENGTH];
    int info_count = 0, warning_count = 0, error_count = 0;

    // Read the log file line by line
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "[%ld] [%9[^]]: %[^\n]", &entry.timestamp, entry.level, entry.message);
        
        if (strcmp(entry.level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(entry.level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(entry.level, "ERROR") == 0) {
            error_count++;
        }
        
        // Print each log entry
        print_log_entry(&entry);
    }
    fclose(file);

    // Generate an analysis report
    printf("\n--- Analysis Report ---\n");
    printf("INFO Count: %d\n", info_count);
    printf("WARNING Count: %d\n", warning_count);
    printf("ERROR Count: %d\n", error_count);
    
    // Determine the status
    if (error_count > 0) {
        printf("Status: Critically Impacted\n");
    } else if (warning_count > 0) {
        printf("Status: Minor Issues Detected\n");
    } else {
        printf("Status: Running Smoothly\n");
    }
}

// Main function
int main() {
    printf("Welcome to the Log Analysis Tool!\n");
    printf("Analyzing logs from: %s\n", LOG_FILE);
    
    analyze_logs(LOG_FILE);
    
    printf("Log analysis complete. Thank you!\n");
    return 0;
}