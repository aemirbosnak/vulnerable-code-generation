//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 10

struct event {
    char name[50];
    int start_time;
    int end_time;
};

struct event events[MAX_EVENTS];
int num_events = 0;

void add_event(char* name, int start_time, int end_time) {
    struct event new_event;
    strcpy(new_event.name, name);
    new_event.start_time = start_time;
    new_event.end_time = end_time;

    events[num_events] = new_event;
    num_events++;
}

void display_events() {
    printf("\n\n-----------------------\n");
    printf("Medieval Appointment Scheduler\n");
    printf("-----------------------\n");
    printf("Event Name\t\tStart Time\tEnd Time\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s\t\t%d\t\t%d\n", events[i].name, events[i].start_time, events[i].end_time);
    }
    printf("-----------------------\n");
}

void delete_event(int index) {
    for (int i = index; i < num_events; i++) {
        events[i - 1] = events[i];
    }
    num_events--;
}

void main() {
    int num_entries = 0;
    while (1) {
        printf("\n\n-----------------------\n");
        printf("Medieval Appointment Scheduler\n");
        printf("-----------------------\n");
        printf("1. Add Event\n");
        printf("2. Delete Event\n");
        printf("3. Display Events\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &num_entries);

        switch (num_entries) {
            case 1:
                printf("Enter event name: ");
                scanf("%s", events[num_events].name);
                printf("Enter start time (24-hour format): ");
                scanf("%d", &events[num_events].start_time);
                printf("Enter end time (24-hour format): ");
                scanf("%d", &events[num_events].end_time);
                add_event(events[num_events].name, events[num_events].start_time, events[num_events].end_time);
                break;
            case 2:
                printf("Enter index of event to delete: ");
                scanf("%d", &num_entries);
                delete_event(num_entries);
                break;
            case 3:
                display_events();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}