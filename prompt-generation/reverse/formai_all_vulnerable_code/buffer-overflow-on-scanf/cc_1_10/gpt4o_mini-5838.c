//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENTS 100
#define EVENT_DESC_LENGTH 256

typedef struct {
    char description[EVENT_DESC_LENGTH];
    time_t timestamp;
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int event_count;
} EventLogger;

// Function declarations
void initialize_logger(EventLogger *logger);
void add_event(EventLogger *logger, const char *description);
void view_events(const EventLogger *logger);
void save_events_to_file(const EventLogger *logger, const char *filepath);
const char *format_timestamp(time_t timestamp);

int main() {
    EventLogger logger;
    initialize_logger(&logger);

    int choice;
    char description[EVENT_DESC_LENGTH];

    while (1) {
        printf("\nEvent Logger Menu:\n");
        printf("1. Add Event\n");
        printf("2. View Events\n");
        printf("3. Save Events to File\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(description, EVENT_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline
                add_event(&logger, description);
                break;
            case 2:
                view_events(&logger);
                break;
            case 3:
                save_events_to_file(&logger, LOG_FILE);
                printf("Events saved to %s\n", LOG_FILE);
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void initialize_logger(EventLogger *logger) {
    logger->event_count = 0;
}

void add_event(EventLogger *logger, const char *description) {
    if (logger->event_count < MAX_EVENTS) {
        strncpy(logger->events[logger->event_count].description, description, EVENT_DESC_LENGTH);
        logger->events[logger->event_count].timestamp = time(NULL);
        logger->event_count++;
        printf("Event added: %s\n", description);
    } else {
        printf("Event log is full. Cannot add new event.\n");
    }
}

void view_events(const EventLogger *logger) {
    if (logger->event_count == 0) {
        printf("No events logged.\n");
        return;
    }
    printf("\nLogged Events:\n");
    for (int i = 0; i < logger->event_count; i++) {
        printf("%d: [%s] %s\n", i + 1, format_timestamp(logger->events[i].timestamp), logger->events[i].description);
    }
}

void save_events_to_file(const EventLogger *logger, const char *filepath) {
    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    for (int i = 0; i < logger->event_count; i++) {
        fprintf(file, "[%s] %s\n", format_timestamp(logger->events[i].timestamp), logger->events[i].description);
    }
    fclose(file);
}

const char *format_timestamp(time_t timestamp) {
    static char buffer[20];
    struct tm *tm_info = localtime(&timestamp);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}