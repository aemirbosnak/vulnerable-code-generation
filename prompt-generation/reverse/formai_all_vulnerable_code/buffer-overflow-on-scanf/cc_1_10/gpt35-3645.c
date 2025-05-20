//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
char player_name[100];
int hp = 100;
int gold = 0;
int room_number = 0;

// Function prototypes
void intro();
void game_over();
void explore_room();
void fight_monster();
void do_nothing();
void shop();

// Main function
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Display the intro message
    intro();

    // Main game loop
    while (hp > 0)
    {
        // Display current room number and menu
        printf("\nYou are in room %d\n", room_number);
        printf("HP: %d\n", hp);
        printf("Gold: %d\n", gold);
        printf("\nAvailable actions:\n");
        printf("1. Explore the room\n");
        printf("2. Fight a monster\n");
        printf("3. Do nothing\n");
        printf("4. Visit the shop\n");
        printf("5. Quit the game\n");

        // Get the user's choice
        int choice;
        scanf("%d", &choice);

        // Execute the chosen action
        switch (choice)
        {
            case 1:
                explore_room();
                break;
            case 2:
                fight_monster();
                break;
            case 3:
                do_nothing();
                break;
            case 4:
                shop();
                break;
            case 5:
                printf("Goodbye, %s!\n", player_name);
                exit(0); // Terminate the program
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    // Game over
    game_over();
    return 0;
}

// Display the intro message and get the player's name
void intro()
{
    printf("Welcome to the dungeon!\n");
    printf("What is your name?\n");
    scanf("%s", player_name);
    printf("Hello, %s! You have %d HP and %d gold.\n", player_name, hp, gold);
}

// Display the game over message and terminate the program
void game_over()
{
    printf("Game over, %s! You made it to room %d with %d HP and %d gold.\n", player_name, room_number, hp, gold);
    printf("Better luck next time!\n");
    exit(0); // Terminate the program
}

// Explore the current room and add a random amount of gold to the player's inventory
void explore_room()
{
    int amount = rand() % 20 + 1; // Generate a random amount of gold between 1 and 20
    gold += amount;
    printf("You explore the room and find %d gold coins!\n", amount);

    if (rand() % 2 == 0)
    {
        printf("You also find a potion that restores 25 HP!\n");
        hp += 25;
    }
}

// Fight a random monster and take damage based on the outcome
void fight_monster()
{
    int monster = rand() % 3; // Choose a random monster to fight

    switch (monster)
    {
        case 0:
            printf("You encounter a small goblin!\n");
            break;
        case 1:
            printf("You encounter a fierce ogre!\n");
            break;
        case 2:
            printf("You encounter a giant dragon!\n");
            break;
    }

    int outcome = rand() % 2; // 50/50 chance of winning the fight
    if (outcome == 0)
    {
        printf("You defeat the monster and take some damage!\n");
        hp -= rand() % 10 + 1; // Take a random amount of damage between 1 and 10
    }
    else
    {
        printf("The monster defeats you and takes some of your gold!\n");
        gold -= rand() % 10 + 1; // Lose a random amount of gold between 1 and 10
    }
}

// Do nothing and take a random amount of damage
void do_nothing()
{
    printf("You do nothing and take some damage!\n");
    hp -= rand() % 5 + 1; // Take a random amount of damage between 1 and 5
}

// Visit the shop and buy a random item
void shop()
{
    int item = rand() % 3; // Choose a random item to buy

    switch (item)
    {
        case 0:
            printf("You buy a potion that restores 50 HP for 25 gold!\n");
            if (gold >= 25)
            {
                gold -= 25;
                hp += 50;
            }
            else
            {
                printf("You don't have enough gold!\n");
            }
            break;
        case 1:
            printf("You buy a sword that deals extra damage for 50 gold!\n");
            if (gold >= 50)
            {
                gold -= 50;
            }
            else
            {
                printf("You don't have enough gold!\n");
            }
            break;
        case 2:
            printf("You buy a shield that reduces damage taken for 50 gold!\n");
            if (gold >= 50)
            {
                gold -= 50;
            }
            else
            {
                printf("You don't have enough gold!\n");
            }
            break;
    }
}