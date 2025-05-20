//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_TEXT_LENGTH 80
#define MAX_TIME_TRAVEL 10

typedef struct event {
    time_t time;
    char text[MAX_EVENT_TEXT_LENGTH];
} Event;

int num_events = 0;
Event events[MAX_EVENTS];

void add_event(time_t time, char* text) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: maximum number of events reached.\n");
        return;
    }
    events[num_events].time = time;
    strcpy(events[num_events].text, text);
    num_events++;
}

void time_travel(int num_jumps, time_t* jump_times) {
    if (num_jumps > MAX_TIME_TRAVEL) {
        printf("Error: maximum number of time jumps reached.\n");
        return;
    }
    for (int i = 0; i < num_jumps; i++) {
        time_t current_time = time(NULL);
        time_t jump_time = jump_times[i];
        if (jump_time < current_time) {
            printf("Error: cannot travel back in time.\n");
            return;
        }
        while (current_time < jump_time) {
            current_time = time(NULL);
        }
        for (int j = 0; j < num_events; j++) {
            if (events[j].time == current_time) {
                printf("%s\n", events[j].text);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    add_event(time(NULL) + rand() % 3600, "Hello, world!");
    add_event(time(NULL) + rand() % 3600, "How are you?");
    add_event(time(NULL) + rand() % 3600, "Goodbye!");
    time_t jump_times[3] = {time(NULL) + 60, time(NULL) + 120, time(NULL) + 180};
    time_travel(3, jump_times);
    return 0;
}