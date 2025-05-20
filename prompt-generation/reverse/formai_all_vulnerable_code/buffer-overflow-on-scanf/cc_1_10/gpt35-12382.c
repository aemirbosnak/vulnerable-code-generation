//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the maximum number of events */
#define MAX_EVENTS 100

/* Define the maximum length of an event description */
#define MAX_EVENT_LENGTH 100

/* Define the time format */
#define TIME_FORMAT "%Y-%m-%d %H:%M:%S"

/* Define the colors for text formatting */
#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RESET "\x1b[0m"

/* Define the struct for an event */
typedef struct Event {
    char description[MAX_EVENT_LENGTH];
    char time[20];
} Event;

/* Define the struct for the event logger */
typedef struct EventLogger {
    int count;
    Event events[MAX_EVENTS];
} EventLogger;

/* Function to get the current time */
void get_current_time(char* timestamp) {
    time_t t = time(NULL);
    strftime(timestamp, 20, TIME_FORMAT, localtime(&t));
}

/* Function to add an event to the event logger */
void log_event(EventLogger* logger, char* description) {
    if (logger->count == MAX_EVENTS) {
        printf(COLOR_RED "Error: Maximum number of events reached.\n" COLOR_RESET);
        return;
    }
    Event event;
    get_current_time(event.time);
    snprintf(event.description, MAX_EVENT_LENGTH, "%s", description);
    logger->events[logger->count++] = event;
    printf(COLOR_GREEN "Event logged successfully.\n" COLOR_RESET);
}

/* Function to print all events in the event logger */
void print_events(EventLogger* logger) {
    printf(COLOR_YELLOW "Event Logs:\n" COLOR_RESET);
    for (int i = 0; i < logger->count; i++) {
        printf("%s - %s\n", logger->events[i].time, logger->events[i].description);
    }
}

/* The main function */
int main() {
    EventLogger logger;
    logger.count = 0;
    int choice = 0;
    char description[MAX_EVENT_LENGTH];

    printf(COLOR_YELLOW "Welcome to the Event Logger Program.\n" COLOR_RESET);

    do {
        printf("Please select an option:\n");
        printf("1 - Log an Event\n");
        printf("2 - Print Event Logs\n");
        printf("3 - Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf(" %[^\n]s", description);
                log_event(&logger, description);
                break;
            case 2:
                print_events(&logger);
                break;
            case 3:
                printf(COLOR_YELLOW "Exiting Event Logger Program...\n" COLOR_RESET);
                break;
            default:
                printf(COLOR_RED "Invalid choice. Please try again.\n" COLOR_RESET);
                break;
        }
    } while (choice != 3);

    return 0;
}