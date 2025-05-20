//Falcon-180B DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 100

struct event {
    time_t timestamp;
    char *description;
};

int event_count = 0;
struct event events[MAX_EVENTS];

void log_event(char *description) {
    time_t timestamp = time(NULL);
    events[event_count].timestamp = timestamp;
    events[event_count].description = strdup(description);
    event_count++;
}

void print_events() {
    for (int i = 0; i < event_count; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

void *event_logger(void *arg) {
    while (1) {
        log_event("Event logger is running.");
        sleep(5);
    }
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, event_logger, NULL);

    while (1) {
        printf("Enter 'p' to print events or 'q' to quit: ");
        char input[2];
        scanf("%s", input);
        if (input[0] == 'p') {
            print_events();
        } else if (input[0] == 'q') {
            break;
        }
    }

    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);

    return 0;
}