//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void timeTravel(int year, int month, int day);
int isValid(int year, int month, int day);

int main() {

    int year, month, day;

    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("Enter the year (yyyy) you want to time travel to: ");
    scanf("%d", &year);

    printf("Enter the month (mm) you want to time travel to: ");
    scanf("%d", &month);

    printf("Enter the day (dd) you want to time travel to: ");
    scanf("%d", &day);

    if (!isValid(year, month, day)) {
        printf("\nSorry, the date you entered is invalid.\n");
        exit(0);
    }

    printf("\nHold on tight, we're time traveling to %d/%d/%d!\n\n", month, day, year);

    timeTravel(year, month, day);

    printf("\nYou have arrived in %d/%d/%d!\n", month, day, year);

    return 0;
}

void timeTravel(int year, int month, int day) {

    printf("Initializing time travel...\n");

    // Code to simulate time travel
    // ...

    printf("Time travel successful!\n");
}

int isValid(int year, int month, int day) {

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return 0;

    // Code to validate dates
    // ...

    return 1;
}