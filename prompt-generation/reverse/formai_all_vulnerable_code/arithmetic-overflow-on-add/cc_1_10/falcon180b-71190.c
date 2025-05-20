//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_HISTORY 100
#define MAX_EVENTS 1000

struct event {
    time_t timestamp;
    char *description;
};

struct history {
    int num_events;
    struct event events[MAX_EVENTS];
};

void add_event(struct history *history, char *description) {
    if (history->num_events >= MAX_EVENTS) {
        printf("ERROR: Event buffer full.\n");
        return;
    }

    time_t timestamp = time(NULL);
    struct event event = {timestamp, description};
    history->events[history->num_events++] = event;
}

void print_history(struct history *history) {
    printf("Timeline:\n");
    for (int i = 0; i < history->num_events; i++) {
        struct event event = history->events[i];
        printf("%s (%ld)\n", event.description, event.timestamp);
    }
}

int main() {
    srand(time(NULL));

    struct history history = {0};

    add_event(&history, "You are born.");
    add_event(&history, "You learn to walk.");
    add_event(&history, "You start school.");
    add_event(&history, "You graduate high school.");
    add_event(&history, "You go to college.");
    add_event(&history, "You get your first job.");
    add_event(&history, "You meet your significant other.");
    add_event(&history, "You get married.");
    add_event(&history, "You have children.");
    add_event(&history, "You retire.");

    int num_changes = rand() % 5 + 1;

    for (int i = 0; i < num_changes; i++) {
        int event_index = rand() % history.num_events;
        struct event *event = &history.events[event_index];

        time_t new_timestamp = event->timestamp + rand() % (time(NULL) - event->timestamp);
        char *new_description = malloc(strlen(event->description) + 20);
        sprintf(new_description, "%s (Changed: %ld)", event->description, new_timestamp);

        free(event->description);
        event->description = new_description;
        event->timestamp = new_timestamp;
    }

    print_history(&history);

    return 0;
}