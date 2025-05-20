//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 80

struct event {
    time_t timestamp;
    char message[MAX_EVENT_LENGTH];
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);

    while (1) {
        printf("Current time: %s\n", ctime(&current_time));

        int choice;
        printf("Enter your choice:\n");
        printf("1. Add event\n");
        printf("2. Travel back in time\n");
        printf("3. Travel forward in time\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_events >= MAX_EVENTS) {
                printf("Maximum number of events reached.\n");
                break;
            }

            printf("Enter event message: ");
            scanf("%s", events[num_events].message);
            events[num_events].timestamp = current_time;
            num_events++;
            break;

        case 2:
            if (num_events == 0) {
                printf("No events to travel back to.\n");
                break;
            }

            int event_index;
            printf("Enter event index to travel back to: ");
            scanf("%d", &event_index);

            if (event_index >= 0 && event_index < num_events) {
                current_time = events[event_index].timestamp;
                printf("Traveled back to event %d.\n", event_index);
            } else {
                printf("Invalid event index.\n");
            }
            break;

        case 3:
            if (num_events == 0) {
                printf("No events to travel forward from.\n");
                break;
            }

            event_index = num_events - 1;
            current_time += 60;  // Travel one minute into the future

            if (event_index >= 0 && event_index < num_events) {
                while (current_time < events[event_index].timestamp) {
                    current_time += 60;
                }
                printf("Traveled forward to event %d.\n", event_index);
            } else {
                printf("Invalid event index.\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}