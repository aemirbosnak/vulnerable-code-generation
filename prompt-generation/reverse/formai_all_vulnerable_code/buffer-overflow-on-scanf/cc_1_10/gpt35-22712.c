//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayWelcomeMessage();
void initializeGame();
void displayPlanetDescription(int planetIndex);
void explore();

char planetNames[5][20] = {
    "Astron",
    "Galaxia",
    "Starion",
    "Nebulon",
    "Cosmica"
};

char planetDescriptions[5][200] = {
    "Astron is known for its abundant mineral resources. Be careful of frequent meteor showers.",
    "Galaxia is inhabited by a peaceful alien race who love to trade resources.",
    "Starion is known for its high radiation levels - make sure to wear protective suits.",
    "Nebulon is a gas giant, but it has floating islands that you can land on and explore.",
    "Cosmica is a desert planet with giant sandstorms, but its oasis has the best food in the galaxy."
};

int visitedPlanets[5] = {0, 0, 0, 0, 0};
int currentPlanetIndex;

int main()
{
    displayWelcomeMessage();
    initializeGame();
    explore();

    return 0;
}

void displayWelcomeMessage()
{
    printf("Welcome to the C Procedural Space Adventure!\n\n");
    printf("You are the captain of your own spaceship, and your mission is to explore the galaxy\n");
    printf("and discover new planets. Each planet has its own unique characteristics, and you\n");
    printf("will encounter different challenges and opportunities on each one. Good luck!\n\n");
}

void initializeGame()
{
    srand(time(NULL)); // seed random number generator
    
    printf("Initializing game...\n");
    printf("You are starting your adventure on one of the five randomly chosen planets:\n\n");

    currentPlanetIndex = rand() % 5;
    visitedPlanets[currentPlanetIndex] = 1;

    displayPlanetDescription(currentPlanetIndex);
}

void displayPlanetDescription(int planetIndex)
{
    printf("%s\n", planetNames[planetIndex]);
    printf("%s\n\n", planetDescriptions[planetIndex]);
}

void explore()
{
    char input;

    printf("Would you like to explore this planet? (y/n): ");
    scanf(" %c", &input);

    if (input == 'y')
    {
        printf("You begin your exploration of %s...\n\n", planetNames[currentPlanetIndex]);

        // code to simulate exploration of planet goes here

        printf("Your planet exploration is complete.\n\n");
    }

    printf("Would you like to visit another planet? (y/n): ");
    scanf(" %c", &input);

    if (input == 'y')
    {
        int newPlanetIndex;
        do
        {
            newPlanetIndex = rand() % 5;
        } while (visitedPlanets[newPlanetIndex] == 1);

        visitedPlanets[newPlanetIndex] = 1;
        currentPlanetIndex = newPlanetIndex;

        displayPlanetDescription(currentPlanetIndex);
        explore();
    }
    else
    {
        printf("Thank you for playing the C Procedural Space Adventure!\n");
    }
}