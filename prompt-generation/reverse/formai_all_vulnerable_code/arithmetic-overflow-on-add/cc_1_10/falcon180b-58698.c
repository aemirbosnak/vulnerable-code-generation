//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_EVENTS 100
#define MAX_STRING_LEN 100

typedef struct {
    char event[MAX_STRING_LEN];
    time_t timestamp;
    struct event_t *next;
} event_t;

event_t *event_list = NULL;

void add_event(char *event, time_t timestamp) {
    event_t *new_event = (event_t*)malloc(sizeof(event_t));
    strncpy(new_event->event, event, MAX_STRING_LEN);
    new_event->timestamp = timestamp;
    new_event->next = NULL;

    if (event_list == NULL) {
        event_list = new_event;
    } else {
        event_t *current_event = event_list;
        while (current_event->next!= NULL) {
            current_event = current_event->next;
        }
        current_event->next = new_event;
    }
}

void print_events() {
    event_t *current_event = event_list;
    while (current_event!= NULL) {
        printf("%s @ %s\n", current_event->event, ctime(&current_event->timestamp));
        current_event = current_event->next;
    }
}

void time_travel(time_t timestamp) {
    event_t *current_event = event_list;
    while (current_event!= NULL) {
        if (current_event->timestamp == timestamp) {
            printf("You have arrived at the event: %s\n", current_event->event);
            break;
        }
        current_event = current_event->next;
    }
}

int main() {
    srand(time(NULL));
    int num_events = rand() % MAX_EVENTS + 1;
    for (int i = 0; i < num_events; i++) {
        char event_name[MAX_STRING_LEN];
        sprintf(event_name, "Event %d", i + 1);
        time_t event_timestamp = rand() % (time(NULL) - 86400) + time(NULL) - 86400;
        add_event(event_name, event_timestamp);
        printf("Event %d added: %s @ %s\n", i + 1, event_name, ctime(&event_timestamp));
    }

    printf("Press enter to time travel...\n");
    getchar();

    time_t current_time = time(NULL);
    while (current_time < event_list->timestamp) {
        current_time += 86400;
    }

    time_travel(current_time);

    return 0;
}