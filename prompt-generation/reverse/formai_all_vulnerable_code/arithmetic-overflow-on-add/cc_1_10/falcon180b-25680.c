//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
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

void time_travel(time_t target_time) {
    struct tm* target_tm = localtime(&target_time);
    printf("Time traveling to %s...", asctime(target_tm));

    for (int i = 0; i < num_events; i++) {
        if (events[i].time > target_time) {
            printf("\nEvent at %s: %s\n", asctime(localtime(&events[i].time)), events[i].message);
        }
    }
}

int main() {
    srand(time(NULL));

    add_event(time(NULL) + rand() % 3600, "You arrive in the future!");
    add_event(time(NULL) - rand() % 3600, "You travel back in time!");

    while (1) {
        printf("\nEnter a time to travel to (or 0 to quit): ");
        time_t target_time;
        scanf("%ld", &target_time);

        if (target_time == 0) {
            break;
        }

        time_travel(target_time);
    }

    return 0;
}