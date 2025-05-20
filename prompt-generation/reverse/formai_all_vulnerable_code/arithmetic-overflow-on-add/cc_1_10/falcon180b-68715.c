//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 80

typedef struct {
    time_t time;
    char message[MAX_EVENT_LENGTH];
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void add_event(time_t time, char* message) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events.\n");
        return;
    }

    events[num_events].time = time;
    strncpy(events[num_events].message, message, MAX_EVENT_LENGTH);
    num_events++;
}

int main() {
    srand(time(NULL));

    add_event(time(NULL) + 5, "Hello, world!");
    add_event(time(NULL) + 10, "How are you?");

    while (1) {
        time_t current_time = time(NULL);

        for (int i = 0; i < num_events; i++) {
            if (events[i].time <= current_time) {
                printf("%s\n", events[i].message);
                memmove(&events[i], &events[i+1], sizeof(event_t) * (num_events - i - 1));
                num_events--;
                i--;
            }
        }

        time_t next_event_time = events[0].time;
        if (next_event_time > current_time) {
            time_t sleep_time = next_event_time - current_time;
            printf("Sleeping for %ld seconds...\n", sleep_time);
            sleep(sleep_time);
        }
    }

    return 0;
}