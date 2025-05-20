//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *event;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    time_t current_time = time(NULL);

    printf("Welcome to the Time Travel Simulator!\n\n");

    while (num_events < MAX_EVENTS) {
        printf("Enter an event (leave blank to stop): ");
        char event[100];
        fgets(event, 100, stdin);

        if (strcmp(event, "") == 0) {
            break;
        }

        events[num_events].event = strdup(event);
        events[num_events].timestamp = current_time;
        num_events++;

        printf("Event %d added: %s\n", num_events - 1, events[num_events - 1].event);
    }

    printf("\n");

    while (1) {
        printf("Enter a time to travel to (in seconds since epoch): ");
        long int target_time;
        scanf("%ld", &target_time);

        current_time = target_time;

        printf("\n");
        printf("Current time: %s\n", ctime(&current_time));

        for (int i = 0; i < num_events; i++) {
            if (difftime(current_time, events[i].timestamp) >= 0) {
                printf("Event %d occurred: %s\n", i + 1, events[i].event);
            }
        }
    }

    return 0;
}