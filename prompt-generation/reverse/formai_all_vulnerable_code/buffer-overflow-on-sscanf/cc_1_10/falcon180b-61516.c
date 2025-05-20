//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

struct event {
    time_t time;
    char *description;
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    char input[1024];
    time_t current_time, next_event_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter 'help' for a list of commands.\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  travel <time>\n");
            printf("  add_event <time> <description>\n");
            printf("  remove_event <index>\n");
            printf("  list_events\n");
        } else if (sscanf(input, "travel %ld", &current_time) == 1) {
            current_time += time(NULL);
            printf("You have traveled to the year %ld!\n", current_time);
        } else if (sscanf(input, "add_event %ld %s", &current_time, events[num_events].description) == 2) {
            events[num_events].time = current_time;
            num_events++;
            printf("Event added: %s\n", events[num_events - 1].description);
        } else if (sscanf(input, "remove_event %d", &current_time) == 1) {
            if (current_time >= 0 && current_time < num_events) {
                printf("Event removed: %s\n", events[current_time].description);
                memmove(&events[current_time], &events[current_time + 1], sizeof(struct event) * (num_events - current_time - 1));
                num_events--;
            } else {
                printf("Invalid event index.\n");
            }
        } else if (strcmp(input, "list_events") == 0) {
            printf("Upcoming events:\n");
            for (int i = 0; i < num_events; i++) {
                time_t event_time = events[i].time;
                char *time_string = ctime(&event_time);
                printf("%s - %s\n", time_string, events[i].description);
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}