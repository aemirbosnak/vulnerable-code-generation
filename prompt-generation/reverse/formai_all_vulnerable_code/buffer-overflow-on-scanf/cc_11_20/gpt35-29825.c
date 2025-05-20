//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLANET_COUNT 5

int main(void) {
    srand(time(NULL));

    // Generate our starting location
    int current_planet = rand() % PLANET_COUNT;

    // Set up our planet names
    char planet_names[PLANET_COUNT][20] = {"Arcturus", "Vega", "Sirius", "Proxima Centauri", "Alpha Centauri"};

    // Set up our planet distances
    int planet_distances[PLANET_COUNT][PLANET_COUNT] = {
        {0, 10, 20, 30, 15},
        {10, 0, 12, 8, 25},
        {20, 12, 0, 15, 18},
        {30, 8, 15, 0, 5},
        {15, 25, 18, 5, 0}
    };

    printf("Welcome to our C Procedural Space Adventure!\n");
    printf("You are currently on the planet %s.\n\n", planet_names[current_planet]);

    int player_choice = 1;
    while(player_choice != 0) {
        printf("What do you want to do?\n");
        printf("1 - Travel to a new planet.\n");
        printf("2 - Land on this planet.\n");
        printf("0 - Quit the game.\n\n");

        printf("Enter your choice: ");
        scanf("%d", &player_choice);

        switch(player_choice) {
            case 0:
                printf("Thanks for playing our game!\n");
                break;
            case 1:
                printf("Which planet do you want to travel to?\n");

                for(int i = 0; i < PLANET_COUNT; i++) {
                    if(i != current_planet) {
                        printf("%d - %s\n", i + 1, planet_names[i]);
                    }
                }

                printf("Enter the number of your choice: ");
                int planet_choice;
                scanf("%d", &planet_choice);

                if(planet_choice <= 0 || planet_choice > PLANET_COUNT || planet_choice == current_planet + 1) {
                    printf("Invalid planet choice. Please try again.\n");
                } else {
                    printf("Traveling to %s.\n", planet_names[planet_choice - 1]);
                    printf("The journey will take %d days.\n\n", planet_distances[current_planet][planet_choice - 1]);
                    current_planet = planet_choice - 1;
                }

                break;
            case 2:
                printf("Landing on %s.\n\n", planet_names[current_planet]);

                // Generate a random event on this planet
                int event = rand() % 3;

                switch(event) {
                    case 0:
                        printf("You found a cache of valuable resources.\n\n");
                        break;
                    case 1:
                        printf("You encountered hostile aliens.\n\n");
                        break;
                    case 2:
                        printf("You discovered a new species of plant.\n\n");
                        break;
                }

                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}