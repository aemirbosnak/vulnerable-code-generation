//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_DISTANCE 1000
#define MAX_ENERGY 100
#define MAX_HEALTH 100
#define MAX_ALIEN_HEALTH 50
#define MAX_NUM_ALIENS 10
#define ALIEN_DAMAGE 10
#define WEAPON_DAMAGE 20

// Define functions
void printIntro();
void printMenu();
void moveForward(int* distance, int* energy, int* health);
void increaseEnergy(int* distance, int* energy, int* health);
void rest(int* energy, int* health);
void fight(int* energy, int* health, int* numAliens, int* alienHealth, int* alienDamage);

int main()
{
    // Set up variables
    int distance = 0;
    int energy = MAX_ENERGY;
    int health = MAX_HEALTH;
    int numAliens = 0;
    int alienHealth[MAX_NUM_ALIENS] = { 0 }; // initially all aliens have 0 health
    int alienDamage = ALIEN_DAMAGE;

    // Seed random number generator
    srand(time(NULL));

    // Print intro message
    printIntro();

    // Start game loop
    while (health > 0 && distance < MAX_DISTANCE)
    {
        // Print menu and get user input
        printMenu();
        int choice;
        scanf("%d", &choice);

        // Handle user choice
        switch (choice)
        {
            case 1:
                moveForward(&distance, &energy, &health);
                break;
            case 2:
                increaseEnergy(&distance, &energy, &health);
                break;
            case 3:
                rest(&energy, &health);
                break;
            case 4:
                fight(&energy, &health, &numAliens, alienHealth, &alienDamage);
                break;
            default:
                printf("Invalid choice\n");
        }

        // Check if any aliens are defeated
        for (int i = 0; i < numAliens; i++)
        {
            if (alienHealth[i] <= 0)
            {
                printf("You defeated an alien!\n");
                alienHealth[i] = -1; // mark as defeated
            }
        }

        // Check if all aliens are defeated
        int allDefeated = 1;
        for (int i = 0; i < numAliens; i++)
        {
            if (alienHealth[i] != -1)
            {
                allDefeated = 0;
                break;
            }
        }
        if (allDefeated)
        {
            printf("You defeated all the aliens and won the game!\n");
            return 0;
        }
    }

    // Check if player won or lost
    if (health <= 0)
    {
        printf("You died and lost the game :(\n");
    }
    else
    {
        printf("You reached the end of the space adventure and won the game!!\n");
    }

    return 0;
}

void printIntro()
{
    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("You are a space explorer traveling through the galaxy in search of new planets to colonize.\n");
    printf("Your mission is to reach the end of the galaxy, %d light years away.\n", MAX_DISTANCE);
    printf("Be careful of aliens that you encounter along the way!\n");
    printf("You have a maximum of %d energy and %d health.\n", MAX_ENERGY, MAX_HEALTH);
    printf("Good luck!\n");
}

void printMenu()
{
    printf("\nMenu:\n");
    printf("1. Move forward (costs 5 energy)\n");
    printf("2. Increase energy (costs 1 health)\n");
    printf("3. Rest (costs 10 energy, gains 10 health)\n");
    printf("4. Fight (encounter a random number of aliens)\n");
    printf("Enter choice: ");
}

void moveForward(int* distance, int* energy, int* health)
{
    int cost = 5;
    if (*energy >= cost)
    {
        *distance += 10 + rand() % 11; // move between 10 and 20 light years
        *energy -= cost;
        printf("You moved forward and are now %d light years from Earth.\n", *distance);
    }
    else
    {
        printf("You don't have enough energy to move forward.\n");
    }
}

void increaseEnergy(int* distance, int* energy, int* health)
{
    int cost = 1;
    if (*health >= cost)
    {
        *energy += 10;
        *health -= cost;
        printf("You increased your energy.\n");
    }
    else
    {
        printf("You don't have enough health to increase your energy.\n");
    }
}

void rest(int* energy, int* health)
{
    int cost = 10;
    if (*energy >= cost)
    {
        *health += 10;
        *energy -= cost;
        printf("You rested and gained 10 health.\n");
    }
    else
    {
        printf("You don't have enough energy to rest.\n");
    }
}

void fight(int* energy, int* health, int* numAliens, int* alienHealth, int* alienDamage)
{
    // Encounter a random number of aliens
    int num = rand() % 3 + 1; // between 1 and 3 aliens
    printf("You encountered %d alien%s!\n", num, num == 1 ? "" : "s");

    // Set up alien health
    for (int i = 0; i < num; i++)
    {
        alienHealth[i] = MAX_ALIEN_HEALTH;
    }
    *numAliens = num;

    // Start fight loop
    while (*numAliens > 0 && *health > 0 && *energy > 0)
    {
        // Print status
        printf("You have %d health and %d energy.\n", *health, *energy);
        printf("Alien status:");
        for (int i = 0; i < *numAliens; i++)
        {
            if (alienHealth[i] != -1)
            {
                printf(" Alien %d: %d health", i+1, alienHealth[i]);
            }
        }
        printf("\n");

        // Get user input
        printf("What do you want to do?\n");
        printf("1. Use weapon (costs 10 energy, deals %d damage to a random alien)\n", WEAPON_DAMAGE);
        printf("2. Defend (costs 5 energy, reduces alien damage by half)\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        
        // Handle user choice
        switch (choice)
        {
            case 1:
                if (*energy < 10)
                {
                    printf("You don't have enough energy to use your weapon.\n");
                }
                else
                {
                    // Choose random alien and deal damage
                    int alienIndex = rand() % (*numAliens);
                    alienHealth[alienIndex] -= WEAPON_DAMAGE;
                    printf("You used your weapon on Alien %d and dealt %d damage.\n", alienIndex+1, WEAPON_DAMAGE);
                    *energy -= 10;
                }
                break;
            case 2:
                if (*energy < 5)
                {
                    printf("You don't have enough energy to defend.\n");
                }
                else
                {
                    // Reduce alien damage by half
                    *alienDamage = ALIEN_DAMAGE / 2;
                    printf("You defended yourself and reduced alien damage by half.\n");
                    *energy -= 5;
                }
                break;
            default:
                printf("Invalid choice\n");
        }
        
        // Handle alien attacks
        for (int i = 0; i < *numAliens; i++)
        {
            if (alienHealth[i] != -1)
            {
                *health -= *alienDamage;
                printf("Alien %d attacked you and dealt %d damage.\n", i+1, *alienDamage);
            }
        }

        // Check for defeated aliens
        for (int i = 0; i < *numAliens; i++)
        {
            if (alienHealth[i] <= 0)
            {
                printf("You defeated Alien %d!\n", i+1);
                alienHealth[i] = -1; // mark as defeated
                *numAliens -= 1;
            }
        }
    }
}