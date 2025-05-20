//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 20
#define MAX_EVENT_DESCRIPTION_LENGTH 50

typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
    int start_time;
    int end_time;
} Event;

int compare_events(const void *a, const void *b) {
    const Event *event_a = a;
    const Event *event_b = b;
    if (event_a->start_time < event_b->start_time) {
        return -1;
    } else if (event_a->start_time > event_b->start_time) {
        return 1;
    } else {
        return 0;
    }
}

void print_event(const Event *event) {
    printf("Name: %s\nDescription: %s\nStart Time: %d\nEnd Time: %d\n", event->name, event->description, event->start_time, event->end_time);
}

int main() {
    int num_events;
    char input_buffer[100];
    Event events[MAX_EVENTS];
    int i;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("How many events do you want to schedule? ");
    scanf("%d", &num_events);

    for (i = 0; i < num_events; i++) {
        printf("Enter the name of event #%d: ", i + 1);
        scanf("%s", events[i].name);

        printf("Enter the description of event #%d: ", i + 1);
        scanf("%s", events[i].description);

        printf("Enter the start time of event #%d (in minutes): ", i + 1);
        scanf("%d", &events[i].start_time);

        printf("Enter the end time of event #%d (in minutes): ", i + 1);
        scanf("%d", &events[i].end_time);
    }

    qsort(events, num_events, sizeof(Event), compare_events);

    for (i = 0; i < num_events; i++) {
        print_event(&events[i]);
    }

    return 0;
}