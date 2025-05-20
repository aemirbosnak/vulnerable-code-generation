//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char character_name[20];
    int character_health = 100;
    int character_strength = 20;
    int character_intelligence = 15;
    int character_agility = 12;
    int enemy_health = 150;
    int enemy_strength = 25;
    int enemy_intelligence = 10;
    int enemy_agility = 18;

    printf("Welcome, traveler, to the realm of Aion. Please choose a name:");
    scanf("%s", character_name);

    printf("Your journey begins in the quaint village of Willow Creek. You are a humble villager, known for your strength, intelligence, and agility. You have a loyal companion, a mighty warrior named Aegna. You have been summoned to the grand hall of the Dragon's Lair, where you must face a formidable enemy. Are you ready?");

    system("pause");

    // Battle sequence
    while (character_health > 0 && enemy_health > 0)
    {
        // Character's turn
        printf("What would you like to do? (Attack, Cast Spell, Defend): ");
        char input;
        scanf("%c", &input);

        switch (input)
        {
            case 'A':
                enemy_health -= character_strength;
                printf("You have attacked the enemy, dealing %d damage.\n", character_strength);
                break;
            case 'C':
                enemy_health -= character_intelligence;
                printf("You have cast a spell, dealing %d damage.\n", character_intelligence);
                break;
            case 'D':
                enemy_agility -= character_agility;
                printf("You have defended against the enemy's attack.\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Enemy's turn
        printf("The enemy has taken damage and is attacking. Prepare for battle...\n");
        character_health -= enemy_strength;
        printf("The enemy has attacked you, dealing %d damage.\n", enemy_strength);
    }

    // Game over
    if (character_health <= 0)
    {
        printf("Your journey ends here. You have fallen in battle against the formidable enemy.\n");
    }
    else
    {
        printf("Congratulations, traveler. You have defeated the enemy and saved the realm of Aion.\n");
    }

    return 0;
}