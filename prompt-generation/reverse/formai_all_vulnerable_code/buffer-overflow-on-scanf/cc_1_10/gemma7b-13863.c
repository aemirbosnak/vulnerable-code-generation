//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <string.h>

#define DEBUG 1

typedef struct Spellcasting {
    char name[20];
    int mana_cost;
    char effect[100];
} Spellcasting;

Spellcasting spells[] = {
    {"Telekinesis", 5, "Move objects with your mind."},
    {"Invisibility", 3, "Become invisible."},
    {"Fireball", 7, "Throw a ball of fire."},
    {"Lightning Bolt", 6, "Summon a bolt of lightning."}
};

int main()
{
    int spell_index;
    char spell_name[20];
    int mana_cost;
    char spell_effect[100];

    printf("Gather 'round, young apprentice, and hear the tale of the forgotten spell.\n");

    // Get the spell name from the user
    printf("What is the name of the spell you wish to recover? ");
    scanf("%s", spell_name);

    // Search for the spell in the spellcasting list
    for (spell_index = 0; spell_index < 4; spell_index++)
    {
        if (strcmp(spell_name, spells[spell_index].name) == 0)
        {
            // Found the spell!

            // Print the spell information
            printf("Name: %s\n", spells[spell_index].name);
            printf("Mana Cost: %d\n", spells[spell_index].mana_cost);
            printf("Effect: %s\n", spells[spell_index].effect);

            break;
        }
    }

    // If the spell was not found, inform the user
    if (spell_index == 4)
    {
        printf("The spell you are searching for does not exist.\n");
    }

    return 0;
}