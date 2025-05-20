//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 5
#define MAX_INPUT 100

typedef struct {
    int year;
    char description[MAX_INPUT];
} TimeEvent;

void displayEvents(TimeEvent events[], int size) {
    printf("Available Time Travel Destinations:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. Year: %d - %s\n", i + 1, events[i].year, events[i].description);
    }
}

void travelToYear(TimeEvent event) {
    printf("Time Traveling to the year %d...\n", event.year);
    printf("You arrived in the year %d!\n", event.year);
    printf("Event: %s\n", event.description);
    printf("Enjoy your stay!\n\n");
}

int main() {
    TimeEvent events[MAX_EVENTS] = {
        {1776, "American Declaration of Independence"},
        {1865, "End of the American Civil War"},
        {1969, "First Moon Landing"},
        {1989, "Fall of the Berlin Wall"},
        {2001, "Launch of the first iPod"}
    };

    int choice;
    char input[MAX_INPUT];

    while (1) {
        displayEvents(events, MAX_EVENTS);
        printf("Enter the number of the year you want to travel to (0 to exit): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > MAX_EVENTS) {
            printf("Invalid choice. Please select a valid year.\n\n");
            continue;
        }

        travelToYear(events[choice - 1]);
    }

    return 0;
}