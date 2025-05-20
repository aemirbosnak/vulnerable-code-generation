//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 1000

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef struct {
    time_t timestamp;
    LogLevel level;
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void logMessage(LogLevel level, const char* message) {
    if (logCount >= MAX_LOG_ENTRIES) {
        printf("Log capacity reached. Can't log more entries.\n");
        return;
    }

    LogEntry newEntry;
    newEntry.timestamp = time(NULL);
    newEntry.level = level;
    strncpy(newEntry.message, message, MAX_LINE_LENGTH - 1);
    newEntry.message[MAX_LINE_LENGTH - 1] = '\0'; // Ensure null-termination

    logEntries[logCount++] = newEntry;
}

void printLogEntry(const LogEntry* entry) {
    char* levelStr;
    switch (entry->level) {
        case INFO:
            levelStr = "INFO";
            break;
        case WARNING:
            levelStr = "WARNING";
            break;
        case ERROR:
            levelStr = "ERROR";
            break;
        default:
            levelStr = "UNKNOWN";
    }

    char timeString[20];
    struct tm* tm_info = localtime(&entry->timestamp);
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", tm_info);

    printf("[%s] %s: %s\n", timeString, levelStr, entry->message);
}

void printLog() {
    printf("=== LOG ENTRIES ===\n");
    for (int i = 0; i < logCount; i++) {
        printLogEntry(&logEntries[i]);
    }
}

void filterLog(LogLevel level) {
    printf("=== FILTERED LOGS (%s) ===\n", level == INFO ? "INFO" :
                                          level == WARNING ? "WARNING" :
                                          "ERROR");
    for (int i = 0; i < logCount; i++) {
        if (logEntries[i].level == level) {
            printLogEntry(&logEntries[i]);
        }
    }
}

void clearLog() {
    logCount = 0;
    printf("Log cleared.\n");
}

void showMenu() {
    printf("\n--- Log Management System ---\n");
    printf("1. Log Info Message\n");
    printf("2. Log Warning Message\n");
    printf("3. Log Error Message\n");
    printf("4. Show All Logs\n");
    printf("5. Filter Logs by Level\n");
    printf("6. Clear All Logs\n");
    printf("0. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char message[MAX_LINE_LENGTH];
    LogLevel selectedLevel;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Info Message: ");
                // Clear the new line character from the input buffer
                getchar();
                fgets(message, sizeof(message), stdin);
                strtok(message, "\n"); // Remove new line
                logMessage(INFO, message);
                break;
            case 2:
                printf("Enter Warning Message: ");
                getchar();
                fgets(message, sizeof(message), stdin);
                strtok(message, "\n");
                logMessage(WARNING, message);
                break;
            case 3:
                printf("Enter Error Message: ");
                getchar();
                fgets(message, sizeof(message), stdin);
                strtok(message, "\n");
                logMessage(ERROR, message);
                break;
            case 4:
                printLog();
                break;
            case 5:
                printf("Select Log Level to Filter (1. INFO, 2. WARNING, 3. ERROR): ");
                scanf("%d", &choice);
                selectedLevel = (LogLevel)(choice - 1);
                if (selectedLevel < INFO || selectedLevel > ERROR) {
                    printf("Invalid selection.\n");
                } else {
                    filterLog(selectedLevel);
                }
                break;
            case 6:
                clearLog();
                break;
            case 0:
                printf("Exiting the Log Management System.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}