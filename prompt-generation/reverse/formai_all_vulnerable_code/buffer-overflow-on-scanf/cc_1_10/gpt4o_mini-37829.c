//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Time Travel Simulator by Alan Turing, inspired
// A basic simulation of time travel based on user choice

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char description[256];
} TimeEvent;

void initEvent(TimeEvent* event, int year, int month, int day, const char* desc) {
    event->date.year = year;
    event->date.month = month;
    event->date.day = day;
    snprintf(event->description, sizeof(event->description), "%s", desc);
}

void displayEvent(const TimeEvent* event) {
    printf("Transporting to: %04d-%02d-%02d\n", event->date.year, event->date.month, event->date.day);
    printf("Event Description: %s\n\n", event->description);
}

void travelInTime(int destinationYear, TimeEvent* events, int numEvents) {
    int found = 0;
    for (int i = 0; i < numEvents; i++) {
        if (events[i].date.year == destinationYear) {
            displayEvent(&events[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No recorded events for the year %d.\n\n", destinationYear);
    }
}

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to a specific year\n");
    printf("2. Exit\n");
}

int main() {
    TimeEvent events[5];
    
    // Initialize a few historical events
    initEvent(&events[0], 1945, 5, 8, "End of World War II");
    initEvent(&events[1], 1969, 7, 20, "First Moon Landing");
    initEvent(&events[2], 1989, 11, 9, "Fall of the Berlin Wall");
    initEvent(&events[3], 2001, 9, 11, "September 11 attacks");
    initEvent(&events[4], 2020, 3, 11, "COVID-19 declared a pandemic");
    
    int choice;
    int yearToTravel;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter year to travel to (e.g., 1969): ");
                scanf("%d", &yearToTravel);
                travelInTime(yearToTravel, events, 5);
                break;
            case 2:
                printf("Exiting the Time Travel Simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);

    return 0;
}