//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime, futureTime; // Declare time variables
    struct tm *currentTm, *futureTm; // Declare tm structures

    // Get the current time
    currentTime = time(NULL);
    currentTm = localtime(&currentTime);

    // Print the current year
    printf("It is currently the year %d. ", currentTm->tm_year + 1900);

    // Get a future time to travel to
    printf("Where would you like to travel? Enter a year: ");
    int futureYear;
    scanf("%d", &futureYear);

    // Create a tm structure for the future time
    futureTm = localtime(&currentTime);
    futureTm->tm_year = futureYear - 1900;
    futureTm->tm_mday = 1;

    // Compute the difference in seconds between the current time and future time
    currentTime = mktime(currentTm);
    futureTime = mktime(futureTm);
    double secondsDifference = difftime(futureTime, currentTime);

    if (secondsDifference > 0) {
        printf("You are about to travel %ld years into the future!\n\n", (futureYear - (currentTm->tm_year + 1900)));
    } else if (secondsDifference < 0) {
        printf("You are about to travel %ld years into the past!\n\n", ((currentTm->tm_year + 1900) - futureYear));
    } else {
        printf("You are not traveling anywhere...\n");
        exit(0);
    }

    // Compute how many minutes, hours, days, weeks, and years are in the time difference
    int minutesDifference = (int) (secondsDifference / 60.0);
    int hoursDifference = (int) (secondsDifference / 3600.0);
    int daysDifference = (int) (secondsDifference / 86400.0);
    int weeksDifference = (int) (daysDifference / 7.0);
    int yearsDifference = futureYear - (currentTm->tm_year + 1900);

    printf("Time travel summary:\n");
    printf("---------------------\n");
    printf("%d minutes\n", minutesDifference);
    printf("%d hours\n", hoursDifference);
    printf("%d days\n", daysDifference);
    printf("%d weeks\n", weeksDifference);
    printf("%d years\n", yearsDifference);
    printf("---------------------\n");

    return 0;
}