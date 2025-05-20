//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
// Time Travel Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel events
typedef struct {
    int year;
    char* event;
} Event;

Event events[] = {
    {1955, "Elvis Presley's first performance on The Ed Sullivan Show"},
    {1969, "First manned moon landing"},
    {1989, "Fall of the Berlin Wall"},
    {2001, "September 11 attacks"},
    {2011, "First manned landing on Mars"}
};

// Define the time travel function
void travel_to_past(int year) {
    // Calculate the difference in years between the current year and the selected year
    int years_diff = year - 2023;

    // Set the current year to the selected year
    time_t current_time = time(NULL);
    struct tm* current_tm = localtime(&current_time);
    current_tm->tm_year = year - 1900;
    mktime(current_tm);

    // Print the current year and the selected event
    printf("Current year: %d\n", current_tm->tm_year + 1900);
    printf("Event: %s\n", events[years_diff].event);
}

int main() {
    // Print the current year and event
    time_t current_time = time(NULL);
    struct tm* current_tm = localtime(&current_time);
    printf("Current year: %d\n", current_tm->tm_year + 1900);
    printf("Event: %s\n", events[0].event);

    // Ask the user to input a year
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    // Travel to the past
    travel_to_past(year);

    return 0;
}