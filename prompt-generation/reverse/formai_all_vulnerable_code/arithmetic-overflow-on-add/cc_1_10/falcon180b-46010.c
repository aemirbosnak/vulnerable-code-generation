//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_NAME_LEN 100
#define MAX_DESCRIPTION_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    time_t start_time;
    time_t end_time;
} Event;

void add_event(Event *events, int num_events, char *name, char *description, time_t start_time, time_t end_time) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events.\n");
        return;
    }

    strncpy(events[num_events].name, name, MAX_NAME_LEN);
    strncpy(events[num_events].description, description, MAX_DESCRIPTION_LEN);
    events[num_events].start_time = start_time;
    events[num_events].end_time = end_time;

    num_events++;
}

void print_event(Event event) {
    printf("Name: %s\n", event.name);
    printf("Description: %s\n", event.description);
    printf("Start time: %s\n", ctime(&event.start_time));
    printf("End time: %s\n", ctime(&event.end_time));
}

void sort_events(Event events[], int num_events) {
    for (int i = 0; i < num_events - 1; i++) {
        for (int j = i + 1; j < num_events; j++) {
            if (events[i].start_time > events[j].start_time) {
                Event temp = events[i];
                events[i] = events[j];
                events[j] = temp;
            }
        }
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, num_events, "Meeting", "Discuss project progress", time(NULL), time(NULL) + 60*60);
    add_event(events, num_events, "Lunch", "Grab a bite to eat", time(NULL) + 60*60, time(NULL) + 60*60*2);
    add_event(events, num_events, "Deadline", "Submit final report", time(NULL) + 60*60*6, time(NULL) + 60*60*7);

    printf("Unsorted events:\n");
    for (int i = 0; i < num_events; i++) {
        print_event(events[i]);
    }

    sort_events(events, num_events);

    printf("\nSorted events:\n");
    for (int i = 0; i < num_events; i++) {
        print_event(events[i]);
    }

    return 0;
}