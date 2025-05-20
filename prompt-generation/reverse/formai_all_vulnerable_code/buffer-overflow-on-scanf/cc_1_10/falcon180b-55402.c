//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start_time;
    int end_time;
} Event;

void schedule_event(Event* events, int num_events) {
    int start_time, end_time;
    printf("Enter start time for event (24-hour format): ");
    scanf("%d", &start_time);
    printf("Enter end time for event (24-hour format): ");
    scanf("%d", &end_time);

    for (int i = 0; i < num_events; i++) {
        if (events[i].start_time > start_time || events[i].end_time < end_time) {
            printf("Event can be scheduled at %s.\n", events[i].name);
            return;
        }
    }

    printf("No available time slots.\n");
}

void print_events(Event* events, int num_events) {
    printf("Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s: %d - %d\n", events[i].name, events[i].start_time, events[i].end_time);
    }
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Welcome to the Appointment Scheduler!\n");

    while (num_events < MAX_EVENTS) {
        printf("Choose an option:\n");
        printf("1. Schedule an event\n");
        printf("2. Print schedule\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter name for event (max %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", events[num_events].name);
            printf("Enter start time for event (24-hour format): ");
            scanf("%d", &events[num_events].start_time);
            printf("Enter end time for event (24-hour format): ");
            scanf("%d", &events[num_events].end_time);
            num_events++;
        } else if (choice == 2) {
            print_events(events, num_events);
        } else if (choice == 3) {
            printf("Thank you for using the Appointment Scheduler!\n");
            return 0;
        }
    }

    printf("Schedule is full.\n");

    return 0;
}