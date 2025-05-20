//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
/*
Procedural Space Adventure

In this program, the user gets to embark on a procedural space adventure, where they travel to different planets in a randomized fashion. 

The program generates a list of randomized planets, and the user gets to choose from that list which planet to explore next. The user can also choose to end their adventure at any time.

Each planet has its own unique attributes, such as climate, terrain, and number of moons. The program displays this information for the user to see.

The user has the option to interact with the planet in various ways, such as scanning for life, mining for resources, or relaxing at a space bar.

This program was developed using C language.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Randomize seed for generating planets
    srand(time(NULL));

    //Generate a list of 10 planets
    char *planets[] = {"Mars", "Venus", "Mercury", "Neptune", "Jupiter", "Saturn", "Uranus", "Pluto", "Earth", "Alpha Centauri"};

    //Variables to hold user input
    int choice, continue_adventure;

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("In this adventure, you will travel to different planets in a randomized fashion.\n");

    //Loop for main game sequence
    do
    {
        //Generate a random planet to explore
        int random_number = rand() % 10;
        char *planet = planets[random_number];

        //Display planet information
        printf("\nPlanet Selected: %s\n", planet);
        printf("---------------------------\n");
        printf("Climate: Temperate\n");
        printf("Terrain: Rocky\n");
        printf("Number of Moons: 2\n");
        printf("---------------------------\n");

        //Loop for planet interaction sequence
        do
        {
            printf("\nWhat would you like to do on %s?\n", planet);
            printf("1. Scan for life\n");
            printf("2. Mine for resources\n");
            printf("3. Relax at a space bar\n");
            printf("4. Choose another planet\n");
            printf("5. End the adventure\n");

            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("\nScanning for life on %s...\n", planet);
                printf("No signs of life detected.\n");
                break;
            case 2:
                printf("\nMining for resources on %s...\n", planet);
                printf("No valuable resources found.\n");
                break;
            case 3:
                printf("\nRelaxing at a space bar on %s...\n", planet);
                printf("You feel refreshed and ready for more adventure!\n");
                break;
            case 4:
                printf("\nReturning to the planet selection...\n");
                break;
            case 5:
                printf("\nEnding the adventure...");
                return 0;
                break;
            default:
                printf("\nInvalid choice!\n");
            }
        } while (choice != 4);

        //Ask user if they want to continue the adventure
        printf("\nDo you want to continue your space adventure?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &continue_adventure);
    } while (continue_adventure == 1);

    printf("\nThanks for playing the Procedural Space Adventure!\n");

    return 0;
}