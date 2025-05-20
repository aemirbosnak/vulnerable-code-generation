//Falcon-180B DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define EVENT_LOG_FILE "event_log.txt"

// Event structure
typedef struct {
    char event_type[50];
    char event_description[200];
    time_t timestamp;
} Event;

// Function to log an event
void log_event(Event event) {
    FILE *event_log;
    event_log = fopen(EVENT_LOG_FILE, "a");
    
    if (event_log == NULL) {
        printf("Error opening event log file.\n");
        exit(1);
    }
    
    fprintf(event_log, "Event Type: %s\n", event.event_type);
    fprintf(event_log, "Event Description: %s\n", event.event_description);
    fprintf(event_log, "Timestamp: %s", ctime(&event.timestamp));
    
    fclose(event_log);
}

// Function to read events from the log file
void read_events() {
    FILE *event_log;
    char event_buffer[500];
    Event event;
    
    event_log = fopen(EVENT_LOG_FILE, "r");
    
    if (event_log == NULL) {
        printf("Error opening event log file.\n");
        exit(1);
    }
    
    while (fgets(event_buffer, sizeof(event_buffer), event_log)!= NULL) {
        sscanf(event_buffer, "Event Type: %[^\n]", event.event_type);
        sscanf(event_buffer, "Event Description: %[^\n]", event.event_description);
        sscanf(event_buffer, "Timestamp: %s", event.timestamp);
        
        printf("Event Type: %s\n", event.event_type);
        printf("Event Description: %s\n", event.event_description);
        printf("Timestamp: %s", ctime(&event.timestamp));
        printf("\n");
    }
    
    fclose(event_log);
}

int main() {
    int choice;
    Event event;
    
    do {
        printf("Event Logger\n");
        printf("1. Log an event\n");
        printf("2. Read events\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter event type: ");
                scanf("%[^\n]", event.event_type);
                printf("Enter event description: ");
                scanf("%[^\n]", event.event_description);
                
                time(&event.timestamp);
                
                log_event(event);
                break;
                
            case 2:
                read_events();
                break;
                
            case 3:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);
    
    return 0;
}