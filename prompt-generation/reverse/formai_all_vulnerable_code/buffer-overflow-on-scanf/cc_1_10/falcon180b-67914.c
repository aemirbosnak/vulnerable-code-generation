//Falcon-180B DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char event_type[10];
    char event_description[100];
    time_t event_time;
} Event;

void log_event(Event event) {
    FILE *log_file = fopen(EVENT_LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Unable to open log file.\n");
        return;
    }

    fprintf(log_file, "Event Type: %s\n", event.event_type);
    fprintf(log_file, "Event Description: %s\n", event.event_description);
    fprintf(log_file, "Event Time: %s\n\n", ctime(&event.event_time));

    fclose(log_file);
}

int main() {
    Event event;
    int choice;

    do {
        printf("Event Logger\n");
        printf("1. Log an event\n");
        printf("2. View log file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter event type (max 10 characters): ");
                scanf("%s", event.event_type);
                printf("Enter event description (max 100 characters): ");
                scanf("%s", event.event_description);
                event.event_time = time(NULL);
                log_event(event);
                break;
            case 2:
                system("notepad event_log.txt");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}