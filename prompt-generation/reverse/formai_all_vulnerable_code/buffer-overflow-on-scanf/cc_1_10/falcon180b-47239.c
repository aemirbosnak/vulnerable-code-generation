//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    double time;
    char *description;
} Event;

int main() {
    int num_events;
    Event events[MAX_EVENTS];
    double current_time = 0.0;
    char input[100];
    int i;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Enter the number of events you would like to simulate (up to %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    for (i = 0; i < num_events; i++) {
        printf("Enter event %d (format: time description): ", i+1);
        scanf("%s", input);
        events[i].time = atof(strtok(input, " "));
        events[i].description = strdup(strtok(NULL, " "));
    }

    while (1) {
        printf("\nCurrent time: %.2f\n", current_time);
        printf("Enter your next action (type 'event' followed by an event number, 'travel' followed by a time, or 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "event") == 0) {
            int event_num;
            scanf("%d", &event_num);
            if (event_num >= 0 && event_num < num_events) {
                current_time = events[event_num].time;
                printf("\nEvent %d: %s\n", event_num+1, events[event_num].description);
            } else {
                printf("Invalid event number.\n");
            }
        } else if (strcmp(input, "travel") == 0) {
            double travel_time;
            scanf("%lf", &travel_time);
            current_time += travel_time;
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid action.\n");
        }
    }

    return 0;
}