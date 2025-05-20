//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    srand(time(0)); // Generating random seed based on current time
    int current_year = 1400; // Setting the initial year to 1400
    bool quit = false; // Setting the quit flag to false
    printf("Welcome to the Medieval Time Travel Simulator!\n\n");

    while (!quit)
    {
        int year_index = rand() % 5; // Picking a random year from the list of available years
        int available_years[] = {1066, 1215, 1348, 1415, 1485}; // Array of available years
        int travel_year = available_years[year_index]; // Selecting the travel year based on the index
        int time_traveled = abs(current_year - travel_year); // Calculating the years time traveled

        printf("You have time traveled to the year %d!\n", travel_year);

        if (travel_year < current_year)
            printf("You have traveled back in time by %d years.\n", time_traveled);
        else
            printf("You have traveled forward in time by %d years.\n", time_traveled);

        // Performing actions based on the travel_year
        switch (travel_year)
        {
            case 1066:
                printf("Harold Godwinson is crowned King of England after the death of Edward the Confessor.\n");
                printf("The Norman Conquest will soon follow.\n");
                break;
            case 1215:
                printf("King John of England signs the Magna Carta, limiting the power of monarchs.\n");
                printf("This document will serve as the basis for the modern concept of constitutional law.\n");
                break;
            case 1348:
                printf("The Black Death, caused by the bubonic plague, ravages Europe.\n");
                printf("It is estimated that around 20 million people died from this deadly disease.\n");
                break;
            case 1415:
                printf("The Battle of Agincourt takes place during the Hundred Years' War between England and France.\n");
                printf("The English, led by King Henry V, win a decisive victory against the French forces.\n");
                break;
            case 1485:
                printf("The Wars of the Roses come to an end with the victory of Henry Tudor over Richard III.\n");
                printf("This marks the start of the Tudor dynasty, which will rule England for over a century.\n");
                break;
            default:
                printf("Unknown year.\n");
                break;
        }

        // Updating the current_year
        current_year = travel_year;

        // Asking the user if they want to time travel again
        char answer[3];
        printf("\nDo you want to time travel again? (yes or no): ");
        scanf("%s", answer);
        if (strcmp(answer, "no") == 0)
            quit = true;

        printf("\n");
    }

    return 0;
}