//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_YEARS 5
#define MAX_PERIOD_DESC 100

// Define a structure for a time travel period
typedef struct {
    int year;
    char description[MAX_PERIOD_DESC];
} TimePeriod;

TimePeriod timePeriods[MAX_YEARS] = {
    { 1776, "American Declaration of Independence is signed." },
    { 1888, "Jack the Ripper commits his crimes in London." },
    { 1969, "Humans land on the Moon during Apollo 11 mission." },
    { 1989, "The Berlin Wall falls, symbolizing the end of the Cold War." },
    { 2023, "Advancements in AI lead to unprecedented innovations." }
};

void displayWelcomeMessage() {
    printf("===================================\n");
    printf("    Welcome to the Time Travel Simulator!\n");
    printf("===================================\n");
}

void displayTimePeriods() {
    printf("Please choose a year from the following list:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf(" [%d] %d\n", i + 1, timePeriods[i].year);
    }
    printf(" [0] Exit\n");
}

void travelToTimePeriod(int choice) {
    if (choice > 0 && choice <= MAX_YEARS) {
        printf("Time Traveling to the year %d...\n", timePeriods[choice - 1].year);
        printf("Event: %s\n", timePeriods[choice - 1].description);
    } else if (choice == 0) {
        printf("Exiting the Time Travel Simulator. Safe travels!\n");
    } else {
        printf("Invalid choice. Please choose a valid year.\n");
    }
}

int main() {
    int choice;

    displayWelcomeMessage();

    do {
        displayTimePeriods();
        printf("Your choice: ");
        scanf("%d", &choice);
        travelToTimePeriod(choice);
        printf("\n");
    } while (choice != 0);

    return 0;
}