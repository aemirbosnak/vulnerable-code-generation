//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

void displayDate(Date date) {
    printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
}

void travelToFuture(Date *currentDate, int years) {
    currentDate->year += years;
    printf("You have traveled to the future!\n");
    displayDate(*currentDate);
}

void travelToPast(Date *currentDate, int years) {
    currentDate->year -= years;
    printf("You have traveled to the past!\n");
    displayDate(*currentDate);
}

void simulateTimeTravel(Date *currentDate) {
    int choice, years;

    while (1) {
        printf("\nCurrent Date: ");
        displayDate(*currentDate);
        printf("Time Travel Simulator\n");
        printf("1. Travel to Future\n");
        printf("2. Travel to Past\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter years to travel to the future: ");
            scanf("%d", &years);
            travelToFuture(currentDate, years);
        } else if (choice == 2) {
            printf("Enter years to travel to the past: ");
            scanf("%d", &years);
            travelToPast(currentDate, years);
        } else if (choice == 3) {
            printf("Exiting the Time Travel Simulator. Safe travels!\n");
            break;
        } else {
            printf("Invalid choice. Please select again.\n");
        }
    }
}

int main() {
    Date currentDate;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    currentDate.year = tm.tm_year + 1900;
    currentDate.month = tm.tm_mon + 1;
    currentDate.day = tm.tm_mday;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today's date is: ");
    displayDate(currentDate);

    simulateTimeTravel(&currentDate);

    return 0;
}