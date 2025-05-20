//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LENGTH 256
#define LOG_FILE "application.log"

// Log level enum
typedef enum {
    DEBUG,
    INFO,
    WARNING,
    ERROR
} LogLevel;

// Log entry structure
typedef struct {
    time_t timestamp;
    LogLevel level;
    char message[MAX_LOG_LENGTH];
} LogEntry;

// Function to get the string representation of the log level
const char* logLevelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

// Function to write a log entry to a file
void writeLog(LogLevel level, const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        LogEntry entry;
        entry.timestamp = time(NULL);
        entry.level = level;
        strncpy(entry.message, message, MAX_LOG_LENGTH);

        fprintf(file, "[%s] [%s] %s\n", ctime(&entry.timestamp), logLevelToString(level), entry.message);
        fclose(file);
    } else {
        perror("Could not open log file");
    }
}

// Function to read and display the logs from the file
void displayLogs() {
    FILE* file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    char line[MAX_LOG_LENGTH + 64]; // Extra space for timestamp and log level
    printf("=== Log Entries ===\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Main function to demonstrate the logging functionality
int main() {
    int choice;
    char buffer[MAX_LOG_LENGTH];

    while (1) {
        printf("\nLog Analysis Program\n");
        printf("1. Write Log Entry\n");
        printf("2. Display Log Entries\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after entering the choice

        switch (choice) {
            case 1:
                printf("Enter log level (0: DEBUG, 1: INFO, 2: WARNING, 3: ERROR): ");
                int level;
                scanf("%d", &level);
                getchar(); // Consume newline

                if (level < 0 || level > 3) {
                    printf("Invalid log level.\n");
                    break;
                }

                printf("Enter message: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

                writeLog((LogLevel)level, buffer);
                printf("Log entry added.\n");
                break;

            case 2:
                displayLogs();
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Please select a valid option.\n");
        }
    }

    return 0;
}