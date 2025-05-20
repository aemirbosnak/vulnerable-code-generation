//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int numPlanets = 10;
    int playerFuel = 50;
    int playerMoney = 1000;
    int currentPlanet = 0;
    int planetPrices[10] = {150, 200, 250, 300, 350, 400, 450, 500, 550, 600};
    char planetNames[10][20] = {"Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Alpha Centauri", "Proxima Centauri", "Andromeda"};
    
    printf("Welcome to Space Adventure!\n");

    while(playerFuel > 0 && currentPlanet < numPlanets) {
        printf("\nYou are currently on %s\n", planetNames[currentPlanet]);

        // Generate random events
        int event = rand() % 5;
        switch(event) {
            case 0:
                printf("There is nothing of interest on this planet.\n");
                break;
            case 1:
                printf("You found a rare mineral on this planet! You can sell it for 1000 space bucks.\n");
                playerMoney += 1000;
                break;
            case 2:
                printf("A space pirate has appeared and is attacking your ship!\n");
                int damage = rand() % 50 + 1;
                printf("Your ship has taken %d damage.\n", damage);
                playerFuel -= damage;
                break;
            case 3:
                printf("You have discovered a new planet!\n");
                numPlanets++;
                break;
            case 4:
                printf("You found a friendly alien race who gave you 200 space bucks.\n");
                playerMoney += 200;
                break;
        }

        // Check if player can afford to buy fuel or upgrade ship
        if(playerMoney >= planetPrices[currentPlanet]) {
            printf("You can buy fuel for 50 space bucks or upgrade your ship for %d space bucks. Type 'fuel' to buy fuel or 'upgrade' to upgrade your ship: ", planetPrices[currentPlanet]);
            char action[10];
            scanf("%s", action);
            if(strcmp(action, "fuel") == 0) {
                playerFuel += 50;
                playerMoney -= 50;
            } else if(strcmp(action, "upgrade") == 0) {
                printf("Your ship is now upgraded!\n");
                planetPrices[currentPlanet] += 200;
                playerMoney -= 200;
            }
        } else {
            printf("You don't have enough money to buy fuel or upgrade your ship.\n");
        }

        // Move to next planet
        currentPlanet++;
    }

    // Game over
    if(playerFuel <= 0) {
        printf("\nYou ran out of fuel and your ship is stranded in space. Game over.\n");
    } else {
        printf("\nCongratulations! You made it to the end of the space adventure with %d space bucks and %d fuel left.\n", playerMoney, playerFuel);
    }

    return 0;
}