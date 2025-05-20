//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIME 10000

struct event {
    int time;
    char *description;
};

int main() {
    int num_events;
    struct event events[MAX_EVENTS];
    int current_time = 0;
    int choice;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter the number of events you would like to simulate (up to %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    printf("\nEnter %d events in the format 'time description':\n", num_events);
    for (int i = 0; i < num_events; i++) {
        scanf("%d %s", &events[i].time, events[i].description);
    }

    while (current_time < MAX_TIME) {
        printf("\nCurrent time: %d\n", current_time);
        printf("Enter your choice:\n1. Advance time by 1 second\n2. Go back in time\n3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            current_time++;
            break;
        case 2:
            if (current_time > 0) {
                current_time--;
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }

        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                printf("\nEvent: %s\n", events[i].description);
            }
        }
    }

    return 0;
}