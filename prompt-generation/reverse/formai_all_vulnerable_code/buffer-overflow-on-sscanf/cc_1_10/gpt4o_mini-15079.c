//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char timestamp[20];
    char log_level[6];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

// Function to read logs from the file
void read_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(log_entries[log_count].timestamp, sizeof(log_entries[log_count].timestamp), file)) {
        // Assuming the log format as "YYYY-MM-DD hh:mm:ss [LEVEL] Message"
        sscanf(log_entries[log_count].timestamp, "%s %s %[^\n]", log_entries[log_count].timestamp, log_entries[log_count].log_level, log_entries[log_count].message);
        log_count++;
        if (log_count >= MAX_LOG_ENTRIES) break; // Stop if max entries reached
    }
    fclose(file);
}

// Function to summarize log levels
void summarize_log_levels() {
    int info_count = 0, warn_count = 0, error_count = 0;

    for (int i = 0; i < log_count; i++) {
        if (strcmp(log_entries[i].log_level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(log_entries[i].log_level, "WARN") == 0) {
            warn_count++;
        } else if (strcmp(log_entries[i].log_level, "ERROR") == 0) {
            error_count++;
        }
    }

    printf("\n--- Log Level Summary ---\n");
    printf("\033[0;32mINFO Count: \033[0m%d\n", info_count);   // Green
    printf("\033[0;33mWARN Count: \033[0m%d\n", warn_count);   // Yellow
    printf("\033[0;31mERROR Count: \033[0m%d\n", error_count); // Red
}

// Function to print detailed log entries
void print_log_entries() {
    printf("\n--- Log Entries ---\n");
    for (int i = 0; i < log_count; i++) {
        printf("[%s] [%s] %s\n", log_entries[i].timestamp, log_entries[i].log_level, log_entries[i].message);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_log_file(argv[1]);
    summarize_log_levels();
    print_log_entries();

    return EXIT_SUCCESS;
}