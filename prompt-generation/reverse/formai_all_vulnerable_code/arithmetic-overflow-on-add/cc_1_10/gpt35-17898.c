//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Time Travel Simulator!\n");

    // Get the current year
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    int currentYear = currentTime->tm_year + 1900;

    // Prompt the user to enter a year to travel to
    int desiredYear;
    printf("Which year do you want to travel to? (Enter an integer between 1900 and %d): ", currentYear + 100);
    scanf("%d", &desiredYear);

    // Make sure the desired year is within range
    if (desiredYear < 1900 || desiredYear > currentYear + 100) {
        printf("Sorry, that year is out of range.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the number of years to travel
    int yearsToTravel = abs(desiredYear - currentYear);

    // Prompt the user to enter how they want to travel: DeLorean or TARDIS
    char modeOfTransport[10];
    printf("How do you want to travel, DeLorean or TARDIS? ");
    scanf("%s", modeOfTransport);

    // Check for valid mode of transport
    if (strcmp(modeOfTransport, "DeLorean") != 0 && strcmp(modeOfTransport, "TARDIS") != 0) {
        printf("Sorry, that mode of transport is not available.\n");
        exit(EXIT_FAILURE);
    }

    // Display travel details
    printf("Great, you will be travelling %d years into the %s.\n", yearsToTravel, (desiredYear > currentYear) ? "future" : "past");
    printf("You will be travelling in a %s.\n", modeOfTransport);

    // Simulate time travel
    printf("Hold on tight, we are travelling through time!\n");
    for (int i = 0; i < yearsToTravel; i++) {
        printf("Year %d...\n", currentYear + i + 1);
    }

    // Arrive at selected year
    printf("Welcome to %d! You have arrived safely.\n", desiredYear);

    // Exit program
    printf("Thanks for using the Time Travel Simulator. Have a great day!\n");

    return 0;
}