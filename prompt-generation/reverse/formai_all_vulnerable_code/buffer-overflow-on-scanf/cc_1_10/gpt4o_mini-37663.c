//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_MESSAGE_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

const char* logLevelToString(LogLevel level) {
    switch(level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logEvent(LogLevel level, const char* message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file");
        return;
    }

    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character

    fprintf(file, "[%s] [%s]: %s\n", timestamp, logLevelToString(level), message);
    fclose(file);
}

void displayLogs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file");
        return;
    }

    printf("Current Event Log Entries:\n");
    char buffer[MAX_LOG_MESSAGE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main() {
    char command[10];
    char message[MAX_LOG_MESSAGE_LENGTH];
    LogLevel level;

    printf("Welcome to the Event Logger!\n");
    printf("Use 'info', 'warning', or 'error' to log an event alongside a message.\n");
    printf("Type 'display' to see current log entries, or 'exit' to quit.\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "info") == 0) {
            printf("Enter your message: ");
            scanf(" %[^\n]", message); // Read string with spaces
            logEvent(INFO, message);
        } else if (strcmp(command, "warning") == 0) {
            printf("Enter your message: ");
            scanf(" %[^\n]", message);
            logEvent(WARNING, message);
        } else if (strcmp(command, "error") == 0) {
            printf("Enter your message: ");
            scanf(" %[^\n]", message);
            logEvent(ERROR, message);
        } else if (strcmp(command, "display") == 0) {
            displayLogs();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the event logger. Goodbye!\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    return 0;
}