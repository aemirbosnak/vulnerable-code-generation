//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t = time(NULL); // get current time in seconds
    struct tm tm = *localtime(&t); // convert to struct

    printf("Welcome to our Time Travel Simulator!\n\n");

    printf("Today's date is %d/%d/%d.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    int year;
    printf("Please enter the year you wish to travel to: ");
    scanf("%d", &year);

    // calculate if the entered year is in the past or future
    char* direction;
    if (year < tm.tm_year + 1900) {
        direction = "in the past, ";
    } else if (year > tm.tm_year + 1900) {
        direction = "in the future, ";
    } else {
        direction = "";
    }

    // randomly generate the month and day
    int month = (rand() % 12) + 1;
    int day = (rand() % 31) + 1;

    // set the time for the chosen date
    struct tm travel_tm = { .tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = day };
    time_t travel_time = mktime(&travel_tm);

    // format the date
    char travel_date[11];
    strftime(travel_date, 11, "%d/%m/%Y", &travel_tm);

    printf("\nYou will be traveling %sto %s.\n", direction, travel_date);

    // wait for user to confirm travel
    char answer;
    printf("Are you ready to travel? (Y/N) ");
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y') {
        printf("\nYou have traveled through time!\n");

        // wait for user to return to present time
        printf("Press Enter to return to the present.");
        getchar();
        getchar();

        printf("\nWelcome back to the present!\n");
    } else {
        printf("\nYou have chosen not to travel through time.");
    }

    return 0;
}