//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_TIME 1000

typedef struct {
    int time;
    int type;
    char *description;
} Event;

int main() {
    int num_events, i;
    Event events[MAX_EVENTS];
    char input[100];
    int time = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can enter events with a time and description.\n");
    printf("Type 'travel' to travel through time.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "travel") == 0) {
            time += 10;
            printf("You have traveled 10 seconds into the future!\n");
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            sscanf(input, "%d %s", &events[num_events].time, events[num_events].description);
            events[num_events].type = 1;
            num_events++;
        }
    }

    for (i = 0; i < num_events; i++) {
        if (events[i].type == 1) {
            if (time >= events[i].time) {
                printf("%s\n", events[i].description);
            }
        }
    }

    return 0;
}