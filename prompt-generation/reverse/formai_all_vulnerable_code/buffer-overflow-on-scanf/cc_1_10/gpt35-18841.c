//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define our character structure */
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} character;

/* Function prototypes */
void print_character(character *c);
void battle(character *player, character *enemy);
void story();

int main() {
    story(); // Start the game by setting the scene
    character romeo = {"Romeo", 100, 50, 20};
    character juliet = {"Juliet", 100, 40, 30};
    printf("As you start your journey, two unlikely characters cross your path...\n");
    printf("You see Romeo, a brave warrior, and Juliet, a skilled commander.\n");
    printf("Who will you choose to travel with?\n\n");

    char choice;
    do {
        printf("Enter 1 for Romeo or 2 for Juliet: ");
        scanf(" %c", &choice);
    } while (choice != '1' && choice != '2');

    if (choice == '1') {
        printf("\nYou have chosen Romeo. Let the adventure begin!\n");
        battle(&romeo, &juliet);
    } else {
        printf("\nYou have chosen Juliet. Let the adventure begin!\n");
        battle(&juliet, &romeo);
    }

    return 0; // End the game
}

void print_character(character *c) {
    printf("%s: Health: %d, Attack: %d, Defense: %d\n", c->name, c->health, c->attack, c->defense);
}

void battle(character *player, character *enemy) {
    printf("\nAs you travel through space, you encounter an enemy spacecraft!\n");
    printf("With no way to avoid it, you prepare for battle...\n\n");

    while (player->health > 0 && enemy->health > 0) {
        /* Player attacks enemy */
        int damage = player->attack - enemy->defense;
        if (damage < 0) {
            damage = 0;
        }
        enemy->health -= damage;

        printf("%s attacks %s for %d damage! %s's health is now %d.\n", player->name, enemy->name, damage, enemy->name, enemy->health);

        /* Check if enemy is defeated */
        if (enemy->health <= 0) {
            printf("%s has been defeated!\n", enemy->name);
            break;
        }

        /* Enemy attacks player */
        damage = enemy->attack - player->defense;
        if (damage < 0) {
            damage = 0;
        }
        player->health -= damage;

        printf("%s attacks %s for %d damage! %s's health is now %d.\n", enemy->name, player->name, damage, player->name, player->health);

        /* Check if player is defeated */
        if (player->health <= 0) {
            printf("%s has been defeated!\n", player->name);
            break;
        }

        /* Print current health */
        printf("\nCurrent health:\n");
        print_character(player);
        print_character(enemy);

        /* Pause for dramatic effect */
        printf("\nPress any key to continue...\n");
        getchar();
    }

    printf("\nThe battle is over. %s and %s continue their journey through space.\n", player->name, enemy->name);
}

void story() {
    printf("In the distant future, mankind has colonized the stars and formed vast interstellar civilizations.\n");
    printf("You are a daring adventurer, traveling through space in search of excitement and riches.\n");
    printf("As you journey through the galaxy, you come across a tale as old as time...\n\n");
    printf("Two factions are at war with each other, fighting for control over a precious resource.\n");
    printf("On one side, there are the Montagues. They are known for their bravery and fierce fighting style.\n");
    printf("On the other side, there are the Capulets. They are known for their cunning and tactical skills.\n");
    printf("But amidst this ancient conflict, a love story has blossomed...\n");
    printf("Romeo, a Montague warrior, has fallen deeply in love with Juliet, a Capulet commander.\n");
    printf("The two star-crossed lovers must fight to stay together in a galaxy torn apart by war...\n\n");
}