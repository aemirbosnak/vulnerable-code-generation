//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char eventType[50];
    char message[256];
} Event;

Event eventLog[MAX_EVENTS];
int eventCount = 0;

void logEvent(const char *eventType, const char *message) {
    if (eventCount < MAX_EVENTS) {
        time(&eventLog[eventCount].timestamp);
        strncpy(eventLog[eventCount].eventType, eventType, sizeof(eventLog[eventCount].eventType) - 1);
        strncpy(eventLog[eventCount].message, message, sizeof(eventLog[eventCount].message) - 1);
        eventCount++;
    } else {
        printf("Event log is full. Cannot log new event.\n");
    }
}

void writeLogToFile() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file == NULL) {
        printf("Error: Could not open log file for writing.\n");
        return;
    }
    for (int i = 0; i < eventCount; i++) {
        fprintf(file, "Time: %sEvent Type: %s\nMessage: %s\n\n",
                ctime(&eventLog[i].timestamp), eventLog[i].eventType, eventLog[i].message);
    }
    fclose(file);
    printf("Log written to %s\n", LOG_FILE);
}

void displayLog() {
    for (int i = 0; i < eventCount; i++) {
        printf("Time: %sEvent Type: %s\nMessage: %s\n\n",
               ctime(&eventLog[i].timestamp), eventLog[i].eventType, eventLog[i].message);
    }
}

void generateStatistics() {
    int infoCount = 0, warningCount = 0, errorCount = 0;
    for (int i = 0; i < eventCount; i++) {
        if (strcmp(eventLog[i].eventType, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(eventLog[i].eventType, "WARNING") == 0) {
            warningCount++;
        } else if (strcmp(eventLog[i].eventType, "ERROR") == 0) {
            errorCount++;
        }
    }
    printf("Event Statistics:\n");
    printf("INFO: %d\n", infoCount);
    printf("WARNING: %d\n", warningCount);
    printf("ERROR: %d\n", errorCount);
}

int main() {
    int choice;
    char message[256];

    while (1) {
        printf("Event Logger Menu:\n");
        printf("1. Log INFO Event\n");
        printf("2. Log WARNING Event\n");
        printf("3. Log ERROR Event\n");
        printf("4. Display Log\n");
        printf("5. Write Log to File\n");
        printf("6. View Statistics\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter INFO message: ");
                fgets(message, sizeof(message), stdin);
                logEvent("INFO", message);
                break;
            case 2:
                printf("Enter WARNING message: ");
                fgets(message, sizeof(message), stdin);
                logEvent("WARNING", message);
                break;
            case 3:
                printf("Enter ERROR message: ");
                fgets(message, sizeof(message), stdin);
                logEvent("ERROR", message);
                break;
            case 4:
                displayLog();
                break;
            case 5:
                writeLogToFile();
                break;
            case 6:
                generateStatistics();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}