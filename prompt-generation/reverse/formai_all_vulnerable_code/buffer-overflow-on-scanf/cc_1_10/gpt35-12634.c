//FormAI DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_CHARS 100

struct LogEvent {
    time_t timestamp;
    char description[MAX_CHARS];
};

struct Logger {
    char name[MAX_CHARS];
    int num_events;
    struct LogEvent events[MAX_EVENTS];
};

void log_event(struct Logger* logger, char* description) {
    if (logger->num_events >= MAX_EVENTS) {
        printf("Error: logger is full.\n");
        return;
    }

    struct LogEvent event;
    event.timestamp = time(NULL);
    strncpy(event.description, description, MAX_CHARS);

    logger->events[logger->num_events++] = event;

    printf("Event logged for %s at %s\n", logger->name, ctime(&event.timestamp));
}

void print_event(struct LogEvent event) {
    printf("%s: %s", ctime(&event.timestamp), event.description);
}

void print_logger(struct Logger* logger) {
    printf("Logger: %s\n", logger->name);
    printf("Number of events: %d\n", logger->num_events);
    for (int i=0; i<logger->num_events; i++) {
        print_event(logger->events[i]);
    }
}

int main() {
    bool is_running = true;
    int num_loggers = 0;
    struct Logger loggers[MAX_EVENTS];

    printf("Welcome to the C System Event Logger\n");

    while (is_running) {
        printf("\nPlease choose an action:\n");
        printf("1. Create a new logger\n");
        printf("2. Log an event\n");
        printf("3. Print logs for a logger\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the name of the logger: ");
                char logger_name[MAX_CHARS];
                scanf("%s", logger_name);

                struct Logger logger;
                strncpy(logger.name, logger_name, MAX_CHARS);
                logger.num_events = 0;
                loggers[num_loggers++] = logger;

                printf("Logger %s created successfully with ID %d\n", logger.name, num_loggers-1);
                break;
            }

            case 2: {
                if (num_loggers == 0) {
                    printf("Error: There are no loggers to log to.\n");
                    break;
                }

                printf("Enter the ID of the logger to log to: ");
                int logger_id;
                scanf("%d", &logger_id);

                if (logger_id < 0 || logger_id >= num_loggers) {
                    printf("Error: Invalid logger ID.\n");
                    break;
                }

                printf("Enter a description for the event: ");
                char event_description[MAX_CHARS];
                scanf("%s", event_description);

                log_event(&loggers[logger_id], event_description);
                break;
            }

            case 3: {
                if (num_loggers == 0) {
                    printf("Error: There are no loggers to print from.\n");
                    break;
                }

                printf("Enter the ID of the logger to print from: ");
                int logger_id;
                scanf("%d", &logger_id);

                if (logger_id < 0 || logger_id >= num_loggers) {
                    printf("Error: Invalid logger ID.\n");
                    break;
                }

                print_logger(&loggers[logger_id]);
                break;
            }

            case 4: {
                printf("Goodbye!\n");
                is_running = false;
                break;
            }

            default: {
                printf("Error: Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}