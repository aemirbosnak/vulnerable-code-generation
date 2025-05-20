//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "system.log"
#define BUFFER_SIZE 256

enum LogLevel {
    INFO,
    WARNING,
    ERROR,
    DEBUG
};

typedef struct LogEntry {
    enum LogLevel level;
    char timestamp[20];
    char message[BUFFER_SIZE];
} LogEntry;

void getCurrentTime(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void logMessage(enum LogLevel level, const char* message) {
    FILE* logFile = fopen(LOG_FILE, "a");
    if (!logFile) {
        fprintf(stderr, "Critical Error: Unable to open log file!\n");
        exit(EXIT_FAILURE);
    }

    LogEntry entry;
    entry.level = level;
    getCurrentTime(entry.timestamp, sizeof(entry.timestamp));
    strncpy(entry.message, message, BUFFER_SIZE - 1);
    entry.message[BUFFER_SIZE - 1] = '\0';  // Ensure null termination

    fprintf(logFile, "[%s] [%s] %s\n", entry.timestamp,
            level == INFO ? "INFO" : level == WARNING ? "WARNING" :
            level == ERROR ? "ERROR" : "DEBUG", entry.message);
    fclose(logFile);
}

void parseLogFile() {
    FILE* logFile = fopen(LOG_FILE, "r");
    if (!logFile) {
        fprintf(stderr, "Paranoia Alert: Log file not found!\n");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), logFile)) {
        printf("Parsing log: %s", buffer);
    }
    fclose(logFile);
}

void filterLogMessages(enum LogLevel filterLevel) {
    FILE* logFile = fopen(LOG_FILE, "r");
    if (!logFile) {
        fprintf(stderr, "Panic: Could not read log file!\n");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), logFile)) {
        if (strstr(buffer, filterLevel == INFO ? "INFO" : 
                   filterLevel == WARNING ? "WARNING" : 
                   filterLevel == ERROR ? "ERROR" : "DEBUG")) {
            printf("Filtered log: %s", buffer);
        }
    }
    fclose(logFile);
}

void showLogMenu() {
    printf("\n--- Log Analysis Menu ---\n");
    printf("1. Log Info Message\n");
    printf("2. Log Warning Message\n");
    printf("3. Log Error Message\n");
    printf("4. Log Debug Message\n");
    printf("5. Parse Log File\n");
    printf("6. Filter Log Messages\n");
    printf("7. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    int choice;
    char message[BUFFER_SIZE];

    while (1) {
        showLogMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter info message: ");
                fgets(message, sizeof(message), stdin);
                logMessage(INFO, message);
                break;
            case 2:
                printf("Enter warning message: ");
                fgets(message, sizeof(message), stdin);
                logMessage(WARNING, message);
                break;
            case 3:
                printf("Enter error message: ");
                fgets(message, sizeof(message), stdin);
                logMessage(ERROR, message);
                break;
            case 4:
                printf("Enter debug message: ");
                fgets(message, sizeof(message), stdin);
                logMessage(DEBUG, message);
                break;
            case 5:
                parseLogFile();
                break;
            case 6:
                printf("Select log level to filter (0:INFO, 1:WARNING, 2:ERROR, 3:DEBUG): ");
                int filterChoice;
                scanf("%d", &filterChoice);
                filterLogMessages((enum LogLevel)filterChoice);
                break;
            case 7:
                printf("Exiting the paranoid log analyzer...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Check your surroundings and try again.\n");
                break;
        }
    }
    return 0;
}