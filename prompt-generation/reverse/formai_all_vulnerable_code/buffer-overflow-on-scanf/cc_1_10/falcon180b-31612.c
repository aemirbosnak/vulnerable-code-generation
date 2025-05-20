//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct event {
    time_t timestamp;
    char *description;
} Event;

int main(int argc, char **argv) {
    int num_events = 0;
    Event events[MAX_EVENTS];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel through time and witness historical events.\n");
    printf("Please enter the number of events you want to witness (maximum %d): ", MAX_EVENTS);
    scanf("%d", &num_events);

    for (int i = 0; i < num_events; i++) {
        printf("Enter the timestamp (in seconds since January 1, 1970) for event %d: ", i+1);
        time_t timestamp;
        scanf("%ld", &timestamp);
        events[i].timestamp = timestamp;

        printf("Enter a description for event %d: ", i+1);
        char *description = malloc(100);
        scanf("%s", description);
        events[i].description = description;
    }

    while (1) {
        printf("\nCurrent time: ");
        time_t current_time = time(NULL);
        printf("%ld\n", current_time);

        for (int i = 0; i < num_events; i++) {
            if (current_time >= events[i].timestamp) {
                printf("\nEvent %d (%s) is happening now!\n", i+1, events[i].description);
                break;
            }
        }

        printf("\nPress enter to travel forward in time...\n");
        getchar();
    }

    return 0;
}