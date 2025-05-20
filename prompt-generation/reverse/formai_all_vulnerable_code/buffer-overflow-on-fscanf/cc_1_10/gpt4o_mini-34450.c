//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_MESSAGE_SIZE 256

typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_MESSAGE_SIZE];
} LogEntry;

LogEntry logs[MAX_LOG_SIZE];
int log_count = 0;

void read_log_file(const char *filename);
void analyze_logs();
void print_log_summary();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_log_file(argv[1]);
    analyze_logs();
    
    return EXIT_SUCCESS;
}

void read_log_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%19s %9s %[^\n]", logs[log_count].timestamp, logs[log_count].level, logs[log_count].message) != EOF) {
        log_count++;
        if (log_count >= MAX_LOG_SIZE) {
            printf("Warning: log array full, only processed %d logs.\n", log_count);
            break;
        }
    }

    fclose(file);
}

void analyze_logs() {
    int info_count = 0, warning_count = 0, error_count = 0;
    char latest_error[MAX_MESSAGE_SIZE] = "";

    for (int i = 0; i < log_count; i++) {
        if (strcmp(logs[i].level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(logs[i].level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(logs[i].level, "ERROR") == 0) {
            error_count++;
            strcpy(latest_error, logs[i].message);
        }
    }

    printf("Log Summary:\n");
    printf("Total INFO logs: %d\n", info_count);
    printf("Total WARNING logs: %d\n", warning_count);
    printf("Total ERROR logs: %d\n", error_count);
    
    if (error_count > 0) {
        printf("Latest ERROR message: %s\n", latest_error);
    }
}