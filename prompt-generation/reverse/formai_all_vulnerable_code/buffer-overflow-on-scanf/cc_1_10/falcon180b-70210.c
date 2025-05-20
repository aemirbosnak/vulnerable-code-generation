//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct event {
    int time;
    char *description;
} Event;

int main() {
    srand(time(NULL));

    int num_events = rand() % (MAX_EVENTS - 1) + 1;
    Event events[MAX_EVENTS];

    for (int i = 0; i < num_events; i++) {
        events[i].time = rand() % 100;
        events[i].description = (char *)malloc(100 * sizeof(char));
        sprintf(events[i].description, "Event %d occurred at time %d.", i+1, events[i].time);
    }

    int current_time = 0;
    char input[100];

    while (1) {
        printf("Current time: %d\n", current_time);
        printf("Enter your action (travel back/forward in time or quit): ");
        scanf("%s", input);

        if (strcmp(input, "travel back") == 0) {
            current_time -= 10;
        } else if (strcmp(input, "travel forward") == 0) {
            current_time += 10;
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid action.\n");
        }

        for (int i = 0; i < num_events; i++) {
            if (events[i].time == current_time) {
                printf("%s\n", events[i].description);
            }
        }
    }

    return 0;
}