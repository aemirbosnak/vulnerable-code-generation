//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Dungeon of Doom!\n");

    // Create a hero
    char hero_name[20];
    printf("Enter your hero's name: ");
    scanf("%s", hero_name);

    // Create a monster
    char monster_name[20];
    printf("Enter the name of the monster you want to fight: ");
    scanf("%s", monster_name);

    // Determine the monster's strength
    int monster_strength = rand() % 10 + 1;

    // Determine the hero's strength
    int hero_strength = rand() % 10 + 1;

    // Battle!
    while (hero_strength > monster_strength)
    {
        // Hero attacks
        printf("%s attacks the %s with a mighty %s!\n", hero_name, monster_name, hero_name);
        monster_strength -= hero_strength;

        // Monster attacks
        printf("%s attacks the %s with its sharp claws!\n", monster_name, hero_name);
        hero_strength -= monster_strength;

        // Check if the hero is still alive
        if (hero_strength <= 0)
        {
            printf("Sorry, %s, you have been defeated.\n", hero_name);
            break;
        }

        // Print the status of the battle
        printf("Hero: %s, Strength: %d\n", hero_name, hero_strength);
        printf("Monster: %s, Strength: %d\n", monster_name, monster_strength);
    }

    // Game over
    printf("Congratulations, %s, you have slain the %s!\n", hero_name, monster_name);
    system("pause");
    return 0;
}