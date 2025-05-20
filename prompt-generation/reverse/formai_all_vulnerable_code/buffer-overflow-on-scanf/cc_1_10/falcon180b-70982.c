//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_TIME 1000000000 // 1 billion seconds

typedef struct {
    time_t time;
    int type;
    int data;
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void add_event(time_t time, int type, int data) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        exit(1);
    }

    events[num_events].time = time;
    events[num_events].type = type;
    events[num_events].data = data;
    num_events++;
}

int main() {
    int choice;
    time_t current_time = time(NULL);

    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Current time: %s\n", ctime(&current_time));
        printf("1. Add event\n");
        printf("2. Travel back in time\n");
        printf("3. Travel forward in time\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the type of event (1 = past, 2 = future): ");
            int event_type;
            scanf("%d", &event_type);

            printf("Enter the time of the event (in seconds since epoch): ");
            time_t event_time;
            scanf("%ld", &event_time);

            add_event(event_time, event_type, 0);
            break;

        case 2:
            if (num_events == 0) {
                printf("No past events to travel to.\n");
            } else {
                int event_index;
                printf("Enter the index of the past event to travel to: ");
                scanf("%d", &event_index);

                if (event_index >= 0 && event_index < num_events) {
                    time_t event_time = events[event_index].time;
                    int event_type = events[event_index].type;

                    if (event_type == 1) {
                        printf("Traveling back in time to %s...\n", ctime(&event_time));
                        current_time = event_time;
                    } else {
                        printf("Error: Invalid event type.\n");
                    }
                } else {
                    printf("Invalid event index.\n");
                }
            }
            break;

        case 3:
            if (num_events == 0) {
                printf("No future events to travel to.\n");
            } else {
                int event_index;
                printf("Enter the index of the future event to travel to: ");
                scanf("%d", &event_index);

                if (event_index >= 0 && event_index < num_events) {
                    time_t event_time = events[event_index].time;
                    int event_type = events[event_index].type;

                    if (event_type == 2) {
                        printf("Traveling forward in time to %s...\n", ctime(&event_time));
                        current_time = event_time;
                    } else {
                        printf("Error: Invalid event type.\n");
                    }
                } else {
                    printf("Invalid event index.\n");
                }
            }
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}