//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 256
#define LOG_FILE "event_log.txt"

typedef enum {
    INFO,
    WARNING,
    ERROR
} EventType;

const char* event_type_to_string(EventType type) {
    switch (type) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void log_event(EventType type, const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    // Remove the newline character from the timestamp
    timestamp[strcspn(timestamp, "\n")] = '\0'; 

    fprintf(file, "[%s] [%s] %s\n", timestamp, event_type_to_string(type), message);
    fclose(file);
}

void display_logs() {
    FILE* file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    char line[MAX_MESSAGE_LENGTH + 64]; // Extra space for timestamp and log level
    printf("Event Logs:\n");
    printf("------------------------------------------------\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void clear_logs() {
    FILE* file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        perror("Failed to clear log file");
        return;
    }
    fclose(file); // Just opening and closing to clear contents
    printf("Log file cleared.\n");
}

void print_menu() {
    printf("Event Logger Menu:\n");
    printf("1. Log Info Event\n");
    printf("2. Log Warning Event\n");
    printf("3. Log Error Event\n");
    printf("4. Display Logs\n");
    printf("5. Clear Logs\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        print_menu();
        scanf("%d", &option);
        getchar(); // Clear newline

        switch (option) {
            case 1:
                printf("Enter info message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                log_event(INFO, message);
                break;
            case 2:
                printf("Enter warning message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                log_event(WARNING, message);
                break;
            case 3:
                printf("Enter error message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                log_event(ERROR, message);
                break;
            case 4:
                display_logs();
                break;
            case 5:
                clear_logs();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}