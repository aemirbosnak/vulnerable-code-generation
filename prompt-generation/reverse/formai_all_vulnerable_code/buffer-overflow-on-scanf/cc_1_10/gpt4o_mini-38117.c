//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE "log.txt"

typedef struct LogEntry {
    time_t timestamp;
    char severity[10];
    char message[MAX_LOG_SIZE];
    struct LogEntry *next;
} LogEntry;

LogEntry *head = NULL;

void add_log_entry(const char *severity, const char *message) {
    LogEntry *new_entry = (LogEntry *)malloc(sizeof(LogEntry));
    new_entry->timestamp = time(NULL);
    strncpy(new_entry->severity, severity, sizeof(new_entry->severity) - 1);
    strncpy(new_entry->message, message, sizeof(new_entry->message) - 1);
    new_entry->next = head;
    head = new_entry;
}

void save_logs_to_file() {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file for writing");
        return;
    }

    LogEntry *current = head;
    while (current) {
        char time_buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&current->timestamp);
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        fprintf(file, "%s [%s] %s\n", time_buffer, current->severity, current->message);
        current = current->next;
    }

    fclose(file);
}

void print_logs() {
    LogEntry *current = head;
    while (current) {
        char time_buffer[26];
        struct tm* tm_info;

        tm_info = localtime(&current->timestamp);
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("%s [%s] %s\n", time_buffer, current->severity, current->message);
        current = current->next;
    }
}

void free_logs() {
    LogEntry *current = head;
    while (current) {
        LogEntry *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

void uppercase_log_severity() {
    LogEntry *current = head;
    while (current) {
        for (int i = 0; current->severity[i]; i++) {
            current->severity[i] = toupper(current->severity[i]);
        }
        current = current->next;
    }
}

void filter_logs_by_severity(const char *filter_severity) {
    LogEntry *current = head;
    while (current) {
        if (strcasecmp(current->severity, filter_severity) == 0) {
            char time_buffer[26];
            struct tm* tm_info;

            tm_info = localtime(&current->timestamp);
            strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);
            printf("%s [%s] %s\n", time_buffer, current->severity, current->message);
        }
        current = current->next;
    }
}

void log_analysis_interface() {
    int choice;
    char severity[10];
    char message[MAX_LOG_SIZE];
    
    do {
        printf("\n--- Log Analysis Interface ---\n");
        printf("1. Add Log Entry\n");
        printf("2. Print All Logs\n");
        printf("3. Filter Logs by Severity\n");
        printf("4. Save Logs to File\n");
        printf("5. Convert Severity to Uppercase\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline

        switch (choice) {
            case 1:
                printf("Enter severity (INFO, WARNING, ERROR): ");
                fgets(severity, sizeof(severity), stdin);
                severity[strcspn(severity, "\n")] = 0; // Remove newline
                printf("Enter log message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                add_log_entry(severity, message);
                break;
            case 2:
                print_logs();
                break;
            case 3:
                printf("Filter log by severity: ");
                fgets(severity, sizeof(severity), stdin);
                severity[strcspn(severity, "\n")] = 0; // Remove newline
                filter_logs_by_severity(severity);
                break;
            case 4:
                save_logs_to_file();
                printf("Logs saved to %s\n", LOG_FILE);
                break;
            case 5:
                uppercase_log_severity();
                printf("All severities converted to uppercase.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 6);

    free_logs();
}

int main() {
    log_analysis_interface();
    return 0;
}