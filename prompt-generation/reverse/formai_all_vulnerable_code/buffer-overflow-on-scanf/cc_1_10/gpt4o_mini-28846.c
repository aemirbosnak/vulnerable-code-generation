//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 5000
#define TIME_TRAVEL_RECORDS 100

typedef struct {
    int year;
    char event[100];
} TimeEvent;

typedef struct {
    TimeEvent events[TIME_TRAVEL_RECORDS];
    int count;
} TimeTravelHistory;

void initializeHistory(TimeTravelHistory *history) {
    history->count = 0;
}

void addTimeEvent(TimeTravelHistory *history, int year, const char *event) {
    if (history->count < TIME_TRAVEL_RECORDS) {
        history->events[history->count].year = year;
        strncpy(history->events[history->count].event, event, 99);
        history->events[history->count].event[99] = '\0'; // Ensure null-termination
        history->count++;
    } else {
        printf("Time travel history full!\n");
    }
}

void displayHistory(const TimeTravelHistory *history) {
    printf("Time Travel History:\n");
    for (int i = 0; i < history->count; i++) {
        printf("Year %d: %s\n", history->events[i].year, history->events[i].event);
    }
    printf("\n");
}

int validYear(int year) {
    return (year >= 0 && year <= MAX_YEARS);
}

void timeTravel(int year, TimeTravelHistory *history) {
    if (validYear(year)) {
        char event[100];
        printf("Traveling to the year %d...\n", year);
        printf("Please describe a significant event for the year %d: ", year);
        fgets(event, sizeof(event), stdin);
        event[strcspn(event, "\n")] = '\0'; // Remove newline character
        addTimeEvent(history, year, event);
        printf("Event recorded!\n");
    } else {
        printf("Invalid year! Please enter a year between 0 and %d.\n", MAX_YEARS);
    }
}

void displayMenu() {
    printf("Time Travel Simulator Menu:\n");
    printf("1. Travel to a year and record an event\n");
    printf("2. Show time travel history\n");
    printf("3. Exit\n");
}

int main() {
    TimeTravelHistory history;
    initializeHistory(&history);
    int choice, year;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Clear stdin buffer

        switch (choice) {
            case 1:
                printf("Enter year to travel to (0 - %d): ", MAX_YEARS);
                scanf("%d", &year);
                while (getchar() != '\n'); // Clear stdin buffer
                timeTravel(year, &history);
                break;
            case 2:
                displayHistory(&history);
                break;
            case 3:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}