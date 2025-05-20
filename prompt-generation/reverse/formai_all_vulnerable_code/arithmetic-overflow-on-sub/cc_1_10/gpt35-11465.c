//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t presentTime;
    time(&presentTime);

    struct tm* localTime = localtime(&presentTime);

    printf("Present Time: %s", asctime(localTime));

    // Time machine activated
    printf("\nTime machine activated. Enter the year (yyyy) to travel to: ");
    int year;
    scanf("%d", &year);

    // Checking if the year is in the past or future
    if (year >= localTime->tm_year + 1900) {
        printf("\nSorry, you can only travel to the past.\n");
        return 0;
    }

    // Adjusting struct tm for the entered year
    localTime->tm_year = year - 1900;
    localTime->tm_mday = 1;
    localTime->tm_mon = 0;
    localTime->tm_sec = 0;
    localTime->tm_min = 0;
    localTime->tm_hour = 0;

    // Converting the struct tm to time_t
    time_t travelTime = mktime(localTime);

    // Printing the year we traveled to
    printf("\nWelcome to the year %d!\n\n", year);

    // Time travel simulation begins
    for (int i = 1; i <= 12; i++) {
        // Adjusting the struct tm for each month
        localTime->tm_mon = i - 1;

        // Converting the struct tm to time_t
        time_t monthTime = mktime(localTime);

        // Printing the month and year
        printf("%s", asctime(localtime(localtime)));

        // Sleeping for 1 second to simulate actual time travel
        sleep(1);
    }

    printf("\nYou have successfully completed your time travel simulation! Returning to the present time...\n");

    // Waiting for 3 seconds to simulate time machine deactivation
    sleep(3);

    // Printing the present time
    time(&presentTime);
    printf("\nPresent Time: %s", asctime(localtime(localtime)));

    return 0;
}