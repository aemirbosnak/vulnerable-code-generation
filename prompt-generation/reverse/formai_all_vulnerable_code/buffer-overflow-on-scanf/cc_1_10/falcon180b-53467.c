//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31

struct date {
    int year;
    int month;
    int day;
};

void time_travel(struct date *date) {
    printf("Entering time machine...\n");
    sleep(1);
    printf("Time travel initiated.\n");
    sleep(2);
    printf("Arriving in %d...\n", date->year);
    sleep(1);
    printf("Welcome to the future/past!\n");
}

int main() {
    struct date date;
    int choice;

    srand(time(NULL));
    date.year = rand() % MAX_YEAR + 1;
    date.month = rand() % MAX_MONTH + 1;
    date.day = rand() % MAX_DAY + 1;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Today's date is: %d-%d-%d\n", date.year, date.month, date.day);

    do {
        printf("\nWhere would you like to go?\n");
        printf("1. Future\n2. Past\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to (between %d and %d): ", date.year, MAX_YEAR);
                scanf("%d", &date.year);
                time_travel(&date);
                break;
            case 2:
                printf("Enter the year you want to travel to (between 1 and %d): ", date.year - 1);
                scanf("%d", &date.year);
                time_travel(&date);
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}