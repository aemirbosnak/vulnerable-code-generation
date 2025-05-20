//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char* message;
} Event;

void add_event(Event* events, int num_events, time_t time, char* message) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events!\n");
        exit(1);
    }
    events[num_events].time = time;
    events[num_events].message = message;
    num_events++;
}

void print_events(Event* events, int num_events) {
    for (int i = 0; i < num_events; i++) {
        printf("%s (%ld)\n", events[i].message, events[i].time);
    }
}

int main() {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, num_events, time(NULL) + rand() % 100, "You start your journey through time!");
    add_event(events, num_events, time(NULL) + rand() % 100, "You arrive in the year 2050!");
    add_event(events, num_events, time(NULL) + rand() % 100, "You witness flying cars and robots everywhere!");
    add_event(events, num_events, time(NULL) + rand() % 100, "You travel back to the present day.");

    printf("Get ready for a journey through time!\n");

    for (int i = 0; i < num_events; i++) {
        time_t event_time = events[i].time;
        while (difftime(event_time, time(NULL)) > 0) {
            printf("Time traveling...\n");
            sleep(1);
        }
        printf("%s\n", events[i].message);
    }

    return 0;
}