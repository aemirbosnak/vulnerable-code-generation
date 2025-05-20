//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_SIZE 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} EventType;

// Function to get the current timestamp as a string
char* get_timestamp() {
    time_t now;
    struct tm *tm_info;
    static char buffer[25];

    time(&now);
    tm_info = localtime(&now);
    strftime(buffer, 25, "%Y-%m-%d %H:%M:%S", tm_info);

    return buffer;
}

// Function to log an event
void log_event(EventType type, const char *message) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    const char *event_type;
    switch (type) {
        case INFO:
            event_type = "INFO";
            break;
        case WARNING:
            event_type = "WARNING";
            break;
        case ERROR:
            event_type = "ERROR";
            break;
        default:
            event_type = "UNKNOWN";
    }

    // Write the event to the log file
    fprintf(logfile, "[%s] [%s] %s\n", get_timestamp(), event_type, message);
    fclose(logfile);
}

// Function to read and display log entries
void display_log() {
    FILE *logfile = fopen(LOG_FILE, "r");
    if (logfile == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_EVENT_SIZE];
    printf("Log Entries:\n");
    while (fgets(line, sizeof(line), logfile) != NULL) {
        printf("%s", line);
    }

    fclose(logfile);
}

// Function to clear the log file
void clear_log() {
    FILE *logfile = fopen(LOG_FILE, "w");
    if (logfile == NULL) {
        perror("Unable to clear log file");
        exit(EXIT_FAILURE);
    }
    fclose(logfile);
    printf("Log file cleared.\n");
}

// Main function demonstrating the event logger
int main() {
    int choice;
    char message[MAX_EVENT_SIZE];

    do {
        printf("\nEvent Logger Menu:\n");
        printf("1. Log INFO event\n");
        printf("2. Log WARNING event\n");
        printf("3. Log ERROR event\n");
        printf("4. Display log\n");
        printf("5. Clear log\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Clear the newline from input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter INFO message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline
                log_event(INFO, message);
                break;
            case 2:
                printf("Enter WARNING message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline
                log_event(WARNING, message);
                break;
            case 3:
                printf("Enter ERROR message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;  // Remove newline
                log_event(ERROR, message);
                break;
            case 4:
                display_log();
                break;
            case 5:
                clear_log();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}