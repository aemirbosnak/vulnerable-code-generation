//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256
#define TIMESTAMP_LENGTH 20

// Function to get the current timestamp
void getCurrentTimestamp(char *buffer, size_t length) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, length, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to log an event to a file
void logEvent(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    char timestamp[TIMESTAMP_LENGTH];
    getCurrentTimestamp(timestamp, sizeof(timestamp));

    fprintf(file, "[%s] %s\n", timestamp, event);
    fclose(file);
}

// Function to display the log file content
void displayLog() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    char line[MAX_EVENT_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// Function to simulate an event
void triggerEvent(const char *eventDescription) {
    printf("Event Triggered: %s\n", eventDescription);
    logEvent(eventDescription);
}

void printMenu() {
    printf("\nEvent Logger\n");
    printf("1. Trigger an Event\n");
    printf("2. Display Log\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char eventDescription[MAX_EVENT_LENGTH];

    // Clear the log file at the start
    FILE *file = fopen(LOG_FILE, "w");
    if (file != NULL) {
        fclose(file);
    }

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(eventDescription, sizeof(eventDescription), stdin);
                eventDescription[strcspn(eventDescription, "\n")] = 0; // Remove newline
                triggerEvent(eventDescription);
                break;
            case 2:
                displayLog();
                break;
            case 3:
                printf("Exiting Event Logger. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}