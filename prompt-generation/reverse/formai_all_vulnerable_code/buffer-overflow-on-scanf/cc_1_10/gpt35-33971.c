//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include<stdio.h>

//function prototypes
void startGame(void);
void startJourney(void);
void approachPlanet(int number);
void landOnPlanet(int number);
void explorePlanet(int number);
void returnToShip(void);
void gameWon(void);
void gameOver(void);

//global variables
int currentPlanet = 1;

int main()
{
    printf("Welcome to Procedural Space Adventure!\n");
    startGame();

    return 0;
}

void startGame()
{
    printf("You are captain of a starship on a journey through space.\n");
    printf("Your mission is to visit all 5 planets in this star system and collect valuable resources.\n");

    startJourney();
}

void startJourney()
{
    printf("You and your crew set off on your journey.\n");
    printf("You approach Planet %d.\n", currentPlanet);
    approachPlanet(currentPlanet);
}

void approachPlanet(int number)
{
    printf("You scan Planet %d and detect valuable resources.\n", number);
    printf("Do you want to attempt to land on Planet %d? (Y/N)\n", number);

    char choice;
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y') {
        landOnPlanet(number);
    } 
    else {
        printf("You decide not to land on Planet %d and continue your journey.\n", number);
        currentPlanet++;

        if (currentPlanet == 6) {
            gameWon();
        } 
        else {
            approachPlanet(currentPlanet);
        }
    }
}

void landOnPlanet(int number)
{
    printf("You land on Planet %d and begin exploring.\n", number);
    explorePlanet(number);
}

void explorePlanet(int number)
{
    printf("You find valuable resources on Planet %d and collect them.\n", number);
    printf("Do you want to continue exploring? (Y/N)\n");

    char choice;
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y') {
        explorePlanet(number);
    } 
    else {
        returnToShip();
    }
}

void returnToShip()
{
    printf("You return to your ship and take off from Planet %d.\n", currentPlanet);
    currentPlanet++;

    if (currentPlanet == 6) {
        gameWon();
    } 
    else {
        approachPlanet(currentPlanet);
    }
}

void gameWon()
{
    printf("Congratulations! You have successfully visited all 5 planets and collected valuable resources.\n");
    printf("Your journey through space comes to an end.\n");
}

void gameOver()
{
    printf("Game over. You failed to complete your mission.\n");
}