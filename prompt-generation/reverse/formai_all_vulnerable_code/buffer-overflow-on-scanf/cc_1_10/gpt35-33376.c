//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random generator with current time

    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("You are currently in the year 2021.\n");

    int targetYear = 0;

    while (targetYear < 2021) {
        printf("Enter the year you would like to travel to (must be after 2021): ");
        scanf("%d", &targetYear);
        if (targetYear < 2021) {
            printf("Invalid year entered. Please enter a year after 2021.\n");
        }
    }

    printf("Traveling to year %d...\n", targetYear);

    while (targetYear > 2021) {
        // Every year you travel, there's a 10% chance of an unexpected event happening
        if (rand() % 10 == 0) {
            int unexpectedYear = rand() % (targetYear - 2021) + 2021;
            printf("Oops! While traveling to the year %d, you got unexpectedly sent to %d instead.\n", targetYear, unexpectedYear);
            targetYear = unexpectedYear;
        }
        else {
            printf("Traveling to year %d...\n", targetYear - 1);
            targetYear--;
        }
    }

    printf("You have arrived in the year %d!\n", targetYear);

    // Let's print out some interesting historical events that happened in the chosen year
    switch (targetYear) {
        case 2021:
            printf("\nSome notable events that happened this year:\n");
            printf("  - COVID-19 was declared a global pandemic\n");
            printf("  - Joe Biden was inaugurated as the 46th President of the United States\n");
            printf("  - SpaceX successfully launched humans into orbit for the first time\n");
            break;
        case 2022:
            printf("\nSome notable events that happened this year:\n");
            printf("  - The Winter Olympics were held in Beijing, China\n");
            printf("  - The first human head transplant was successfully performed\n");
            printf("  - Bitcoin reached an all-time high of $100,000\n");
            break;
        case 2023:
            printf("\nSome notable events that happened this year:\n");
            printf("  - The final season of Game of Thrones was released\n");
            printf("  - The first manned mission to Mars was launched\n");
            printf("  - The world's first commercially available flying car was released\n");
            break;
        default:
            printf("\nSorry, no historical events to report for this year.\n");
    }

    printf("\nThank you for using the Time Travel Simulator!\n");

    return 0;
}