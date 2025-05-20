//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void clearScreen()
{
    system("cls || clear");
}

void printStory(char *story)
{
    clearScreen();
    printf("%s\n", story);
}

void startGame(char *playerName)
{
    char *story = "Welcome to the Procedural Space Adventure, %s! Your mission is to explore the universe and collect resources to help earth survive a catastrophic event.\nYou will start your journey with a basic spaceship which has limited fuel and resources. Your spaceship can travel through galaxies, but beware of space pirates and dangerous planets which can damage your ship. \nCollect resources as much as possible and return back to Earth before the catastrophic event strikes. Good luck!";
    printf(story, playerName);
    getchar();

    int fuel = 20; // starting fuel level
    int resources = 0;
    int galaxiesExplored = 0;
    bool catastrophicEvent = false;
    bool gameOver = false;
    srand(time(NULL)); // set seed to randomize events

    while (!gameOver)
    {
        clearScreen();
        printf("Galaxies explored: %d\n", galaxiesExplored);
        printf("Current fuel level: %d\n", fuel);
        printf("Resources collected: %d\n\n", resources);

        // Random event generator
        int event = rand() % 100 + 1; 

        if (event < 50) // no event
        {
            printf("You have traveled safely through space and reached a new galaxy.\n");
            fuel -= 2; // fuel consumption to travel to new galaxy
        }
        else if (event < 75) // resource found
        {
            int randomResource = rand() % 3 + 1; // random resource generator
            printf("You have discovered a planet with resources!\n");
            if (randomResource == 1)
            {
                resources += 10;
                printf("You collected 10 units of water.\n");
            }
            else if (randomResource == 2)
            {
                resources += 5;
                printf("You collected 5 units of oxygen.\n");
            }
            else
            {
                resources += 3;
                printf("You collected 3 units of iron.\n");
            }
            fuel -= 1; // fuel consumption to land on planet
        }
        else if (event < 95) // space pirate attack
        {
            printf("You have encountered space pirates! They have damaged your ship and stolen some of your resources.\n");
            fuel -= 3; // fuel consumption to escape from space pirates
            resources -= 5; // resources stolen by pirates
        }
        else // dangerous planet
        {
            printf("You have landed on a dangerous planet! Your ship has been seriously damaged and you lost some of your resources while trying to fix it.\n");
            fuel -= 4; // fuel consumption to land and escape from dangerous planet
            resources -= 10; // resources lost while fixing the ship
        }

        getchar();

        if (fuel <= 0) // game over if fuel runs out
        {
            printf("You have run out of fuel. Your spaceship is now drifting in space forever.\n");
            gameOver = true;
        }
        else if (resources >= 50) // win condition
        {
            printf("Congratulations, you have collected enough resources to save Earth from the catastrophic event!\n");
            gameOver = true;
        }
        else if (galaxiesExplored >= 10) // catastrophic event after exploring 10 galaxies
        {
            printf("Warning! The catastrophic event has started. You need to return to Earth immediately!\n");
            catastrophicEvent = true;
        }

        if (catastrophicEvent && fuel > 0) // countdown to game over
        {
            printf("You have %d turns left to return to Earth before the catastrophic event hits.\n", fuel);
            getchar();
        }

        galaxiesExplored++; // increment galaxy counter
    }

    printf("Game over. Thank you for playing the Procedural Space Adventure.\n");
    getchar();
}

int main()
{
    clearScreen();
    printf("Welcome to the Procedural Space Adventure! What is your name?\n");

    char playerName[50];
    scanf("%s", playerName);

    startGame(playerName);
    return 0;
}