//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 10
#define MAX_YEARS 5

struct TimeEvent {
    int year;
    char event[100];
};

struct TimeTravelSimulator {
    struct TimeEvent timeline[MAX_YEARS];
    int count;
};

void initializeTimeline(struct TimeTravelSimulator *simulator) {
    simulator->count = 0;

    // Add some known events to the timeline
    simulator->timeline[0] = (struct TimeEvent){-2020, "Global pandemic starts."};
    simulator->timeline[1] = (struct TimeEvent){-1969, "First moon landing."};
    simulator->timeline[2] = (struct TimeEvent){-1776, "Declaration of Independence."};
    simulator->timeline[3] = (struct TimeEvent){+2025, "Mars colonization begins."};
    simulator->timeline[4] = (struct TimeEvent){+2040, "Quantum computing revolution."};

    simulator->count = 5;
}

void displayEvents(struct TimeTravelSimulator simulator, int year) {
    int found = 0;
    printf("\nSignificant events in the year %d:\n", year);
    for (int i = 0; i < simulator.count; ++i) {
        if (simulator.timeline[i].year == year) {
            printf("- %s\n", simulator.timeline[i].event);
            found = 1;
        }
    }
    if (!found) {
        printf("No significant events found for this year.\n");
    }
}

void travelTime(struct TimeTravelSimulator *simulator) {
    int year;
    while (1) {
        printf("\nEnter the year you want to travel to (or enter 0 to exit): ");
        scanf("%d", &year);

        if (year == 0) {
            printf("Exiting Time Travel Simulator. Thank you!\n");
            break;
        }

        displayEvents(*simulator, year);
    }
}

int main() {
    struct TimeTravelSimulator simulator;
    initializeTimeline(&simulator); // Initialize timeline with events
    travelTime(&simulator);          // Begin time travel interactions
    return 0;
}