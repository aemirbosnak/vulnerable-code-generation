//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} event_t;

int main() {
    srand(time(NULL));

    event_t events[MAX_EVENTS];
    int num_events = 0;

    event_t start_event = {.time = time(NULL),.description = "You start your time travel journey."};
    events[num_events++] = start_event;

    int choice;
    do {
        printf("What do you want to do?\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. See the timeline\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_events > 1 && events[num_events - 1].time!= events[num_events - 2].time) {
                    events[num_events++] = (event_t) {.time = events[num_events - 2].time,.description = "You travel back in time."};
                } else {
                    printf("You can't travel back in time from the beginning of time.\n");
                }
                break;
            case 2:
                if (num_events > 1 && events[num_events - 1].time!= events[num_events - 2].time) {
                    events[num_events++] = (event_t) {.time = events[num_events - 2].time + rand() % 86400,.description = "You travel forward in time."};
                } else {
                    printf("You can't travel forward in time from the end of time.\n");
                }
                break;
            case 3:
                printf("Timeline:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("%s - %s\n", ctime(&events[i].time), events[i].description);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice!= 4);

    return 0;
}