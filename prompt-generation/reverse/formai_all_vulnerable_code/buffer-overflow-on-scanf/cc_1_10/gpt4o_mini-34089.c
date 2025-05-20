//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_TRAVEL_OPTIONS 5

typedef struct {
    char* name;
    int year;
    char* description;
} HistoricalEvent;

void displayMenu();
void travelTime(int* currentYear);
void travelToYear(int* currentYear, int year);
void displayEvent(HistoricalEvent event);
void greet();

HistoricalEvent events[] = {
    {"The Declaration of Independence", 1776, "The thirteen American colonies declared their independence from Great Britain."},
    {"First Moon Landing", 1969, "Apollo 11 landed the first humans on the Moon."},
    {"Fall of the Berlin Wall", 1989, "The Berlin Wall, which divided East and West Berlin, fell."},
    {"World Wide Web Created", 1989, "Tim Berners-Lee proposed the World Wide Web."},
    {"COVID-19 Pandemic Begins", 2019, "The COVID-19 pandemic begins globally."}
};

int main() {
    int currentYear = 2024; // Setting the current year
    greet();
    while (1) {
        displayMenu();
        travelTime(&currentYear);
    }
    return 0;
}

void greet() {
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("You can travel to various historical events and learn more about them.\n");
}

void displayMenu() {
    printf("\nCurrent Year: %d\n", 2024);
    printf("Where would you like to travel?\n");
    printf("1. %s (%d)\n", events[0].name, events[0].year);
    printf("2. %s (%d)\n", events[1].name, events[1].year);
    printf("3. %s (%d)\n", events[2].name, events[2].year);
    printf("4. %s (%d)\n", events[3].name, events[3].year);
    printf("5. %s (%d)\n", events[4].name, events[4].year);
    printf("6. Exit\n");
    printf("Please enter the number of your choice: ");
}

void travelTime(int* currentYear) {
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            travelToYear(currentYear, events[0].year);
            break;
        case 2:
            travelToYear(currentYear, events[1].year);
            break;
        case 3:
            travelToYear(currentYear, events[2].year);
            break;
        case 4:
            travelToYear(currentYear, events[3].year);
            break;
        case 5:
            travelToYear(currentYear, events[4].year);
            break;
        case 6:
            printf("Thank you for using the C Time Travel Simulator. Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid option! Please choose again.\n");
            break;
    }
}

void travelToYear(int* currentYear, int year) {
    printf("\nTraveling from %d to %d...\n", *currentYear, year);
    *currentYear = year; // Update current year to the year traveled to
    for (int i = 0; i <= 5; i++) { // Simple delay to mimic time travel
        printf(".");
        fflush(stdout);
        struct timespec ts = {0, 500000000}; // 0.5 seconds delay
        nanosleep(&ts, NULL);
    }
    printf("\nYou have arrived in the year %d!\n", *currentYear);
    for (int i = 0; i < TIME_TRAVEL_OPTIONS; i++) {
        if (events[i].year == year) {
            displayEvent(events[i]);
            break;
        }
    }
}

void displayEvent(HistoricalEvent event) {
    printf("Event: %s\n", event.name);
    printf("Year: %d\n", event.year);
    printf("Description: %s\n", event.description);
}