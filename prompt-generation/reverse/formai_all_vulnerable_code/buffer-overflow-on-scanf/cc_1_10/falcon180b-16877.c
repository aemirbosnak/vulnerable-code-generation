//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EVENTS 1000
#define MAX_EVENTS_PER_SECOND 100
#define EVENT_WINDOW_SIZE 10

typedef struct {
    char ip[16];
    char event;
    int timestamp;
} Event;

Event events[MAX_EVENTS];
int event_index = 0;

void process_event(char *ip, char event) {
    events[event_index].ip[0] = '\0';
    strcat(events[event_index].ip, ip);
    events[event_index].event = event;
    events[event_index].timestamp = time(NULL);
    event_index++;
    if (event_index >= MAX_EVENTS) {
        event_index = 0;
    }
}

void detect_intrusion() {
    int count = 0;
    int start_index = event_index - EVENT_WINDOW_SIZE;
    if (start_index < 0) {
        start_index += MAX_EVENTS;
    }
    for (int i = start_index; i < event_index; i++) {
        if (events[i].event == 'A') {
            count++;
        }
    }
    if (count >= MAX_EVENTS_PER_SECOND) {
        printf("Possible intrusion detected!\n");
    }
}

int main() {
    setbuf(stdout, NULL);

    while (true) {
        char ip[16];
        char event;
        scanf("%s %c", ip, &event);
        process_event(ip, event);
        detect_intrusion();
    }

    return 0;
}