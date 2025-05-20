//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define YEAR_MIN 1900
#define YEAR_MAX 2100

typedef struct {
    int day;
    int month;
    int year;
} Date;

void displayDate(Date date) {
    printf("Current Date: %02d/%02d/%04d\n", date.day, date.month, date.year);
}

void travelToDate(Date *current, Date target) {
    if (target.year < YEAR_MIN || target.year > YEAR_MAX) {
        printf("Date out of allowable range (1900-2100). Please try again.\n");
        return;
    }
    *current = target;
    printf("Time travel successful!\n");
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

void travelToFuture(Date *current, int years) {
    current->year += years;
    if (current->year > YEAR_MAX) {
        current->year = YEAR_MAX;
    }
    printf("You have traveled %d years into the future...\n", years);
}

void travelToPast(Date *current, int years) {
    current->year -= years;
    if (current->year < YEAR_MIN) {
        current->year = YEAR_MIN;
    }
    printf("You have traveled %d years into the past...\n", years);
}

void promptUser() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel to a specific date or to the future/past.\n");
}

Date getUserDate() {
    Date target;
    printf("Enter target date (dd mm yyyy): ");
    scanf("%d %d %d", &target.day, &target.month, &target.year);
    return target;
}

void travelOptions(Date *current) {
    int choice, years;
    Date target;

    printf("Choose a travel option:\n");
    printf("1. Travel to a specific date.\n");
    printf("2. Travel into the future.\n");
    printf("3. Travel into the past.\n");
    printf("4. Exit the simulator.\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            target = getUserDate();
            travelToDate(current, target);
            break;
        case 2:
            printf("How many years into the future? ");
            scanf("%d", &years);
            travelToFuture(current, years);
            break;
        case 3:
            printf("How many years into the past? ");
            scanf("%d", &years);
            travelToPast(current, years);
            break;
        case 4:
            printf("Exiting the simulator. Thank you for using Time Travel Simulator! Goodbye.\n");
            exit(0);
        default:
            printf("Invalid option! Please select again.\n");
    }
}

int main() {
    Date currentDate = {1, 1, 2023}; // Start date
    char continuePrompt;

    promptUser();

    do {
        displayDate(currentDate);
        travelOptions(&currentDate);
        printf("\nDo you want to make another trip? (y/n): ");
        scanf(" %c", &continuePrompt);
    } while (continuePrompt == 'y' || continuePrompt == 'Y');

    printf("Thank you for using Time Travel Simulator! Goodbye!\n");
    return 0;
}