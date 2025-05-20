//GEMINI-pro DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Character;

typedef struct {
    char *name;
    int damage;
    int accuracy;
} Weapon;

typedef struct {
    char *name;
    int strength;
    int dexterity;
    int intelligence;
    int charisma;
} Attribute;

typedef struct {
    char *name;
    int level;
    int experience;
    Character character;
    Attribute attributes;
    Weapon weapons[5];
} Player;

Player player;

void createPlayer() {
    player.name = "Player";
    player.level = 1;
    player.experience = 0;
    player.character.health = 100;
    player.character.attack = 10;
    player.character.defense = 10;
    player.attributes.strength = 10;
    player.attributes.dexterity = 10;
    player.attributes.intelligence = 10;
    player.attributes.charisma = 10;
    for (int i = 0; i < 5; i++) {
        player.weapons[i].name = NULL;
        player.weapons[i].damage = 0;
        player.weapons[i].accuracy = 0;
    }
}

void printPlayer() {
    printf("Name: %s\n", player.name);
    printf("Level: %d\n", player.level);
    printf("Experience: %d\n", player.experience);
    printf("Health: %d\n", player.character.health);
    printf("Attack: %d\n", player.character.attack);
    printf("Defense: %d\n", player.character.defense);
    printf("Strength: %d\n", player.attributes.strength);
    printf("Dexterity: %d\n", player.attributes.dexterity);
    printf("Intelligence: %d\n", player.attributes.intelligence);
    printf("Charisma: %d\n", player.attributes.charisma);
    for (int i = 0; i < 5; i++) {
        if (player.weapons[i].name != NULL) {
            printf("Weapon %d: %s (%d damage, %d accuracy)\n", i + 1, player.weapons[i].name, player.weapons[i].damage, player.weapons[i].accuracy);
        }
    }
}

void fight(Character *attacker, Character *defender) {
    int attackRoll = rand() % 20 + 1;
    int defenseRoll = rand() % 20 + 1;
    if (attackRoll >= defender->defense) {
        int damage = attacker->attack - defender->defense;
        defender->health -= damage;
        printf("%s attacked %s for %d damage!\n", attacker->name, defender->name, damage);
    } else {
        printf("%s missed %s!\n", attacker->name, defender->name);
    }
}

void explore() {
    printf("You are exploring the forest.\n");
    if (rand() % 10 == 0) {
        printf("You encounter a monster!\n");
        Character monster;
        monster.name = "Goblin";
        monster.health = 100;
        monster.attack = 10;
        monster.defense = 10;
        while (monster.health > 0 && player.character.health > 0) {
            fight(&player.character, &monster);
            if (monster.health > 0) {
                fight(&monster, &player.character);
            }
        }
        if (monster.health <= 0) {
            printf("You defeated the monster!\n");
            player.experience += 10;
        } else {
            printf("You were defeated by the monster!\n");
            player.character.health = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    createPlayer();
    while (player.character.health > 0) {
        printf("What do you want to do?\n");
        printf("1. Print player stats\n");
        printf("2. Explore the forest\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printPlayer();
                break;
            case 2:
                explore();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}