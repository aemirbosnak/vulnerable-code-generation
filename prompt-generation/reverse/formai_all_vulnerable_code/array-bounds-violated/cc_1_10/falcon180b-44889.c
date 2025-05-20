//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10
#define NUM_EVENTS 5

typedef struct {
    char name[20];
    int time;
    bool happened;
} Event;

Event events[NUM_EVENTS] = {
    {"Event 1", 0, false},
    {"Event 2", 0, false},
    {"Event 3", 0, false},
    {"Event 4", 0, false},
    {"Event 5", 0, false}
};

int main() {
    srand(time(NULL));
    int num_events = rand() % NUM_EVENTS + 1;

    for (int i = 0; i < num_events; i++) {
        int event_index = rand() % NUM_EVENTS;
        events[event_index].time = rand() % 100;
    }

    int num_travellers = rand() % 10 + 1;
    char travellers[num_travellers][20];
    for (int i = 0; i < num_travellers; i++) {
        sprintf(travellers[i], "Traveller %d", i + 1);
    }

    int num_rounds = rand() % 10 + 1;

    for (int round = 1; round <= num_rounds; round++) {
        printf("Round %d:\n", round);
        for (int i = 0; i < num_travellers; i++) {
            printf("Traveller %s travels back in time...\n", travellers[i]);
        }

        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < num_travellers; k++) {
                if (events[k].time == j) {
                    printf("Traveller %s arrives at event %s.\n", travellers[k], events[k].name);
                    events[k].happened = true;
                }
            }
        }

        for (int i = 0; i < num_travellers; i++) {
            printf("Traveller %s returns to the present.\n", travellers[i]);
        }
    }

    return 0;
}