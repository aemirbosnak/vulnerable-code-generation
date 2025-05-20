//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLANETS 5
#define MAX_COMMODITIES 3

typedef struct {
    char name[20];
    int prices[MAX_COMMODITIES]; // Prices for different commodities
} Planet;

typedef struct {
    char name[20];
    int money;
} Player;

void initializePlanets(Planet planets[], int count) {
    const char *planetNames[] = {"Earth", "Mars", "Jupiter", "Venus", "Saturn"};
    const int basePrices[MAX_COMMODITIES] = {50, 100, 200};

    for (int i = 0; i < count; i++) {
        strcpy(planets[i].name, planetNames[i]);
        for (int j = 0; j < MAX_COMMODITIES; j++) {
            planets[i].prices[j] = basePrices[j] + (rand() % 50) - 25; // Random price fluctuation
        }
    }
}

void displayPlanets(Planet planets[], int count) {
    printf("Available planets:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, planets[i].name);
        printf("   Prices: Ore: %d, Water: %d, Food: %d\n", 
               planets[i].prices[0], planets[i].prices[1], planets[i].prices[2]);
    }
}

int buyCommodity(Player *player, Planet *planet, int commodityIndex, int quantity) {
    int cost = planet->prices[commodityIndex] * quantity;
    if (player->money >= cost) {
        player->money -= cost;
        printf("You bought %d units of commodity %d for %d money.\n", quantity, commodityIndex + 1, cost);
        return 1; // Success
    } else {
        printf("You don't have enough money to buy that!\n");
        return 0; // Failure
    }
}

int sellCommodity(Player *player, Planet *planet, int commodityIndex, int quantity) {
    int earn = planet->prices[commodityIndex] * quantity;
    player->money += earn;
    printf("You sold %d units of commodity %d for %d money.\n", quantity, commodityIndex + 1, earn);
    return 1; // Success
}

void randomEvent(Player *player) {
    int event = rand() % 3;
    switch (event) {
        case 0:
            printf("You encountered a space pirate and lost 20 money.\n");
            player->money -= 20;
            break;
        case 1:
            printf("You found a stash of credits! You gained 50 money.\n");
            player->money += 50;
            break;
        case 2:
            printf("You experienced a market crash. All commodities are now halve price!\n");
            // Implement price fluctuation (for simplicity ignoring the details here)
            break;
    }
}

int main() {
    srand(time(NULL));

    Player player;
    strcpy(player.name, "Trader");
    player.money = 100;

    Planet planets[MAX_PLANETS];
    initializePlanets(planets, MAX_PLANETS);

    int choice = 0;
    while (1) {
        printf("\nWelcome to Galactic Trader, %s! You have %d money.\n", player.name, player.money);
        displayPlanets(planets, MAX_PLANETS);
        
        printf("Choose a planet (1-%d) to trade or 0 to exit: ", MAX_PLANETS);
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        Planet *currentPlanet = &planets[choice - 1];
        // Trading Menu
        printf("Trading on planet %s. What would you like to do?\n", currentPlanet->name);
        printf("1. Buy Commodity\n2. Sell Commodity\n3. Random Event\n4. Leave Planet\n");
        int action;
        scanf("%d", &action);

        if (action == 1) {
            printf("Which commodity would you like to buy? (1-Ore, 2-Water, 3-Food): ");
            int commodity;
            scanf("%d", &commodity);
            printf("How many units would you like to buy? ");
            int quantity;
            scanf("%d", &quantity);
            if (commodity >= 1 && commodity <= 3) {
                buyCommodity(&player, currentPlanet, commodity - 1, quantity);
            } else {
                printf("Invalid commodity.\n");
            }
        } else if (action == 2) {
            printf("Which commodity would you like to sell? (1-Ore, 2-Water, 3-Food): ");
            int commodity;
            scanf("%d", &commodity);
            printf("How many units would you like to sell? ");
            int quantity;
            scanf("%d", &quantity);
            if (commodity >= 1 && commodity <= 3) {
                sellCommodity(&player, currentPlanet, commodity - 1, quantity);
            } else {
                printf("Invalid commodity.\n");
            }
        } else if (action == 3) {
            randomEvent(&player);
        } else if (action == 4) {
            printf("Leaving planet...\n");
        } else {
            printf("Invalid action.\n");
        }
    }

    printf("Thanks for playing, %s! You have %d money left.\n", player.name, player.money);
    return 0;
}