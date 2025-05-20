//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 50

struct Event {
    char name[MAX_EVENT_NAME_LENGTH];
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
    int duration;
};

int compare_events(const void *a, const void *b) {
    const struct Event *event1 = a;
    const struct Event *event2 = b;

    if (event1->start_hour < event2->start_hour) {
        return -1;
    } else if (event1->start_hour > event2->start_hour) {
        return 1;
    } else if (event1->start_minute < event2->start_minute) {
        return -1;
    } else if (event1->start_minute > event2->start_minute) {
        return 1;
    } else {
        return 0;
    }
}

void print_event(const struct Event *event) {
    printf("%s (%d-%d-%d %d:%d-%d:%d)\n", event->name, event->start_hour, event->start_minute, event->end_hour, event->start_hour, event->start_minute, event->end_hour, event->end_minute);
}

int main() {
    int num_events;
    struct Event events[MAX_EVENTS];

    printf("Enter the number of events (up to %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    for (int i = 0; i < num_events; i++) {
        printf("Enter the name of event %d: ", i + 1);
        scanf("%s", events[i].name);

        printf("Enter the start time (HH:MM): ");
        scanf("%d:%d", &events[i].start_hour, &events[i].start_minute);

        printf("Enter the end time (HH:MM): ");
        scanf("%d:%d", &events[i].end_hour, &events[i].end_minute);

        events[i].duration = (events[i].end_hour * 60 + events[i].end_minute) - (events[i].start_hour * 60 + events[i].start_minute);
    }

    qsort(events, num_events, sizeof(struct Event), compare_events);

    for (int i = 0; i < num_events; i++) {
        print_event(&events[i]);
    }

    return 0;
}