//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 50

struct event {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_event(struct event *event) {
    printf("Event: %s\n", event->name);
    printf("Start Time: %s\n", ctime(&event->start_time));
    printf("End Time: %s\n\n", ctime(&event->end_time));
}

void print_calendar(struct event calendar[], int num_events, time_t current_time) {
    printf("Calendar:\n");
    for (int i = 0; i < num_events; i++) {
        if (calendar[i].start_time <= current_time && calendar[i].end_time >= current_time) {
            print_event(&calendar[i]);
        }
    }
}

int main() {
    struct event calendar[MAX_EVENTS];
    int num_events = 0;

    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);

    printf("Current Date and Time: %s\n", asctime(current_tm));

    while (num_events < MAX_EVENTS) {
        printf("Enter event name (or press enter to finish): ");
        scanf("%s", calendar[num_events].name);

        if (strcmp(calendar[num_events].name, "") == 0) {
            break;
        }

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", calendar[num_events].name);
        strcat(calendar[num_events].name, " ");
        strcat(calendar[num_events].name, "00:00:00");
        calendar[num_events].start_time = mktime(current_tm) + atoi(calendar[num_events].name);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", calendar[num_events].name);
        strcat(calendar[num_events].name, " ");
        strcat(calendar[num_events].name, "23:59:59");
        calendar[num_events].end_time = mktime(current_tm) + atoi(calendar[num_events].name);

        num_events++;
    }

    printf("Calendar:\n");
    print_calendar(calendar, num_events, current_time);

    return 0;
}