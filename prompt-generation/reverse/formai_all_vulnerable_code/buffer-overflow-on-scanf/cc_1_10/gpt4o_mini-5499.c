//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_ENTRY_LENGTH 256

typedef struct {
    char timestamp[20];
    char message[LOG_ENTRY_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

void getCurrentTimestamp(char* buffer, size_t size) {
    time_t rawTime;
    struct tm * timeInfo;
    
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", timeInfo);
}

void logEvent(const char* message) {
    if (logCount < MAX_LOG_ENTRIES) {
        getCurrentTimestamp(logEntries[logCount].timestamp, sizeof(logEntries[logCount].timestamp));
        strncpy(logEntries[logCount].message, message, LOG_ENTRY_LENGTH - 1);
        logEntries[logCount].message[LOG_ENTRY_LENGTH - 1] = '\0'; // Ensure null termination
        logCount++;
    } else {
        printf("Log storage is full, unable to log new events!\n");
    }
}

void displayLogs() {
    if (logCount == 0) {
        printf("No logs available.\n");
        return;
    }
    
    printf("System Event Logs:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < logCount; i++) {
        printf("[%s] %s\n", logEntries[i].timestamp, logEntries[i].message);
    }
    printf("-----------------------------------\n");
}

void clearLogs() {
    logCount = 0;
    printf("All logs have been cleared.\n");
}

void showMenu() {
    printf("System Event Logger\n");
    printf("--------------------\n");
    printf("1. Log an event\n");
    printf("2. Display logs\n");
    printf("3. Clear logs\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char message[LOG_ENTRY_LENGTH];

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf
        
        switch (choice) {
            case 1:
                printf("Enter log message: ");
                fgets(message, LOG_ENTRY_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline
                logEvent(message);
                break;
            case 2:
                displayLogs();
                break;
            case 3:
                clearLogs();
                break;
            case 4:
                printf("Exiting the Logger. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}