//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENTS_PER_DAY 10

struct event {
    char name[50];
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
    int day;
};

void add_event(struct event events[], int num_events) {
    printf("Enter event name: ");
    scanf("%s", events[num_events].name);

    printf("Enter start time in 24-hour format (HH:MM): ");
    scanf("%d:%d", &events[num_events].start_hour, &events[num_events].start_min);

    printf("Enter end time in 24-hour format (HH:MM): ");
    scanf("%d:%d", &events[num_events].end_hour, &events[num_events].end_min);

    printf("Enter day of week (0-6, Sunday to Saturday): ");
    scanf("%d", &events[num_events].day);

    num_events++;
}

void print_events(struct event events[], int num_events) {
    printf("\nSchedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s: ", events[i].name);
        printf("%02d:%02d - %02d:%02d on ", events[i].start_hour, events[i].start_min, events[i].end_hour, events[i].end_min);
        switch (events[i].day) {
            case 0:
                printf("Sunday");
                break;
            case 1:
                printf("Monday");
                break;
            case 2:
                printf("Tuesday");
                break;
            case 3:
                printf("Wednesday");
                break;
            case 4:
                printf("Thursday");
                break;
            case 5:
                printf("Friday");
                break;
            case 6:
                printf("Saturday");
                break;
            default:
                printf("Invalid day");
                break;
        }
        printf("\n");
    }
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;

    printf("Welcome to the Appointment Scheduler!\n");

    while (num_events < MAX_EVENTS) {
        add_event(events, num_events);
        if (num_events == MAX_EVENTS - 1) {
            printf("You've reached the maximum number of events. Do you want to continue? (y/n) ");
            char choice;
            scanf("%c", &choice);
            if (choice == 'n' || choice == 'N') {
                break;
            }
        }
    }

    printf("\nYour schedule:\n");
    print_events(events, num_events);

    return 0;
}