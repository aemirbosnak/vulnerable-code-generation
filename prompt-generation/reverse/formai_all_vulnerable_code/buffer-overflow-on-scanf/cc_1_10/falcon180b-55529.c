//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_NAME_LENGTH 50

typedef struct event {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t timestamp;
} Event;

int num_events = 0;
Event events[MAX_EVENTS];

void add_event(char* name, time_t timestamp) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }
    strcpy(events[num_events].name, name);
    events[num_events].timestamp = timestamp;
    num_events++;
}

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter 'add event' followed by an event name and timestamp in the format 'YYYY-MM-DD HH:MM:SS' to add an event.\n");
    printf("Enter 'travel to event' followed by an event name to travel to that event.\n");
    printf("Enter 'quit' to exit the program.\n");

    char input[MAX_EVENT_NAME_LENGTH];
    while (1) {
        printf("> ");
        scanf("%s", input);
        if (strcmp(input, "add event") == 0) {
            char name[MAX_EVENT_NAME_LENGTH];
            char timestamp_str[20];
            printf("Enter event name: ");
            scanf("%s", name);
            printf("Enter timestamp (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", timestamp_str);
            struct tm timestamp = {0};
            strptime(timestamp_str, "%Y-%m-%d %H:%M:%S", &timestamp);
            add_event(name, mktime(&timestamp));
        } else if (strcmp(input, "travel to event") == 0) {
            char event_name[MAX_EVENT_NAME_LENGTH];
            printf("Enter event name: ");
            scanf("%s", event_name);
            for (int i = 0; i < num_events; i++) {
                if (strcmp(events[i].name, event_name) == 0) {
                    time_t target_timestamp = events[i].timestamp;
                    printf("Traveling to event '%s' at %s...\n", events[i].name, ctime(&target_timestamp));
                    sleep(1);
                    printf("Arrived at event '%s'!\n", events[i].name);
                    break;
                }
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}