//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 256
#define LOG_FILE "event_log.txt"

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

Event eventLog[MAX_EVENTS];
int eventCount = 0;

// Function to log an event
void logEvent(const char *event) {
    if (eventCount >= MAX_EVENTS) {
        printf("Log is full. Cannot log new events.\n");
        return;
    }
    
    strncpy(eventLog[eventCount].event, event, MAX_EVENT_LENGTH - 1);
    eventLog[eventCount].event[MAX_EVENT_LENGTH - 1] = '\0'; // Ensure null termination
    eventLog[eventCount].timestamp = time(NULL);
    eventCount++;

    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fprintf(file, "%s: %s\n", ctime(&eventLog[eventCount - 1].timestamp), eventLog[eventCount - 1].event);
        fclose(file);
    } else {
        printf("Error opening log file for writing.\n");
    }
}

// Function to display the event log
void displayLog() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file) {
        char line[512];
        printf("Event Log:\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error opening log file for reading.\n");
    }
}

// Function to clear the event log
void clearLog() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file) {
        fclose(file);
        eventCount = 0; // Reset the event count
        printf("Event log cleared.\n");
    } else {
        printf("Error opening log file for clearing.\n");
    }
}

// Main function
int main() {
    int choice;
    char input[MAX_EVENT_LENGTH];

    do {
        printf("\nEvent Logger Menu:\n");
        printf("1. Log a new event\n");
        printf("2. Display event log\n");
        printf("3. Clear event log\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter the event description: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                logEvent(input);
                break;
            case 2:
                displayLog();
                break;
            case 3:
                clearLog();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}