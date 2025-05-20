//FormAI DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    char name[50];
    char description[100];
    time_t timestamp;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void log_event(char* name, char* description) {
    if(num_events < MAX_EVENTS) {
        Event new_event;
        strncpy(new_event.name, name, sizeof(new_event.name));
        strncpy(new_event.description, description, sizeof(new_event.description));
        new_event.timestamp = time(NULL);
        events[num_events++] = new_event;
    }
    else {
        printf("Event log is full. Unable to log event");
    }
}

void print_events() {
    printf("Total events logged: %d\n", num_events);
    for(int i = 0; i < num_events; i++) {
        char time_str[30];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&events[i].timestamp));
        printf("Event #%d:\n", i+1);
        printf("Name: %s\n", events[i].name);
        printf("Description: %s\n", events[i].description);
        printf("Timestamp: %s\n", time_str);
    }
}

int main() {
    printf("Welcome to the event logger!\n");
    int choice = 0;
    do {
        printf("\nChoose an option:\n");
        printf("1. Log an event\n");
        printf("2. View all events\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter event name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter event description: ");
                char description[100];
                scanf("%s", description);
                log_event(name, description);
                printf("Event logged successfully!\n");
                break;
            case 2:
                print_events();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    } while(choice != 3);

    return 0;
}