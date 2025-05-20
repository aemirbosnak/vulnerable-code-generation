//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

struct event {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    time_t start_time;
    time_t end_time;
};

void add_event(struct event *events, int *num_events, char *name, char *description, time_t start_time, time_t end_time) {
    if (*num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    strncpy(events[*num_events].name, name, MAX_NAME_LEN);
    strncpy(events[*num_events].description, description, MAX_DESCRIPTION_LEN);
    events[*num_events].start_time = start_time;
    events[*num_events].end_time = end_time;

    (*num_events)++;
}

void print_event(struct event event) {
    printf("Name: %s\n", event.name);
    printf("Description: %s\n", event.description);
    printf("Start time: %s\n", ctime(&event.start_time));
    printf("End time: %s\n", ctime(&event.end_time));
    printf("\n");
}

void print_schedule(struct event events[], int num_events) {
    printf("Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        print_event(events[i]);
    }
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, &num_events, "Meeting", "Discuss project progress", time(NULL) + (60 * 60 * 2), time(NULL) + (60 * 60 * 3));
    add_event(events, &num_events, "Lunch", "Grab a bite to eat", time(NULL) + (60 * 60 * 5), time(NULL) + (60 * 60 * 6));
    add_event(events, &num_events, "Deadline", "Submit report", time(NULL) + (60 * 60 * 8), time(NULL) + (60 * 60 * 9));

    print_schedule(events, num_events);

    return 0;
}