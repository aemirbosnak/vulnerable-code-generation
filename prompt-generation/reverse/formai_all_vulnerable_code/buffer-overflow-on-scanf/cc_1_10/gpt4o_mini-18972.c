//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAVELS 10
#define CURRENT_YEAR 2023

struct TimeTravel {
    int year;
    char event[256];
    char location[100];
};

void displayMenu() {
    printf("\n*** Time Travel Simulator ***\n");
    printf("1. Travel to a specific year\n");
    printf("2. View all time travels\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

void travelToYear(struct TimeTravel travels[], int *count) {
    if (*count >= MAX_TRAVELS) {
        printf("Travel limit reached! Clear some past travels first.\n");
        return;
    }
    
    int year;
    char event[256];
    char location[100];
    
    printf("Enter year to travel (e.g., 1492, 1776): ");
    scanf("%d", &year);
    if (year >= CURRENT_YEAR - 1000 && year <= CURRENT_YEAR + 1000) {
        printf("Enter a significant event in %d: ", year);
        scanf(" %[^\n]", event);
        printf("Enter location of the event: ");
        scanf(" %[^\n]", location);
        
        travels[*count].year = year;
        snprintf(travels[*count].event, sizeof(travels[*count].event), "%s", event);
        snprintf(travels[*count].location, sizeof(travels[*count].location), "%s", location);
        (*count)++;
        
        printf("Successfully traveled to %d! Event logged.\n", year);
    } else {
        printf("Year is out of allowable range!\n");
    }
}

void viewTravels(struct TimeTravel travels[], int count) {
    if (count == 0) {
        printf("No time travels recorded.\n");
        return;
    }

    printf("\n*** Your Time Travels ***\n");
    for (int i = 0; i < count; i++) {
        printf("Travel %d: Year: %d, Event: %s, Location: %s\n", 
               i + 1, travels[i].year, travels[i].event, travels[i].location);
    }
}

void clearTravels(struct TimeTravel travels[], int *count) {
    *count = 0;
    printf("All recorded time travels cleared.\n");
}

int main() {
    struct TimeTravel travels[MAX_TRAVELS];
    int travelCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToYear(travels, &travelCount);
                break;
            case 2:
                viewTravels(travels, travelCount);
                break;
            case 3:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}