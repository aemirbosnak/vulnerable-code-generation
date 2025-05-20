//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 1000
#define MAX_EVENTS 10

// Structure to represent a historical event
typedef struct {
    int year;
    char description[256];
} Event;

// Function to simulate time travel
void timeTravel(int targetYear, Event history[], int eventCount) {
    if (targetYear < 0 || targetYear > MAX_YEARS) {
        printf("Invalid year! Please choose a year between 0 and %d.\n", MAX_YEARS);
        return;
    }

    printf("\nWelcome to the Year %d!\n", targetYear);
    int foundEvent = 0;
    
    for (int i = 0; i < eventCount; i++) {
        if (history[i].year == targetYear) {
            printf("Historical Event: %s\n", history[i].description);
            foundEvent = 1;
        }
    }

    if (!foundEvent) {
        printf("No significant events recorded for this year. Enjoy your exploration!\n");
    }
}

void printMenu() {
    printf("\n--- Time Travel Menu ---\n");
    printf("1. Travel to a Year\n");
    printf("2. List Historical Events\n");
    printf("3. Exit\n");
    printf("-----------------------\n");
}

void listEvents(Event history[], int eventCount) {
    printf("\n--- Historical Events ---\n");
    for (int i = 0; i < eventCount; i++) {
        printf("Year %d: %s\n", history[i].year, history[i].description);
    }
}

int main() {
    // Set up some interesting historical events
    Event history[MAX_EVENTS] = {
        {1776, "Declaration of Independence"},
        {1865, "End of the American Civil War"},
        {1969, "First Moon Landing"},
        {1989, "Fall of the Berlin Wall"},
        {2001, "September 11 Attacks"},
        {2010, "Smartphones become mainstream"},
        {2020, "Global Pandemic"},
        {2023, "First successful human-AI collaboration in medicine"}
    };

    int eventCount = 8;
    int choice, year;

    printf("Welcome to the Time Travel Simulator!\n");

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to (0 - %d): ", MAX_YEARS);
                scanf("%d", &year);
                timeTravel(year, history, eventCount);
                break;
            case 2:
                listEvents(history, eventCount);
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator. Farewell!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}