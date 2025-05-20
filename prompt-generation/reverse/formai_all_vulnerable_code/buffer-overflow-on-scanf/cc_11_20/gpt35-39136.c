//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TRAVEL_YEARS 200

int main(void)
{
    int players, current_year, max_travel_years, i, j;
    int player_years[MAX_PLAYERS], travel_years[MAX_PLAYERS];
    char player_names[MAX_PLAYERS][20];

    // Seed random number generator with current time
    srand(time(NULL));

    printf("Welcome to the Time Travel Simulator!\n");

    // Get number of players
    do
    {
        printf("How many players? (1-%d): ", MAX_PLAYERS);
        scanf("%d", &players);
    } while (players < 1 || players > MAX_PLAYERS);

    // Get player names and initial years
    for (i = 0; i < players; i++)
    {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", player_names[i]);
        player_years[i] = 2022;
    }

    // Get maximum number of years to travel
    printf("How many years do you want to travel? (1-%d): ", MAX_TRAVEL_YEARS);
    scanf("%d", &max_travel_years);

    // Game loop
    current_year = 2022;
    while (current_year < 2222 && max_travel_years > 0)
    {
        // Print current year
        printf("\nCurrent year: %d\n", current_year);

        // Loop through players
        for (i = 0; i < players; i++)
        {
            // Get number of years this player wants to travel
            printf("%s, how many years do you want to travel? (0-%d): ", player_names[i], max_travel_years);
            scanf("%d", &travel_years[i]);

            // Make sure it's a valid number of years
            if (travel_years[i] < 0)
            {
                travel_years[i] = 0;
            }
            else if (travel_years[i] > max_travel_years)
            {
                travel_years[i] = max_travel_years;
            }

            // Update player's year
            player_years[i] += travel_years[i];

            // Print player's new year
            printf("%s traveled %d years and arrived in %d.\n", player_names[i], travel_years[i], player_years[i]);

            // Subtract travel years from max
            max_travel_years -= travel_years[i];
        }

        // Check for any conflicts
        for (i = 0; i < players; i++)
        {
            for (j = i + 1; j < players; j++)
            {
                if (player_years[i] == player_years[j])
                {
                    printf("\n%s and %s have arrived in the same year %d! There must be a conflict...\n", player_names[i], player_names[j], player_years[i]);
                    printf("%s, do you want to go forward one year to avoid the conflict? (y/n): ", player_names[i]);
                    char choice;
                    scanf(" %c", &choice);
                    if (choice == 'y')
                    {
                        player_years[i]++;
                        printf("%s advanced to %d.\n", player_names[i], player_years[i]);
                    }
                    else
                    {
                        player_years[j]++;
                        printf("%s advanced to %d.\n", player_names[j], player_years[j]);
                    }
                }
            }
        }

        // Advance to next year
        current_year++;
    }

    printf("\nGame over. Final scores:\n");
    for (i = 0; i < players; i++)
    {
        printf("%s: %d\n", player_names[i], player_years[i]);
    }

    return 0;
}