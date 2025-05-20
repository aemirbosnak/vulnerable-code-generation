//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100

typedef struct {
    char username[50];
    char action[100];
    time_t timestamp;
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logCount = 0;

// Function to log actions
void logAction(const char* username, const char* action) {
    if (logCount < MAX_LOG_ENTRIES) {
        strcpy(logEntries[logCount].username, username);
        strcpy(logEntries[logCount].action, action);
        logEntries[logCount].timestamp = time(NULL);
        logCount++;
        printf("Action logged successfully. Keep up the good work, %s!\n", username);
    } else {
        printf("Log limit reached! Time to review the log history.\n");
    }
}

// Function to display logs
void displayLogs() {
    printf("\n--- Intrusion Detection Logs ---\n");
    for (int i = 0; i < logCount; i++) {
        printf("%s performed the action: '%s' at %s", logEntries[i].username,
               logEntries[i].action, ctime(&logEntries[i].timestamp));
    }
    if (logCount == 0) {
        printf("No actions logged yet. Stay safe!\n");
    }
    printf("-------------------------------\n");
}

// Function to detect suspicious actions based on predefined criteria
void analyzeLogs() {
    printf("\n--- Analyzing Logs for Suspicious Actions ---\n");
    for (int i = 0; i < logCount; i++) {
        if (strstr(logEntries[i].action, "failed login") != NULL) {
            printf("Warning! Suspicious action detected by %s: '%s'.\n",
                   logEntries[i].username, logEntries[i].action);
        }
    }
    printf("-------------------------------------------\n");
}

// Main function
int main() {
    char username[50];
    char action[100];

    printf("🌟 Welcome to the Cheerful Intrusion Detection System! 🌟\n");

    while (1) {
        printf("Please enter your username (or type 'exit' to quit): ");
        scanf("%s", username);

        if (strcmp(username, "exit") == 0) {
            printf("Exiting the IDS. Stay safe and secure! 😊\n");
            break;
        }

        printf("Hello, %s! What action would you like to log? (e.g., 'login', 'failed login', 'logout')\n", username);
        scanf(" %[^\n]", action); // Read a line including spaces

        logAction(username, action);
        displayLogs();
        analyzeLogs();
    }

    return 0;
}