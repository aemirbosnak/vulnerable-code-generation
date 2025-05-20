//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void travel(int year) {
    time_t t;
    struct tm * tm;
    char buffer[80];

    t = time(NULL);
    tm = localtime(&t);

    tm->tm_year = year - 1900;

    mktime(tm);

    strftime(buffer, sizeof(buffer), "%c", tm);

    printf("You have arrived in the year %d: %s\n", year, buffer);
}

int main() {
    int choice = 0;

    while (choice != 4) {
        printf("----------\n");
        printf("Time travel menu\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Travel to a specific year\n");
        printf("4. Exit\n");
        printf("----------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many years back would you like to travel? ");
                int yearsPast;
                scanf("%d", &yearsPast);
                travel(1900 + yearsPast);
                break;
            case 2:
                printf("How many years ahead would you like to travel? ");
                int yearsFuture;
                scanf("%d", &yearsFuture);
                travel(1900 + yearsFuture);
                break;
            case 3:
                printf("What year would you like to travel to? ");
                int specificYear;
                scanf("%d", &specificYear);
                travel(specificYear);
                break;
            case 4:
                printf("Thank you for using the time travel simulator.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }

    return 0;
}