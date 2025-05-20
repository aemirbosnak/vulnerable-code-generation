//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Character
{
    char name[MAX_NAME_LENGTH];
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
} Character;

Character createCharacter();
void displayCharacter(Character);
void attack(Character, Character);

int main()
{
    Character hero = createCharacter();
    displayCharacter(hero);

    Character villain = createCharacter();
    displayCharacter(villain);

    attack(hero, villain);

    return 0;
}

Character createCharacter()
{
    Character character;

    character.strength = rand() % 10 + 1;
    character.dexterity = rand() % 10 + 1;
    character.constitution = rand() % 10 + 1;
    character.intelligence = rand() % 10 + 1;
    character.wisdom = rand() % 10 + 1;

    printf("Enter a name for your character: ");
    scanf("%s", character.name);

    return character;
}

void displayCharacter(Character character)
{
    printf("Name: %s\n", character.name);
    printf("Strength: %d\n", character.strength);
    printf("Dexterity: %d\n", character.dexterity);
    printf("Constitution: %d\n", character.constitution);
    printf("Intelligence: %d\n", character.intelligence);
    printf("Wisdom: %d\n", character.wisdom);
}

void attack(Character attacker, Character defender)
{
    int damage = attacker.strength - defender.constitution;

    if (damage > 0)
    {
        printf("%s attacks %s and deals %d damage!\n", attacker.name, defender.name, damage);
        defender.constitution -= damage;

        if (defender.constitution <= 0)
        {
            printf("%s has been defeated!\n", defender.name);
        }
    }
    else
    {
        printf("%s's attack failed!\n", attacker.name);
    }
}