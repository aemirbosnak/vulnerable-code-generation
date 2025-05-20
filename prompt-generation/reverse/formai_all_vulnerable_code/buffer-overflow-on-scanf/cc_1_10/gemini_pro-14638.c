//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time travel events
#define MAX_EVENTS 100

// Define the structure of a time travel event
typedef struct {
    int year;
    char *event;
} TimeTravelEvent;

// Define an array of time travel events
TimeTravelEvent events[MAX_EVENTS];

// Initialize the array of time travel events
void initializeEvents() {
    events[0].year = 1955;
    events[0].event = "The first time machine is invented.";

    events[1].year = 1985;
    events[1].event = "The first human travels back in time.";

    events[2].year = 2015;
    events[2].event = "The first time tourism becomes a reality.";

    events[3].year = 2050;
    events[3].event = "The first time travel war breaks out.";

    events[4].year = 2100;
    events[4].event = "The first time machine is destroyed.";
}

// Print the array of time travel events
void printEvents() {
    for (int i = 0; i < MAX_EVENTS; i++) {
        printf("%d: %s\n", events[i].year, events[i].event);
    }
}

// Simulate time travel
void timeTravel() {
    // Get the current year
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    int currentYear = tm->tm_year + 1900;

    // Get the year the user wants to travel to
    printf("What year do you want to travel to? ");
    int year;
    scanf("%d", &year);

    // Check if the year is valid
    if (year < 1955 || year > 2100) {
        printf("Invalid year. Please enter a year between 1955 and 2100.\n");
        return;
    }

    // Calculate the number of years the user wants to travel
    int years = year - currentYear;

    // Print the events that will occur during the user's time travel
    printf("\nEvents that will occur during your time travel:\n");
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (events[i].year >= year) {
            printf("%d: %s\n", events[i].year, events[i].event);
        }
    }
}

// Main function
int main() {
    // Initialize the array of time travel events
    initializeEvents();

    // Print the array of time travel events
    printEvents();

    // Simulate time travel
    timeTravel();

    return 0;
}