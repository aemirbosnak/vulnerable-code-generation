//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *description;
} Event;

int main() {
    int num_events;
    Event events[MAX_EVENTS];
    char input_buffer[1000];
    time_t current_time, target_time;
    int i;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the current time
    current_time = time(NULL);

    // Get the number of events from the user
    printf("Enter the number of events: ");
    scanf("%d", &num_events);

    // Get the events from the user
    for (i = 0; i < num_events; i++) {
        printf("Enter event %d: ", i+1);
        fgets(input_buffer, 1000, stdin);

        // Parse the event description
        events[i].description = malloc(strlen(input_buffer) + 1);
        strcpy(events[i].description, input_buffer);

        // Remove the newline character from the end of the input buffer
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Get the timestamp for the event
        if (sscanf(input_buffer, "%s %ld", events[i].description, &events[i].timestamp)!= 2) {
            printf("Invalid event format: %s\n", input_buffer);
            exit(1);
        }
    }

    // Sort the events by timestamp
    for (i = 0; i < num_events - 1; i++) {
        for (int j = i + 1; j < num_events; j++) {
            if (events[i].timestamp > events[j].timestamp) {
                Event temp = events[i];
                events[i] = events[j];
                events[j] = temp;
            }
        }
    }

    // Travel through time
    printf("Traveling through time...\n");
    for (i = 0; i < num_events; i++) {
        target_time = events[i].timestamp;
        while (current_time < target_time) {
            current_time = time(NULL);
            printf("Current time: %s", ctime(&current_time));
        }
        printf("Arrived at event %s\n", events[i].description);
    }

    return 0;
}