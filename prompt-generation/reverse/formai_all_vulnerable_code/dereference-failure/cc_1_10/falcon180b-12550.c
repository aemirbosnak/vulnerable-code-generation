//Falcon-180B DATASET v1.0 Category: System event logger ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100

struct event {
    char *message;
    time_t timestamp;
};

void add_event(struct event *events, int *num_events, char *message) {
    if (*num_events >= MAX_EVENTS) {
        printf("Event log is full.\n");
        return;
    }

    struct event *new_event = realloc(events, sizeof(struct event) * (*num_events + 1));
    if (new_event == NULL) {
        printf("Failed to allocate memory for new event.\n");
        return;
    }

    events = new_event;

    strncpy(events[*num_events].message, message, MAX_EVENT_LENGTH);
    events[*num_events].timestamp = time(NULL);

    (*num_events)++;
}

void print_events(struct event *events, int num_events) {
    printf("Event log:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", events[i].message, ctime(&events[i].timestamp));
    }
}

void *log_events(void *arg) {
    struct event *events = arg;
    int num_events = 0;

    while (1) {
        sleep(1);

        add_event(events, &num_events, "Test event");
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    struct event events[MAX_EVENTS];
    int num_events = 0;

    pthread_create(&thread_id, NULL, log_events, events);

    while (1) {
        print_events(events, num_events);

        if (num_events >= MAX_EVENTS) {
            break;
        }

        sleep(1);
    }

    pthread_join(thread_id, NULL);

    return 0;
}