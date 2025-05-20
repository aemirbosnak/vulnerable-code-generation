//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENTS 100
#define EVENT_DESC_LENGTH 256

typedef struct {
    time_t timestamp;
    char description[EVENT_DESC_LENGTH];
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int event_count;
} EventLogger;

void init_logger(EventLogger *logger) {
    logger->event_count = 0;
    FILE *file = fopen(LOG_FILE, "w");
    if (file) {
        fclose(file);
    } else {
        perror("Failed to initialize log file");
    }
}

void log_event(EventLogger *logger, const char *description) {
    if (logger->event_count < MAX_EVENTS) {
        logger->events[logger->event_count].timestamp = time(NULL);
        strncpy(logger->events[logger->event_count].description, description, EVENT_DESC_LENGTH - 1);
        logger->events[logger->event_count].description[EVENT_DESC_LENGTH - 1] = '\0'; // Ensuring null-termination
        logger->event_count++;
        
        // Append to the log file
        FILE *file = fopen(LOG_FILE, "a");
        if (file) {
            fprintf(file, "[%s] %s\n", ctime(&logger->events[logger->event_count - 1].timestamp), description);
            fclose(file);
        } else {
            perror("Failed to log event to file");
        }
    } else {
        printf("Maximum event log count reached. Cannot log more events.\n");
    }
}

void display_logs(EventLogger *logger) {
    printf("\nEvent Log (%d events recorded):\n", logger->event_count);
    for (int i = 0; i < logger->event_count; i++) {
        printf("[%s] %s\n", ctime(&logger->events[i].timestamp), logger->events[i].description);
    }
}

void clear_logs(EventLogger *logger) {
    logger->event_count = 0;
    FILE *file = fopen(LOG_FILE, "w");
    if (file) {
        fclose(file);
        printf("Event logs have been cleared.\n");
    } else {
        perror("Failed to clear log file");
    }
}

int main() {
    EventLogger logger;
    init_logger(&logger);
    int choice;
    char description[EVENT_DESC_LENGTH];

    do {
        printf("\n--- Event Logger Menu ---\n");
        printf("1. Log an event\n");
        printf("2. Display all events\n");
        printf("3. Clear all logs\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(description, EVENT_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // Strip newline character
                log_event(&logger, description);
                break;
            case 2:
                display_logs(&logger);
                break;
            case 3:
                clear_logs(&logger);
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}