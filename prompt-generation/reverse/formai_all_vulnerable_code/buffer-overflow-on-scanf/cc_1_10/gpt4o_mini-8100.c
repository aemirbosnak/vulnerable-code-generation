//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_YEAR 3000
#define MIN_YEAR 1000

struct Event {
    int year;
    char description[256];
};

struct TimeMachine {
    struct Event events[MAX_EVENTS];
    int count;
};

void initializeTimeMachine(struct TimeMachine *tm) {
    tm->count = 0;

    // Adding some historical events
    tm->events[tm->count++] = (struct Event){ 1492, "Columbus discovers America" };
    tm->events[tm->count++] = (struct Event){ 1776, "American Declaration of Independence" };
    tm->events[tm->count++] = (struct Event){ 1865, "End of the American Civil War" };
    tm->events[tm->count++] = (struct Event){ 1969, "First Moon Landing" };
    tm->events[tm->count++] = (struct Event){ 1989, "Fall of the Berlin Wall" };
    tm->events[tm->count++] = (struct Event){ 2000, "Y2K" };
    tm->events[tm->count++] = (struct Event){ 2023, "2023 Year of AI Advancements" };
}

void displayMenu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("1. Travel to a Specific Year\n");
    printf("2. List All Important Events\n");
    printf("3. Exit\n");
}

void travelToYear(struct TimeMachine *tm, int year) {
    int found = 0;
    for (int i = 0; i < tm->count; i++) {
        if (tm->events[i].year == year) {
            printf("Traveling to the year %d: %s\n", year, tm->events[i].description);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No significant events found for the year %d.\n", year);
    }
}

void listEvents(struct TimeMachine *tm) {
    printf("\n=== List of Important Events ===\n");
    for (int i = 0; i < tm->count; i++) {
        printf("%d: %s\n", tm->events[i].year, tm->events[i].description);
    }
}

int main() {
    struct TimeMachine myTimeMachine;
    int choice, year;

    initializeTimeMachine(&myTimeMachine);

    do {
        displayMenu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            choice = 0; // reset to continue loop
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to (%d - %d): ", MIN_YEAR, MAX_YEAR);
                if (scanf("%d", &year) != 1 || year < MIN_YEAR || year > MAX_YEAR) {
                    printf("Invalid year. Please try again.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                travelToYear(&myTimeMachine, year);
                break;
            case 2:
                listEvents(&myTimeMachine);
                break;
            case 3:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}