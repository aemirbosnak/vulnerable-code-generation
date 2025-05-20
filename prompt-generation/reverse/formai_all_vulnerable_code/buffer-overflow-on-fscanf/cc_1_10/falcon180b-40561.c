//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define EVENT_SIZE 128

struct event {
    char message[EVENT_SIZE];
    time_t timestamp;
};

int main() {
    int num_events = 0;
    struct event events[MAX_EVENTS];
    char input[EVENT_SIZE];

    // Read in events from file
    FILE *file = fopen("events.log", "r");
    if (file == NULL) {
        printf("Error: could not open events.log\n");
        exit(1);
    }

    while (fscanf(file, "%s %ld\n", input, &events[num_events].timestamp) == 2 && num_events < MAX_EVENTS) {
        strncpy(events[num_events].message, input, EVENT_SIZE);
        num_events++;
    }

    fclose(file);

    // Start monitoring
    while (1) {
        printf("Enter event: ");
        fgets(input, EVENT_SIZE, stdin);

        // Check for intrusion
        if (strstr(input, "intrusion")!= NULL) {
            printf("Intrusion detected!\n");
        }

        // Add event to log
        if (num_events >= MAX_EVENTS) {
            printf("Event log is full.\n");
        } else {
            strncpy(events[num_events].message, input, EVENT_SIZE);
            events[num_events].timestamp = time(NULL);
            num_events++;
        }
    }

    return 0;
}