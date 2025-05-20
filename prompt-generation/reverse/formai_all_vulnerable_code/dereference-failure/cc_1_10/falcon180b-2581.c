//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *description;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void add_event(const char *description) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Cannot add more events.\n");
        return;
    }

    Event new_event;
    strcpy(new_event.description, description);
    time(&new_event.timestamp);

    events[num_events++] = new_event;
}

void travel_to_event(int index) {
    if (index < 0 || index >= num_events) {
        printf("Error: Invalid event index.\n");
        return;
    }

    Event event = events[index];
    time_t target_time = event.timestamp;

    while (difftime(time(NULL), target_time) > 0) {
        sleep(1);
    }

    printf("You have arrived at the event: %s\n", event.description);
}

int main() {
    srand(time(NULL));

    add_event("The day you were born");
    add_event("Your first kiss");
    add_event("The moment you fell in love");

    int choice;
    do {
        printf("Choose an event to travel to:\n");
        for (int i = 0; i < num_events; i++) {
            printf("%d. %s\n", i+1, events[i].description);
        }
        printf("%d. Go back in time\n", num_events+1);
        scanf("%d", &choice);

        if (choice <= num_events) {
            travel_to_event(choice-1);
        } else if (choice == num_events+1) {
            time_t current_time;
            time(&current_time);
            while (difftime(current_time, events[num_events-1].timestamp) > 0) {
                sleep(1);
            }
        }
    } while (1);

    return 0;
}