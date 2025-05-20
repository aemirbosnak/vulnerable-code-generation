//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    time_t current_time = time(NULL);
    char input[100];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter 'travel' followed by a Unix timestamp to go back in time.\n");
    printf("Enter 'event' followed by a description to create a new event.\n");
    printf("Enter 'quit' to exit the program.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "travel") == 0) {
            sscanf(input, "travel %lu", &current_time);
            printf("You have traveled back in time to %s.\n", ctime(&current_time));
        } else if (strcmp(input, "event") == 0) {
            printf("Enter the description of the event:\n");
            fgets(input, sizeof(input), stdin);
            events[num_events].time = current_time;
            events[num_events].description = strdup(input);
            num_events++;
            if (num_events == MAX_EVENTS) {
                printf("Maximum number of events reached.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }

    return 0;
}