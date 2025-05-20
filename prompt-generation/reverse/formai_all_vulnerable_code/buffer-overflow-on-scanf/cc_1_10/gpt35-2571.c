//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed random number generator with current time
    int light_years = rand() % 100 + 1; // Generate a random number of light years to travel
    printf("Welcome to our Space Adventure! You will be traveling "
           "through %d light years of unknown territory.\n\n", light_years);
    int current_year = 2021;
    int target_year = current_year + light_years; // Calculate the target year by adding light years to current year
    printf("Your journey starts in the year %d and you will reach your destination in the year %d.\n\n", current_year, target_year);
    printf("You will be making a stop at an unknown planet in the middle of your journey.\n\n");

    // Generate a random name for the planet
    char planet_name[10][10] = {"Lucent", "Nirn", "Xalax", "Solara", "Talos", "Zephyr", "Auriga", "Mira", "Orion", "Vega"};
    int planet_index = rand() % 10;
    printf("You have arrived at planet %s.\n\n", planet_name[planet_index]);

    int fuel = 100; // Start with 100% fuel
    while (light_years > 0) // Keep traveling until all light years are covered
    {
        printf("You have %d light years left to reach your destination and %d%% fuel.\n", light_years, fuel);

        // Prompt user for input
        printf("Do you want to 'continue' or 'refuel'?\n");
        char choice[10];
        scanf("%s", choice);
        if (strcmp(choice, "refuel") == 0)
        {
            fuel = 100;
            printf("You have refueled to 100%%.\n");
        }
        else
        {
            int speed = rand() % 10 + 1; // Generate a random speed between 1 and 10
            fuel -= speed; // Deduct fuel based on speed
            if (fuel <= 0) // Check if fuel is over
            {
                printf("You ran out of fuel and got stranded.\n");
                return 0;
            }
            light_years -= speed; // Deduct light years based on speed
            printf("You traveled %d light years with a speed of %d.\n", speed, speed + 1);
        }
        printf("----------------------------------------------------\n");
    }
    printf("Congratulations, you have reached your destination in the year %d!\n\n", target_year);
    return 0;
}