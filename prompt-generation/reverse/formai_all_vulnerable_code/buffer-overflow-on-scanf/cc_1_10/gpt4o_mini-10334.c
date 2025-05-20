//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEARS 5

typedef struct {
    int year;
    char event[100];
} TimePeriod;

void show_menu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. Show Time Periods\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

void travel_past(TimePeriod *timePeriods) {
    int choice;
    printf("\nChoose a year to travel back to:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d. %d - %s\n", i + 1, timePeriods[i].year, timePeriods[i].event);
    }
    printf("Enter your choice (1-%d): ", MAX_YEARS);
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_YEARS) {
        printf("Invalid choice!\n");
        return;
    }
    printf("You have traveled to %d: %s\n", timePeriods[choice - 1].year, timePeriods[choice - 1].event);
}

void travel_future() {
    int year;
    printf("\nEnter a year in the future to travel to (greater than current year): ");
    scanf("%d", &year);
    if (year > 2023) {
        printf("You have traveled to the year %d (A time of technological advancements)!\n", year);
    } else {
        printf("Invalid year! Please enter a year greater than 2023.\n");
    }
}

void show_time_periods(TimePeriod *timePeriods) {
    printf("\n--- Time Periods ---\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d. %d - %s\n", i + 1, timePeriods[i].year, timePeriods[i].event);
    }
}

int main() {
    TimePeriod timePeriods[MAX_YEARS] = {
        { 490, "Battle of Marathon" },
        { 1066, "Norman Conquest" },
        { 1776, "American Declaration of Independence" },
        { 1969, "Apollo 11 Moon Landing" },
        { 1989, "Fall of the Berlin Wall" }
    };

    int option;
    while (1) {
        show_menu();
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                travel_past(timePeriods);
                break;
            case 2:
                travel_future();
                break;
            case 3:
                show_time_periods(timePeriods);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}