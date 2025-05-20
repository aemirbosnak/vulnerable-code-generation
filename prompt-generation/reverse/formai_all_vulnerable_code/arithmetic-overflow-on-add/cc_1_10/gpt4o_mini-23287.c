//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIALS 5
#define YEAR_BASE 2023
#define YEAR_MIN 1900
#define YEAR_MAX 2100

typedef struct {
    int year;
    int month;
    int day;
} Date;

void displayMenu() {
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. Show Current Date\n");
    printf("4. Exit\n");
}

void getCurrentDate(Date* currentDate) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    currentDate->year = tm.tm_year + 1900;
    currentDate->month = tm.tm_mon + 1;
    currentDate->day = tm.tm_mday;
}

void travelToPast() {
    int years;
    printf("Enter number of years to travel to the past (up to %d): ", YEAR_BASE - YEAR_MIN);
    scanf("%d", &years);
    if (years < 1 || years > (YEAR_BASE - YEAR_MIN)) {
        printf("Invalid number of years.\n");
        return;
    }

    printf("You traveled to the year %d!\n", YEAR_BASE - years);
}

void travelToFuture() {
    int years;
    printf("Enter number of years to travel to the future (up to %d): ", YEAR_MAX - YEAR_BASE);
    scanf("%d", &years);
    if (years < 1 || years > (YEAR_MAX - YEAR_BASE)) {
        printf("Invalid number of years.\n");
        return;
    }

    printf("You traveled to the year %d!\n", YEAR_BASE + years);
}

void showCurrentDate() {
    Date currentDate;
    getCurrentDate(&currentDate);
    printf("Current Date: %04d-%02d-%02d\n", currentDate.year, currentDate.month, currentDate.day);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                travelToPast();
                break;
            case 2:
                travelToFuture();
                break;
            case 3:
                showCurrentDate();
                break;
            case 4:
                printf("Exiting the simulator. Safe travels!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
        printf("\n");
    }
    return 0;
}