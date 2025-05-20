//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "log.txt"
#define MAX_LINE_LENGTH 256

// Enum for log levels
typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

// Function to convert LogLevel enum to string
const char* logLevelToString(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

// Function to generate a timestamp
void getCurrentTimestamp(char *buffer, size_t length) {
    time_t now = time(NULL);
    struct tm *tm_info;
    tm_info = localtime(&now);
    strftime(buffer, length, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to write a log message to the log file
void writeLog(LogLevel level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    
    char timestamp[20];
    getCurrentTimestamp(timestamp, sizeof(timestamp));
    
    fprintf(file, "%s [%s]: %s\n", timestamp, logLevelToString(level), message);
    fclose(file);
}

// Function to read logs from the log file
void readLogs() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    printf("------ Log Entries ------\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to filter logs by severity level
void filterLogs(LogLevel level) {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    printf("------ Filtered Log Entries (%s) ------\n", logLevelToString(level));
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, logLevelToString(level)) != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);
}

// Main log analysis program
int main() {
    int choice;
    char message[200];

    // Initialize log file
    FILE *file = fopen(LOG_FILE, "w");
    if (file) fclose(file); // Create or clear the log file

    // Simple menu for logging operations
    do {
        printf("\n----- Log Analysis Program -----\n");
        printf("1. Log Info Message\n");
        printf("2. Log Warning Message\n");
        printf("3. Log Error Message\n");
        printf("4. Read All Logs\n");
        printf("5. Filter Logs by Severity\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter info message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                writeLog(INFO, message);
                break;
            case 2:
                printf("Enter warning message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                writeLog(WARNING, message);
                break;
            case 3:
                printf("Enter error message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                writeLog(ERROR, message);
                break;
            case 4:
                readLogs();
                break;
            case 5:
                printf("Select log level to filter (0: INFO, 1: WARNING, 2: ERROR): ");
                int level;
                scanf("%d", &level);
                if (level >= INFO && level <= ERROR) {
                    filterLogs((LogLevel)level);
                } else {
                    printf("Invalid log level selected.\n");
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}