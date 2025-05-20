//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

struct event {
    time_t time;
    char *description;
};

int compare_events(const void *a, const void *b) {
    struct event *event_a = (struct event *)a;
    struct event *event_b = (struct event *)b;

    if (event_a->time < event_b->time) {
        return -1;
    } else if (event_a->time > event_b->time) {
        return 1;
    } else {
        return 0;
    }
}

void print_events(struct event events[], int num_events) {
    qsort(events, num_events, sizeof(struct event), compare_events);

    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

int main() {
    char input[100];
    struct event events[MAX_EVENTS];
    int num_events = 0;

    while (1) {
        printf("Enter an event (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        time_t event_time;
        if (strcmp(input, "now") == 0) {
            event_time = time(NULL);
        } else {
            struct tm tm;
            strptime(input, "%Y-%m-%d %H:%M:%S", &tm);
            event_time = mktime(&tm);
        }

        if (num_events >= MAX_EVENTS) {
            printf("Maximum number of events reached.\n");
        } else {
            events[num_events].time = event_time;
            printf("Enter a description for the event: ");
            scanf("%s", events[num_events].description);
            num_events++;
        }
    }

    print_events(events, num_events);

    return 0;
}