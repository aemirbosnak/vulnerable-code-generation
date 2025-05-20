//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int health = 100;
int money = 50;
int weapons = 0;
bool key = false;

// Function for generating random numbers
int random_number(int lower, int upper)
{
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Function for processing user input
void process_input(char *input)
{
    // Separate input into words
    char words[3][20];
    int word_count = sscanf(input, "%s %s %s", words[0], words[1], words[2]);

    // Check if input matches a command and execute it
    if (strcmp(words[0], "help") == 0)
    {
        printf("Available commands:\n");
        printf("- look\n");
        printf("- go [north/south/east/west]\n");
        printf("- fight\n");
        printf("- buy [weapon/healing]\n");
        printf("- use key\n");
        printf("- status\n");
        printf("- help\n");
    }
    else if (strcmp(words[0], "look") == 0)
    {
        printf("You see a dark forest. There is a path going north and south.\n");
    }
    else if (strcmp(words[0], "go") == 0)
    {
        if (word_count < 2)
        {
            printf("Where do you want to go?\n");
        }
        else if (strcmp(words[1], "north") == 0)
        {
            printf("You follow the path north and find a clearing with a shop.\n");
            printf("You have %d money.\n", money);
        }
        else if (strcmp(words[1], "south") == 0)
        {
            printf("You follow the path south and find a cave.\n");
        }
        else if (strcmp(words[1], "east") == 0)
        {
            printf("The east is blocked by a large boulder.\n");
        }
        else if (strcmp(words[1], "west") == 0)
        {
            printf("The west is a dense forest that seems difficult to navigate.\n");
        }
        else
        {
            printf("Invalid direction.\n");
        }
    }
    else if (strcmp(words[0], "fight") == 0)
    {
        int enemy_health = random_number(50, 100);
        printf("You encounter a monster with %d health.\n", enemy_health);

        while (health > 0 && enemy_health > 0)
        {
            int damage = random_number(10, 20);
            enemy_health -= damage;
            printf("You deal %d damage. The monster has %d health.\n", damage, enemy_health);

            if (enemy_health <= 0)
            {
                printf("You have defeated the monster!\n");
                money += random_number(10, 20);
                weapons++;
                break;
            }

            damage = random_number(10, 20);
            health -= damage;
            printf("The monster attacks and deals %d damage. You have %d health.\n", damage, health);
        }

        if (health <= 0)
        {
            printf("Game over. You have died.\n");
            exit(0);
        }
    }
    else if (strcmp(words[0], "buy") == 0)
    {
        if (word_count < 2)
        {
            printf("What do you want to buy?\n");
        }
        else if (strcmp(words[1], "weapon") == 0)
        {
            if (money < 30)
            {
                printf("You cannot afford a weapon.\n");
            }
            else
            {
                money -= 30;
                weapons++;
                printf("You buy a new weapon. You have %d money and %d weapons.\n", money, weapons);
            }
        }
        else if (strcmp(words[1], "healing") == 0)
        {
            if (money < 20)
            {
                printf("You cannot afford healing.\n");
            }
            else
            {
                money -= 20;
                health = 100;
                printf("You are healed. You have %d money and %d health.\n", money, health);
            }
        }
        else
        {
            printf("Invalid item.\n");
        }
    }
    else if (strcmp(words[0], "use") == 0 && strcmp(words[1], "key") == 0)
    {
        if (!key)
        {
            printf("You do not have a key.\n");
        }
        else
        {
            printf("You unlock the chest and find a treasure! You win the game.\n");
            exit(0);
        }
    }
    else if (strcmp(words[0], "status") == 0)
    {
        printf("Health: %d\n", health);
        printf("Money: %d\n", money);
        printf("Weapons: %d\n", weapons);
        printf("Key: %s\n", key ? "yes" : "no");
    }
    else
    {
        printf("Invalid command. Type 'help' for available commands.\n");
    }
}

// Main function
int main()
{
    printf("Welcome to the adventure game!\n");
    printf("Type 'help' for available commands.\n");

    while (true)
    {
        printf("> ");

        char input[100];
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n");

        process_input(input);
    }

    return 0;
}