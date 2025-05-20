//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_TIME 10000

typedef struct {
    int time;
    int type;
    int data;
} Event;

int main() {
    srand(time(NULL));
    Event events[MAX_EVENTS];
    int num_events = 0;
    int current_time = 0;

    while (num_events < MAX_EVENTS) {
        int type = rand() % 3;
        int data = rand() % 100;
        int time = current_time + rand() % MAX_EVENT_TIME;

        if (type == 0) {
            printf("A new species of animal has been discovered at time %d.\n", time);
        } else if (type == 1) {
            printf("A major technological breakthrough has occurred at time %d.\n", time);
        } else {
            printf("A catastrophic event has taken place at time %d.\n", time);
        }

        events[num_events] = (Event) {.time = time,.type = type,.data = data};
        num_events++;
    }

    int user_time = 0;
    printf("Enter the time you want to travel to: ");
    scanf("%d", &user_time);

    int i;
    for (i = 0; i < num_events; i++) {
        if (events[i].time > user_time) {
            break;
        }

        if (events[i].type == 0) {
            printf("At time %d, a new species of animal was discovered.\n", events[i].time);
        } else if (events[i].type == 1) {
            printf("At time %d, a major technological breakthrough occurred.\n", events[i].time);
        } else {
            printf("At time %d, a catastrophic event took place.\n", events[i].time);
        }
    }

    if (i == num_events) {
        printf("No events found after time %d.\n", user_time);
    }

    return 0;
}