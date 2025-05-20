//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 80
#define MAX_NAME_LENGTH 40

typedef struct {
    char name[MAX_NAME_LENGTH];
    char event[MAX_EVENT_LENGTH];
    time_t start_time;
    time_t end_time;
} Event;

void add_event(Event* events, int num_events, char* name, char* event, time_t start_time, time_t end_time) {
    if (num_events >= MAX_EVENTS) {
        printf("Cannot add more events. Maximum limit of %d events reached.\n", MAX_EVENTS);
        return;
    }

    strcpy(events[num_events].name, name);
    strcpy(events[num_events].event, event);
    events[num_events].start_time = start_time;
    events[num_events].end_time = end_time;

    num_events++;
}

void print_events(Event* events, int num_events) {
    printf("Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s (%s - %s)\n", events[i].name, events[i].event, ctime(&events[i].start_time), ctime(&events[i].end_time));
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    char name[MAX_NAME_LENGTH];
    char event[MAX_EVENT_LENGTH];
    time_t start_time, end_time;

    while (1) {
        printf("Enter name (leave blank to exit): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter event: ");
        scanf("%s", event);

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", event);
        start_time = strptime(event, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", event);
        end_time = strptime(event, "%Y-%m-%d %H:%M:%S", NULL);

        add_event(events, num_events, name, event, start_time, end_time);
    }

    print_events(events, num_events);

    return 0;
}