//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Time Travel Simulator!\n");

    int currentYear = 2022;

    // prompt user for desired year
    printf("Enter the year you want to travel to: ");
    int desiredYear;
    scanf("%d", &desiredYear);

    // check if desired year is in the future or past
    if (desiredYear > currentYear) {
        // travel to future
        printf("Preparing to travel to year %d...\n", desiredYear);
        printf("3...2...1...Blast off!\n");

        // calculate the number of years to travel
        int yearsToTravel = desiredYear - currentYear;

        // wait for the time machine to travel
        printf("Travelling through time...\n");
        for (int i = 0; i < yearsToTravel; i++) {
            printf("Year %d...\n", currentYear + i + 1);
            // simulate time travel by sleeping for 1 second
            sleep(1);
        }

        // arrive at desired year
        printf("Arrived at year %d!\n", desiredYear);
        // do something amazing in the future
        printf("Wow, flying cars really do exist!\n");

    } else if (desiredYear < currentYear) {
        // travel to past
        printf("Preparing to travel to year %d...\n", desiredYear);
        printf("3...2...1...Blast off!\n");

        // calculate the number of years to travel
        int yearsToTravel = currentYear - desiredYear;

        // wait for the time machine to travel
        printf("Travelling through time...\n");
        for (int i = 0; i < yearsToTravel; i++) {
            printf("Year %d...\n", currentYear - i - 1);
            // simulate time travel by sleeping for 1 second
            sleep(1);
        }

        // arrive at desired year
        printf("Arrived at year %d!\n", desiredYear);
        // do something amazing in the past
        printf("I can't believe I'm seeing the first moon landing!\n");

    } else {
        // already in desired year
        printf("Congratulations, you're already in year %d!\n", currentYear);
        // do something fun in the present
        printf("I'm going to grab some pizza, want to join me?\n");
    }

    return 0;
}