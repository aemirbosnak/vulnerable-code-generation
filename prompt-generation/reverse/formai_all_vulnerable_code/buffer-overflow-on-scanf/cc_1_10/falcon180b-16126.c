//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time travel events
#define MAX_EVENTS 100

// Define the structure for a time travel event
struct event {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Function to compare two time travel events
int compare_events(const void *a, const void *b) {
    const struct event *event_a = a;
    const struct event *event_b = b;
    return difftime(mktime(event_a), mktime(event_b));
}

// Function to print a time travel event
void print_event(const struct event *event) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
           event->year, event->month, event->day, event->hour, event->minute, event->second);
}

// Function to time travel
void time_travel(int num_events, struct event *events) {
    qsort(events, num_events, sizeof(struct event), compare_events);

    for (int i = 0; i < num_events; ++i) {
        struct event event = events[i];
        printf("Time traveling to ");
        print_event(&event);
        sleep(1);
    }
}

int main() {
    int num_events;
    printf("Enter the number of time travel events (1 to %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    struct event events[num_events];
    printf("Enter the time travel events (YYYY-MM-DD HH:MM:SS):\n");
    for (int i = 0; i < num_events; ++i) {
        scanf("%d-%d-%d %d:%d:%d", &events[i].year, &events[i].month, &events[i].day, &events[i].hour, &events[i].minute, &events[i].second);
    }

    time_travel(num_events, events);

    return 0;
}