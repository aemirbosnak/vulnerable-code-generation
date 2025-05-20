//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct Event {
    Date date;
    char *description;
} Event;

int main() {
    srand(time(NULL));

    // Create a list of random events
    int num_events = 10;
    Event events[num_events];
    for (int i = 0; i < num_events; i++) {
        events[i].date.year = rand() % 2023 + 1;
        events[i].date.month = rand() % 12 + 1;
        events[i].date.day = rand() % 31 + 1;
        events[i].description = (char *)malloc(50);
        sprintf(events[i].description, "Event %d", i);
    }

    // Create a time travel machine
    int current_year = 2023;
    int current_month = 1;
    int current_day = 1;

    // Loop until the user quits
    int quit = 0;
    while (!quit) {
        // Display the current date
        printf("Current date: %d-%d-%d\n", current_year, current_month, current_day);

        // Display a list of possible destinations
        printf("Possible destinations: \n");
        for (int i = 0; i < num_events; i++) {
            printf("%d: %d-%d-%d: %s\n", i+1, events[i].date.year, events[i].date.month, events[i].date.day, events[i].description);
        }

        // Prompt the user for a destination
        int destination;
        printf("Enter a destination (1-%d or 0 to quit): ", num_events);
        scanf("%d", &destination);

        // If the user entered 0, quit the program
        if (destination == 0) {
            quit = 1;
        } else {
            // Otherwise, travel to the destination
            current_year = events[destination-1].date.year;
            current_month = events[destination-1].date.month;
            current_day = events[destination-1].date.day;

            // Display the new date
            printf("New date: %d-%d-%d\n", current_year, current_month, current_day);
        }
    }

    // Free the memory allocated for the events
    for (int i = 0; i < num_events; i++) {
        free(events[i].description);
    }

    return 0;
}