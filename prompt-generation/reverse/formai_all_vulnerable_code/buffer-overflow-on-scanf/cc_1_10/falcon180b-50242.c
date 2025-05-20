//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME_TRAVEL 10

struct event {
    int time;
    int type;
};

void travel_back_in_time(int time) {
    printf("Traveling back in time to %d...\n", time);
}

void travel_forward_in_time(int time) {
    printf("Traveling forward in time to %d...\n", time);
}

void add_event(struct event *events, int num_events, int time, int type) {
    if (num_events >= MAX_EVENTS) {
        printf("Cannot add more events. Maximum limit reached.\n");
        return;
    }

    events[num_events].time = time;
    events[num_events].type = type;
    num_events++;
}

void print_events(struct event *events, int num_events) {
    printf("Events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%d: Type - %d\n", events[i].time, events[i].type);
    }
}

int main() {
    srand(time(NULL));

    int num_events = 0;
    struct event events[MAX_EVENTS];

    add_event(events, num_events, 2022, 1);
    add_event(events, num_events, 2050, 2);
    add_event(events, num_events, 3000, 3);

    print_events(events, num_events);

    int choice;
    printf("Enter your choice:\n1. Travel back in time\n2. Travel forward in time\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the year you want to travel back to: ");
            int year = rand() % 2022 + 1;
            travel_back_in_time(year);
            break;
        case 2:
            printf("Enter the year you want to travel forward to: ");
            int future_year = rand() % 3000 + 1;
            travel_forward_in_time(future_year);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}