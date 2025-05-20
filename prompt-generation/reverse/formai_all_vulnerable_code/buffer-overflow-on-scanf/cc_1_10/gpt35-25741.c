//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Time Travel Simulator!\n");

    // Get current time
    time_t t = time(NULL);
    struct tm current_time = *localtime(&t);

    // Set the starting point to 2060
    struct tm time_travel = {
        .tm_sec = 0,
        .tm_min = 0,
        .tm_hour = 0,
        .tm_mday = 1,
        .tm_mon = 0,
        .tm_year = 160,
        .tm_wday = 0,
        .tm_yday = 0,
        .tm_isdst = -1
    };

    // Set time zone to Cyberpunk City
    char *tz = "CST-8";
    setenv("TZ", tz, 1);
    tzset();

    printf("You are now in Cyberpunk City, year 2060.\n");

    // Main loop
    while (1) {
        printf("What would you like to do? (type 'help' for a list of commands)\n");

        char input[50];
        scanf("%s", input);

        // Help command
        if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  time - display current time\n");
            printf("  travel [year] - travel to specified year\n");
            printf("  exit - exit the simulator\n");
        }

        // Time command
        else if (strcmp(input, "time") == 0) {
            time_t t = time(NULL);
            struct tm current_time = *localtime(&t);

            printf("Current time: %s", asctime(&current_time));
        }

        // Travel command
        else if (strcmp(input, "travel") == 0) {
            int year;
            scanf("%d", &year);

            // Check if travel to the past or future
            if (year < current_time.tm_year + 1900) {
                printf("You can\'t travel to the past!\n");
            } else if (year > 2100) {
                printf("That year is beyond the scope of this simulator.\n");
            } else {
                int years_to_travel = year - (current_time.tm_year + 1900);

                printf("You are now traveling through time...\n");

                // Calculate time travel
                time_travel.tm_year += years_to_travel;

                // Set time
                time_t tt = mktime(&time_travel);

                printf("You have arrived in the year %d!\n", year);

                // Display time
                printf("Current time: %s", asctime(localtime(&tt)));
            }
        }

        // Exit command
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting Time Travel Simulator...\n");
            return 0;
        }

        // Invalid input
        else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }

        // Wait for input
        printf("\n");
    }
}