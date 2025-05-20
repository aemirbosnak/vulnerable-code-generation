//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LEN 256
#define MAX_EVENTS 100

typedef struct {
    int id;
    char description[MAX_EVENT_LEN];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void log_event(const char *description) {
    if (event_count >= MAX_EVENTS) {
        printf("Log is full. Cannot log new events.\n");
        return;
    }

    events[event_count].id = event_count + 1;
    strncpy(events[event_count].description, description, MAX_EVENT_LEN - 1);
    events[event_count].description[MAX_EVENT_LEN - 1] = '\0';
    events[event_count].timestamp = time(NULL);
    
    // Save to file
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fprintf(file, "%d|%s|%ld\n", events[event_count].id, events[event_count].description, events[event_count].timestamp);
        fclose(file);
    } else {
        printf("Failed to open log file for writing.\n");
    }
    
    event_count++;
    printf("Event logged: %s\n", description);
}

void view_logs() {
    printf("Current Events:\n");
    if (event_count == 0) {
        printf("No events logged.\n");
        return;
    }

    for (int i = 0; i < event_count; i++) {
        printf("ID: %d | Description: %s | Timestamp: %s", events[i].id, events[i].description, ctime(&events[i].timestamp));
    }
}

void delete_event(int id) {
    if (id <= 0 || id > event_count) {
        printf("Invalid event ID.\n");
        return;
    }

    for (int i = id - 1; i < event_count - 1; i++) {
        events[i] = events[i + 1];
    }
    event_count--;
    printf("Deleted event ID: %d\n", id);
    
    // Rewrite to file
    FILE *file = fopen(LOG_FILE, "w");
    if (file) {
        for (int i = 0; i < event_count; i++) {
            fprintf(file, "%d|%s|%ld\n", events[i].id, events[i].description, events[i].timestamp);
        }
        fclose(file);
    } else {
        printf("Failed to open log file for writing.\n");
    }
}

void show_menu() {
    printf("\nEvent Logger Menu:\n");
    printf("1. Log Event\n");
    printf("2. View Logs\n");
    printf("3. Delete Event\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    char event_description[MAX_EVENT_LEN];
    int event_id;

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter event description: ");
                fgets(event_description, MAX_EVENT_LEN, stdin);
                event_description[strcspn(event_description, "\n")] = 0; // Remove newline
                log_event(event_description);
                break;
            case 2:
                view_logs();
                break;
            case 3:
                printf("Enter event ID to delete: ");
                scanf("%d", &event_id);
                delete_event(event_id);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}