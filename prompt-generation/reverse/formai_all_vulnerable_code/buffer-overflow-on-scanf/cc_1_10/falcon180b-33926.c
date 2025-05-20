//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
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
    int currentTimeTravel = 0;
    int choice;

    srand(time(NULL));

    do {
        printf("Welcome to the Post-Apocalyptic Time Travel Simulator!\n");
        printf("You have %d time travels left.\n", MAX_TIME_TRAVELS - currentTimeTravel);
        printf("What would you like to do?\n");
        printf("1. Travel to a random time\n");
        printf("2. Set a specific time to travel to\n");
        printf("3. View remaining time travels\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                timeTravels[currentTimeTravel].year = rand() % 1000 + 1;
                timeTravels[currentTimeTravel].month = rand() % 12 + 1;
                timeTravels[currentTimeTravel].day = rand() % 28 + 1;
                timeTravels[currentTimeTravel].hour = rand() % 24;
                timeTravels[currentTimeTravel].minute = rand() % 60;
                timeTravels[currentTimeTravel].second = rand() % 60;
                currentTimeTravel++;
                printf("You have traveled to the year %d.\n", timeTravels[currentTimeTravel-1].year);
                break;
            case 2:
                printf("Enter the year: ");
                scanf("%d", &timeTravels[currentTimeTravel].year);
                printf("Enter the month: ");
                scanf("%d", &timeTravels[currentTimeTravel].month);
                printf("Enter the day: ");
                scanf("%d", &timeTravels[currentTimeTravel].day);
                printf("Enter the hour: ");
                scanf("%d", &timeTravels[currentTimeTravel].hour);
                printf("Enter the minute: ");
                scanf("%d", &timeTravels[currentTimeTravel].minute);
                printf("Enter the second: ");
                scanf("%d", &timeTravels[currentTimeTravel].second);
                currentTimeTravel++;
                printf("You have set a time travel to the year %d.\n", timeTravels[currentTimeTravel-1].year);
                break;
            case 3:
                printf("You have %d time travels left.\n", MAX_TIME_TRAVELS - currentTimeTravel);
                break;
            case 4:
                printf("Thank you for using the Post-Apocalyptic Time Travel Simulator!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(currentTimeTravel < MAX_TIME_TRAVELS);

    return 0;
}