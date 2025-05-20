//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 5
#define MAX_YEARS 5

typedef struct {
    int year;
    char event[100];
} TimeEvent;

typedef struct {
    TimeEvent events[MAX_EVENTS];
    int event_count;
} TimeTravelSimulator;

void initialize_events(TimeTravelSimulator *simulator) {
    // Sample events in various years
    simulator->event_count = 0;

    // Adding events for year 2023
    simulator->events[simulator->event_count++] = (TimeEvent){2023, "Discovered a new energy source."};
    // Adding events for year 2020
    simulator->events[simulator->event_count++] = (TimeEvent){2020, "Global pandemic leads to unprecedented lockdowns."};
    // Adding events for year 1990
    simulator->events[simulator->event_count++] = (TimeEvent){1990, "The World Wide Web was born."};
    // Adding events for year 1969
    simulator->events[simulator->event_count++] = (TimeEvent){1969, "Man lands on the Moon."};
    // Adding events for year 1776
    simulator->events[simulator->event_count++] = (TimeEvent){1776, "The Declaration of Independence was adopted."};
}

void travel_to_year(TimeTravelSimulator *simulator, int year) {
    int found = 0;
    for (int i = 0; i < simulator->event_count; i++) {
        if (simulator->events[i].year == year) {
            printf("Time Travel Successful! You have traveled to the year %d.\n", year);
            printf("Historical Event: %s\n", simulator->events[i].event);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("There are no recorded events for the year %d. Try a different year.\n", year);
    }
}

void print_menu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("Select a year to travel to:\n");
    printf("1. 2023\n");
    printf("2. 2020\n");
    printf("3. 1990\n");
    printf("4. 1969\n");
    printf("5. 1776\n");
    printf("0. Exit\n");
}

int main() {
    TimeTravelSimulator simulator;
    int choice;
    initialize_events(&simulator);

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travel_to_year(&simulator, 2023);
                break;
            case 2:
                travel_to_year(&simulator, 2020);
                break;
            case 3:
                travel_to_year(&simulator, 1990);
                break;
            case 4:
                travel_to_year(&simulator, 1969);
                break;
            case 5:
                travel_to_year(&simulator, 1776);
                break;
            case 0:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}