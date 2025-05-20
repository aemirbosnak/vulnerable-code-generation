//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to Procedural Space Adventure!\n\n");

    // Generate a random planet name
    srand(time(NULL));
    char* planet_names[5] = {"Zorlon", "Nebulon", "Xanthor", "Krynn", "Gareth"};
    int planet_index = rand() % 5;
    char* planet_name = planet_names[planet_index];
    printf("Your ship has landed on planet %s.\n", planet_name);

    // Generate a random number of aliens
    int aliens = (rand() % 20) + 1;
    printf("There are %d friendly aliens on planet %s.\n", aliens, planet_name);

    // Ask if the player wants to explore the planet
    char choice;
    printf("Would you like to explore planet %s? (Y/N)\n", planet_name);
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Let's explore!\n");

        // Generate random events on planet
        int event = rand() % 3;
        switch (event) {
            case 0:
                printf("You have discovered an underground cave system.\n");
                break;
            case 1:
                printf("You have found a crashed spaceship.\n");
                break;
            case 2:
                printf("You have encountered a group of hostile aliens!\n");
                break;
        }

        // Ask if the player wants to continue exploring
        printf("Would you like to continue exploring? (Y/N)\n");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            printf("Let's keep going!\n");

            // Generate another random event
            event = rand() % 3;
            switch (event) {
                case 0:
                    printf("You have discovered an ancient temple.\n");
                    break;
                case 1:
                    printf("You have found a hidden treasure chest.\n");
                    break;
                case 2:
                    printf("You have encountered an injured alien in need of help.\n");
                    break;
            }

            // Ask if the player wants to help the alien
            printf("Would you like to help the alien? (Y/N)\n");
            scanf(" %c", &choice);

            if (choice == 'Y' || choice == 'y') {
                printf("Great job! The alien has joined your crew.\n");
            } else {
                printf("The alien is disappointed but understands.\n");
            }
        } else {
            printf("Thanks for exploring planet %s.\n", planet_name);
        }
    } else {
        printf("That's okay, maybe next time!\n");
    }

    printf("Thanks for playing Procedural Space Adventure!\n");

    return 0;
}