//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LEN 256
#define MAX_BUFFER 512

// Struct to hold event details
typedef struct {
    time_t timestamp;
    char event[MAX_EVENT_LEN];
} Event;

// Function to log the event
void log_event(const char *event_description) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    Event event;
    event.timestamp = time(NULL);
    strncpy(event.event, event_description, MAX_EVENT_LEN - 1);
    event.event[MAX_EVENT_LEN - 1] = '\0'; // Ensure null termination

    // Write to file with formatted timestamp
    fprintf(file, "[%s] %s\n", ctime(&event.timestamp), event.event);
    fclose(file);
}

// Function to display the log file contents
void display_log() {
    char buffer[MAX_BUFFER];
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    printf("=== Event Log ===\n");
    while (fgets(buffer, MAX_BUFFER, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

// Function to clear the log file
void clear_log() {
    if (remove(LOG_FILE) != 0) {
        perror("Failed to clear log file");
    } else {
        printf("Log file cleared.\n");
    }
}

// A simple menu for the logger
void menu() {
    int choice;
    char event_description[MAX_EVENT_LEN];

    do {
        printf("=== Event Logger Menu ===\n");
        printf("1. Log a new event\n");
        printf("2. Display log\n");
        printf("3. Clear log\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event_description, MAX_EVENT_LEN, stdin);
                event_description[strcspn(event_description, "\n")] = 0; // Remove newline
                log_event(event_description);
                break;

            case 2:
                display_log();
                break;

            case 3:
                clear_log();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");

    } while (choice != 4);
}

int main() {
    // Initialize the log file
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    // Start the menu
    menu();

    return 0;
}