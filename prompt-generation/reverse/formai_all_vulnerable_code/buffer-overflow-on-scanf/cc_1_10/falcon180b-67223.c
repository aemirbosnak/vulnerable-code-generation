//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 50
#define MAX_EVENT_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} Event;

void print_event(Event* event) {
    printf("Name: %s\n", event->name);
    printf("Description: %s\n", event->description);
    printf("Start Time: %s\n", ctime(&event->start_time));
    printf("End Time: %s\n", ctime(&event->end_time));
}

int compare_events(const void* a, const void* b) {
    const Event* event_a = (const Event*)a;
    const Event* event_b = (const Event*)b;

    time_t start_time_a = event_a->start_time;
    time_t start_time_b = event_b->start_time;

    return difftime(start_time_a, start_time_b);
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    char input[MAX_EVENT_NAME_LENGTH];
    printf("Enter event name (or press enter to quit): ");
    scanf("%s", input);

    while (strcmp(input, "")!= 0) {
        if (num_events >= MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
            break;
        }

        printf("Enter event description: ");
        scanf("%s", events[num_events].description);

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        events[num_events].start_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        events[num_events].end_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

        num_events++;

        printf("Enter event name (or press enter to quit): ");
        scanf("%s", input);
    }

    qsort(events, num_events, sizeof(Event), compare_events);

    printf("Event Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        print_event(&events[i]);
    }

    return 0;
}