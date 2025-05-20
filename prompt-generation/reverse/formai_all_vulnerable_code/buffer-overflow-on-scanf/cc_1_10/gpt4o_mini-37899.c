//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_MESSAGE_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    LogLevel level;
    time_t timestamp;
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void logEvent(const char *message, LogLevel level) {
    if (logCount < MAX_LOG_ENTRIES) {
        strncpy(logEntries[logCount].message, message, MAX_MESSAGE_LENGTH);
        logEntries[logCount].level = level;
        logEntries[logCount].timestamp = time(NULL);
        logCount++;
    } else {
        printf("Log limit reached! Can't log more events.\n");
    }
}

void printLogEntry(const LogEntry *entry) {
    char timeBuffer[26];
    struct tm* tm_info;

    tm_info = localtime(&entry->timestamp);
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", tm_info);

    switch (entry->level) {
        case INFO:
            printf("[INFO]   [%s]: %s\n", timeBuffer, entry->message);
            break;
        case WARNING:
            printf("[WARNING][%s]: %s\n", timeBuffer, entry->message);
            break;
        case ERROR:
            printf("[ERROR]  [%s]: %s\n", timeBuffer, entry->message);
            break;
    }
}

void printLog() {
    printf("\n--- Event Log ---\n");
    for (int i = 0; i < logCount; i++) {
        printLogEntry(&logEntries[i]);
    }
    printf("--- End of Log ---\n\n");
}

void clearLog() {
    logCount = 0;
    printf("The event log has been cleared!\n");
}

int main() {
    int choice;
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        printf("Welcome to the Event Logger! Choose an option:\n");
        printf("1. Log an Info Event\n");
        printf("2. Log a Warning Event\n");
        printf("3. Log an Error Event\n");
        printf("4. Print Log\n");
        printf("5. Clear Log\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Info Message: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0';  // remove newline
                logEvent(message, INFO);
                break;
            case 2:
                printf("Enter Warning Message: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0';  // remove newline
                logEvent(message, WARNING);
                break;
            case 3:
                printf("Enter Error Message: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = '\0';  // remove newline
                logEvent(message, ERROR);
                break;
            case 4:
                printLog();
                break;
            case 5:
                clearLog();
                break;
            case 6:
                printf("Exiting the Event Logger! Bye-bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    return 0;
}