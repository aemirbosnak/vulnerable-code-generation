//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 100

typedef struct {
    char *description;
    time_t timestamp;
} Event;

int main() {
    srand(time(NULL));
    int num_events = rand() % MAX_EVENTS + 1;
    Event events[MAX_EVENTS];

    for (int i = 0; i < num_events; i++) {
        events[i].description = (char *)malloc(MAX_EVENT_LENGTH * sizeof(char));
        events[i].timestamp = time(NULL);
        sprintf(events[i].description, "Event %d occurred at %s", i + 1, ctime(&events[i].timestamp));
    }

    int current_event = 0;
    while (1) {
        printf("Current event: %s\n", events[current_event].description);
        printf("Do you want to time travel? (y/n)\n");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Enter the event number you want to travel to: ");
            int event_num;
            scanf("%d", &event_num);

            if (event_num >= 0 && event_num < num_events) {
                current_event = event_num;
            } else {
                printf("Invalid event number.\n");
            }
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}