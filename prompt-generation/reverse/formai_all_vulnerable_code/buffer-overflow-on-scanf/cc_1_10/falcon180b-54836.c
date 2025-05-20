//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravel;

int main() {
    int numTimeTravels;
    TimeTravel timeTravels[MAX_TIME_TRAVELS];
    int i;
    int choice;

    srand(time(NULL));
    numTimeTravels = rand() % MAX_TIME_TRAVELS + 1;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You have %d time travels available.\n", numTimeTravels);

    for (i = 0; i < numTimeTravels; i++) {
        timeTravels[i].year = rand() % 1000 + 1;
        timeTravels[i].month = rand() % 12 + 1;
        timeTravels[i].day = rand() % 28 + 1;
        timeTravels[i].hour = rand() % 24;
        timeTravels[i].minute = rand() % 60;
        timeTravels[i].second = rand() % 60;

        printf("Time Travel %d:\n", i + 1);
        printf("Year: %d\n", timeTravels[i].year);
        printf("Month: %d\n", timeTravels[i].month);
        printf("Day: %d\n", timeTravels[i].day);
        printf("Hour: %d\n", timeTravels[i].hour);
        printf("Minute: %d\n", timeTravels[i].minute);
        printf("Second: %d\n", timeTravels[i].second);
        printf("\n");
    }

    do {
        printf("Enter the number of the time travel you want to take: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= numTimeTravels) {
            printf("You are now traveling through time to the year %d...\n", timeTravels[choice - 1].year);
            printf("3...2...1...\n");
            printf("You have arrived in the year %d!\n", timeTravels[choice - 1].year);
        } else {
            printf("Invalid choice.\n");
        }

        printf("Do you want to take another time travel? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}