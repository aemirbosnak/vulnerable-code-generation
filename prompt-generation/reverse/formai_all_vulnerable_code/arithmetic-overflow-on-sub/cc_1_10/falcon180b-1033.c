//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIMESTAMPS 100

typedef struct event {
    char *description;
    time_t timestamp;
    struct event *next;
} Event;

typedef struct {
    Event *head;
    int count;
} Timeline;

void add_event(Timeline *timeline, char *description, time_t timestamp) {
    Event *event = (Event *) malloc(sizeof(Event));
    event->description = description;
    event->timestamp = timestamp;
    event->next = NULL;

    if (timeline->head == NULL) {
        timeline->head = event;
    } else {
        Event *last_event = timeline->head;
        while (last_event->next!= NULL) {
            last_event = last_event->next;
        }
        last_event->next = event;
    }

    timeline->count++;
}

void print_timeline(Timeline *timeline) {
    Event *event = timeline->head;
    while (event!= NULL) {
        printf("%s (%ld)\n", event->description, event->timestamp);
        event = event->next;
    }
}

void time_travel(Timeline *timeline, time_t target_timestamp) {
    time_t current_timestamp = time(NULL);

    if (current_timestamp < target_timestamp) {
        printf("Traveling through time...\n");
        sleep(target_timestamp - current_timestamp);
    } else {
        printf("You are already in the future.\n");
    }

    print_timeline(timeline);
}

int main() {
    Timeline timeline;
    timeline.head = NULL;
    timeline.count = 0;

    add_event(&timeline, "You are born", 0);
    add_event(&timeline, "You start school", 6 * 365 * 24 * 60 * 60);
    add_event(&timeline, "You graduate from college", 22 * 365 * 24 * 60 * 60);
    add_event(&timeline, "You get your first job", 25 * 365 * 24 * 60 * 60);
    add_event(&timeline, "You retire", 65 * 365 * 24 * 60 * 60);

    printf("Your timeline:\n");
    print_timeline(&timeline);

    time_travel(&timeline, 18 * 365 * 24 * 60 * 60);

    return 0;
}