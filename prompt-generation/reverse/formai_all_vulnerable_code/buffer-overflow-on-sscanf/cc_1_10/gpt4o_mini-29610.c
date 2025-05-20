//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char timestamp[30];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void parse_line(const char *line, LogEntry *entry) {
    sscanf(line, "%s %s %[^\n]", entry->timestamp, entry->level, entry->message);
}

int is_error_log(const LogEntry *entry) {
    return strcmp(entry->level, "ERROR") == 0;
}

void display_error_logs(LogEntry logs[], int count) {
    printf("\n=== Error Logs ===\n");
    for (int i = 0; i < count; i++) {
        if (is_error_log(&logs[i])) {
            printf("[%s] [%s]: %s\n", logs[i].timestamp, logs[i].level, logs[i].message);
        }
    }
}

void display_summary(LogEntry logs[], int count) {
    int error_count = 0, warning_count = 0, info_count = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].level, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(logs[i].level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(logs[i].level, "INFO") == 0) {
            info_count++;
        }
    }

    printf("\n=== Log Summary ===\n");
    printf("Total Logs: %d\n", count);
    printf("Errors: %d\n", error_count);
    printf("Warnings: %d\n", warning_count);
    printf("Info: %d\n", info_count);
}

void save_summary_to_file(const char *filename, LogEntry logs[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error creating summary file.\n");
        return;
    }

    int error_count = 0, warning_count = 0, info_count = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(logs[i].level, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(logs[i].level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(logs[i].level, "INFO") == 0) {
            info_count++;
        }
    }

    fprintf(file, "Total Logs: %d\n", count);
    fprintf(file, "Errors: %d\n", error_count);
    fprintf(file, "Warnings: %d\n", warning_count);
    fprintf(file, "Info: %d\n", info_count);

    fclose(file);
}

void read_log_file(const char *filename, LogEntry logs[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening log file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (*count < MAX_LINES && fgets(line, sizeof(line), file)) {
        parse_line(line, &logs[*count]);
        (*count)++;
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    LogEntry logs[MAX_LINES];
    int log_count = 0;

    read_log_file(argv[1], logs, &log_count);
    display_summary(logs, log_count);
    display_error_logs(logs, log_count);
    save_summary_to_file("log_summary.txt", logs, log_count);

    printf("\nLog analysis completed! Summary saved in 'log_summary.txt'.\n");
    return EXIT_SUCCESS;
}