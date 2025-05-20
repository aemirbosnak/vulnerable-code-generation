//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_MESSAGE_SIZE 256
#define MAX_EVENTS 1000

typedef enum {
    INFO,
    WARNING,
    ERROR
} SeverityLevel;

const char *severityToString(SeverityLevel level) {
    switch (level) {
        case INFO:    return "INFO";
        case WARNING: return "WARNING";
        case ERROR:   return "ERROR";
        default:      return "UNKNOWN";
    }
}

typedef struct {
    char timestamp[20];
    SeverityLevel level;
    char message[MAX_MESSAGE_SIZE];
} Event;

Event eventLog[MAX_EVENTS];
int eventCount = 0;

void getCurrentTime(char *buffer, size_t bufSize) {
    time_t now = time(NULL);
    struct tm *tm_info;
    tm_info = localtime(&now);
    strftime(buffer, bufSize, "%Y-%m-%d %H:%M:%S", tm_info);
}

void logEvent(SeverityLevel level, const char *message) {
    if (eventCount >= MAX_EVENTS) {
        fprintf(stderr, "Event log is full! Cannot log more events.\n");
        return;
    }

    getCurrentTime(eventLog[eventCount].timestamp, sizeof(eventLog[eventCount].timestamp));
    eventLog[eventCount].level = level;
    strncpy(eventLog[eventCount].message, message, MAX_MESSAGE_SIZE - 1);
    eventLog[eventCount].message[MAX_MESSAGE_SIZE - 1] = '\0'; // Ensure null-termination
    eventCount++;

    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fprintf(file, "[%s] [%s] %s\n", eventLog[eventCount - 1].timestamp, severityToString(level), message);
        fclose(file);
    } else {
        fprintf(stderr, "Could not open log file for writing.\n");
    }
}

void displayEvents() {
    printf("----- Event Log -----\n");
    for (int i = 0; i < eventCount; i++) {
        printf("[%s] [%s] %s\n", eventLog[i].timestamp, severityToString(eventLog[i].level), eventLog[i].message);
    }
    printf("---------------------\n");
}

void clearLog() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file) {
        fclose(file);
    } else {
        fprintf(stderr, "Could not open log file for clearing.\n");
    }
    eventCount = 0; // Reset in-memory log
}

int main() {
    int choice;
    char message[MAX_MESSAGE_SIZE];

    while (1) {
        printf("Event Logger Menu:\n");
        printf("1. Log Info\n");
        printf("2. Log Warning\n");
        printf("3. Log Error\n");
        printf("4. Display Events\n");
        printf("5. Clear Log\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter message: ");
                getchar(); // Consume newline
                fgets(message, MAX_MESSAGE_SIZE, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                logEvent((SeverityLevel)(choice - 1), message);
                break;
            case 4:
                displayEvents();
                break;
            case 5:
                clearLog();
                printf("Log cleared.\n");
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}