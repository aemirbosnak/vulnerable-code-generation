//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEARS 10

typedef struct {
    int year;
    char event[100];
} TimeTravelEvent;

TimeTravelEvent timeEvents[MAX_YEARS] = {
    { 1066, "The Battle of Hastings occurs, marking the start of Norman rule in England." },
    { 1492, "Christopher Columbus reaches the Americas." },
    { 1776, "The Declaration of Independence is signed in the United States." },
    { 1865, "The American Civil War ends after the defeat of the Confederacy." },
    { 1969, "Apollo 11 successfully lands the first humans on the Moon." },
    { 1989, "The Berlin Wall falls, marking the end of the Cold War." },
    { 2001, "Wikipedia is launched, revolutionizing the way we access information." },
    { 2008, "The global financial crisis occurs, impacting economies worldwide." },
    { 2020, "The COVID-19 pandemic affects people and economies across the globe." },
    { 2021, "The first successful mRNA COVID-19 vaccines are administered worldwide." }
};

void displayMenu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("Available Years to Travel:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d: %d\n", i + 1, timeEvents[i].year);
    }
    printf("Enter 0 to return to the present time.\n");
    printf("Choose a year to travel to (1-%d): ", MAX_YEARS);
}

void travelToYear(int choice) {
    if (choice == 0) {
        printf("You have returned to the present time.\n");
    } else if (choice > 0 && choice <= MAX_YEARS) {
        int index = choice - 1;
        printf("Traveling to the year %d...\n", timeEvents[index].year);
        printf("Event: %s\n", timeEvents[index].event);
    } else {
        printf("Invalid choice! Try again.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Explore significant events in history by traveling to different years.\n");

    do {
        displayMenu();
        scanf("%d", &choice);
        travelToYear(choice);
    } while (choice != 0);

    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}