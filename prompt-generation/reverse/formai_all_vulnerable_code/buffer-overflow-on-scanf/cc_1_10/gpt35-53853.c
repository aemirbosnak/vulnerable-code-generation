//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH 100
#define MAX_ENERGY 100
#define MAX_OXYGEN 100

typedef struct Player {
    char name[20];
    int health;
    int energy;
    int oxygen;
} Player;

void printStats(Player player) {
    printf("Name: %s\nHealth: %d\nEnergy: %d\nOxygen: %d\n\n",
           player.name, player.health, player.energy, player.oxygen);
}

int main() {
    srand(time(NULL)); //seed the random number generator with current time

    printf("Welcome to the Procedural Space Adventure!\n\n");

    //generate a random planet and its characteristics
    char* planets[5] = {"Luna", "Mars", "Jupiter", "Saturn", "Neptune"};
    int planetIndex = rand() % 5;
    char* planetName = planets[planetIndex];
    int planetHealth = rand() % MAX_HEALTH + 1;
    int planetEnergy = rand() % MAX_ENERGY + 1;
    int planetOxygen = rand() % MAX_OXYGEN + 1;
    printf("You are currently in orbit around %s.\n", planetName);

    //initialize player's stats
    Player player;
    printf("What's your name, adventurer? ");
    scanf("%s", player.name);
    player.health = MAX_HEALTH;
    player.energy = MAX_ENERGY;
    player.oxygen = MAX_OXYGEN;
    printf("\n");

    //print player's stats
    printf("Here are your starting stats:\n");
    printStats(player);
    printf("Press enter to begin your adventure...\n");
    getchar(); //wait for user to press enter

    //start the game loop
    while (player.health > 0 && player.energy > 0 && player.oxygen > 0) {
        printf("You are on %s.\nWhat would you like to do? (Enter 1-3)\n", planetName);
        printf("1. Explore\n2. Rest\n3. Refuel\nChoice: ");
        int choice;
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("You explore %s and find...\n", planetName);
                int foundHealth = rand() % 51; //player can find up to 50 health
                int foundEnergy = rand() % 51; //player can find up to 50 energy
                int foundOxygen = rand() % 51; //player can find up to 50 oxygen
                printf("%d health\n%d energy\n%d oxygen\n", foundHealth, foundEnergy, foundOxygen);
                player.health = (player.health + foundHealth) > MAX_HEALTH ? MAX_HEALTH : (player.health + foundHealth); //cap health at MAX_HEALTH
                player.energy = (player.energy + foundEnergy) > MAX_ENERGY ? MAX_ENERGY : (player.energy + foundEnergy); //cap energy at MAX_ENERGY
                player.oxygen = (player.oxygen + foundOxygen) > MAX_OXYGEN ? MAX_OXYGEN : (player.oxygen + foundOxygen); //cap oxygen at MAX_OXYGEN
                break;
            case 2:
                printf("You take a rest on %s...\n", planetName);
                player.health += 20; //resting gives 20 health
                player.energy += 10; //resting gives 10 energy
                player.oxygen -= 10; //resting uses up 10 oxygen
                printStats(player);
                break;
            case 3:
                printf("You refuel your spacecraft on %s...\n", planetName);
                player.energy = MAX_ENERGY; //refueling gives full energy
                player.oxygen -= 20; //refueling uses up 20 oxygen
                printStats(player);
                break;
            default:
                printf("Invalid choice. Try again.\n\n");
        }

        //consume oxygen for every action taken
        player.oxygen--;
        if (player.oxygen <= 0) {
            player.oxygen = 0;
            player.health--; //suffocation causes health loss
        }

        //random chance of encountering an enemy
        int enemyChance = rand() % 10 + 1; //1 in 10 chance
        if (enemyChance == 1) {
            printf("OH NO! You encountered a hostile alien!\n");
            int alienHealth = rand() % 51 + 50; //alien can have up to 100 health
            int alienEnergy = rand() % 51 + 50; //alien can have up to 100 energy
            int alienOxygen = rand() % 51 + 50; //alien can have up to 100 oxygen
            printf("The alien has:\n%d health\n%d energy\n%d oxygen\n\n", alienHealth, alienEnergy, alienOxygen);

            //fight the alien
            while (player.health > 0 && alienHealth > 0) {
                int attack = rand() % 10 + 1; //player can deal up to 10 damage
                alienHealth -= attack;
                printf("You attack the alien for %d damage.\n", attack);
                printf("The alien has %d health left.\n", alienHealth);

                attack = rand() % 10 + 1; //alien can deal up to 10 damage
                player.health -= attack;
                printf("The alien attacks you for %d damage.\n", attack);
                printf("You have %d health left.\n\n", player.health);
            }

            if (player.health <= 0) {
                printf("GAME OVER! The alien defeated you.\n");
                exit(0);
            } else {
                printf("Congratulations! You defeated the alien.\n");
                player.health = MAX_HEALTH; //winning gives full health
                player.energy = MAX_ENERGY; //winning gives full energy
                player.oxygen = MAX_OXYGEN; //winning gives full oxygen
                printf("Your stats have been fully restored.\n\n");
            }
        }
    }

    //game is over
    printf("GAME OVER! ");
    if (player.health <= 0) {
        printf("You have died.\n");
    } else if (player.energy <= 0) {
        printf("Your spacecraft has run out of energy.\n");
    } else if (player.oxygen <= 0) {
        printf("You have suffocated.\n");
    }

    return 0;
}