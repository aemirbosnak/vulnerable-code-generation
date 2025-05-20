//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 5

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char location[50];
} TimeTravel;

int main() {
    int numTimeTravels, i;
    TimeTravel timeTravels[MAX_TIME_TRAVELS];
    char choice;

    printf("Welcome to the Time Travel Simulator!\n");

    // get number of time travels from user
    printf("How many time travels would you like to record? (up to %d): ", MAX_TIME_TRAVELS);
    scanf("%d", &numTimeTravels);

    // get time travel details from user
    for (i = 0; i < numTimeTravels; i++) {
        printf("\nEnter the details for time travel #%d:\n", i+1);
        printf("Year: ");
        scanf("%d", &timeTravels[i].year);
        printf("Month: ");
        scanf("%d", &timeTravels[i].month);
        printf("Day: ");
        scanf("%d", &timeTravels[i].day);
        printf("Hour: ");
        scanf("%d", &timeTravels[i].hour);
        printf("Minute: ");
        scanf("%d", &timeTravels[i].minute);
        printf("Second: ");
        scanf("%d", &timeTravels[i].second);
        printf("Location: ");
        scanf("%s", timeTravels[i].location);
    }

    // display time travel details
    printf("\nTime Travel Details:\n");
    for (i = 0; i < numTimeTravels; i++) {
        printf("Time Travel #%d:\n", i+1);
        printf("Year: %d\n", timeTravels[i].year);
        printf("Month: %d\n", timeTravels[i].month);
        printf("Day: %d\n", timeTravels[i].day);
        printf("Hour: %d\n", timeTravels[i].hour);
        printf("Minute: %d\n", timeTravels[i].minute);
        printf("Second: %d\n", timeTravels[i].second);
        printf("Location: %s\n\n", timeTravels[i].location);
    }

    // ask user if they want to time travel
    printf("\nDo you want to time travel? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // TODO: implement time travel simulation
    }

    return 0;
}