//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_LENGTH 256
#define LOG_FILE "application.log"

typedef struct LogEntry {
    time_t timestamp;
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

void append_log_entry(LogEntry entry) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%ld [%s] %s\n", entry.timestamp, entry.level, entry.message);
    fclose(file);
}

void read_logs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Unable to open log file");
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
        perror("Unable to open log file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    printf("Filtered logs for level: %s\n", level);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, level)) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void log_errors(const char *message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    strcpy(entry.level, "ERROR");
    strncpy(entry.message, message, MAX_LINE_LENGTH - 1);
    append_log_entry(entry);
}

void log_info(const char *message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    strcpy(entry.level, "INFO");
    strncpy(entry.message, message, MAX_LINE_LENGTH - 1);
    append_log_entry(entry);
}

void log_warning(const char *message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    strcpy(entry.level, "WARNING");
    strncpy(entry.message, message, MAX_LINE_LENGTH - 1);
    append_log_entry(entry);
}

void show_menu() {
    printf("\nLog Management System\n");
    printf("1. Add Info Log\n");
    printf("2. Add Warning Log\n");
    printf("3. Add Error Log\n");
    printf("4. Read All Logs\n");
    printf("5. Filter Logs by Level\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char message[MAX_LINE_LENGTH];
    char level[10];

    while (1) {
        show_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter info message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                log_info(message);
                break;
            case 2:
                printf("Enter warning message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                log_warning(message);
                break;
            case 3:
                printf("Enter error message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                log_errors(message);
                break;
            case 4:
                read_logs();
                break;
            case 5:
                printf("Enter log level to filter (INFO, WARNING, ERROR): ");
                fgets(level, sizeof(level), stdin);
                level[strcspn(level, "\n")] = 0; // Remove newline
                filter_logs(level);
                break;
            case 6:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}