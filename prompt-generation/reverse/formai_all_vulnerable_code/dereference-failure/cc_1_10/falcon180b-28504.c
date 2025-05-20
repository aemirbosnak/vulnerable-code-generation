//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

int main() {
    char input[1024];
    time_t current_time = time(NULL);
    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter 'travel' followed by a Unix timestamp (in seconds) to go back in time.\n");
    printf("Enter 'event' followed by a description to create a new event at the current time.\n");
    printf("Enter 'quit' to exit the program.\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *command = strtok(input, " ");

        if (strcmp(command, "travel") == 0) {
            time_t destination_time = strtol(strtok(NULL, " "), NULL, 10);

            if (destination_time < current_time) {
                printf("You cannot travel to a time in the future.\n");
            } else {
                current_time = destination_time;
                printf("You have traveled back in time to %s.\n", ctime(&current_time));
            }
        } else if (strcmp(command, "event") == 0) {
            char *description = strtok(NULL, " ");

            if (num_events >= MAX_EVENTS) {
                printf("You cannot create any more events.\n");
            } else {
                events[num_events].time = current_time;
                events[num_events].description = strdup(description);
                num_events++;

                printf("You have created a new event: %s\n", description);
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}