//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travelToPast(int years) {
    time_t rawtime;
    struct tm * timeinfo;
    int currentYear, pastYear;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    currentYear = timeinfo->tm_year + 1900;
    pastYear = currentYear - years;

    printf("\nTraveling back in time to %d...\n\n", pastYear);

    for (int i = currentYear; i >= pastYear; i--) {
        printf("Year: %d\n", i);
        sleep(1);
    }

    printf("\nArrived in %d!\n", pastYear);
}

void travelToFuture(int years) {
    time_t rawtime;
    struct tm * timeinfo;
    int currentYear, futureYear;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    currentYear = timeinfo->tm_year + 1900;
    futureYear = currentYear + years;

    printf("\nTraveling to the future, year %d...\n\n", futureYear);

    for (int i = currentYear; i <= futureYear; i++) {
        printf("Year: %d\n", i);
        sleep(1);
    }

    printf("\nArrived in %d!\n", futureYear);
}

int main() {
    int choice, years;

    printf("\nWelcome to the Time Travel Simulator!\n");
    printf("Choose an option:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("0. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("\nGoodbye!\n");
        return 0;
    } else if (choice == 1) {
        printf("Enter the number of years to travel back: ");
        scanf("%d", &years);
        travelToPast(years);
    } else if (choice == 2) {
        printf("Enter the number of years to travel ahead: ");
        scanf("%d", &years);
        travelToFuture(years);
    } else {
        printf("\nInvalid choice, exiting...\n");
        return 0;
    }

    return 0;
}