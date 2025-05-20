//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char timestamp[20];
    char log_level[10];
    char message[100];
} LogEntry;

LogEntry logs[MAX_LOG_LINES];
int log_count = 0;

void add_log_entry(const char *level, const char *message) {
    if (log_count >= MAX_LOG_LINES) {
        printf("Log limit reached. Cannot add more entries.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(logs[log_count].timestamp, sizeof(logs[log_count].timestamp), "%Y-%m-%d %H:%M:%S", t);
    
    strncpy(logs[log_count].log_level, level, sizeof(logs[log_count].log_level) - 1);
    strncpy(logs[log_count].message, message, sizeof(logs[log_count].message) - 1);
    
    log_count++;
}

void print_logs() {
    printf("\n--- Log Entries ---\n");
    for (int i = 0; i < log_count; i++) {
        printf("[%s] [%s]: %s\n", logs[i].timestamp, logs[i].log_level, logs[i].message);
    }
    printf("-------------------\n");
}

void save_logs_to_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < log_count; i++) {
        fprintf(file, "[%s] [%s]: %s\n", logs[i].timestamp, logs[i].log_level, logs[i].message);
    }

    fclose(file);
    printf("Logs saved to %s\n", filename);
}

void filter_logs_by_level(const char *level) {
    printf("\n--- Filtered Log Entries [%s] ---\n", level);
    for (int i = 0; i < log_count; i++) {
        if (strcmp(logs[i].log_level, level) == 0) {
            printf("[%s] [%s]: %s\n", logs[i].timestamp, logs[i].log_level, logs[i].message);
        }
    }
    printf("-------------------\n");
}

void log_action() {
    char action[100];
    printf("\nEnter an action message: ");
    fgets(action, sizeof(action), stdin);
    action[strcspn(action, "\n")] = 0; // Remove the newline character

    if (strlen(action) == 0) {
        printf("Empty action message. No log added.\n");
        return;
    }

    int level_choice;
    printf("Choose log level (1: INFO, 2: WARNING, 3: ERROR): ");
    scanf("%d", &level_choice);
    while (getchar() != '\n'); // Clear the buffer
    
    switch (level_choice) {
        case 1:
            add_log_entry("INFO", action);
            break;
        case 2:
            add_log_entry("WARNING", action);
            break;
        case 3:
            add_log_entry("ERROR", action);
            break;
        default:
            printf("Invalid choice of log level. No log added.\n");
            return;
    }
    
    printf("Log added successfully.\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Log Management System ---\n");
        printf("1. Log an action\n");
        printf("2. Display all logs\n");
        printf("3. Filter logs by level\n");
        printf("4. Save logs to file\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear the buffer

        switch (choice) {
            case 1:
                log_action();
                break;
            case 2:
                print_logs();
                break;
            case 3: {
                char level[10];
                printf("Enter log level (INFO, WARNING, ERROR): ");
                fgets(level, sizeof(level), stdin);
                level[strcspn(level, "\n")] = 0; // Remove newline character
                filter_logs_by_level(level);
                break;
            }
            case 4: {
                char filename[100];
                printf("Enter filename to save logs (e.g., logs.txt): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                save_logs_to_file(filename);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}