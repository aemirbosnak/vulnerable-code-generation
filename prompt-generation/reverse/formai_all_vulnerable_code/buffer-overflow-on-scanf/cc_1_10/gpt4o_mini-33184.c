//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 5000
#define NUM_EVENTS 10

typedef struct {
    int year;
    char description[100];
} Event;

void displayEvents(Event events[], int size) {
    printf("Historical Events:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", events[i].year, events[i].description);
    }
}

void travelThroughTime(int targetYear, Event events[], int size) {
    int yearDifference = targetYear - 2023;
    
    if (yearDifference > 0) {
        printf("Traveling forward to the year %d...\n", targetYear);
    } else if (yearDifference < 0) {
        printf("Traveling back to the year %d...\n", targetYear);
    } else {
        printf("You are already in the year 2023.\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        if (events[i].year == targetYear) {
            printf("You have arrived in %d! Event: %s\n", events[i].year, events[i].description);
            return;
        }
    }
    
    printf("No notable events recorded for the year %d.\n", targetYear);
}

int main() {
    srand(time(NULL));

    Event events[NUM_EVENTS] = {
        {1776, "Declaration of Independence signed."},
        {1865, "Civil War ends in the USA."},
        {1920, "Women gain the right to vote in the USA."},
        {1969, "First moon landing."},
        {1989, "Fall of the Berlin Wall."},
        {2001, "Introduction of Wikipedia."},
        {2008, "Global financial crisis."},
        {2011, "First electric car surpasses 300 miles on a single charge."},
        {2020, "Global pandemic declared."},
        {2023, "The advent of widespread AI technology."}
    };
    
    displayEvents(events, NUM_EVENTS);

    int targetYear;
    printf("Enter the year you wish to travel to (between 1776 and 5000): ");
    scanf("%d", &targetYear);
    
    if (targetYear < 1776 || targetYear > MAX_YEARS) {
        printf("Invalid year! The year must be between 1776 and %d.\n", MAX_YEARS);
        exit(EXIT_FAILURE);
    }
    
    travelThroughTime(targetYear, events, NUM_EVENTS);

    return 0;
}