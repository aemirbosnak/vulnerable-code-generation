//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_LEN 256
#define LOG_FILE "event_log.txt"

// Logging levels
typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

// Function prototypes
void log_event(LogLevel level, const char *message);
void display_logs();
const char* log_level_to_string(LogLevel level);

// Main function
int main() {
    int choice;
    char message[MAX_LOG_LEN];

    while (1) {
        printf("\nEvent Logger Menu:\n");
        printf("1. Log Info Event\n");
        printf("2. Log Warning Event\n");
        printf("3. Log Error Event\n");
        printf("4. Display All Logs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter info message: ");
                fgets(message, MAX_LOG_LEN, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character
                log_event(LOG_INFO, message);
                break;
            case 2:
                printf("Enter warning message: ");
                fgets(message, MAX_LOG_LEN, stdin);
                message[strcspn(message, "\n")] = '\0';
                log_event(LOG_WARNING, message);
                break;
            case 3:
                printf("Enter error message: ");
                fgets(message, MAX_LOG_LEN, stdin);
                message[strcspn(message, "\n")] = '\0';
                log_event(LOG_ERROR, message);
                break;
            case 4:
                display_logs();
                break;
            case 5:
                printf("Exiting the event logger.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Log event function implementation
void log_event(LogLevel level, const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    // Format: YYYY-MM-DD HH:MM:SS
    fprintf(log_file, "%04d-%02d-%02d %02d:%02d:%02d [%s] %s\n",
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday,
            t->tm_hour,
            t->tm_min,
            t->tm_sec,
            log_level_to_string(level),
            message);

    fclose(log_file);
}

// Display logs function implementation
void display_logs() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    char buffer[MAX_LOG_LEN + 100];
    printf("\n--- Event Logs ---\n");
    while (fgets(buffer, sizeof(buffer), log_file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(log_file);
}

// Convert log level to string
const char* log_level_to_string(LogLevel level) {
    switch (level) {
        case LOG_INFO: return "INFO";
        case LOG_WARNING: return "WARNING";
        case LOG_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}