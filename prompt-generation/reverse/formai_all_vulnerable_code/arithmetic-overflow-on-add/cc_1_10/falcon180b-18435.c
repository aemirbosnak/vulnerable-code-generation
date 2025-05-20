//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

int main() {
    srand(time(NULL));

    Event events[MAX_EVENTS];
    int num_events = 0;

    events[num_events++] = (Event){.time = 946684800,.description = "Google is founded"};
    events[num_events++] = (Event){.time = 978307200,.description = "iPod is released"};
    events[num_events++] = (Event){.time = 1234567890,.description = "First tweet is sent"};
    events[num_events++] = (Event){.time = 1300000000,.description = "First Instagram photo is posted"};
    events[num_events++] = (Event){.time = 1451606400,.description = "Pokemon Go is released"};

    time_t current_time = time(NULL);

    printf("Welcome to the Time Travel Simulator!\n");

    while (1) {
        printf("\nCurrent time: %s", ctime(&current_time));

        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. View past events\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            current_time += rand() % 100000000;
            break;
        case 2:
            current_time -= rand() % 100000000;
            break;
        case 3:
            printf("\nPast events:\n");
            for (int i = 0; i < num_events; i++) {
                if (events[i].time > current_time) {
                    printf("%s\n", events[i].description);
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}