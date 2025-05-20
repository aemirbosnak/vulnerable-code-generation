//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_YEARS 10
#define MAX_EVENT_LENGTH 256

typedef struct {
    int year;
    char event[MAX_EVENT_LENGTH];
} TimeTravelEvent;

TimeTravelEvent events[MAX_YEARS] = {
    {2023, "Launch of the new generation smartphone."},
    {2020, "World entered the COVID-19 pandemic."},
    {2019, "First image of a black hole released."},
    {2016, "UK voted to leave the European Union."},
    {2001, "September 11 attacks in the United States."},
    {1999, "Y2K scare as the year 2000 approached."},
    {1989, "Fall of the Berlin Wall."},
    {1969, "Apollo 11 lands on the Moon."},
    {1945, "End of World War II with the surrender of Japan."},
    {1776, "Declaration of Independence of the United States."}
};

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel to the following years:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d: Year %d\n", i + 1, events[i].year);
    }
    printf("Please choose a year (1-%d) to travel to (or 0 to exit): ", MAX_YEARS);
}

void travelToYear(int choice) {
    if (choice < 1 || choice > MAX_YEARS) {
        printf("Invalid choice. Please try again.\n");
        return;
    }
    
    int index = choice - 1;
    printf("Time traveling to the year %d...\n", events[index].year);
    printf("Notable event: %s\n", events[index].event);
}

int main() {
    int userChoice;

    while (1) {
        displayMenu();
        scanf("%d", &userChoice);

        if (userChoice == 0) {
            printf("Exiting the Time Travel Simulator. Safe travels!\n");
            break;
        }

        travelToYear(userChoice);
        printf("\n");
    }

    return 0;
}