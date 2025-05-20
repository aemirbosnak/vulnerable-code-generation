//FormAI DATASET v1.0 Category: Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for Player
typedef struct {
    char name[20];
    int health;
    int attack;
} Player;

// Function that generates a random number between two given values (inclusive)
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Player player1, player2;

    // Ask for player names
    printf("Enter player 1 name: ");
    scanf("%s", player1.name);
    printf("Enter player 2 name: ");
    scanf("%s", player2.name);

    // Set player health and attack
    player1.health = 100;
    player1.attack = generateRandomNumber(5, 10);
    player2.health = 100;
    player2.attack = generateRandomNumber(5, 10);

    // Game loop
    while (player1.health > 0 && player2.health > 0) {
        // Player 1 attack
        printf("%s attacks %s for %d damage!\n", player1.name, player2.name, player1.attack);
        player2.health -= player1.attack;
        if (player2.health < 0) {
            player2.health = 0;
        }
        printf("%s has %d health left.\n", player2.name, player2.health);
        if (player2.health == 0) {
            printf("%s has been defeated!\n", player2.name);
            break;
        }

        // Player 2 attack
        printf("%s attacks %s for %d damage!\n", player2.name, player1.name, player2.attack);
        player1.health -= player2.attack;
        if (player1.health < 0) {
            player1.health = 0;
        }
        printf("%s has %d health left.\n", player1.name, player1.health);
        if (player1.health == 0) {
            printf("%s has been defeated!\n", player1.name);
            break;
        }
    }

    // Print winner
    if (player1.health == 0) {
        printf("%s wins!\n", player2.name);
    } else if (player2.health == 0) {
        printf("%s wins!\n", player1.name);
    }

    return 0;
}