//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FITNESS_EVENTS 100

struct fitness_event {
    char *name;
    time_t start_time;
    time_t end_time;
    int duration;
};

void add_fitness_event(struct fitness_event *events, int num_events, char *name) {
    if (num_events >= MAX_FITNESS_EVENTS) {
        printf("Error: Maximum number of fitness events reached.\n");
        return;
    }

    struct fitness_event new_event;
    strcpy(new_event.name, name);
    time(&new_event.start_time);
    new_event.duration = 0;

    events[num_events] = new_event;
    num_events++;
}

void end_fitness_event(struct fitness_event *events, int num_events, char *name) {
    int i;
    for (i = 0; i < num_events; i++) {
        if (strcmp(events[i].name, name) == 0) {
            time(&events[i].end_time);
            events[i].duration = difftime(events[i].end_time, events[i].start_time);
            break;
        }
    }
}

void print_fitness_events(struct fitness_event *events, int num_events) {
    printf("Fitness events:\n");
    printf("Name\tStart Time\tEnd Time\tDuration\n");

    int i;
    for (i = 0; i < num_events; i++) {
        printf("%s\t%s\t%s\t%d seconds\n", events[i].name, ctime(&events[i].start_time), ctime(&events[i].end_time), events[i].duration);
    }
}

int main() {
    struct fitness_event events[MAX_FITNESS_EVENTS];
    int num_events = 0;

    add_fitness_event(events, num_events, "Jogging");
    add_fitness_event(events, num_events, "Swimming");

    end_fitness_event(events, num_events, "Jogging");
    end_fitness_event(events, num_events, "Swimming");

    print_fitness_events(events, num_events);

    return 0;
}