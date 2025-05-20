//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limit = 100; // maximum characters player can enter for their response
int player_health = 100; // player's starting health
int monster_health = 50; // monster's starting health

// function to check if player has won the game
void check_win() {
    if (monster_health <= 0) {
        printf("You have defeated the monster and survived!\n");
        exit(0); // exit the game
    }
}

// function to check if player has lost the game
void check_loss() {
    if (player_health <= 0) {
        printf("You have been defeated by the monster...\n");
        exit(0); // exit the game
    }
}

int main() {
    char response[limit]; // array to store player's response

    // game introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself trapped in a dungeon with a fearsome monster!\n");
    printf("You must defeat the monster or be trapped forever...\n");

    // game loop
    while (1) {
        printf("What do you do?\n");
        printf("1. Attack the monster\n");
        printf("2. Use a healing potion\n");
        printf("3. Run away\n");

        // get player's response
        fgets(response, limit, stdin);
        response[strlen(response) - 1] = '\0'; // remove newline character

        // handle player's response
        if (strcmp(response, "1") == 0) {
            // player attacks the monster and the monster takes damage
            int damage = rand() % 10 + 1; // random damage between 1-10
            monster_health -= damage;
            printf("You attack the monster and deal %d damage!\n", damage);
            printf("The monster now has %d health.\n", monster_health);
            check_win(); // check if player has won the game
            // monster attacks the player and the player takes damage
            damage = rand() % 10 + 1; // random damage between 1-10
            player_health -= damage;
            printf("The monster attacks you and deals %d damage!\n", damage);
            printf("You now have %d health.\n", player_health);
            check_loss(); // check if player has lost the game
        } else if (strcmp(response, "2") == 0) {
            // player uses a healing potion and gains health
            int healing = rand() % 25 + 1; // random healing between 1-25
            player_health += healing;
            if (player_health > 100) {
                player_health = 100; // limit player's health to 100
            }
            printf("You use a healing potion and gain %d health!\n", healing);
            printf("You now have %d health.\n", player_health);
            // monster attacks the player and the player takes damage
            int damage = rand() % 10 + 1; // random damage between 1-10
            player_health -= damage;
            printf("The monster attacks you and deals %d damage!\n", damage);
            printf("You now have %d health.\n", player_health);
            check_loss(); // check if player has lost the game
        } else if (strcmp(response, "3") == 0) {
            // player tries to run away but the monster attacks them
            printf("You try to run away but the monster attacks you!\n");
            int damage = rand() % 10 + 1; // random damage between 1-10
            player_health -= damage;
            printf("The monster deals %d damage!\n", damage);
            printf("You now have %d health.\n", player_health);
            check_loss(); // check if player has lost the game
        } else {
            // invalid response
            printf("Invalid response. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}