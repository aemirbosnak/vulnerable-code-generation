//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 30
#define MAX_DATES 10

typedef struct {
    int year;
    char event[50];
} TimeEvent;

void showMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to the future\n");
    printf("2. Travel to the past\n");
    printf("3. View historical events\n");
    printf("4. Get back to the present\n");
    printf("5. Exit the simulator\n");
}

void travelToFuture(int currentYear) {
    int yearsToTravel;
    printf("How many years into the future do you want to travel? (up to %d)\n", MAX_YEARS);
    scanf("%d", &yearsToTravel);
    
    if (yearsToTravel > MAX_YEARS) {
        printf("Sorry, time travel malfunction! Must be less than or equal to %d.\n", MAX_YEARS);
        return;
    }
    
    printf("Bwoooooooom! You jumped %d years into the future!\n", yearsToTravel);
    printf("Welcome to the year %d!\n", currentYear + yearsToTravel);
}

void travelToPast(int currentYear) {
    int yearsToTravel;
    printf("How many years into the past do you want to travel? (up to %d)\n", MAX_YEARS);
    scanf("%d", &yearsToTravel);
    
    if (yearsToTravel > MAX_YEARS) {
        printf("Oops! Time travel failure! Must be less than or equal to %d.\n", MAX_YEARS);
        return;
    }
    
    printf("Zoooooooom! You've arrived in the year %d!\n", currentYear - yearsToTravel);
}

void viewHistoricalEvents(TimeEvent *events, int totalEvents) {
    printf("Here's a list of fascinating historical events!\n");
    for (int i = 0; i < totalEvents; i++) {
        printf("Year %d: %s\n", events[i].year, events[i].event);
    }
}

void getBackToPresent(int *currentYear) {
    printf("Reverting back to the present time... Whoosh!\n");
    printf("You're back in the year %d!\n", *currentYear);
}

int main() {
    TimeEvent events[MAX_DATES] = {
        { 1969, "Man first landed on the moon!" },
        { 1776, "Declaration of Independence signed." },
        { 1989, "Fall of the Berlin Wall." },
        { 1999, "Y2K panic begins." },
        { 2021, "People finally learned to cook banana bread." }
    };
    
    int currentYear = 2023;
    int choice;
    
    while (1) {
        showMenu();
        printf("What would you like to do? ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                travelToFuture(currentYear);
                break;
            case 2:
                travelToPast(currentYear);
                break;
            case 3:
                viewHistoricalEvents(events, sizeof(events) / sizeof(TimeEvent));
                break;
            case 4:
                getBackToPresent(&currentYear);
                break;
            case 5:
                printf("Thanks for time traveling! See you in the future (or past!)\n");
                exit(0);
            default:
                printf("Sorry, that's not a valid option. Try time traveling in a better way!\n");
        }
        
        printf("\n");
    }
    
    return 0;
}