//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function declarations
void startGame();
void initializeSpace();
void printIntro();
void displayMenu();
void displayMap();
void visitPlanet(int planet);
void upgradeShip();
void gameOver();

// global variables
int currPlanet = 1;
int numPlanets = 5;
int fuel = 5;
int maxFuel = 10;
int shield = 5;
int maxShield = 10;
int credits = 0;
int maxCreditCapacity = 10000;
int shipLevel = 1;
int shieldUpgrades = 0;
int fuelUpgrades = 0;
int jumpDriveUpgrades = 0;
int scanUpgrades = 0;
int currentSystem = 1;
int numSystems = 10;

int main()
{
    srand(time(NULL)); // seed random number generator
    
    startGame(); // begin game
    
    return 0;
}

void startGame()
{
    printIntro(); // display intro
    
    initializeSpace(); // create game environment
    
    while (1) // game loop
    {
        displayMenu(); // display menu options
        
        int option;
        scanf("%d", &option); // input selection
        
        switch (option)
        {
            case 1: // display map
                displayMap();
                break;
            case 2: // visit planet
                visitPlanet(currPlanet);
                currPlanet++;
                if (currPlanet > numPlanets) currPlanet = 1; // wrap around to first planet
                break;
            case 3: // upgrade ship
                upgradeShip();
                break;
            case 4: // refuel
                if (credits >= 50) // check if player has enough credits
                {
                    credits -= 50;
                    fuel = maxFuel;
                    printf("You refueled your ship.\n");
                }
                else printf("You don't have enough credits to refuel.\n");
                break;
            case 5: // repair shield
                if (credits >= 50) // check if player has enough credits
                {
                    credits -= 50;
                    shield = maxShield;
                    printf("You repaired your ship's shield.\n");
                }
                else printf("You don't have enough credits to repair your shield.\n");
                break;
            case 6: // jump to next system
                currentSystem++;
                if (currentSystem > numSystems) gameOver();
                else printf("Jumping to the next system...\n");
                break;
            case 7: // quit game
                gameOver();
                break;
            default:
                printf("Invalid Input.\n");
                break;
        }
        
        // check if player has lost
        if (fuel <= 0 || shield <= 0) gameOver();
    }
}

void initializeSpace()
{
    printf("System Initializing...\n\n");
    printf("Welcome to Proxima Centauri, you have been chosen to explore our interstellar system for valuable resources.\n");
    printf("Your mission is to visit each planet in our system and collect as many credits as possible.\n");
    printf("But beware, the journey will be treacherous. You are likely to encounter hostile alien creatures and other dangers.\n\n");
    
    printf("Total number of systems: %d\n", numSystems);
    printf("Total number of planets: %d\n\n", numPlanets);
    
    printf("Your ship is a basic model with the following specifications:\n");
    printf("Fuel: %d/%d\n", fuel, maxFuel);
    printf("Shield: %d/%d\n", shield, maxShield);
    printf("Credits: %d/%d\n", credits, maxCreditCapacity);
    printf("Level: %d\n", shipLevel);
    printf("Upgrade slots:\n");
    printf("- Shield: %d/3\n", shieldUpgrades);
    printf("- Fuel: %d/3\n", fuelUpgrades);
    printf("- Jump Drive: %d/3\n", jumpDriveUpgrades);
    printf("- Scan: %d/3\n\n", scanUpgrades);
    
    printf("Good luck, captain!\n\n");
}

void printIntro()
{
    printf("WELCOME TO PROXIMA CENTAURI\n");
    printf("***************************\n");
    printf("You are the captain of an interstellar spacecraft, on a mission to explore the Proxima Centauri system.\n");
    printf("You will be traveling to various planets seeking valuable resources. Along the way, you will encounter hostile alien creatures and other dangers.\n\n");
    printf("Your task is to visit all %d planets in the system, collect as many credits as possible, and return safely to Earth.\n\n", numPlanets);
}

void displayMenu()
{
    printf("What would you like to do?\n");
    printf("1) Display Map\n");
    printf("2) Visit Planet %d\n", currPlanet);
    printf("3) Upgrade Ship\n");
    printf("4) Refuel Ship (50 credits)\n");
    printf("5) Repair Shield (50 credits)\n");
    printf("6) Jump to Next System\n");
    printf("7) Quit Game\n\n");
}

void displayMap()
{
    printf("Map of Proxima Centauri System\n");
    printf("------------------------------\n");
    printf("          |  Planet %d  |\n", numPlanets);
    printf("          |     %c     |\n", currentSystem >= 1 ? '*' : ' ');
    printf("          |           |\n");
    printf("Planet %d  |           |  Planet %d\n", 1, numPlanets - 1);
    printf("    %c     |           |     %c\n", currentSystem >= 2 ? '*' : ' ', currentSystem >= 2 ? '*' : ' ');
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |     %c     |\n", currentSystem >= 3 ? '*' : ' ');
    printf("          |           |\n");
    printf("Planet %d  |           |  Planet %d\n", 2, numPlanets - 2);
    printf("    %c     |           |     %c\n", currentSystem >= 4 ? '*' : ' ', currentSystem >= 4 ? '*' : ' ');
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |     %c     |\n", currentSystem >= 5 ? '*' : ' ');
    printf("          |           |\n");
    printf("Planet %d  |           |  Planet %d\n", 3, numPlanets - 3);
    printf("    %c     |           |     %c\n", currentSystem >= 6 ? '*' : ' ', currentSystem >= 6 ? '*' : ' ');
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |     %c     |\n", currentSystem >= 7 ? '*' : ' ');
    printf("          |           |\n");
    printf("Planet %d  |           |  Planet %d\n", 4, numPlanets - 4);
    printf("    %c     |           |     %c\n", currentSystem >= 8 ? '*' : ' ', currentSystem >= 8 ? '*' : ' ');
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |           |\n");
    printf("          |     %c     |\n", currentSystem >= 9 ? '*' : ' ');
    printf("          |           |\n");
    printf("Planet %d  |     X     |  Planet %d\n", 5, numPlanets - 5);
    printf("          |           |\n");
    printf("------------------------------\n\n");
}

void visitPlanet(int planet)
{
    printf("Descending to Planet %d...\n", planet);
    
    int value = rand() % 500 + 500; // generate a random credit value between 500 and 1000
    
    printf("You found %d credits on this planet!\n", value);
    
    credits += value;
    
    int danger = rand() % 4;
    
    if (danger == 0) // 25% chance of encountering a hostile alien
    {
        printf("Oh no! You have encountered a hostile alien on this planet!\n");
        int damage = rand() % 50 + 50; // generate a random damage value between 50 and 100
        shield -= damage;
        printf("Your shield took %d damage.\n", damage);
    }
    else printf("Planet %d is safe and you may proceed.\n", planet);
    
    printf("Returning to ship...\n\n");
}

void upgradeShip()
{
    printf("What would you like to upgrade?\n");
    printf("1) Shield (+1) (50 credits)\n");
    printf("2) Fuel (+1) (50 credits)\n");
    printf("3) Jump Drive (+1) (500 credits)\n");
    printf("4) Scan (+1) (250 credits)\n\n");
    
    int option;
    scanf("%d", &option);
    
    switch (option)
    {
        case 1:
            if (credits >= 50 && shieldUpgrades < 3)
            {
                credits -= 50;
                shieldUpgrades++;
                maxShield += 10;
                printf("Ship upgraded! Shield capacity increased to %d.\n", maxShield);
            }
            else if (shieldUpgrades >= 3) printf("You have reached the maximum number of shield upgrades (3).\n");
            else printf("You don't have enough credits to upgrade shield.\n");
            break;
        case 2:
            if (credits >= 50 && fuelUpgrades < 3)
            {
                credits -= 50;
                fuelUpgrades++;
                maxFuel += 5;
                printf("Ship upgraded! Fuel capacity increased to %d.\n", maxFuel);
            }
            else if (fuelUpgrades >= 3) printf("You have reached the maximum number of fuel upgrades (3).\n");
            else printf("You don't have enough credits to upgrade fuel.\n");
            break;
        case 3:
            if (credits >= 500 && jumpDriveUpgrades < 3)
            {
                credits -= 500;
                jumpDriveUpgrades++;
                printf("Ship upgraded! You can now jump to the next system.\n");
            }
            else if (jumpDriveUpgrades >= 3) printf("You have reached the maximum number of jump drive upgrades (3).\n");
            else printf("You don't have enough credits to upgrade jump drive.\n");
            break;
        case 4:
            if (credits >= 250 && scanUpgrades < 3)
            {
                credits -= 250;
                scanUpgrades++;
                printf("Ship upgraded! You can now scan for valuable resources on planets.\n");
            }
            else if (scanUpgrades >= 3) printf("You have reached the maximum number of scan upgrades (3).\n");
            else printf("You don't have enough credits to upgrade scan.\n");
            break;
        default:
            printf("Invalid Input.\n");
            break;
    }
}

void gameOver()
{
    printf("GAME OVER!\n");
    printf("Final Score: %d credits\n", credits);
    exit(0);
}