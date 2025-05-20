//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME_TRAVELS 10

typedef struct {
    time_t time;
    int event_index;
} TimeTravelEvent;

typedef struct {
    char *description;
    time_t time;
} Event;

void add_event(Event *events, int *event_count, char *description, time_t time) {
    events[*event_count] = (Event) {
       .description = description,
       .time = time,
    };
    (*event_count)++;
}

int main() {
    Event events[MAX_EVENTS];
    int event_count = 0;

    add_event(events, &event_count, "You are born.", 0);
    add_event(events, &event_count, "You start school.", 5 * 365 * 24 * 60 * 60);
    add_event(events, &event_count, "You graduate high school.", 13 * 365 * 24 * 60 * 60);
    add_event(events, &event_count, "You start college.", 17 * 365 * 24 * 60 * 60);
    add_event(events, &event_count, "You get your first job.", 22 * 365 * 24 * 60 * 60);

    int num_time_travels;
    printf("How many times do you want to time travel? ");
    scanf("%d", &num_time_travels);

    TimeTravelEvent time_travel_events[MAX_TIME_TRAVELS];
    int time_travel_event_count = 0;

    for (int i = 0; i < num_time_travels; i++) {
        printf("Enter the time you want to travel to (in seconds since January 1, 1970): ");
        time_t time;
        scanf("%ld", &time);

        for (int j = 0; j < event_count; j++) {
            if (time >= events[j].time) {
                time_travel_events[time_travel_event_count] = (TimeTravelEvent) {
                   .time = time,
                   .event_index = j,
                };
                time_travel_event_count++;
                break;
            }
        }
    }

    printf("Your life events:\n");
    for (int i = 0; i < event_count; i++) {
        printf("%s\n", events[i].description);
    }

    printf("\nYour time travel events:\n");
    for (int i = 0; i < time_travel_event_count; i++) {
        int event_index = time_travel_events[i].event_index;
        printf("You time travel to %s.\n", events[event_index].description);
    }

    return 0;
}