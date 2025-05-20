//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_YEAR 2023
#define MIN_YEAR 1900
#define EVENTS_COUNT 5

typedef struct {
    int year;
    char event[256];
} HistoricalEvent;

HistoricalEvent events[] = {
    {1901, "The first Nobel Prizes are awarded."},
    {1914, "World War I begins."},
    {1969, "Apollo 11 lands on the moon."},
    {1989, "The Berlin Wall falls."},
    {2000, "Y2K scare comes and goes without incident."},
    {2020, "COVID-19 pandemic affects the world."},
    {2023, "AI technology reaches new heights."}
};

void displayMenu() {
    printf("\nWelcome to the Time Travel Simulator!\n");
    printf("You can travel to the following years:\n");
    printf("%d to %d\n", MIN_YEAR, MAX_YEAR);
    printf("Please enter a year to see historical events (or type -1 to exit): ");
}

void displayEvents(int year) {
    int found = 0;
    printf("Traveling to the year %d...\n", year);
    printf("Historical events in that year:\n");

    for (int i = 0; i < sizeof(events) / sizeof(events[0]); i++) {
        if (events[i].year == year) {
            printf("- %s\n", events[i].event);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No significant events found for the year %d.\n", year);
    }
}

int main() {
    int year;

    while (1) {
        displayMenu();
        scanf("%d", &year);

        if (year == -1) {
            printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
            break;
        }

        if (year < MIN_YEAR || year > MAX_YEAR) {
            printf("Invalid year. Please enter a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
            continue;
        }

        displayEvents(year);
    }

    return 0;
}