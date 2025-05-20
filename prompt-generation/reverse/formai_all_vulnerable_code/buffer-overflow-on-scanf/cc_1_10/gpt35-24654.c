//FormAI DATASET v1.0 Category: System event logger ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define MAX_EVENT_LENGTH 50

typedef struct {
    time_t timestamp;
    char event[MAX_EVENT_LENGTH];
} LogEntry;

LogEntry log_entries[MAX_LOG_ENTRIES];
int num_entries = 0;

// Function to add a new log entry
void addLogEntry(char* event) {
    if (num_entries >= MAX_LOG_ENTRIES) {
        printf("Error: log is full\n");
        return;
    }

    LogEntry entry;
    entry.timestamp = time(NULL);
    strncpy(entry.event, event, MAX_EVENT_LENGTH);

    log_entries[num_entries] = entry;
    num_entries++;
    printf("%s event logged at %ld\n", entry.event, entry.timestamp);
}

// Function to display logs
void displayLogs() {
    printf("Event Logs:\n");
    printf("-------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("[%ld]: %s\n", log_entries[i].timestamp, log_entries[i].event);
    }
    printf("-------------------------\n");
}

int main() {
    while (1) {
        int choice;
        printf("Select an option:\n");
        printf("1. Add log entry\n");
        printf("2. Display logs\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event: ");
                char event[MAX_EVENT_LENGTH];
                scanf("%s", event);
                addLogEntry(event);
                break;

            case 2:
                displayLogs();
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}