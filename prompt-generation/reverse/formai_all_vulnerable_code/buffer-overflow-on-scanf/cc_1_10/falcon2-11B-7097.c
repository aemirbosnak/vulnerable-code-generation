//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct event_data {
    char event_name[50];
    struct timeval time;
} event_data_t;

event_data_t event_data[MAX_EVENTS];
int num_events = 0;

void add_event(char* event_name, struct timeval time) {
    event_data_t new_event;
    strcpy(new_event.event_name, event_name);
    new_event.time = time;
    if (num_events < MAX_EVENTS) {
        event_data[num_events] = new_event;
        num_events++;
    } else {
        fprintf(stderr, "Too many events. Maximum number reached.");
    }
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        struct timeval now = {0};
        gettimeofday(&now, NULL);
        int time_diff = (now.tv_sec - event_data[i].time.tv_sec) * 1000000 + now.tv_usec - event_data[i].time.tv_usec;
        printf("%s - %ld.%06ld\n", event_data[i].event_name, event_data[i].time.tv_sec, event_data[i].time.tv_usec);
        if (time_diff > 0) {
            printf("Elapsed time: %ld.%06ld seconds\n", time_diff / 1000000, time_diff % 1000000);
        }
    }
}

int main() {
    char event_name[50];
    struct timeval time;
    printf("Enter an event name (or 'q' to quit): ");
    while (scanf("%s", event_name)!= EOF) {
        gettimeofday(&time, NULL);
        add_event(event_name, time);
        printf("Event added.\n");
        if (strcmp(event_name, "q") == 0) {
            break;
        }
    }
    print_events();
    return 0;
}