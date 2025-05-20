//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MIN_PROBABILITY 0.0
#define MAX_PROBABILITY 1.0

typedef struct {
    char eventName[30];
    double probability; // probability of this event occurring
} Event;

void initializeEvents(Event *events, int numEvents) {
    for (int i = 0; i < numEvents; i++) {
        snprintf(events[i].eventName, sizeof(events[i].eventName), "Event %d", i + 1);
        events[i].probability = MIN_PROBABILITY + (rand() / (RAND_MAX / (MAX_PROBABILITY - MIN_PROBABILITY)));
    }
}

void displayEvents(const Event *events, int numEvents) {
    printf("\nList of Events and their Probabilities:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%s: %.2f%%\n", events[i].eventName, events[i].probability * 100);
    }
}

double calculateOverallProbability(const Event *events, int numEvents) {
    double overallProbability = 1.0;
    for (int i = 0; i < numEvents; i++) {
        overallProbability *= (1 - events[i].probability);
    }
    return 1 - overallProbability; // Probability of at least one event occurring
}

void getUserInput(int *numEvents) {
    printf("Enter the number of events (1 to %d): ", MAX_EVENTS);
    while (1) {
        scanf("%d", numEvents);
        if (*numEvents > 0 && *numEvents <= MAX_EVENTS) {
            break;
        }
        printf("Invalid input. Please enter a number between 1 and %d: ", MAX_EVENTS);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numEvents;
    Event events[MAX_EVENTS];

    getUserInput(&numEvents);
    initializeEvents(events, numEvents);
    displayEvents(events, numEvents);

    double invasionProbability = calculateOverallProbability(events, numEvents);
    printf("\nTotal Probability of Alien Invasion: %.2f%%\n", invasionProbability * 100);

    return 0;
}