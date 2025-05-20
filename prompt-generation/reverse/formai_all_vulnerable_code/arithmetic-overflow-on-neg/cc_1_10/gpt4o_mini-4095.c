//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 5000
#define CURRENT_YEAR 2023

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date currentDate;

void initializeCurrentDate() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    currentDate.day = t->tm_mday;
    currentDate.month = t->tm_mon + 1;
    currentDate.year = t->tm_year + 1900;
}

void displayCurrentDate() {
    printf("Current Date: %02d/%02d/%04d\n", currentDate.day, currentDate.month, currentDate.year);
}

void travelInTime(int years) {
    if (years < -MAX_YEARS || years > MAX_YEARS) {
        printf("Time travel limit exceeded!\n");
        return;
    }
    currentDate.year += years;
    if (currentDate.year < 0) {
        printf("That would take you to before recorded history!\n");
        currentDate.year = 0; // Set to year 0 in case of going too far back
    }
    printf("You have time traveled %d years.\n", years);
}

void displayTimeTravelOptions() {
    printf("Time Travel Options:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Exit\n");
}

int main() {
    int choice, years;

    initializeCurrentDate();
    displayCurrentDate();

    do {
        displayTimeTravelOptions();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of years to travel to the past: ");
                scanf("%d", &years);
                travelInTime(-years);
                break;
            case 2:
                printf("Enter the number of years to travel to the future: ");
                scanf("%d", &years);
                travelInTime(years);
                break;
            case 3:
                printf("Exiting the Time Travel Simulator.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        if (choice != 3) {
            displayCurrentDate();
        }

    } while (choice != 3);

    return 0;
}