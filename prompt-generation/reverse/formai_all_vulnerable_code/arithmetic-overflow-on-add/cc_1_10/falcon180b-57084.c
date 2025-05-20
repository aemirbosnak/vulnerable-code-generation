//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct {
    time_t time;
    char *description;
} event_t;

int main() {
    srand(time(NULL));

    event_t events[MAX_EVENTS];
    int num_events = 0;

    event_t *current_event = &events[0];
    current_event->time = time(NULL) + rand() % 86400; // Start at a random time within the next 24 hours
    current_event->description = "You wake up in the morning and realize you can time travel.";
    num_events++;

    int choice;
    while (1) {
        printf("\n");
        for (int i = 0; i < num_events; i++) {
            if (events[i].time <= time(NULL)) {
                printf("%s\n", events[i].description);
            }
        }

        printf("\nWhat do you want to do?\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Do nothing\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_event->time -= 86400; // Travel back one day
                current_event->description = "You go back in time one day.";
                break;
            case 2:
                current_event->time += 86400; // Travel forward one day
                current_event->description = "You go forward in time one day.";
                break;
            case 3:
                current_event->time = time(NULL) + rand() % 86400; // Do nothing, but generate a new random time for the next event
                current_event->description = "Nothing happens.";
                break;
            default:
                printf("Invalid choice.\n");
        }

        current_event++;
        if (current_event >= &events[MAX_EVENTS]) {
            current_event = &events[0];
        }

        num_events++;
        events[num_events - 1].time = current_event->time;
        events[num_events - 1].description = current_event->description;
    }

    return 0;
}