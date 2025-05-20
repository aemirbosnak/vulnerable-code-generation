//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\nWelcome to the Grateful Time Travel Simulator!\n");

    // Get current time
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);

    // Ask user for a year to travel to
    int target_year;
    printf("\nPlease enter a year to travel to (after 1900): ");
    scanf("%d", &target_year);

    // Calculate time difference
    int years_difference = target_year - 1900;
    time_t target_time = now + (years_difference * 31536000); // seconds in a year

    // Convert target time to struct tm
    struct tm *target_tm = localtime(&target_time);

    // Print time travel summary
    printf("\nYou are traveling from %d to %d.\n", now_tm->tm_year + 1900, target_year);
    printf("The time difference is %d years.\n", years_difference);

    // Ask user to confirm time travel
    printf("\nAre you ready to travel through space and time? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'y')
    {
        printf("\nHold on tight, time traveler!\n");
        printf("3... 2... 1...\n");
        printf("Blast off!!\n");

        // Wait for 3 seconds before "arriving" at target time
        for (int i = 3; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1);
        }

        printf("Welcome to the year %d!\n", target_tm->tm_year + 1900);
    }
    else
    {
        printf("\nTime travel canceled. Maybe next time, adventurer.\n");
    }

    return 0;
}
