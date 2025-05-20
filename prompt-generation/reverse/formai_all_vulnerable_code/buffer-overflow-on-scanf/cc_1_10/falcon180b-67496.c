//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EVENTS 50
#define EVENT_NAME_LEN 50
#define EVENT_DATE_LEN 20

typedef struct {
    char name[EVENT_NAME_LEN];
    char date[EVENT_DATE_LEN];
    int month;
    int day;
    int year;
    int hour;
    int minute;
    int am_pm;
    int duration;
} Event;

void add_event(Event* event, int num_events) {
    printf("Enter event name: ");
    scanf("%s", event->name);

    printf("Enter event date (MM/DD/YYYY HH:MM AM/PM): ");
    scanf("%s", event->date);

    event->month = atoi(event->date) / 100;
    event->day = atoi(event->date) % 100;
    event->year = 0;
    event->hour = 0;
    event->minute = 0;
    event->am_pm = 0;
    event->duration = 0;

    printf("Enter event date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &event->month, &event->day, &event->year);

    printf("Enter event time (HH:MM AM/PM): ");
    scanf("%d:%d %c", &event->hour, &event->minute, &event->am_pm);

    if (event->am_pm == 'p' || event->am_pm == 'P') {
        event->hour += 12;
    }

    event->duration = 60 * (event->hour * 60 + event->minute);

    printf("Event added successfully!\n");
    num_events++;
}

void display_events(Event* events, int num_events) {
    printf("Event schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s on %d/%d/%d at %d:%d %c for %d minutes\n", events[i].name, events[i].month, events[i].day, events[i].year, events[i].hour, events[i].minute, events[i].am_pm, events[i].duration);
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    while (num_events < MAX_EVENTS) {
        printf("1. Add event\n2. Display events\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_event(events, num_events);
                break;
            case 2:
                display_events(events, num_events);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}