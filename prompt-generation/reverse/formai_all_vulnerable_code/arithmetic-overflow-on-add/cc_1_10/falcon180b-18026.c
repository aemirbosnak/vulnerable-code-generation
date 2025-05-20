//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

struct event {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char *description;
};

void add_event(struct event *events, int num_events, int year, int month, int day, int hour, int minute, int second, char *description) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }

    struct event *new_event = (struct event *) malloc(sizeof(struct event));
    if (new_event == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    new_event->year = year;
    new_event->month = month;
    new_event->day = day;
    new_event->hour = hour;
    new_event->minute = minute;
    new_event->second = second;
    new_event->description = description;

    events[num_events] = *new_event;
    num_events++;
}

void print_events(struct event *events, int num_events) {
    printf("Events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%d-%02d-%02d %02d:%02d:%02d %s\n", events[i].year, events[i].month, events[i].day, events[i].hour, events[i].minute, events[i].second, events[i].description);
    }
}

void time_travel(struct event *events, int num_events, time_t start_time, time_t end_time) {
    time_t current_time = start_time;

    while (current_time <= end_time) {
        int year, month, day, hour, minute, second;
        struct tm *tm = localtime(&current_time);
        year = tm->tm_year + 1900;
        month = tm->tm_mon + 1;
        day = tm->tm_mday;
        hour = tm->tm_hour;
        minute = tm->tm_min;
        second = tm->tm_sec;

        for (int i = 0; i < num_events; i++) {
            if (year == events[i].year && month == events[i].month && day == events[i].day && hour == events[i].hour && minute == events[i].minute && second == events[i].second) {
                printf("%s\n", events[i].description);
            }
        }

        current_time += 60; // Travel one second at a time
    }
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;

    add_event(events, num_events, 2022, 10, 21, 16, 29, 0, "Back to the Future Day");
    add_event(events, num_events, 2065, 7, 20, 9, 0, 0, "First manned mission to Mars");

    print_events(events, num_events);

    time_t start_time = time(NULL);
    time_t end_time = start_time + 60 * 60 * 24 * 365 * 10; // Travel 10 years into the future

    time_travel(events, num_events, start_time, end_time);

    return 0;
}