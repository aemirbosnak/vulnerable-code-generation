//Falcon-180B DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define EVENT_SIZE 100

typedef struct {
    char event[EVENT_SIZE];
    time_t timestamp;
} Event;

void log_event(const char* event) {
    Event* new_event = malloc(sizeof(Event));
    strncpy(new_event->event, event, EVENT_SIZE);
    new_event->timestamp = time(NULL);
    printf("Logged event: %s\n", new_event->event);
}

void display_events() {
    FILE* events_file = fopen("events.log", "r");
    if (events_file == NULL) {
        printf("No events found.\n");
        return;
    }

    Event events[MAX_EVENTS];
    int num_events = 0;

    while (fscanf(events_file, "%s %ld\n", events[num_events].event, &events[num_events].timestamp)!= EOF) {
        num_events++;
    }

    fclose(events_file);

    printf("Displaying %d events:\n", num_events);
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", events[i].event, ctime(&events[i].timestamp));
    }
}

int main() {
    log_event("Program started");
    sleep(1);
    log_event("Something happened");
    sleep(2);
    log_event("Program ended");

    display_events();

    return 0;
}